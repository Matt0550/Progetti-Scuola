<?php
$dati = [
    [
        "id" => 1,
        "marca" => "Fiat",
        "modello" => "Panda",
        "prezzo" => 15000,
        "specifiche" => [
            "motore" => "100kw"
        ],
        "optionalDisponibili" => [
            [
                "nome" => "Cerchi in lega",
                "prezzo" => 500,
            ],
            [
                "nome" => "CarPlay",
                "prezzo" => 2000,
            ],
            
        ],
        
    ],
    [
        "id" => 2,
        "marca" => "Audi",
        "modello" => "Q3",
        "prezzo" => 44000,
        "specifiche" => [
            "motore" => "200kw"
        ],
        "optionalDisponibili" => [
            [
                "nome" => "Cambio Automatico",
                "prezzo" => 2000,
            ],
            [
                "nome" => "Cerchi in lega",
                "prezzo" => 2000,
            ],
            [
                "nome" => "CarPlay",
                "prezzo" => 2000,
            ],
            [
                "nome" => "Tettuccio",
                "prezzo" => 1400,
            ],   
            [
                "nome" => "Sedili in pelle",
                "prezzo" => 2500,
            ],   
        ],
    ],
];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nome = $_POST["nome"];
    $cognome = $_POST["cognome"];
    $modelloAuto = $_POST["modelloAuto"];
    $annotazioni = $_POST["annotazioni"];
    $optionalSelezionati = isset($_POST["optionalSelezionati"]) ? $_POST["optionalSelezionati"] : [];

    // Retrieve the available options for the selected car
    $autoIndex = array_search($modelloAuto, array_column($dati, 'id'));
    $optionalLista = $dati[$autoIndex]["optionalDisponibili"];
    
    // Calculate the total cost
    $costoBase = $dati[$autoIndex]["prezzo"];
    $costoOpzionali = 0;
    foreach ($optionalLista as $optional) {
        if (in_array($optional['nome'], $optionalSelezionati)) {
            $costoOpzionali += $optional['prezzo'];
        }
    }
    $costoTotale = $costoBase + $costoOpzionali;

}



?>

<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Terza esercitazione</title>
    <link href="https://cdn.jsdelivr.net/npm/daisyui@4.6.1/dist/full.min.css" rel="stylesheet" type="text/css" />
    <script src="https://cdn.tailwindcss.com"></script>

</head>

<body data-theme="emerald">
    <div class="hero min-h-screen bg-base-200">
        <div class="hero-content flex-col">
            <div class="text-center">
                <h1 class="text-5xl font-bold mb-4">Terza esercitazione</h1>
            </div>
            <div class="card shrink-0 w-full max-w-md shadow-2xl bg-base-100">
                <form class="card-body" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
                    <div class="form-control">
                        <label class="label">
                            <span class="label-text">Nome</span>
                        </label>
                        <input name="nome" type="text" placeholder="Nome" value="<?php echo $nome ?>" class="input input-bordered" required />

                    </div>
                    <div class="form-control">
                        <label class="label">
                            <span class="label-text">Cognome</span>
                        </label>
                        <input name="cognome" type="text" placeholder="Cognome"  value="<?php echo $cognome ?>" class="input input-bordered" required />

                    </div>
                    <div class="form-control">
                        <div class="label">
                            <span class="label-text">Modello</span>
                        </div>
                        <select class="select select-bordered" name="modelloAuto" onchange="this.form.submit()">
                            <option disabled selected>Seleziona</option>
                            <?php
                                foreach ($dati as $auto) {
                                    $isSelected = isset($modelloAuto) && $modelloAuto == $auto["id"];
                                    // print_r($auto);
                                    // echo $auto["marca"];
                                    echo '<optgroup label="' . $auto["marca"] . '">';
                                    echo '<option ' . ($isSelected ? "selected" : "") . ' value="' . $auto["id"] . '">' . $auto["modello"] . '</option>';
                                    echo '</optgroup>';
                                }
                                
                            ?>
                        </select>

                    </div>
                    <span class="label-text text-center mt-2 mb-0">Optional disponibili</span>

                        <div class="form-control flex-wrap flex-row gap-x-3 justify-center">

                            <?php
                                foreach ($optionalLista as $optional) {
                                    $isChecked = isset($_POST['optionalSelezionati']) && in_array($optional["nome"], $_POST['optionalSelezionati']);
                                    echo '<label class="label cursor-pointer">';
                                    echo '<input type="checkbox" onChange="this.form.submit()" class="checkbox" name="optionalSelezionati[]" value="' . $optional["nome"] . '" ' . ($isChecked ? 'checked' : '') . ' />';
                                    echo '<span class="label-text mx-2">' . $optional["nome"] . " <b>+" . $optional["prezzo"] . "€</b>" . '</span>';
                                    echo '</label>';
                                }
                                
                            ?>

                        </div>
                    <label class="form-control">
                        <div class="label">
                            <span class="label-text">Annotazioni</span>
                        </div>
                        <textarea name="annotazioni" class="textarea textarea-bordered h-24" placeholder="Scrivere qui..."><?php echo $annotazioni ?></textarea>
        
                    </label>

                    <div class="form-control mt-6">
                        <button class="btn btn-primary">Aggiorna preventivo</button>
                    </div>
                    <p class="text-center my-4 text-xl">Costo totale: <b><?php echo $costoTotale ?>€</b></p>

                </form>

            </div>
            <a class="font-bold" href="https://bio.matt05.it" target="_blank">Matteo Sillitti 5C INF</a>
        </div>
    </div>
</body>

</html>