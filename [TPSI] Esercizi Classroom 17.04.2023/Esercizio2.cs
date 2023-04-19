using System;
using System.Threading;

/*
2) Creare un programma in c# con 2 thread il primo riempie un vettore con 100 numeri a caso il secondo riempie la seconda parte del vettore con altri numeri a caso.
alla fine effettuare la somma  
*/

class Esercizio2
{
    // Creo un'array da 100 elementi
    static int[] array = new int[100];

    // Creo l'oggetto random per generare numeri casuali
    static Random random = new Random();

    static void Main(string[] args)
    {

        // Creo due thread
        Thread thread1 = new Thread(new ThreadStart(Riempi1));
        Thread thread2 = new Thread(new ThreadStart(Riempi2));
        // Avvio i due thread
        thread1.Start();
        thread2.Start();
        // Eseguo un join in modo da visualizzare il risultato
        thread1.Join();
        thread2.Join();

        // Eseguo la somma
        Somma();
    }

    // Creo la funzione che deve essere eseguita dal thread 1
    static void Riempi1()
    {
        for (int i = 0; i < 50; i++) {
            array[i] = random.Next(0, 100);
        }
    }

    // Creo la funzione che deve essere eseguita dal thread 2
    static void Riempi2()
    {
        for (int i = 50; i < array.Length; i++) {
            array[i] = random.Next(0, 100);
        }
    }

    static void Somma() {
        int sum = 0;

        for (int i = 0; i < array.Length; i++) {
            sum += array[i];
        }

        Console.WriteLine("La somma di tutti gli elementi dell'array è: " + sum);
    }
}