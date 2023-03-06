public class Moto extends Veicolo {
    private int tempi;

    public Moto(String marca, int anno, int cilindrata, int tempi) {
        super(marca, anno, cilindrata);
        this.tempi = tempi;
    }

    public int getTempi() {
        return tempi;
    }

    public void setTempi(int tempi) {
        this.tempi = tempi;
    }

    @Override
    public String getInfo() {
        return "Moto - Marca: " + getMarca() + ", Anno: " + getAnno() + ", Cilindrata: " + getCilindrata() + ", Tempi: " + tempi;
    }
}
