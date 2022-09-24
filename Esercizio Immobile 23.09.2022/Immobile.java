import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Locale;

public class Immobile {
    String tipo, posizione, indirizzo;
    int numeroStanze, numeroLetti, numeroBagni;
    double costoTotale;
    
    public Immobile (String tipo, String posizione, String indirizzo, int numeroStanze, int numeroBagni, int numeroLetti, double costoTotale) {
        this.tipo = tipo;
        this.posizione = posizione;
        this.indirizzo = indirizzo;
        this.numeroStanze = numeroStanze;
        this.numeroBagni = numeroBagni;
        this.numeroLetti = numeroLetti;
        this.costoTotale = costoTotale;
    }
    
    private String formattaPrezzo(double price){
        BigDecimal priceFormat = new BigDecimal(price);
        NumberFormat format = NumberFormat.getCurrencyInstance(Locale.ITALY);
        return format.format(priceFormat);
    }
        
    public void printData() {
        System.out.println("----------------------------");
        System.out.println("Tipo di immobile: " + tipo);
        System.out.println("Posizione dell'immobile: " + posizione);
        System.out.println("Indirizzo dell'immobile: " + indirizzo);
        System.out.println("Numero di stanze: " + numeroStanze);
        System.out.println("Numero di bagni: " + numeroBagni);
        System.out.println("Numero di letti: " + numeroLetti);
        System.out.println("Costo totale dell'immobile: " + formattaPrezzo(costoTotale));
        System.out.println("----------------------------");
    }
    
    public void editType(String newType) {
        tipo = newType;
    }
    
    public void editPosition(String newPosition) {
        posizione = newPosition;
    }
    
    public void editAddress(String newAddress) {
        indirizzo = newAddress;
    }
    
    public void editNumberRooms(int newNumberRooms) {
        numeroStanze = newNumberRooms;
    }
    
    public void editNumberBathrooms(int newNumberBathrooms) {
        numeroBagni = newNumberBathrooms;
    }
    
    public void editNumberBeds(int newNumberBeds) {
        numeroLetti = newNumberBeds;
    }
    
    public void editPrice(int newPrice) {
        costoTotale = newPrice;
    }
}