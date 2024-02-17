<?php
$dati = [
    [
        "id" => 1,
        "marca" => "Fiat",
        "modello" => "Panda",
        "prezzo" => 15000,
        "motoriDisponibili" =>
        [
            [
                "nome" => "Benzina",
                "prezzo" => 0,
            ],
            [
                "nome" => "Diesel",
                "prezzo" => 1500,
            ]
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
        "motoriDisponibili" =>
        [
            [
                "nome" => "Benzina",
                "prezzo" => 0,
            ]
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
    // Variabili
    $nome = $_POST["nome"];
    $cognome = $_POST["cognome"];
    $modelloAuto = $_POST["modelloAuto"];
    $annotazioni = $_POST["annotazioni"];
    $tipoMotoreNome = isset($_POST["tipoMotore"]) ? $_POST["tipoMotore"] : [];
    $optionalSelezionati = isset($_POST["optionalSelezionati"]) ? $_POST["optionalSelezionati"] : [];
    $salvaPreventivo = isset($_POST["salvaPreventivoBtn"]);

    // Ricevo le opzioni disponibili quando l'utente seleziona un modello di auto specifico
    $autoIndex = array_search($modelloAuto, array_column($dati, 'id'));
    $optionalLista = $dati[$autoIndex]["optionalDisponibili"];
    $tipoMotoreLista = $dati[$autoIndex]["motoriDisponibili"];
    $tipoMotoreIndex = array_search($tipoMotoreNome, array_column($tipoMotoreLista, "nome"));

    // Calcolo il costo totale dell'auto
    $costoBase = $dati[$autoIndex]["prezzo"];
    $costoMotore = $tipoMotoreLista[$tipoMotoreIndex]["prezzo"];
    $costoOpzionali = 0;
    foreach ($optionalLista as $optional) {
        if (in_array($optional['nome'], $optionalSelezionati)) {
            $costoOpzionali += $optional['prezzo'];
        }
    }
    $costoTotale = $costoBase + $costoOpzionali + $costoMotore;

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
            <?php if(!$salvaPreventivo): ?>

                <form class="card-body" action="/proxy/80<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
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
                        <select class="select select-bordered" name="modelloAuto" onchange="this.form.submit()" required>
                            <option disabled selected value="">Seleziona</option>
                            <?php
                                foreach ($dati as $auto) {
                                    $isSelected = isset($modelloAuto) && $modelloAuto == $auto["id"];
                                    // print_r($auto);
                                    // echo $auto["marca"];
                                    echo '<optgroup label="' . $auto["marca"] . '">';
                                    echo '<option ' . ($isSelected ? "selected" : "") . ' value="' . $auto["id"] . '">' . $auto["modello"] . ' - ' . $auto["prezzo"] . '€' . '</option>';
                                    echo '</optgroup>';
                                }
                                
                            ?>
                        </select>

                    </div>

                    <?php if(isset($tipoMotoreLista)): ?>
                    <div class="form-control">
                        <div class="label">
                            <span class="label-text">Tipo di motore</span>
                        </div>
                        <select class="select select-bordered" name="tipoMotore" onchange="this.form.submit()" required>
                            <option disabled selected value="">Seleziona</option>
                            <?php
                            foreach ($tipoMotoreLista as $motore) {
                                    $isSelected = isset($motore["nome"]) && $motore["nome"] == $tipoMotoreNome;

                                    // print_r($auto);
                                    // echo $auto["marca"];
                                    echo '<option ' . ($isSelected ? "selected" : "") . ' value="' . $motore["nome"] . '">' . $motore["nome"] . " +" . $motore["prezzo"] . '€</option>';
                                
                            }   
                            ?>
                        </select>
                    </div>
                    <?php endif; ?>

                    <?php if(isset($optionalLista)): ?>
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
                    <?php endif; ?>

                    <label class="form-control">
                        <div class="label">
                            <span class="label-text">Annotazioni</span>
                        </div>
                        <textarea name="annotazioni" class="textarea textarea-bordered h-24" placeholder="Scrivere qui..."><?php echo $annotazioni ?></textarea>
        
                    </label>
                    

                    <div class="form-control mt-6">
                        <?php 
                            $isDone = isset($optionalLista) && isset($tipoMotoreLista);
                            echo '<button '. (!$isDone ? "disabled" : "") .' class="btn btn-primary" name="salvaPreventivoBtn">Salva preventivo</button>'
                        ?>
                    </div>
                    <?php if(isset($costoTotale)): ?>

                    <p class="text-center my-4 text-xl">Costo totale: <b><?php echo $costoTotale ?>€</b></p>
                    <?php endif; ?>

                </form>
                <?php else: ?>
                <div class="card-body">
                    <p class="text-center font-bold text-md">Nome e Cognome
                        <br>
                        <span class="font-normal">
                            <?php echo $nome . ' ' . $cognome; ?>
                        </span>
                    </p>
                    <p class="text-center font-bold text-md">Modello selezionato
                        <br>
                        <span class="font-normal">
                            <?php echo $dati[$autoIndex]["marca"] . ' ' . $dati[$autoIndex]["modello"] . ' - <span class="font-bold">'. $dati[$autoIndex]["prezzo"] . '€</span>'; ?>
                        </span>
                    </p>
                    <p class="text-center font-bold text-md">Motore selezionato
                        <br>
                        <span class="font-normal">
                            <?php echo $tipoMotoreNome . ' - <span class="font-bold">'. $costoMotore . '€</span>'; ?>
                        </span>
                    </p>
                    <p class="text-center font-bold text-md">Optional selezionati
                        <br>
                        <span class="font-normal">
                            <?php
                            if (is_null($optionalSelezionati)) echo 'nessuno';
                            foreach ($optionalLista as $optional) {
                                if (in_array($optional['nome'], $optionalSelezionati)) {
                                    echo $optional["nome"] . ' - <span class="font-bold">'. $optional["prezzo"] . '€</span><br>'; 
                                }
                            }    
                    
                            ?>
                        </span>
                    </p>
                    <p class="text-center font-bold text-md">Annotazioni
                        <br>
                        <span class="font-normal">
                            <?php 
                                if (is_null($annotazioni)) echo 'nessuno';

                                echo $annotazioni;
                            ?>
                        </span>
                    </p>
                    <p class="text-center my-2 text-xl">Costo totale: <b><?php echo $costoTotale ?>€</b></p>

                </div>
                <?php endif; ?>
            </div>
            <a class="font-bold" href="https://bio.matt05.it" target="_blank">Matteo Sillitti 5C INF</a>
        </div>
    </div>
</body>

</html>
