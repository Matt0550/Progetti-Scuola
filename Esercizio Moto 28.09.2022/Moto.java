public class Moto
{
    int cilindrata;
    String marca;
    String modello;
    String colore;
    double prezzo;
    
	public Moto(int cilindrata, String marca, String modello, String colore, double prezzo) {
	    this.cilindrata = cilindrata;
	    this.marca = marca;
	    this.modello = modello;
	    this.colore = colore;
	    this.prezzo = prezzo;
	}
	
	public double toDollars(double euro) {
	    return euro*0.95523437;
	}
	
	public String getAllData() {
	    return "Marca: " + marca + "\nModello: " + modello + "\nCilindrata: " + cilindrata + "\nColore " + colore + "\nPrezzo " + prezzo + "€" + "\nPrezzo in dollari: " + toDollars(prezzo) + "$";
	}
}