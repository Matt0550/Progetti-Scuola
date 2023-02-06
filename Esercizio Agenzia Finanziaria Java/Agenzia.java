public class Agenzia { 
    private int sommaDaInvestire;
    private int indiceDiRischio;

    public Agenzia(int sommaDaInvestire, int indiceDiRischio) {
        this.sommaDaInvestire = sommaDaInvestire;
        this.indiceDiRischio = indiceDiRischio;
    }


    
    public int calcolo(int sommaDaInvestire, int indiceDiRischio) {
        if (indiceDiRischio >= 200 && indiceDiRischio <= 600) {
            if (sommaDaInvestire >= 6000) {
                // Distribuisco in maniera Random l’importo dato input nei tre tipi di finanziamento con un minimo di 2000€ per ogni investimento
                int sommaPiA = (int) (Math.random() * (sommaDaInvestire - 6000) + 2000);
                int sommaBtc = (int) (Math.random() * (sommaDaInvestire - 6000) + 2000);
                int sommaFiv = (int) (Math.random() * (sommaDaInvestire - 6000) + 2000);

                // Calcolo il rendimento annuo maturato per ogni prodotto di investimento
                double rendimentoPiA = sommaPiA * 1.5 / 100;
                double rendimentoBtc = sommaBtc * 2.8 / 100;
                double rendimentoFiv = sommaFiv * 1.7 / 100;

                // Calcolo la somma totale dei rendimenti
                double sommaRendimenti = rendimentoPiA + rendimentoBtc + rendimentoFiv;

                // Calcolo l'indice di rischio per ogni prodotto di investimento
                double indiceRischioPiA = sommaPiA * 1.5 % sommaRendimenti;
                double indiceRischioBtc = sommaBtc * 2.8 % sommaRendimenti;
                double indiceRischioFiv = sommaFiv * 1.7 % sommaRendimenti;

                // Calcolo la somma totale degli indici di rischio
                double sommaIndiciRischio = indiceRischioPiA + indiceRischioBtc + indiceRischioFiv;

                System.out.println("Somma indici di rischio: " + sommaIndiciRischio);

                // Controllo se l'indice di rischio è compreso tra 200 e 600
                if (sommaIndiciRischio >= 200 && sommaIndiciRischio <= 600) {
                    System.out.println("Somma PiA: " + sommaPiA);
                    System.out.println("Somma Btc: " + sommaBtc);
                    System.out.println("Somma Fiv: " + sommaFiv);
                    System.out.println("Rendimento PiA: " + rendimentoPiA);
                    System.out.println("Rendimento Btc: " + rendimentoBtc);
                    System.out.println("Rendimento Fiv: " + rendimentoFiv);
                    return 0;
                } else {
                    return -3;
                }
            } else {
                return -2;
            }
            
        } else {
            return -1;
        }
    }
}
