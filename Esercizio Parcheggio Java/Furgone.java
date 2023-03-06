public class Furgone extends Veicolo {
    private int capacita;

    public Furgone(String marca, int anno, int cilindrata, int capacita) {
        super(marca, anno, cilindrata);
        this.capacita = capacita;
    }

    public int getCapacita() {
        return capacita;
    }

    public void setCapacita(int capacita) {
        this.capacita = capacita;
    }

    @Override
    public String getInfo() {
        return "Furgone - Marca: " + getMarca() + ", Anno: " + getAnno() + ", Cilindrata: " + getCilindrata() + ", Capacita': " + capacita;
    }
}