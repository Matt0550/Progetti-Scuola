<?php
/*
Create una semplice applicazione WEB PHP/HTML/SQL che coinvolga un database per la gestione di canzoni, artisti e case discografiche.

Svolgete i seguenti punti:
- Descrivete le scelte progettuali e il funzionamento dell'applicazione.

- Visualizzazione dei titoli delle canzoni e dell'artista in base alla casa discografica scelta dall'utente.
- Inserimento di un artista;
- Inserimento di una canzone con il suo relativo artista.
www.matteosillitti.it
*/
// Check if .env exists
if (!file_exists(".env"))
    exit("File .env non trovato! Copiare il file .env.example e rinominarlo in .env");

// Parse .env
$env = parse_ini_file(".env");

$host = $env["MYSQL_HOST"];
$username = $env["MYSQL_USER"];
$password = $env["MYSQL_PASSWORD"];
$dbName = $env["MYSQL_DATABASE"];
$port = $env["MYSQL_PORT"];

$conn = mysqli_connect($host, $username, $password, $dbName, $port);

if ($conn == false)
    exit("Errore: " . mysqli_connect_error());


$queryCaseDiscografiche = "SELECT * FROM caseDiscografiche";
$datiCaseDiscografiche = mysqli_query($conn, $queryCaseDiscografiche);
if (!$datiCaseDiscografiche)
    die("Errore database!");

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo "<script>console.log('POST: " . json_encode($_POST) . "');</script>";
    if (isset($_POST["casaDiscograficaId"])) {
        $casaDiscograficaId = $_POST["casaDiscograficaId"];

        $queryCaseDiscografica = $conn->prepare("SELECT * FROM caseDiscografiche WHERE id = ? LIMIT 1");
        $queryCaseDiscografica->bind_param("i", $casaDiscograficaId);
        $queryCaseDiscografica->execute();
        $datiCaseDiscografica = $queryCaseDiscografica->get_result();
        $casaDiscografica = mysqli_fetch_assoc($datiCaseDiscografica);

    }

    if (isset($_POST["eliminaCasaDiscografica"])) {
        $id = $_POST["casaDiscograficaId"];

        if (empty($id)) {
            exit("ERRORE: eliminaCasaDiscografica: Dati mancanti!");
        }

        // Delete all artisti_canzoni
        $queryDeleteArtistiCanzoni = $conn->prepare("DELETE FROM artisti_canzoni WHERE idArtista IN (SELECT id FROM artisti WHERE casaDiscograficaId = ?)");
        $queryDeleteArtistiCanzoni->bind_param("i", $id);
        $queryDeleteArtistiCanzoni->execute();

        // Delete all artisti
        $queryDeleteArtisti = $conn->prepare("DELETE FROM artisti WHERE casaDiscograficaId = ?");
        $queryDeleteArtisti->bind_param("i", $id);
        $queryDeleteArtisti->execute();

        // Delete all canzoni
        $queryDeleteCanzoni = $conn->prepare("DELETE FROM canzoni WHERE casaDiscograficaId = ? ");
        $queryDeleteCanzoni->bind_param("i", $id);
        $queryDeleteCanzoni->execute();

        $queryDelete = $conn->prepare("DELETE FROM caseDiscografiche WHERE id = ?");
        $queryDelete->bind_param("i", $id);
        $queryDelete->execute();


        header("Location: .");

    } else if (isset($_POST["editModalCasaDiscografica"])) {
        $id = $_POST["casaDiscograficaId"];
        $nome = $_POST["nome"];
        $website = $_POST["website"];
        $dataFondazione = $_POST["dataFondazione"];

        if (empty($nome) || empty($website) || empty($dataFondazione || empty($id))) {
            exit("ERRORE: editModalCasaDiscografica: Dati mancanti!");
        }

        $queryUpdate = $conn->prepare("UPDATE caseDiscografiche SET nome = ?, website = ?, dataFondazione = ? WHERE id = ?");
        $queryUpdate->bind_param("sssi", $nome, $website, $dataFondazione, $id);
        $queryUpdate->execute();

        header("Location: .");

    } else if (isset($_POST["modificaCasaDiscografica"])) {
        // Questo codice viene eseguito quando si preme il pulsante "Modifica" nella tabella ed apre il dialog

        $id = $_POST["casaDiscograficaId"];

        if (empty($id)) {
            exit("ERRORE: modificaCasaDiscografica: Dati mancanti!");
        }

        echo <<<HTML
            <dialog class="modal" id="modificaCasaModal">
                <div class="modal-box">
                    <h3 class="font-bold text-lg">Modifica riga $id</h3>
                    <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                        <input type="hidden" name="editModalCasaDiscografica"/>
                        <input type="hidden" name="casaDiscograficaId" value="$id"/>

                        <label class="input input-bordered flex items-center gap-2">
                            <input type="text" name="nome" class="grow" required placeholder="Nome" value="{$casaDiscografica['nome']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <input type="url" name="website" class="grow" required placeholder="Website" value="{$casaDiscografica['website']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <input type="date" name="dataFondazione" class="grow" required placeholder="Data Fondazione" value="{$casaDiscografica['dataFondazione']}" />
                        </label>
                        <button class="btn btn-primary" type="submit">Modifica</button>
                        <a href="." class="link link-error text-center">Annulla</a>
                    </form>
                </div>
            </dialog>
            <script>
                // On document ready
                document.addEventListener("DOMContentLoaded", function () {
                    modificaCasaModal.showModal();
                });
            </script>
        HTML;

    } else if (isset($_POST["aggiungiCasaDiscografica"])) {
        $nome = $_POST["nome"];
        $website = $_POST["website"];
        $dataFondazione = $_POST["dataFondazione"];

        if (empty($nome) || empty($website) || empty($dataFondazione)) {
            exit("ERRORE: aggiungiCasaDiscografica: Dati mancanti!");
        }

        $queryInsert = $conn->prepare("INSERT INTO caseDiscografiche (nome, website, dataFondazione) VALUES (?, ?, ?)");
        $queryInsert->bind_param("sss", $nome, $website, $dataFondazione);
        $queryInsert->execute();

        header("Location: .");

    } else if (isset($_POST["apriCasaDiscografica"])) {
        $casaDiscograficaId = $_POST["casaDiscograficaId"];

        if (empty($casaDiscograficaId)) {
            exit("ERRORE: apriCasaDiscografica: Dati mancanti!");
        }

        $queryArtista = $conn->prepare("SELECT * FROM artisti WHERE casaDiscograficaId = ?");
        $queryArtista->bind_param("i", $casaDiscograficaId);
        $queryArtista->execute();
        $datiArtisti = $queryArtista->get_result();


        // Artisti_canzoni è una tabella di relazione tra artisti e canzoni poichè un artista può avere più canzoni e una canzone può avere più artisti using datiArtisti
        $queryArtistiCanzoni = $conn->prepare("SELECT * FROM artisti_canzoni WHERE idArtista IN (SELECT id FROM artisti WHERE casaDiscograficaId = ?)");
        $queryArtistiCanzoni->bind_param("i", $casaDiscograficaId);
        $queryArtistiCanzoni->execute();
        $datiArtistiCanzoni = $queryArtistiCanzoni->get_result();


    } else if (isset($_POST["eliminaArtista"])) {
        $id = $_POST["id"];

        if (empty($id)) {
            exit("ERRORE: eliminaArtista: Dati mancanti!");
        }

        // Delete all artisti_canzoni
        $queryDeleteArtistiCanzoni = $conn->prepare("DELETE FROM artisti_canzoni WHERE idArtista = ?");
        $queryDeleteArtistiCanzoni->bind_param("i", $id);
        $queryDeleteArtistiCanzoni->execute();


        $queryDelete = $conn->prepare("DELETE FROM artisti WHERE id = ?");
        $queryDelete->bind_param("i", $id);
        $queryDelete->execute();

        header("Location: .");

    } else if (isset($_POST["aggiungiArtista"])) {
        $nome = $_POST["nome"];
        $cognome = $_POST["cognome"];
        $nomeArte = $_POST["nomeArte"];
        $biografia = $_POST["biografia"];
        $casaDiscograficaId = $_POST["casaDiscograficaId"];

        if (empty($nome) || empty($cognome) || empty($nomeArte) || empty($biografia) || empty($casaDiscograficaId)) {
            exit("ERRORE: aggiungiArtista: Dati mancanti!");
        }

        $queryInsert = $conn->prepare("INSERT INTO artisti (nome, cognome, nomeArte, biografia, casaDiscograficaId) VALUES (?, ?, ?, ?, ?)");
        $queryInsert->bind_param("ssssi", $nome, $cognome, $nomeArte, $biografia, $casaDiscograficaId);
        $queryInsert->execute();

        header("Location: .");

    } else if (isset($_POST["modificaArtista"])) {
        $id = $_POST["id"];

        if (empty($id)) {
            exit("ERRORE: modificaArtista: Dati mancanti!");
        }

        $queryArtista = $conn->prepare("SELECT * FROM artisti WHERE id = ?");
        $queryArtista->bind_param("i", $id);
        $queryArtista->execute();
        $datiArtista = $queryArtista->get_result();
        $artista = mysqli_fetch_assoc($datiArtista);

        // All casa discografiche
        $queryCaseDiscografiche = $conn->prepare("SELECT * FROM caseDiscografiche");
        $queryCaseDiscografiche->execute();
        $datiCaseDiscografiche = $queryCaseDiscografiche->get_result();


        echo <<<HTML
            <dialog class="modal" id="modificaArtistaModal">
                <div class="modal-box">
                    <h3 class="font-bold text-lg">Modifica riga $id</h3>
                    <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                        <input type="hidden" name="editModalArtista"/>
                        <input type="hidden" name="id" value="$id"/>

                        <label class="input input-bordered flex items-center gap-2">
                            <input type="text" name="nome" class="grow" required placeholder="Nome" value="{$artista['nome']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <input type="text" name="cognome" class="grow" required placeholder="Cognome" value="{$artista['cognome']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <input type="text" name="nomeArte" class="grow" required placeholder="Nome d'arte" value="{$artista['nomeArte']}" />
                        </label>
                        <label class="textarea textarea-bordered flex items-center gap-2">
                            <textarea name="biografia" class="grow" required placeholder="Biografia">{$artista['biografia']}</textarea>
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <select name="casaDiscograficaId" class="grow" required>
                                <option value="" disabled>Seleziona una casa discografica</option>
            HTML;

        if (mysqli_num_rows($datiCaseDiscografiche) > 0) {
            while ($riga = mysqli_fetch_assoc($datiCaseDiscografiche)) {
                $id = $riga["id"];
                $nome = $riga["nome"];
                echo "<option value='$id' " . ($id == $artista["casaDiscograficaId"] ? "selected" : "") . ">$nome</option>";
            }
        }

        echo <<<HTML
                            </select>
                        </label>
                        <button class="btn btn-primary" type="submit">Modifica</button>
                        <a href="." class="link link-error text-center">Annulla</a>
                    </form>
                </div>
            </dialog>
            <script>
                // On document ready
                document.addEventListener("DOMContentLoaded", function () {
                    modificaArtistaModal.showModal();
                });
            </script>
        HTML;

    } else if (isset($_POST["editModalArtista"])) {
        $id = $_POST["id"];
        $nome = $_POST["nome"];
        $cognome = $_POST["cognome"];
        $nomeArte = $_POST["nomeArte"];
        $biografia = $_POST["biografia"];
        $casaDiscograficaId = $_POST["casaDiscograficaId"];

        if (empty($nome) || empty($cognome) || empty($nomeArte) || empty($biografia) || empty($casaDiscograficaId)) {
            exit("ERRORE: editModalArtista: Dati mancanti!");
        }

        $queryUpdate = $conn->prepare("UPDATE artisti SET nome = ?, cognome = ?, nomeArte = ?, biografia = ?, casaDiscograficaId = ? WHERE id = ?");
        $queryUpdate->bind_param("ssssii", $nome, $cognome, $nomeArte, $biografia, $casaDiscograficaId, $id);
        $queryUpdate->execute();

        header("Location: .");

    } else if (isset($_POST["apriArtista"])) {
        $artistaId = $_POST["id"];

        if (empty($artistaId)) {
            exit("ERRORE: apriArtista: Dati mancanti!");
        }

        $queryArtista = $conn->prepare("SELECT * FROM artisti WHERE id = ? LIMIT 1");
        $queryArtista->bind_param("i", $artistaId);
        $queryArtista->execute();
        $datiArtista = $queryArtista->get_result();
        $artista = mysqli_fetch_assoc($datiArtista);

        $queryCanzoni = $conn->prepare("SELECT * FROM canzoni WHERE id IN (SELECT idCanzone FROM artisti_canzoni WHERE idArtista = ?)");
        $queryCanzoni->bind_param("i", $artistaId);
        $queryCanzoni->execute();
        $datiCanzoniPerArtista = $queryCanzoni->get_result();


    } else if (isset($_POST["eliminaCanzone"])) {
        $id = $_POST["id"];

        if (empty($id)) {
            exit("ERRORE: eliminaCanzone: Dati mancanti!");
        }

        $queryDelete = $conn->prepare("DELETE FROM artisti_canzoni WHERE idCanzone = ?");
        $queryDelete->bind_param("i", $id);
        $queryDelete->execute();

        $queryDeleteCanzone = $conn->prepare("DELETE FROM canzoni WHERE id = ?");
        $queryDeleteCanzone->bind_param("i", $id);
        $queryDeleteCanzone->execute();


        header("Location: .");

    } else if (isset($_POST["aggiungiCanzone"])) {
        $nome = $_POST["nome"];
        $durata = $_POST["durata"];
        $artistaId = $_POST["artistaId"];
        $casaDiscograficaId = $_POST["casaDiscograficaId"];

        if (empty($nome) || empty($durata) || empty($artistaId) || empty($casaDiscograficaId)) {
            exit("ERRORE: aggiungiCanzone: Dati mancanti!");
        }

        $queryInsert = $conn->prepare("INSERT INTO canzoni (nome, durataMinuti, casaDiscograficaId) VALUES (?, ?, ?)");
        $queryInsert->bind_param("sis", $nome, $durata, $casaDiscograficaId);
        $queryInsert->execute();

        $idCanzone = $conn->insert_id;

        $queryInsertArtistaCanzone = $conn->prepare("INSERT INTO artisti_canzoni (idArtista, idCanzone) VALUES (?, ?)");
        $queryInsertArtistaCanzone->bind_param("ii", $artistaId, $idCanzone);
        $queryInsertArtistaCanzone->execute();

        header("Location: .");
    } else if (isset($_POST["modificaCanzone"])) {
        $id = $_POST["id"];

        if (empty($id)) {
            exit("ERRORE: modificaCanzone: Dati mancanti!");
        }

        $queryCanzone = $conn->prepare("SELECT * FROM artisti_canzoni WHERE idCanzone = ?");
        $queryCanzone->bind_param("i", $id);
        $queryCanzone->execute();
        $datiCanzone = $queryCanzone->get_result();
        $canzone = mysqli_fetch_assoc($datiCanzone);

        $queryArtista = $conn->prepare("SELECT * FROM artisti WHERE id = ?");
        $queryArtista->bind_param("i", $canzone["idArtista"]);
        $queryArtista->execute();
        $datiArtista = $queryArtista->get_result();
        $artista = mysqli_fetch_assoc($datiArtista);

        $queryCanzone = $conn->prepare("SELECT * FROM canzoni WHERE id = ?");
        $queryCanzone->bind_param("i", $canzone["idCanzone"]);
        $queryCanzone->execute();
        $datiCanzone = $queryCanzone->get_result();
        $canzone = mysqli_fetch_assoc($datiCanzone);

        echo <<<HTML
            <dialog class="modal" id="modificaCanzoneModal">
                <div class="modal-box">
                    <h3 class="font-bold text-lg">Modifica riga $id</h3>
                    <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                        <input type="hidden" name="editModalCanzone"/>
                        <input type="hidden" name="id" value="$id"/>
                        <input type="hidden" name="casaDiscograficaId" value="{$canzone['casaDiscograficaId']}"/>

                        <label class="input input-bordered flex items-center gap-2">
                            <input type="text" name="nome" class="grow" required placeholder="Nome" value="{$canzone['nome']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <input type="number" name="durata" class="grow" required placeholder="Durata" value="{$canzone['durataMinuti']}" />
                        </label>
                        <label class="input input-bordered flex items-center gap-2">
                            <select name="artistaId" class="grow" required>
                                <option value="" disabled>Seleziona un artista</option>
                                <option value="{$artista['id']}" selected>{$artista["nome"]} {$artista["cognome"]}</option>
                            </select>
                        </label>
                        <button class="btn btn-primary" type="submit">Modifica</button>
                        <a href="." class="link link-error text-center">Annulla</a>
                    </form>
                </div>
            </dialog>
            <script>
                // On document ready
                document.addEventListener("DOMContentLoaded", function () {
                    modificaCanzoneModal.showModal();
                });
            </script>
        HTML;


    } else if (isset($_POST["editModalCanzone"])) {
        $id = $_POST["id"];
        $nome = $_POST["nome"];
        $durata = $_POST["durata"];
        $artistaId = $_POST["artistaId"];

        if (empty($nome) || empty($durata) || empty($artistaId)) {
            exit("ERRORE: editModalCanzone: Dati mancanti!");
        }

        $queryUpdate = $conn->prepare("UPDATE canzoni SET nome = ?, durataMinuti = ? WHERE id = ?");
        $queryUpdate->bind_param("ssi", $nome, $durata, $id);
        $queryUpdate->execute();

        $queryUpdateArtistaCanzone = $conn->prepare("UPDATE artisti_canzoni SET idArtista = ? WHERE idCanzone = ?");
        $queryUpdateArtistaCanzone->bind_param("ii", $artistaId, $id);
        $queryUpdateArtistaCanzone->execute();

        header("Location: .");
    } else {
        exit("Azione non valida!");
    }
}
?>


<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Settima esercitazione</title>
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
    <!-- Open the modal using ID.showModal() method -->
    <dialog id="aggiungiCasaModal" class="modal">
        <div class="modal-box">
            <h3 class="font-bold text-lg">Aggiungi casa discografica</h3>
            <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                <input type="hidden" name="aggiungiCasaDiscografica" />
                <label class="input input-bordered flex items-center gap-2">
                    <input type="text" name="nome" class="grow" required placeholder="Nome" />
                </label>
                <label class="input input-bordered flex items-center gap-2">
                    <input type="url" name="website" class="grow" required placeholder="Website" />
                </label>
                <label class="input input-bordered flex items-center gap-2">
                    <input type="date" name="dataFondazione" class="grow" required placeholder="Data Fondazione" />
                </label>
                <button class="btn btn-primary" type="submit">Aggiungi</button>
            </form>
        </div>
        <form method="dialog" class="modal-backdrop">
            <button>close</button>
        </form>
    </dialog>

    <?php if (isset($datiArtisti) || isset($datiArtistiCanzoni)): ?>
        <dialog id="aggiungiArtistaModal" class="modal">
            <div class="modal-box">
                <h3 class="font-bold text-lg">Aggiungi artista</h3>
                <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                    <input type="hidden" name="aggiungiArtista" />
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="nome" class="grow" required placeholder="Nome" />
                    </label>
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="cognome" class="grow" required placeholder="Cognome" />
                    </label>
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="nomeArte" class="grow" required placeholder="Nome d'arte" />
                    </label>
                    <label class="textarea textarea-bordered flex items-center gap-2">
                        <textarea name="biografia" class="grow" required placeholder="Biografia"></textarea>
                    </label>
                    <!-- Casa discografica -->
                    <label class="input input-bordered flex items-center gap-2">
                        <select name="casaDiscograficaId" class="grow" required>
                            <option value="" disabled selected>Seleziona una casa discografica</option>
                            <?php
                            if (mysqli_num_rows($datiCaseDiscografiche) > 0) {
                                while ($riga = mysqli_fetch_assoc($datiCaseDiscografiche)) {
                                    $id = $riga["id"];
                                    $nome = $riga["nome"];
                                    echo "<option value='$id'>$nome</option>";
                                }
                            }
                            ?>
                        </select>
                    </label>


                    <button class="btn btn-primary" type="submit">Aggiungi</button>
                </form>
            </div>
            <form method="dialog" class="modal-backdrop">
                <button>close</button>
            </form>
        </dialog>
    <?php endif; ?>

    <?php if (isset($datiArtistiCanzoni)): ?>
        <dialog id="aggiungiCanzoneModal" class="modal">
            <div class="modal-box">
                <h3 class="font-bold text-lg">Aggiungi canzone</h3>
                <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                    <input type="hidden" name="aggiungiCanzone" />
                    <input type="hidden" name="casaDiscograficaId" value="<?php echo $casaDiscograficaId; ?>" />
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="nome" class="grow" required placeholder="Nome canzone" />
                    </label>
                    <!-- Durata -->
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="number" name="durata" class="grow" required placeholder="Durata" />
                    </label>

                    <!-- Artista -->
                    <label class="input input-bordered flex items-center gap-2">
                        <select name="artistaId" class="grow" required>
                            <option value="" disabled selected>Seleziona un artista</option>
                            <?php
                            if (mysqli_num_rows($datiArtisti) > 0) {
                                while ($riga = mysqli_fetch_assoc($datiArtisti)) {
                                    $id = $riga["id"];
                                    $nome = $riga["nome"];
                                    $cognome = $riga["cognome"];
                                    echo "<option value='$id'>$nome $cognome</option>";
                                }
                            }
                            ?>
                        </select>
                    </label>
                    <button class="btn btn-primary" type="submit">Aggiungi</button>
                </form>
            </div>
            <form method="dialog" class="modal-backdrop">
                <button>close</button>
            </form>
        </dialog>
    <?php endif; ?>

    <?php if (isset($datiCanzoniPerArtista)): ?>
        <dialog id="aggiungiCanzoneModal2" class="modal">
            <div class="modal-box">
                <h3 class="font-bold text-lg">Aggiungi canzone</h3>
                <form class="flex flex-col gap-y-2 py-4" action="." method="post">
                    <input type="hidden" name="aggiungiCanzone" />
                    <input type="hidden" name="casaDiscograficaId" value="<?php echo $casaDiscograficaId; ?>" />
                    <input type="hidden" name="artistaId" value="<?php echo $artistaId; ?>" />
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="nome" class="grow" required placeholder="Nome canzone" />
                    </label>
                    <!-- Durata -->
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="number" name="durata" class="grow" required placeholder="Durata" />
                    </label>

                    <!-- Artista -->
                    <label class="input input-bordered flex items-center gap-2">
                        <input type="text" name="artista" class="grow" required placeholder="Artista"
                            value="<?php echo $artista["nome"] . " " . $artista["cognome"]; ?>" disabled />
                    </label>
                    <button class="btn btn-primary" type="submit">Aggiungi</button>
                </form>
            </div>
            <form method="dialog" class="modal-backdrop">
                <button>close</button>
            </form>
        </dialog>
    <?php endif; ?>

    <div class="hero min-h-screen bg-base-200">
        <div class="hero-content flex-col">
            <div class="flex flex-col items-center justify-center">
                <h1 class="text-5xl font-bold my-4">Settima esercitazione</h1>
                <p class="text-lg">Gestione di canzoni, artisti e case discografiche</p>
            </div>
            <?php if (!isset($datiArtisti) && !isset($datiArtistiCanzoni) && !isset($datiCanzoniPerArtista)): ?>
                <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                    <div class="card-body">
                        <div class="flex flex-row justify-between items-center">
                            <h2 class="card-title">Gestione case discografiche</h2>
                            <button class="btn btn-primary" onclick="aggiungiCasaModal.showModal()">Inserisci</button>
                        </div>

                        <div class="overflow-x-auto">
                            <table class="table">
                                <!-- head -->
                                <thead>
                                    <tr>
                                        <th>ID</th>
                                        <th>Nome</th>
                                        <th>Sito Web</th>
                                        <th>Fondata il</th>
                                        <th>Azioni</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    if (mysqli_num_rows($datiCaseDiscografiche) > 0) {
                                        while ($riga = mysqli_fetch_assoc($datiCaseDiscografiche)) {
                                            $id = $riga["id"];
                                            $nome = $riga["nome"];
                                            $website = $riga["website"];
                                            $dataFondazione = $riga["dataFondazione"];
                                            echo <<<HTML
                                                <tr class="hover">
                                                    <td>$id</td>
                                                    <td>$nome</td>
                                                    <td>$website</td>
                                                    <td>$dataFondazione</td>
                                                    <td class="flex flex-row gap-x-2">
                                                        <form action="." method="post">
                                                            <input type="hidden" name="casaDiscograficaId" value="$id"/>
                                                            <button class="btn btn-accent btn-sm" name="apriCasaDiscografica">Apri</button>
                                                        </form>

                                                        <form action="." method="post">
                                                            <input type="hidden" name="casaDiscograficaId" value="$id"/>
                                                            <button class="btn btn-primary btn-sm" name="modificaCasaDiscografica">Modifica</button>
                                                        </form>
                                                        <form action="." method="post">
                                                            <input type="hidden" name="casaDiscograficaId" value="$id"/>
                                                            <button class="btn btn-error btn-sm" name="eliminaCasaDiscografica">Elimina</button>
                                                        </form>
                                                    </td>
                                                </tr>
                                                HTML;
                                        }
                                    } else {
                                        echo "<tr><td colspan='5'>Nessun dato presente</td></tr>";
                                    }
                                    ?>
                                </tbody>
                            </table>
                        </div>
                    </div>

                </div>
            <?php elseif (isset($datiArtisti) || isset($datiArtistiCanzoni)): ?>
                <div class="text-sm breadcrumbs">
                    <ul>
                        <li><a href=".">Case discografiche</a></li>
                        <li><?php echo "<b>" . $casaDiscografica["nome"] . "</b>"; ?></li>
                    </ul>
                </div>
                <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                    <div class="card-body">
                        <div class="flex flex-row justify-between items-center">
                            <h2 class="card-title">Gestione artisti</h2>
                            <button class="btn btn-primary" onclick="aggiungiArtistaModal.showModal()">Inserisci</button>
                        </div>

                        <div class="overflow-x-auto">
                            <table class="table">
                                <!-- head -->
                                <thead>
                                    <tr>
                                        <th>ID</th>
                                        <th>Nome</th>
                                        <th>Cognome</th>
                                        <th>Nome d'arte</th>
                                        <th>Biografia</th>
                                        <th>Inserito il</th>
                                        <th>Azioni</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    $datiArtisti->data_seek(0);
                                    if (isset($datiArtisti) && $datiArtisti->num_rows > 0) {
                                        while ($riga = $datiArtisti->fetch_assoc()) {
                                            $id = $riga["id"];
                                            $nome = $riga["nome"];
                                            $cognome = $riga["cognome"];
                                            $nomeArte = $riga["nomeArte"];
                                            $biografia = $riga["biografia"];
                                            $dataInserimento = $riga["dataInserimento"];
                                            $casaDiscograficaId = $riga["casaDiscograficaId"];

                                            echo <<<HTML
                                                <tr class="hover">
                                                    <td>$id</td>
                                                    <td>$nome</td>
                                                    <td>$cognome</td>
                                                    <td>$nomeArte</td>
                                                    <td>$biografia</td>
                                                    <td>$dataInserimento</td>
                                                    <td class="flex flex-row gap-x-2">
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <input type="hidden" name="casaDiscograficaId" value="$casaDiscograficaId"/>

                                                            <button class="btn btn-accent btn-sm" name="apriArtista">Apri</button>
                                                        </form>
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <input type="hidden" name="casaDiscograficaId" value="$casaDiscograficaId"/>
                                                            <button class="btn btn-primary btn-sm" name="modificaArtista">Modifica</button>
                                                        </form>
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <button class="btn btn-error btn-sm" name="eliminaArtista">Elimina</button>
                                                        </form>
                                                    </td>
                                                    
                                                </tr>
                                            HTML;
                                        }
                                    } else {
                                        echo "<tr><td colspan='5'>Nessun dato presente</td></tr>";
                                    }
                                    ?>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
                <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                    <div class="card-body">
                        <div class="flex flex-row justify-between items-center">
                            <h2 class="card-title
                        ">Gestione canzoni</h2>
                            <button class="btn btn-primary" onclick="aggiungiCanzoneModal.showModal()">Inserisci</button>
                        </div>

                        <div class="overflow-x-auto">
                            <table class="table">
                                <!-- head -->
                                <thead>
                                    <tr>
                                        <th>ID</th>
                                        <th>Nome</th>
                                        <th>Artista</th>
                                        <th>Durata</th>
                                        <th>Pubblicata il</th>
                                        <th>Azioni</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    if (isset($datiArtistiCanzoni) && $datiArtistiCanzoni->num_rows > 0) {
                                        while ($riga = $datiArtistiCanzoni->fetch_assoc()) {
                                            $id = $riga["id"];
                                            $idArtista = $riga["idArtista"];
                                            $idCanzone = $riga["idCanzone"];

                                            $queryCanzone = $conn->prepare("SELECT * FROM canzoni WHERE id = ?");
                                            $queryCanzone->bind_param("i", $idCanzone);
                                            $queryCanzone->execute();
                                            $datiCanzone = $queryCanzone->get_result();
                                            $canzone = mysqli_fetch_assoc($datiCanzone);

                                            $queryArtista = $conn->prepare("SELECT * FROM artisti WHERE id = ?");
                                            $queryArtista->bind_param("i", $idArtista);
                                            $queryArtista->execute();
                                            $datiArtista = $queryArtista->get_result();
                                            $artista = mysqli_fetch_assoc($datiArtista);


                                            $casaDiscograficaId = $artista["casaDiscograficaId"];

                                            echo <<<HTML
                                                <tr class="hover">
                                                    <td>$id</td>
                                                    <td>{$canzone["nome"]}</td>
                                                    <td>{$artista["nome"]} {$artista["cognome"]}</td>
                                                    <td>{$canzone["durataMinuti"]}</td>
                                                    <td>{$canzone["dataPubblicazione"]}</td>
                                                    <td class="flex flex-row gap-x-2">
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <input type="hidden" name="artistaId" value="$idArtista"/>
                                                            <input type="hidden" name="casaDiscograficaId" value="$casaDiscograficaId"/>

                                                            <button class="btn btn-primary btn-sm" name="modificaCanzone">Modifica</button>
                                                        </form>
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <button class="btn btn-error btn-sm" name="eliminaCanzone">Elimina</button>
                                                        </form>
                                                    </td>
                                                </tr>
                                                HTML;
                                        }
                                    } else {
                                        echo "<tr><td colspan='4'>Nessun dato presente</td></tr>";
                                    }
                                    ?>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
            <?php elseif (isset($datiCanzoniPerArtista)): ?>
                <div class="text-sm breadcrumbs">
                    <ul>
                        <li><a href=".">Case discografiche</a></li>
                        <li><a href="#"><?php echo $casaDiscografica["nome"]; ?></a></li>
                        <li><a href=".">Artisti</a></li>
                        <li><?php echo "<b>" . $artista["nome"] . " " . $artista["cognome"] . "</b>"; ?></li>
                    </ul>
                </div>
                <div class="card shrink-0 w-full max-w-2xl shadow-2xl bg-base-100">
                    <div class="card-body">
                        <div class="flex flex-row justify-between items-center">
                            <h2 class="card-title">Gestione canzoni artista</h2>
                            <button class="btn btn-primary" onclick="aggiungiCanzoneModal2.showModal()">Inserisci</button>
                        </div>

                        <div class="overflow-x-auto">
                            <table class="table">
                                <!-- head -->
                                <thead>
                                    <tr>
                                        <th>ID</th>
                                        <th>Nome</th>
                                        <th>Artista</th>
                                        <th>Durata</th>
                                        <th>Pubblicata il</th>
                                        <th>Azioni</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    if (isset($datiCanzoniPerArtista) && $datiCanzoniPerArtista->num_rows > 0) {
                                        while ($riga = $datiCanzoniPerArtista->fetch_assoc()) {
                                            $id = $riga["id"];
                                            $nomeCanzone = $riga["nome"];
                                            $durata = $riga["durataMinuti"];
                                            $dataPubblicazione = $riga["dataPubblicazione"];

                                            echo <<<HTML
                                                <tr class="hover">
                                                    <td>$id</td>
                                                    <td>{$nomeCanzone}</td>
                                                    <td>{$artista["nome"]} {$artista["cognome"]}</td>
                                                    <td>{$durata}</td>
                                                    <td>{$dataPubblicazione}</td>
                                                    <td class="flex flex-row gap-x-2">
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>
                                                            <input type="hidden" name="artistaId" value="$artistaId"/>

                                                            <button class="btn btn-primary btn-sm" name="modificaCanzone">Modifica</button>
                                                        </form>
                                                        <form action="." method="post">
                                                            <input type="hidden" name="id" value="$id"/>

                                                            <button class="btn btn-error btn-sm" name="eliminaCanzone">Elimina</button>
                                                        </form>
                                                    </td>
                                                </tr>
                                                HTML;
                                        }
                                    } else {
                                        echo "<tr><td colspan='4'>Nessun dato presente</td></tr>";
                                    }
                                    ?>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
            <?php endif; ?>


            <a class="font-bold" href="https://bio.matteosillitti.it" target="_blank">Matteo Sillitti 5C INF</a>

        </div>
    </div>
</body>

</html>
