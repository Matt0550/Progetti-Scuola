<?php
    // Lista delle cartelle che finiscono con esercitazione
    $cartelle_esercitazione = array_filter(glob('*Esercitazione'), 'is_dir');
?>

<!DOCTYPE html>
<html lang="it" data-theme="night">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Indice esercizi Matteo Sillitti 5C INF</title>

    <link href="https://cdn.jsdelivr.net/npm/daisyui@4.6.0/dist/full.min.css" rel="stylesheet" type="text/css" />
    <script src="https://cdn.tailwindcss.com"></script>
</head>

<body>
    <div class="flex max-w-[100vw] flex-col items-center justify-start ">
        <div class="dropdown fixed z-10 dropdown-hover">
            <div tabindex="0" role="button" class="btn m-1">
              Theme
              <svg width="12px" height="12px" class="h-2 w-2 fill-current opacity-60 inline-block" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 2048 2048"><path d="M1799 349l242 241-1017 1017L7 590l242-241 775 775 775-775z"></path></svg>
            </div>
            <ul tabindex="0" class="dropdown-content z-[1] p-2 shadow-2xl bg-base-300 rounded-box w-52">
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Default" value="default"/></li>
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Retro" value="retro"/></li>
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Cyberpunk" value="cyberpunk"/></li>
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Valentine" value="valentine"/></li>
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Aqua" value="aqua"/></li>
              <li><input type="radio" name="theme-dropdown" class="theme-controller btn btn-sm btn-block btn-ghost justify-start" aria-label="Synthwave" value="synthwave"/></li>
            </ul>
          </div>
        <div class="">
            <div
                class="flex min-h-[calc(100vh-4rem)] items-center justify-center px-2 py-10 text-center">
                <div>
                    <h1
                        class="font-title text-center text-[clamp(2rem,6vw,4.2rem)] font-black leading-[1.1] [word-break:auto-phrase] [:root[dir=rtl]_&amp;]:leading-[1.35]">
                        <span
                            class="[&amp;::selection]:text-base-content brightness-150 contrast-150 [&amp;::selection]:bg-blue-700/20">Indice
                            esercizi</span> <br> <span class="inline-grid"><span
                                class="pointer-events-none col-start-1 row-start-1 bg-[linear-gradient(90deg,theme(colors.error)_0%,theme(colors.secondary)_9%,theme(colors.secondary)_42%,theme(colors.primary)_47%,theme(colors.accent)_100%)] bg-clip-text blur-xl [transform:translate3d(0,0,0)] [-webkit-text-fill-color:transparent] before:content-[attr(data-text)] [@supports(color:oklch(0_0_0))]:bg-[linear-gradient(90deg,oklch(var(--s))_4%,color-mix(in_oklch,oklch(var(--s)),oklch(var(--er)))_22%,oklch(var(--p))_45%,color-mix(in_oklch,oklch(var(--p)),oklch(var(--a)))_67%,oklch(var(--a))_100.2%)]"
                                aria-hidden="true" data-text="matteo sillitti"></span> <span
                                class="[&amp;::selection]:text-base-content relative col-start-1 row-start-1 bg-[linear-gradient(90deg,theme(colors.error)_0%,theme(colors.secondary)_9%,theme(colors.secondary)_42%,theme(colors.primary)_47%,theme(colors.accent)_100%)] bg-clip-text [-webkit-text-fill-color:transparent] [&amp;::selection]:bg-blue-700/20 [@supports(color:oklch(0_0_0))]:bg-[linear-gradient(90deg,oklch(var(--s))_4%,color-mix(in_oklch,oklch(var(--s)),oklch(var(--er)))_22%,oklch(var(--p))_45%,color-mix(in_oklch,oklch(var(--p)),oklch(var(--a)))_67%,oklch(var(--a))_100.2%)]">Matteo
                                Sillitti</span></span> <br> <span
                            class="[&amp;::selection]:text-base-content brightness-150 contrast-150 [&amp;::selection]:bg-blue-700/20">TPSIT</span>
                    </h1>
                    <div class="h-4"></div>
                    <p class="text-base-content/70 font-title py-4 font-light md:text-lg xl:text-2xl">Indice di tutti
                        gli esercizi di laboratorio di TPSIT.</p>
                    <div class="h-10"></div>
                    <div class="flex flex-wrap gap-4 justify-center">
                        <?php foreach ($cartelle_esercitazione as $cartella): ?>
                            <div class="card w-96 bg-base-300 shadow-xl">
                                <div class="card-body">
                                    <h2 class="card-title"><?php echo $cartella; ?>
                                    </h2>
                                    <div class="card-actions justify-end">
                                        <a href="<?php echo $cartella; ?>" class="btn btn-primary">Apri</a>
                                    </div>
                                </div>
                                </div>
                        <?php endforeach; ?>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>

</html>
