/**
 Creare una classe "Animale" con proprietà "nome" e "numeroZampe". 
Creare due classi figlio "Cane" e "Gatto" che ereditano dalla classe "Animale". 
La classe "Cane" dovrebbe avere un metodo "abbaia" che stampa "Woof!" e la classe "Gatto" dovrebbe avere un metodo "miagola" che stampa "Meow!". Inoltre è presente la classe Uccello con il rispettivo metodo "cinguetta".
Le classi hanno un metodo stampa() che stampa il valore degli attributi.
Creare istanze di "Cane" e "Gatto" e utilizzare i loro metodi per verificare che funzionino correttamente.
 */
public class Main {
    public static void main(String[] args) {
        Cane cane = new Cane("Fido", 4);
        cane.abbaia();
        cane.stampa();
        Gatto gatto = new Gatto("Garfield", 4);
        gatto.miagola();
        gatto.stampa();
        Uccello uccello = new Uccello("Pippo", 2);
        uccello.cinguetta();
        cane.stampa();

    }
}