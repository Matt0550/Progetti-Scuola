<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $materia = $_POST["materia"];
    $voto = $_POST["voto"];
    $data = $_POST["data"];

    if (empty($materia) && isset($materia)) echo "Devi inserire una materia!<br>";
    if (empty($voto) && isset($voto)) echo "Devi inserire un voto!<br>";
    if (empty($data) && isset($data)) echo "Devi inserire una data!<br>";


    if ($voto < 0 || $voto > 10) echo "Il voto non può essere inferiore a 0 e superiore a 10<br>"; die();

    echo "In data <b>$data</b> hai preso <b>$voto</b> di <b>$materia</b>";

} else {
    echo "Il metodo utilizzato non è corretto. Metodi accettati: POST";
}
?>