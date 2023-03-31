import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * Implementare una GUI in Java che dati due valori in ingresso, base e altezza, stampi l'area del triangolo,  e il perimetro e l'area del rettangolo.
 */

/**
 * GUI
 */

 
public class GUI {
    
    public GUI() {
        // Creo la finestra
        JFrame frame = new JFrame("Calcolatrice");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.setResizable(false);
        frame.setLayout(new GridLayout(6, 1));
        
        // Creo i campi di testo
        JTextField base = new JTextField();
        JTextField altezza = new JTextField();
        JTextField areaTriangolo = new JTextField();
        JTextField perimetroRettangolo = new JTextField();
        JTextField areaRettangolo = new JTextField();

        // Disabilito le textbox
        areaTriangolo.setEditable(false);
        perimetroRettangolo.setEditable(false);
        areaRettangolo.setEditable(false);

        // Creo i label
        JLabel baseLabel = new JLabel("Base");
        JLabel altezzaLabel = new JLabel("Altezza");
        JLabel areaTriangoloLabel = new JLabel("Area Triangolo");
        JLabel perimetroRettangoloLabel = new JLabel("Perimetro Rettangolo");
        JLabel areaRettangoloLabel = new JLabel("Area Rettangolo");

        // Creo i bottoni
        JButton calcola = new JButton("Calcola");
        JButton reset = new JButton("Reset");

        // Aggiungo i componenti alla finestra
        frame.add(baseLabel);
        frame.add(base);
        frame.add(altezzaLabel);
        frame.add(altezza);
        frame.add(areaTriangoloLabel);
        frame.add(areaTriangolo);
        frame.add(perimetroRettangoloLabel);
        frame.add(perimetroRettangolo);
        frame.add(areaRettangoloLabel);
        frame.add(areaRettangolo);
        frame.add(reset);
        frame.add(calcola);

        // Aggiungo i listener
        calcola.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    double baseValue = Double.parseDouble(base.getText());
                    double altezzaValue = Double.parseDouble(altezza.getText());

                    Calcola calcola = new Calcola(baseValue, altezzaValue);

                    areaTriangolo.setText(String.valueOf(calcola.areaTriangolo()));
                    perimetroRettangolo.setText(String.valueOf(calcola.perimetroRettangolo()));
                    areaRettangolo.setText(String.valueOf(calcola.areaRettangolo()));
                } catch (Exception exception) {
                    JOptionPane.showMessageDialog(null, "Inserisci dei valori validi", "Errore", JOptionPane.ERROR_MESSAGE);
                    
                }
            }
        });

        // Aggiungo i listener
        reset.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                base.setText(null);
                altezza.setText(null);
                areaTriangolo.setText(null);
                perimetroRettangolo.setText(null);
                areaRettangolo.setText(null);                
            }
        });

        frame.setVisible(true);

    }

    

}