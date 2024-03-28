<?php 
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $puntata = $_POST["puntata"];

    if ($puntata < 0 || $puntata > 99) {
        exit("La puntata non è valida!");
    }
    
    $numeriScelti = [];

    for($i = 1; $i<=90; $i++) {
        if(isset($_POST["number_$i"]) and $_POST["number_$i"] == $i) {
            array_push($numeriScelti, $i);
        }
    }
    
    if (empty($numeriScelti)) {
        exit("I numeri inseriti non sono validi!");
    }

    $numeriGenerati = [rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90)];

    while (count(array_unique($numeriGenerati)) != 6) {
        $numeriGenerati = [rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90), rand(1, 90)];
    }
    
    $numeriIndovinati = [];

    foreach($numeriScelti as $numero) {
        if ($numero < 1 || $numero > 90 || count(array_unique($numeriScelti)) != 6) {
            exit("I numeri inseriti non sono validi! Puoi selezionare massimo 6 numeri.");
        }
        
        if (in_array($numero, $numeriGenerati)) {
            array_push($numeriIndovinati, $numero);
        }
    }

    $vincita = ($puntata * count($numeriIndovinati));
}
?>


<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Quinta esercitazione</title>
    <link href="https://cdn.jsdelivr.net/npm/daisyui@4.6.1/dist/full.min.css" rel="stylesheet" type="text/css" />
    <script src="https://cdn.tailwindcss.com"></script>

    <style>
        /* Chrome, Safari, Edge, Opera */
        input[type=number]::-webkit-inner-spin-button, 
        input[type=number]::-webkit-outer-spin-button { 
            -webkit-appearance: none;
            appearance: none; 
        }

        /* Firefox */
        input[type=number] {
            -moz-appearance: textfield;
        }

   
    </style>
</head>

<body data-theme="emerald">
    <div class="hero min-h-screen bg-base-200">
        <div class="hero-content flex-col">
            <div class="flex flex-col items-center justify-center">
                <img class="w-40" src="https://www.superenalotto.it/content/dam/gntn/assets/logos/superenalotto-vertical-raw.png"/>
                <h1 class="text-5xl font-bold my-4">Quinta esercitazione</h1>
                <p class="text-md">Seleziona 6 numeri fortunati</p>
            </div>

            <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                <?php if(isset($numeriIndovinati)): ?>
                    <div class="card-body">
                        <?php if (count($numeriIndovinati) == 0): ?>
                            <p class="text-3xl font-bold text-center">Non hai vinto!</p>
                            <p class="text-md text-center">Mi dispiace, questa volta non hai vinto, ritenta!</p>

                        <?php else:?>
                            <p class="text-3xl font-bold text-center">Hai vinto!</p>
                            <p class="text-3xl font-bold text-center"><?php echo $vincita ?>€</p>
                            <p class="text-xl text-center">Numeri vincenti: <span class="font-bold"><?php echo implode(", ", $numeriIndovinati); ?></span></p>

                            <?php endif;?>
                        <p class="text-sm text-center">Puntata: <?php echo $puntata; ?>€</p>
                        <p class="text-sm text-center">I tuoi numeri: <?php echo implode(", ", $numeriScelti); ?></p>
                        <p class="text-sm text-center">Numeri estratti: <?php echo implode(", ", $numeriGenerati); ?></p>
                        <a class="link text-center" href=".">Nuova schedina</a>

                    </div>
                
                <?php else: ?>

                <form class="card-body" action="." method="post">
                    <div class="grid grid-cols-10 gap-2">
                    <?php
                        for ($i = 1; $i <= 90; $i++) {
                            echo <<<NUM
                        
                                <label class="cursor-pointer label gap-2">
                                    <span class="label-text">$i</span>
                                    <input type="checkbox" class="checkbox" name="number_$i" id="number_$i" value="$i">
                                </label>
                            NUM;
                        }
                    ?>
                    </div>
                    <div class="form-control">
                        <input name="puntata" type="number" placeholder="es. 10€" class="input input-bordered" required min="1" max="99" />
                    </div>

                    <input type="submit" class="btn btn-primary mt-4" value="Scopri se hai vinto"/>
                </form>
                <?php endif; ?>
                
            </div>
            <a class="font-bold" href="https://bio.matt05.it" target="_blank">Matteo Sillitti 5C INF</a>

        </div>
    </div>
</body>
</html>