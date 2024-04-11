<?php
// Connect to mysql
$host = "localhost";
$username = "root";
$password = "";
$dbname = "esercitazioni_tpsit";

$conn = mysqli_connect($host, $username, $password, $dbname);

if ($conn == false)
    exit("Errore DB: " . mysqli_connect_error());

$queryUtenti = "SELECT * FROM utenti";
$datiUtenti = mysqli_query($conn, $queryUtenti);
if (!$datiUtenti)
    die("Errore database!");

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["elimina"])) {
        $id = $_POST["id"];

        if (empty($id)) {
            exit("Dati mancanti!");
        }

        $queryDelete = $conn->prepare("DELETE FROM utenti WHERE id = ?");
        $queryDelete->bind_param("i", $id);
        $queryDelete->execute();



        header("Location: .");

    } else if(isset($_POST["editModal"])) {
        $id = $_POST["id"];
        $nome = $_POST["nome"];
        $cognome = $_POST["cognome"];
        $username = $_POST["username"];

        if (empty($nome) || empty($cognome) || empty($username || $id)) {
            exit("Dati mancanti!");
        }

        $queryUpdate = $conn->prepare("UPDATE utenti SET nome = ?, cognome = ?, username = ? WHERE id = ?");
        $queryUpdate->bind_param("sssi", $nome, $cognome, $username, $id);
        $queryUpdate->execute();

        header("Location: .");

    } else if (isset($_POST["modifica"])) {
        $id = $_POST["id"];
        $nome = $_POST["nome"];
        $cognome = $_POST["cognome"];
        $username = $_POST["username"];

        if (empty($nome) || empty($cognome) || empty($username)) {
            exit("Dati mancanti!");
        }

        echo <<<HTML
            <dialog class="modal" id="modifica_modal">
                <div class="modal-box">
                    <h3 class="font-bold text-lg">Modifica riga $id</h3>
                
          
                <form class="flex flex-col gap-y-2" action="." method="post">
                    <input type="hidden" name="editModal"/>
                    <input type="hidden" name="id" value="$id"/>

                    <label class="input input-bordered flex items-center gap-2">
                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                            class="w-4 h-4 opacity-70">
                            <path
                                d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                        </svg>
                        <input type="text" name="nome" class="grow" required placeholder="Nome" value="$nome" />
                    </label>
                    <label class="input input-bordered flex items-center gap-2">
                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                            class="w-4 h-4 opacity-70">
                            <path
                                d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                        </svg>
                        <input type="text" name="cognome" class="grow" required placeholder="Cognome" value="$cognome" />
                    </label>
                    <label class="input input-bordered flex items-center gap-2">
                        <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                            class="w-4 h-4 opacity-70">
                            <path
                                d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                        </svg>
                        <input type="text" name="username" class="grow" required placeholder="Username" value="$username" />
                    </label>
                    <button class="btn btn-primary" type="submit">Modifica</button>


                </form>
                </div>

            </dialog>
            <script>modifica_modal.showModal()</script>
        HTML;

    } else {
        $nome = $_POST["nome"];
        $cognome = $_POST["cognome"];
        $username = $_POST["username"];

        if (empty($nome) || empty($cognome) || empty($username)) {
            exit("Dati mancanti!");
        }

        $queryInsert = $conn->prepare("INSERT INTO utenti (nome, cognome, username) VALUES (?, ?, ?)");
        $queryInsert->bind_param("sss", $nome, $cognome, $username);
        $queryInsert->execute();

        //header("Location: .");

    }

}
?>


<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sesta esercitazione</title>
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
                <h1 class="text-5xl font-bold my-4">Sesta esercitazione</h1>
            </div>

            <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                <div class="overflow-x-auto">
                    <table class="table">
                        <!-- head -->
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Nome</th>
                                <th>Cognome</th>
                                <th>Username</th>
                                <th>Creato il</th>
                                <th>Azioni</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php
                            if (mysqli_num_rows($datiUtenti) > 0) {
                                while ($riga = mysqli_fetch_assoc($datiUtenti)) {
                                    $id = $riga["id"];
                                    $nome = $riga["nome"];
                                    $cognome = $riga["cognome"];
                                    $username = $riga["username"];
                                    $date = $riga["creato_il"];
                                    echo <<<RIGA
                                        <tr class="hover">
                                            <td>$id</td>
                                            <td>$nome</td>
                                            <td>$cognome</td>
                                            <td>$username</td>
                                            <td>$date</td>
                                            <td class="flex flex-row gap-x-2">
                                                <form action="." method="post">
                                                    <input type="hidden" name="id" value="$id"/>
                                                    <input type="hidden" name="nome" value="$nome"/>
                                                    <input type="hidden" name="cognome" value="$cognome"/>
                                                    <input type="hidden" name="username" value="$username"/>
                                                    <button class="btn btn-primary btn-sm" name="modifica">Modifica</button>
                                                </form>
                                                <form action="." method="post">
                                                    <input type="hidden" name="id" value="$id"/>
                                                    <button class="btn btn-error btn-sm" name="elimina">Elimina</button>
                                                </form>
                                            </td>
                                        </tr>
                                        RIGA;
                                }
                            }
                            ?>
                        </tbody>
                    </table>
                </div>

            </div>
            <h1 class="text-2xl font-bold mt-4 mb-2 text-center">Inserisci</h1>

            <form class="flex flex-col gap-y-2" action="." method="post">
                <label class="input input-bordered flex items-center gap-2">
                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                        class="w-4 h-4 opacity-70">
                        <path
                            d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                    </svg>
                    <input type="text" name="nome" class="grow" required placeholder="Nome" />
                </label>
                <label class="input input-bordered flex items-center gap-2">
                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                        class="w-4 h-4 opacity-70">
                        <path
                            d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                    </svg>
                    <input type="text" name="cognome" class="grow" required placeholder="Cognome" />
                </label>
                <label class="input input-bordered flex items-center gap-2">
                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" fill="currentColor"
                        class="w-4 h-4 opacity-70">
                        <path
                            d="M8 8a3 3 0 1 0 0-6 3 3 0 0 0 0 6ZM12.735 14c.618 0 1.093-.561.872-1.139a6.002 6.002 0 0 0-11.215 0c-.22.578.254 1.139.872 1.139h9.47Z" />
                    </svg>
                    <input type="text" name="username" class="grow" required placeholder="Username" />
                </label>
                <button class="btn btn-primary" type="submit">Inserisci</button>


            </form>

            <a class="font-bold" href="https://bio.matt05.it" target="_blank">Matteo Sillitti 5C INF</a>

        </div>
    </div>
</body>

</html>
