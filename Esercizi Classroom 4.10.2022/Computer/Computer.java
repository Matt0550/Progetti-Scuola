public class Computer {
    String cpu, schedaMadre, dissipatore, alimentatore;
    int ram, hdd, ssd; // Es. 16(gb) di ram, 1500(gb) 1,5tb di hdd...
    double prezzo;
    
    public Computer(String cpu, String schedaMadre, String dissipatore, String alimentatore, int ram, int hdd, int ssd, double prezzo) {
        this.cpu = cpu;
        this.schedaMadre = schedaMadre;
        this.dissipatore = dissipatore;
        this.alimentatore = alimentatore;
        this.ram = ram;
        this.hdd = hdd;
        this.ssd = ssd;
        this.prezzo = prezzo;        
    }

    public void print() {
        System.out.println("--- Specifiche del computer ---");
        System.out.println("CPU: " + cpu);
        System.out.println("Scheda madre: " + schedaMadre);
        System.out.println("Dissipatore: " + dissipatore);
        System.out.println("Alimentatore: " + alimentatore);
        System.out.println("RAM: " + ram + "GB");
        // If hdd is 0, print "Nessun HDD"
        System.out.println("HDD: " + (hdd == 0 ? "Nessun HDD" : hdd + "GB"));
        // If ssd is 0, print "Nessun SSD"
        System.out.println("SSD: " + (ssd == 0 ? "Nessun SSD" : ssd + "GB"));
        System.out.println("Prezzo: " + prezzo + "€");
        System.out.println("-------------------------------");
    }
    
    public void increaseRAM(int gb) {
        ram += gb;
    }

    public void increaseHDD(int gb) {
        hdd += gb;
    }

    public void increaseSSD(int gb) {
        ssd += gb;
    }
}