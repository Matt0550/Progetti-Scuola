/*
Creare un programma in c# che dato in ingresso (da linea di comando) un file di testo ed un certo numero di parole, ricerchi le parole cercate e ne faccia il conteggio.

esempio di chiamata (supponiamo di aver chiamato il nostro programma contaparole)


contaparole pippo.txt qui quo


voglio visualizzare quante volte compare la parola "qui" e quante la parola "quo"

Utilizzare il massimo grado di parallelismo possibile uttilizzando i thread
*/

using System;
using System.Threading;
class Esercizio
{
    // Leggo il file
    static string file = ""; // Per inserire successivamente il contenuto del file
    static void Main(string[] args)
    {
        // Controllo che ci siano almeno due argomenti
        if (args.Length < 2)
        {
            throw new ArgumentException("Devi inserire almeno due argomenti: la path del file e almeno una parola da cercare");
        }

        // Prendo gli argomenti dalla linea di comando. Il primo argomento sarà la path del file, gli altri saranno le parole da cercare
        string path = args[0];
        if (!System.IO.File.Exists(path)) // Controllo che il file esista
        {
            throw new System.IO.FileNotFoundException("Il file non esiste", path);
        } else {
            file = System.IO.File.ReadAllText(path); // Leggo il file e lo salvo in una stringa
        }

        string[] parole = new string[args.Length - 1]; // Creo un array di stringhe di dimensione pari al numero di parole da cercare
        for (int i = 1; i < args.Length; i++)
        {
            parole[i - 1] = args[i]; // Copio le parole da cercare nell'array
        }

        // Stampo le parole da cercare e il file in cui cercarle. Utilizzo la funzione string.Join per unire le parole in un'unica stringa separandole con una virgola e uno spazio
        Console.WriteLine("Ricerco le parole {0} nel file {1}", string.Join(", ", parole), path);
        // Per ogni parola creo un thread che esegue la funzione ContaParola passandogli la path del file e la parola da cercare
        Thread[] threads = new Thread[parole.Length];
        for (int i = 0; i < parole.Length; i++)
        {
            threads[i] = new Thread(ContaParola);
            threads[i].Start(parole[i].ToLower());
        }

        // Attendo che tutti i thread abbiano finito di eseguire
        for (int i = 0; i < threads.Length; i++)
        {
            threads[i].Join();
        }
        Console.WriteLine("Ricerca completata!");
    }

    static void ContaParola(object? parola) // ? per permettere di passare null come parametro
    {
        // Controllo che la parola non sia nulla
        if (parola == null)
        {
            throw new ArgumentNullException("parola", "La parola non può essere nulla");
        }

        // Divido il file in parole e le salvo in un array
        string[] parole = file.Split(' ');
        // Conto le occorrenze della parola
        int occorrenzeParola = 0; 
        for (int i = 0; i < parole.Length; i++)
        {
            // Fix non-nullable value type
            if (parole[i] == (string) parola)
            {
                occorrenzeParola++;
            }
        }
        Console.WriteLine("La parola {0} compare {1} volte", parola, occorrenzeParola);
    }
}