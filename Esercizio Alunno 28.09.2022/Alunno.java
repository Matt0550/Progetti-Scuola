public class Alunno
{
	String nome, cognome, classe, scuola;
	int anniSvolti;
	
	public Alunno(String nome, String cognome, String classe, String scuola, int anniSvolti) {
	    this.nome = nome;
	    this.cognome = cognome;
	    this.classe = classe;
	    this.scuola = scuola;
	    this.anniSvolti = anniSvolti;
	}
	
	public int calcolaGiorniFineScuola() {
	    if(scuola == "superiori" && anniSvolti > 0 && anniSvolti <=5) {
	        int anniRimanenti = 5 - anniSvolti;
	        return anniRimanenti*200;
	    } else if (scuola == "medie" && anniSvolti > 0 && anniSvolti <=3) {
	        int anniRimanenti = 3 - anniSvolti;
	        return anniRimanenti*200;
	    } else {
	        return -1;
	    }
	    
	}
	
	public void stampa() {
	    System.out.println("Nome: " + nome);
	    System.out.println("Cognome: " + cognome);
	    System.out.println("Classe: " + classe);
	    System.out.println("Scuola: " + scuola);
	    System.out.println("Anni svolti " + anniSvolti);
	    var giorni = ((calcolaGiorniFineScuola() == -1) ? "errore" : calcolaGiorniFineScuola());
	    System.out.println("Giorni rimanenti: " + giorni);
	}
}
