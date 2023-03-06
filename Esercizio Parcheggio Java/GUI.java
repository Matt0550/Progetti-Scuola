import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI {
    private JFrame frame;
    private JPanel panel;
    private JLabel labelMarca;
    private JTextField textFieldMarca;
    private JLabel labelAnno;
    private JTextField textFieldAnno;
    private JLabel labelCilindrata;
    private JTextField textFieldCilindrata;
    private JLabel labelPorte;
    private JTextField textFieldPorte;
    private JLabel labelAlimentazione;
    private JComboBox comboBoxAlimentazione;
    private JLabel labelTempi;
    private JTextField textFieldTempi;
    private JLabel labelCapacita;
    private JTextField textFieldCapacita;
    private JButton buttonAggiungi;
    private JButton buttonEstrai;
    private JButton buttonStampa;
    private Parcheggio parcheggio;

    public GUI() {
        parcheggio = new Parcheggio();

        frame = new JFrame("Parcheggio");
        panel = new JPanel();
        panel.setLayout(new GridLayout(6, 4));

        labelMarca = new JLabel("Marca:");
        textFieldMarca = new JTextField(10);
        labelAnno = new JLabel("Anno:");
        textFieldAnno = new JTextField(4);
        labelCilindrata = new JLabel("Cilindrata:");
        textFieldCilindrata = new JTextField(5);
        labelPorte = new JLabel("Porte:");
        textFieldPorte = new JTextField(2);
        labelAlimentazione = new JLabel("Alimentazione:");
        comboBoxAlimentazione = new JComboBox(new String[]{"Benzina", "Diesel"});
        labelTempi = new JLabel("Tempi:");
        textFieldTempi = new JTextField(1);
        labelCapacita = new JLabel("Capacità:");
        textFieldCapacita = new JTextField(2);

        comboBoxAlimentazione.setEnabled(false);
        textFieldPorte.setEnabled(false);
        textFieldTempi.setEnabled(false);
        textFieldCapacita.setEnabled(false);

        JComboBox comboBoxTipoVeicolo = new JComboBox(new String[]{"Auto", "Moto", "Furgone"});
        panel.add(new JLabel("Tipo di veicolo:"));
        panel.add(comboBoxTipoVeicolo);

        panel.add(labelMarca);
        panel.add(textFieldMarca);
        panel.add(labelAnno);
        panel.add(textFieldAnno);
        panel.add(labelCilindrata);
        panel.add(textFieldCilindrata);
        panel.add(labelPorte);
        panel.add(textFieldPorte);
        panel.add(labelAlimentazione);
        panel.add(comboBoxAlimentazione);
        panel.add(labelTempi);
        panel.add(textFieldTempi);
        panel.add(labelCapacita);
        panel.add(textFieldCapacita);
        panel.add(new JLabel(""));
        buttonAggiungi = new JButton("Aggiungi");
        buttonEstrai = new JButton("Estrai");
        buttonStampa = new JButton("Stampa situazione");

        panel.add(buttonAggiungi);
        panel.add(buttonEstrai);
        panel.add(buttonStampa);

        comboBoxTipoVeicolo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {            String tipoVeicolo = (String) comboBoxTipoVeicolo.getSelectedItem();
                switch (tipoVeicolo) {
                    case "Auto":
                        textFieldPorte.setEnabled(true);
                        comboBoxAlimentazione.setEnabled(true);
                        textFieldTempi.setEnabled(false);
                        textFieldCapacita.setEnabled(false);
                        break;
                    case "Moto":
                        textFieldTempi.setEnabled(true);
                        comboBoxAlimentazione.setEnabled(false);
                        textFieldPorte.setEnabled(false);
                        textFieldCapacita.setEnabled(false);
                        break;
                    case "Furgone":
                        textFieldCapacita.setEnabled(true);
                        comboBoxAlimentazione.setEnabled(false);
                        textFieldPorte.setEnabled(false);
                        textFieldTempi.setEnabled(false);
                        break;
                }
            }
        });
    
        buttonAggiungi.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tipoVeicolo = (String) comboBoxTipoVeicolo.getSelectedItem();
                switch (tipoVeicolo) {
                    case "Auto":
                        Auto auto = new Auto(textFieldMarca.getText(), Integer.parseInt(textFieldAnno.getText()),
                                Integer.parseInt(textFieldCilindrata.getText()), Integer.parseInt(textFieldPorte.getText()),
                                (String) comboBoxAlimentazione.getSelectedItem());
                        parcheggio.addVeicolo(auto);
                        break;
                    case "Moto":
                        Moto moto = new Moto(textFieldMarca.getText(), Integer.parseInt(textFieldAnno.getText()),
                                Integer.parseInt(textFieldCilindrata.getText()), Integer.parseInt(textFieldTempi.getText()));
                        parcheggio.addVeicolo(moto);
                        break;
                    case "Furgone":
                        Furgone furgone = new Furgone(textFieldMarca.getText(), Integer.parseInt(textFieldAnno.getText()),
                                Integer.parseInt(textFieldCilindrata.getText()), Integer.parseInt(textFieldCapacita.getText()));
                        parcheggio.addVeicolo(furgone);
                        break;
                }
                JOptionPane.showMessageDialog(null, "Veicolo aggiunto con successo!");
            }
        });
    
        buttonEstrai.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String input = JOptionPane.showInputDialog("Inserisci il numero del posto:");
                int numeroPosto = Integer.parseInt(input);
                Veicolo veicolo = parcheggio.removeVeicolo(numeroPosto);
                if (veicolo != null) {
                    JOptionPane.showMessageDialog(null, "Veicolo estratto con successo!");
                } else {
                    JOptionPane.showMessageDialog(null, "Il posto è vuoto!");
                }
            }
        });
    
        buttonStampa.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, parcheggio.toString());
                
            }
        });
    
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}