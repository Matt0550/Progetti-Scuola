/*
Si realizzi una applicazione java per la gestione di un magazzino secondo le
seguenti specifiche:
 Il magazzino contiene 3 tipi di merci: alimentari, casalinghi,
abbigliamento. La merce è identificata attraverso un codice univoco
progressivo;
 Viene implementata la classe base chiamata merce contenente i
seguenti attributi (numeroprogressivo, descrizione, codice fornitore,
quantità, prezzo unitario, scorta minima)
 si estenda la classe merce modellando le seguenti classi:
o alimentari (+data di scadenza, lattosio s/n, glutine s/n)
o casalinghi (+tipo (liquido, polvere, solido), )
o abbigliamento(+taglia, colore, tipo)

Si implementi una classe che modelli il magazzino sopradescritto
offrendo le seguenti operazioni di gestione utilizzando l’interfaccia
grafica:

1] immissione di un nuovo articolo;
2] estrazione dal magazzino di una merce il cui codice viene dato in
input;
3] stampa della situazione della merce sotto scorta;
4] stampa degli alimenti con data di scadenza inferiore a 5 giorni.
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class GUI {
    /*
        3 radio buttons for the type of product (alimentari, casalinghi, abbigliamento) when user clicks on one of them, show the corresponding fields for that type of product
        Default is alimentari (so when the program starts, the alimentari fields are shown)
    */
    Magazzino magazzino = new Magazzino(100);

    private JFrame frame;
    private JPanel panel;
    private JComboBox<String> type, tipoCasalinghi;
    private JLabel categoria, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima, dataScadenza, tipo, taglia, colore;
    private JTextField descrizioneField, codiceFornitoreField, quantitaField, prezzoUnitarioField, scortaMinimaField, dataScadenzaField, tagliaField, coloreField;
    private JCheckBox lattosio, glutine;
    private JButton submit, altro;

    public GUI() {
        frame = new JFrame("Magazzino");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 500);
        frame.setLayout(new BorderLayout());

        panel = new JPanel();
        panel.setLayout(new GridLayout(0, 2));

        // One combo box for each type of product
        type = new JComboBox<String>();
        type.addItem("Alimentari");
        type.addItem("Casalinghi");
        type.addItem("Abbigliamento");

        categoria = new JLabel("Categoria");
        descrizione = new JLabel("Descrizione");
        codiceFornitore = new JLabel("Codice fornitore");
        quantita = new JLabel("Quantita");
        prezzoUnitario = new JLabel("Prezzo unitario");
        scortaMinima = new JLabel("Scorta minima");
        dataScadenza = new JLabel("Data scadenza");
        tipo = new JLabel("Tipo");
        taglia = new JLabel("Taglia");
        colore = new JLabel("Colore");

        descrizioneField = new JTextField();
        codiceFornitoreField = new JTextField();
        quantitaField = new JTextField();
        prezzoUnitarioField = new JTextField();
        scortaMinimaField = new JTextField();
        dataScadenzaField = new JTextField();
        tipoCasalinghi = new JComboBox<String>();
        tipoCasalinghi.addItem("Liquido");
        tipoCasalinghi.addItem("Polvere");
        tipoCasalinghi.addItem("Solido");

        tagliaField = new JTextField();
        coloreField = new JTextField();

        lattosio = new JCheckBox("Lattosio");
        glutine = new JCheckBox("Glutine");

        submit = new JButton("Submit");
        altro = new JButton("Altro");

        panel.add(categoria);
        panel.add(type);
        panel.add(descrizione);
        panel.add(descrizioneField);
        panel.add(codiceFornitore);
        panel.add(codiceFornitoreField);
        panel.add(quantita);
        panel.add(quantitaField);
        panel.add(prezzoUnitario);
        panel.add(prezzoUnitarioField);
        panel.add(scortaMinima);
        panel.add(scortaMinimaField);
        panel.add(dataScadenza);
        panel.add(dataScadenzaField);
        panel.add(tipo);
        panel.add(tipoCasalinghi);
        panel.add(taglia);
        panel.add(tagliaField);
        panel.add(colore);
        panel.add(coloreField);
        panel.add(lattosio);
        panel.add(glutine);
        
        panel.add(altro);

        panel.add(submit);

        frame.add(panel, BorderLayout.CENTER);
        frame.setVisible(true);

        submit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    int numeroProgressivo = magazzino.getNextNumeroProgressivo();
                    String descrizione = descrizioneField.getText();
                    String codiceFornitore = codiceFornitoreField.getText();
                    int quantita = Integer.parseInt(quantitaField.getText());
                    double prezzoUnitario = Double.parseDouble(prezzoUnitarioField.getText());
                    int scortaMinima = Integer.parseInt(scortaMinimaField.getText());
                    String dataScadenza = dataScadenzaField.getText();
                    String tipo = tipoCasalinghi.getSelectedItem().toString();
                    String taglia = tagliaField.getText();
                    String colore = coloreField.getText();
                    Boolean lattosio = GUI.this.lattosio.isSelected();
                    Boolean glutine = GUI.this.glutine.isSelected();

                    if (type.getSelectedItem().equals("Alimentari")) {
                        // Check if the data is valid
                        if (dataScadenza.length() != 10 || dataScadenza.charAt(2) != '/' || dataScadenza.charAt(5) != '/') {
                            JOptionPane.showMessageDialog(frame, "La data deve essere nel formato gg/mm/aaaa", "Errore", JOptionPane.ERROR_MESSAGE);
                            return;
                        }

                        Alimentari alimentari = new Alimentari(numeroProgressivo, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima, dataScadenza, lattosio, glutine);
                        magazzino.aggiungiMerce(alimentari);

                        // Show an alert dialog with the message
                        JOptionPane.showMessageDialog(frame, "Merce aggiunta con successo", "Successo", JOptionPane.INFORMATION_MESSAGE);

                    } else if (type.getSelectedItem().equals("Casalinghi")) {
                        Casalinghi casalinghi = new Casalinghi(numeroProgressivo, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima, tipo);
                        magazzino.aggiungiMerce(casalinghi);

                        // Show an alert dialog with the message
                        JOptionPane.showMessageDialog(frame, "Merce aggiunta con successo", "Successo", JOptionPane.INFORMATION_MESSAGE);

                    } else if (type.getSelectedItem().equals("Abbigliamento")) {
                        Abbigliamento abbigliamento = new Abbigliamento(numeroProgressivo, descrizione, codiceFornitore, quantita, prezzoUnitario, scortaMinima, tipo, taglia, colore);
                        magazzino.aggiungiMerce(abbigliamento);

                        // Show an alert dialog with the message
                        JOptionPane.showMessageDialog(frame, "Merce aggiunta con successo", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    }
                } catch (Exception exception) {
                    System.out.println(exception.getMessage());
                    // Show an alert dialog with the message
                    JOptionPane.showMessageDialog(frame, "Si è verificato un errore, verifica i dati inseriti", "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        
        altro.addActionListener(new ActionListener() {
            // Open a child window with 3 buttons
            public void actionPerformed(ActionEvent e) {
                JFrame frame = new JFrame("Altro");
                frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                frame.setSize(300, 200);
                frame.setLayout(new GridLayout(0, 1));

                JButton visualizza = new JButton("Visualizza");
                JButton visualizzaInScadenza = new JButton("Visualizza prodotti in scadenza");
                JButton rimuovi = new JButton("Rimuovi");

                frame.add(visualizza);
                frame.add(visualizzaInScadenza);
                frame.add(rimuovi);

                frame.setVisible(true);

                visualizza.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        // Close the child window
                        frame.dispose();

                        // Open a new window with a table
                        JFrame frame = new JFrame("Visualizza");
                        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                        frame.setSize(1500, 500);
                        frame.setLayout(new BorderLayout());

                        String[] columnNames = {"Numero progressivo", "Descrizione", "Codice fornitore", "Quantita", "Prezzo unitario", "Scorta minima", "Data di scadenza", "Tipo", "Taglia", "Colore", "Lattosio", "Glutine"};
                        
                        ArrayList<Merce> merce = magazzino.getMagazzino();
                        Object[][] data = new Object[merce.size()][12];
                        for (int i = 0; i < merce.size(); i++) {
                            data[i][0] = merce.get(i).getNumeroProgressivo();
                            data[i][1] = merce.get(i).getDescrizione();
                            data[i][2] = merce.get(i).getCodiceFornitore();
                            data[i][3] = merce.get(i).getQuantita();
                            data[i][4] = merce.get(i).getPrezzoUnitario();
                            data[i][5] = merce.get(i).getScortaMinima();
                            
                            if (merce.get(i) instanceof Alimentari) { // Utilizzo instanceof per verificare il tipo di oggetto
                                data[i][6] = ((Alimentari) merce.get(i)).getDataDiScadenza(); // Eseguo il cast per accedere ai metodi della classe (converto l'oggetto in Alimentari) 
                                data[i][7] = "N/A"; // Tipo
                                data[i][8] = "N/A"; // Taglia
                                data[i][9] = "N/A"; // Colore
                                data[i][10] = ((Alimentari) merce.get(i)).isLattosio() ? "Si" : "No"; // Se isLattosio() è true, allora "Si", altrimenti "No"
                                data[i][11] = ((Alimentari) merce.get(i)).isGlutine() ? "Si" : "No";
                            } else if (merce.get(i) instanceof Casalinghi) {
                                data[i][6] = "N/A"; // Data di scadenza
                                data[i][7] = ((Casalinghi) merce.get(i)).getTipo();
                                data[i][8] = "N/A"; // Taglia
                                data[i][9] = "N/A"; // Colore 
                                data[i][10] = "N/A"; // Lattosio
                                data[i][11] = "N/A"; // Glutine
                            } else if (merce.get(i) instanceof Abbigliamento) {
                                data[i][6] = "N/A";
                                data[i][7] = ((Abbigliamento) merce.get(i)).getTipo();
                                data[i][8] = ((Abbigliamento) merce.get(i)).getTaglia();
                                data[i][9] = ((Abbigliamento) merce.get(i)).getColore();
                                data[i][10] = "N/A";
                                data[i][11] = "N/A";
                            }
                        }

                        JTable table = new JTable(data, columnNames);
                        JScrollPane scrollPane = new JScrollPane(table);
                        frame.add(scrollPane, BorderLayout.CENTER);

                        frame.setVisible(true);
                    }
                });

                visualizzaInScadenza.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        // Close the child window
                        frame.dispose();

                        // Open a new window with a table
                        JFrame frame = new JFrame("Visualizza prodotti in scadenza");
                        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                        frame.setSize(1500, 500);
                        frame.setLayout(new BorderLayout());

                        String[] columnNames = {"Numero progressivo", "Descrizione", "Codice fornitore", "Quantita", "Prezzo unitario", "Scorta minima", "Data di scadenza", "Tipo", "Taglia", "Colore", "Lattosio", "Glutine"};
                        
                        ArrayList<Merce> merce = magazzino.getAlimentiScadenza();
                        Object[][] data = new Object[merce.size()][12];
                        for (int i = 0; i < merce.size(); i++) {
                            if (merce.get(i) instanceof Alimentari) {
                                data[i][0] = merce.get(i).getNumeroProgressivo();
                                data[i][1] = merce.get(i).getDescrizione();
                                data[i][2] = merce.get(i).getCodiceFornitore();
                                data[i][3] = merce.get(i).getQuantita();
                                data[i][4] = merce.get(i).getPrezzoUnitario();
                                data[i][5] = merce.get(i).getScortaMinima();
                                data[i][6] = ((Alimentari) merce.get(i)).getDataDiScadenza();
                                data[i][7] = "N/A"; // Tipo
                                data[i][8] = "N/A"; // Taglia
                                data[i][9] = "N/A"; // Colore
                                data[i][10] = ((Alimentari) merce.get(i)).isLattosio() ? "Si" : "No";
                                data[i][11] = ((Alimentari) merce.get(i)).isGlutine() ? "Si" : "No";
                            }
                        }

                        JTable table = new JTable(data, columnNames);
                        JScrollPane scrollPane = new JScrollPane(table);
                        frame.add(scrollPane, BorderLayout.CENTER);

                        frame.setVisible(true);
                    }
                });

                rimuovi.addActionListener(new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        // Open a new window with a text field and a button
                        JFrame frame = new JFrame("Rimuovi");
                        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                        frame.setSize(200, 200);
                        frame.setLayout(new GridLayout(0, 1));

                        JLabel numeroProgressivo = new JLabel("Numero progressivo");
                        JTextField numeroProgressivoField = new JTextField();
                        JButton rimuovi = new JButton("Rimuovi");

                        frame.add(numeroProgressivo);
                        frame.add(numeroProgressivoField);
                        frame.add(rimuovi);

                        frame.setVisible(true);

                        rimuovi.addActionListener(new ActionListener() {
                            public void actionPerformed(ActionEvent e) {
                                try {
                                    int numeroProgressivo = Integer.parseInt(numeroProgressivoField.getText());
                                    magazzino.estraiMerce(numeroProgressivo);

                                    // Show an alert dialog with the message
                                    JOptionPane.showMessageDialog(frame, "Merce rimossa con successo", "Successo", JOptionPane.INFORMATION_MESSAGE);

                                    // Close the child window
                                    frame.dispose();

                                } catch (Exception exception) {
                                    // Show an alert dialog with the message
                                    JOptionPane.showMessageDialog(frame, "Si è verificato un errore, verifica i dati inseriti", "Errore", JOptionPane.ERROR_MESSAGE);
                                }
                            }
                        });
                    }
                });
            }
        });

        type.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (type.getSelectedItem().equals("Alimentari")) {
                    panel.remove(tipo);
                    panel.remove(tipoCasalinghi);
                    panel.remove(taglia);
                    panel.remove(tagliaField);
                    panel.remove(colore);
                    panel.remove(coloreField);
                    panel.remove(submit);
                    panel.remove(altro);

                    panel.add(dataScadenza);
                    panel.add(dataScadenzaField);
                    panel.add(lattosio);
                    panel.add(glutine);

                    panel.add(altro);
                    panel.add(submit);

                    panel.revalidate();
                    panel.repaint();
                } else if (type.getSelectedItem().equals("Casalinghi")) {
                    panel.remove(dataScadenza);
                    panel.remove(dataScadenzaField);
                    panel.remove(lattosio);
                    panel.remove(glutine);
                    panel.remove(taglia);
                    panel.remove(tagliaField);
                    panel.remove(colore);
                    panel.remove(coloreField);
                    panel.remove(altro);
                    panel.remove(submit);

                    panel.add(tipo);
                    panel.add(tipoCasalinghi);
                    panel.add(altro);

                    panel.add(submit);

                    panel.revalidate();
                    panel.repaint();
                } else if (type.getSelectedItem().equals("Abbigliamento")) {
                    panel.remove(dataScadenza);
                    panel.remove(dataScadenzaField);
                    panel.remove(lattosio);
                    panel.remove(glutine);
                    panel.remove(submit);
                    panel.remove(altro);

                    panel.add(tipo);
                    panel.add(tipoCasalinghi);
                    panel.add(taglia);
                    panel.add(tagliaField);
                    panel.add(colore);
                    panel.add(coloreField);

                    panel.add(altro);
                    panel.add(submit);

                    panel.revalidate();
                    panel.repaint();
                }
            }
        });

        // Seleziono il primo elemento della combobox
        type.setSelectedIndex(0);
    }
}