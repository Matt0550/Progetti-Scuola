/*
Creare un programma che data in input (utilizzare il parametro args di main) una cartella e 3 parole
1) Controlli la correttezza degli input
2) esegue la lettura dei  file .txt in thread separati contando le parole
4) alla chiusura di tutti i thread (usare CountdounEvent per sincronizzare tutti i thread) calcolare il totale delle parole contate ed indicare quale parola è utilizzata più volte
5) stampare le parole a video in ordine crescente (la parola utilizzata più volte come prima)

Github: @Matt0550
Website: https://matt05.ml
Start: dotnet run pippo ciao giorgio come
*/

namespace Esercizio_5;
using System;
using System.IO;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 4)
        {
            Console.WriteLine("Parametri non trovati: <folder> <word1> <word2> <word3>");
            return;
        }

        string folder = args[0];
        // Creo un array di stringhe con le parole da cercare
        string[] words = new string[] { args[1], args[2], args[3] };

        if (!Directory.Exists(folder))
        {
            Console.WriteLine($"La cartella '{folder}' non esiste!");
            return;
        }

        // Creo un array di stringhe con i file da leggere
        string[] files = Directory.GetFiles(folder, "*.txt");

        // Verifico che ci siano dei file da leggere
        if (files.Length == 0)
        {
            Console.WriteLine($"Nessun file txt trovato nella cartella '{folder}'");
            return;
        }

        // Creo un countdown event con il numero di file da leggere 
        CountdownEvent countdown = new CountdownEvent(files.Length);

        // Creo un dizionario per salvare le parole trovate e il numero di volte che sono state trovate
        Dictionary<string, int> wordsCount = new Dictionary<string, int>();

        // Creo un array di thread
        Thread[] threads = new Thread[files.Length];

        // Ogni thread richiama una funzione in cui passa il file, le parole da cercare, il dizionario e il countdown event
        foreach (var file in files)
        {
            // ParameterizedThreadStart
            Thread thread = new Thread(new ParameterizedThreadStart(ReadFile));
            thread.Start(new object[] { file, words, wordsCount, countdown });
        }
        // Attendo che tutti i thread abbiano terminato
        countdown.Wait();

        // Stampo il numero di parole trovate
        int totalWords = wordsCount.Values.Sum();
        Console.WriteLine($"Totale parole trovate: {totalWords}");
        // Stampo le parole trovate
        foreach (var item in wordsCount.OrderBy(x => x.Key))
        {
            Console.WriteLine($"{item.Key} - {item.Value}");
        }
        // Stampo la parola più utilizzata (ordino il dizionario utilizzando come chiave il numero di volte che è stata trovata) e prendo la prima parola
        string word = wordsCount.OrderByDescending(x => x.Value).First().Key;

        Console.WriteLine($"Parola più utilizzata: {word}");
        Console.WriteLine("Premere un tasto per terminare...");
        Console.ReadLine();
    }

    static void ReadFile(object obj)
    {
        // Leggo i parametri passati al thread
        object[] parameters = (object[])obj; // Eseguo il cast dell'oggetto in un array di oggetti
        string file = (string)parameters[0]; // Eseguo il cast del primo elemento dell'array in una stringa
        string[] words = (string[])parameters[1]; // Eseguo il cast del secondo elemento dell'array in un array di stringhe
        Dictionary<string, int> wordsCount = (Dictionary<string, int>)parameters[2]; // Eseguo il cast del terzo elemento dell'array in un dizionario
        CountdownEvent countdown = (CountdownEvent)parameters[3]; // Eseguo il cast del quarto elemento dell'array in un countdown event

        // Stampo a schermo che il thred con id {Thread.CurrentThread.ManagedThreadId} è iniziato
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId} è iniziato con il file {file}");

        // Leggo il file
        string text = File.ReadAllText(file);

        // Per ogni parola da cercare
        foreach (var word in words)
        {
            // Traformo il testo in minuscolo e cerco la parola
            // Index of restituisce -1 se la parola non è stata trovata
            int index = text.ToLower().IndexOf(word.ToLower());
            // Se la parola è stata trovata
            if (index != -1)
            {
                // Se la parola è già presente nel dizionario
                if (wordsCount.ContainsKey(word))
                {
                    // Incremento il numero di volte che è stata trovata
                    wordsCount[word]++;
                }
                else
                {
                    // Aggiungo la parola al dizionario
                    wordsCount.Add(word, 1);
                }
            }

        }
        // Segnalo che il thread ha terminato
        countdown.Signal();
        // Stampo a schermo che il thred con id {Thread.CurrentThread.ManagedThreadId} ha terminato
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId} ha terminato");
    }
}