import java.util.ArrayList;
import java.util.List;

public class Parcheggio {
    private List<Veicolo> posti;

    public Parcheggio() {
        this.posti = new ArrayList<Veicolo>();
    }

    public boolean isPostoDisponibile() {
        return posti.size() < 12;
    }

    public void addVeicolo(Veicolo veicolo) {
        if (isPostoDisponibile()) {
            posti.add(veicolo);
        }
    }

    public Veicolo removeVeicolo(int posto) {
        if (posto < posti.size()) {
            return posti.remove(posto);
        } else {
            return null;
        }
    }

    public void stampaSituazione() {
        for (int i = 0; i < posti.size(); i++) {
            System.out.println("Posto " + i + ": " + posti.get(i).getInfo());
        }
    }
}
