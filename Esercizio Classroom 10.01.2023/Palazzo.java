class Palazzo {
    private int numeroPiani;
    private int metriQuadriPerAppartamento;
    private String via;
    private int numeroCivico;
    private String citta;

    public Palazzo(int numeroPiani, int metriQuadriPerAppartamento, String via, int numeroCivico, String citta) {
        this.numeroPiani = numeroPiani;
        this.metriQuadriPerAppartamento = metriQuadriPerAppartamento;
        this.via = via;
        this.numeroCivico = numeroCivico;
        this.citta = citta;
    }

    public void setNumeroPiani(int numeroPiani) {
        if (numeroPiani >= 3 && numeroPiani <= 30) {
            this.numeroPiani = numeroPiani;
        }
    }

    public void setMetriQuadriPerAppartamento(int metriQuadriPerAppartamento) {
        if (metriQuadriPerAppartamento <= 200) {
            this.metriQuadriPerAppartamento = metriQuadriPerAppartamento;
        }
    }

    public int calcolaValore() {
        return this.numeroPiani * this.metriQuadriPerAppartamento * 500; // 500 euro al metro quadro
    }

    public void stampa() {
        System.out.println("Numero di piani: " + this.numeroPiani);
        System.out.println("Metri quadri per appartamento: " + this.metriQuadriPerAppartamento);
        System.out.println("Via: " + this.via + " " + this.numeroCivico);
        System.out.println("Città: " + this.citta);
        System.out.println("Valore: " + this.calcolaValore());
    }
}