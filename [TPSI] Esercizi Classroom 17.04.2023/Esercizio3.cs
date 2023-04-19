using System;
using System.Threading;

/*
3) Creare un Programma in c# che con due thread esegue un countDown da 100 a 0 e un countUp da 0 a 100
*/

class Esercizio3
{
    static int countup = -1;
    static int countdown = 101;
    static void Main(string[] args)
    {

        // Creo due thread
        Thread thread1 = new Thread(new ThreadStart(Countup));
        Thread thread2 = new Thread(new ThreadStart(Countdown));
        // Avvio i due thread
        thread1.Start();
        thread2.Start();
        // Eseguo un join in modo da visualizzare il risultato
        thread1.Join();
        thread2.Join();
    }

    // Creo la funzione che deve essere eseguita dal thread 1
    static void Countup()
    {
        for (int i = 0; i < 100; i++) {
            countup++;
            Console.WriteLine("Countup: " + countup);
        }
    }

    // Creo la funzione che deve essere eseguita dal thread 2
    static void Countdown()
    {
        for (int i = 100; i >= 0; i--) {
            countdown--;
            Console.WriteLine("Countdown: " + countdown);
        }
    }
}