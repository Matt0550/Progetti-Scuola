public class Aereoplano {
    private int velocitaMassima;
    private int velocitaCrociera;
    private int numeroMotori;
    private String nomeAereo;

    public Aereoplano(int velocitaMassima, int velocitaCrociera, int numeroMotori, String nomeAereo) {
        this.velocitaMassima = velocitaMassima;
        this.velocitaCrociera = velocitaCrociera;
        this.numeroMotori = numeroMotori;
        this.nomeAereo = nomeAereo;

    }

    public int getVelocitaMassima() {
        return velocitaMassima;
    }

    public int getVelocitaCrociera() {
        return velocitaCrociera;
    }

    public int getNumeroMotori() {
        return numeroMotori;
    }

    public String getNomeAereo() {
        return nomeAereo;
    }


    public void setVelocitaMassima(int val) {
        this.velocitaMassima = val;
    }

    public void setVelocitaCrociera(int val) {
        velocitaCrociera = val;
    }

    public void setNumeroMotori(int val) {
        numeroMotori = val;
    }

    public void setNomeAereo(String val) {
        this.nomeAereo = val;
    }


    public String getAllInfo() {
        return "Velocità massima:" + velocitaMassima + "\nVelocità di crociera: " + velocitaCrociera + "\nNumero di motori: " + numeroMotori + "\nNome aereo: " + nomeAereo;
    }
}
