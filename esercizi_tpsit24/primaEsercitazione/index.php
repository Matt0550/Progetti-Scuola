<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Prima esercitazione</title>

    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }

        .numeri {
            display: grid;
            grid-template-columns: repeat(5, 1fr);
            grid-column-gap: 0px;
            grid-row-gap: 0px;
            justify-content: center;
            text-align: center;
            column-gap: 10px;
        }

        .numeri p {
            padding: 10px;
            background-color: lightblue;
            border-radius: 10px;
        }
    </style>
</head>

<body>
    <?php
$numeri = [];

for($i=0; $i<10; $i++) {
    $numeri[$i] = rand(0, 100);
}

$max = max($numeri);
$min = min($numeri);
$somma = array_sum($numeri);
$media = $somma / count($numeri);

echo "Il numero massimo dell'array è <b>$max</b><br>";
echo "Il numero minimo dell'array è <b>$min</b><br>";
echo "La media dei numeri dell'array è <b>$media</b><br>";
echo "La somma dei numeri dell'array è <b>$somma</b><br>";

echo "<div class='numeri'>";
foreach($numeri as $numero) {
    echo "<p>$numero</p>";
}

echo "</div>";
?>
</body>

</html>