using System;
using System.Threading;

/*
1) Creare un programma in c# che esegua 2 thread il primo thread Scrive la lettera X e il secondo scrive la lettera Y
fare scrivere il risultato in console. Commentare il risultato
*/

class Esercizio1
{
    static void Main(string[] args)
    {
        // Creo due thread
        Thread thread1 = new Thread(new ThreadStart(ScriviX));
        Thread thread2 = new Thread(new ThreadStart(ScriviY));
        // Avvio i due thread
        thread1.Start();
        thread2.Start();
        // Eseguo un join in modo da visualizzare il risultato
        thread1.Join();
        thread2.Join();
    }

    // Creo la funzione che deve essere eseguita dal thread 1
    static void ScriviX()
    {
        Console.Write("X ");
    }

    // Creo la funzione che deve essere eseguita dal thread 2
    static void ScriviY()
    {
        Console.Write("Y ");
    }
}