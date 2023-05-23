/*
2. Implementare un programma GUI che dato un numero, collocato in un JTextField e dotato di due pulsanti Incrementa e Decrementa, permetta l'incremento o il decremento di 1 di quel numero. 
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Esercizio 2");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Impostazione di default per quando si chiude la finestra
        frame.setSize(300, 300); // Impostazione delle dimensioni della finestra

        JTextField input = new JTextField(); // Creazione del campo di input
        JLabel output = new JLabel(); // Creazione del campo di output

        JButton increment = new JButton("Incrementa"); // Creazione del pulsante per incrementare il numero
        JButton decrement = new JButton("Decrementa"); // Creazione del pulsante per decrementare il numero

        JPanel panel = new JPanel(); // Creazione del pannello
        panel.setLayout(new GridLayout(4, 1)); // Impostazione del layout del pannello

        panel.add(input); // Aggiunta del campo di input al pannello
        panel.add(output); // Aggiunta del campo di output al pannello
        panel.add(increment); // Aggiunta del pulsante di incremento al pannello
        panel.add(decrement); // Aggiunta del pulsante di decremento al pannello

        increment.addActionListener(new ActionListener() { // Quando viene premuto il pulsante di incremento
            public void actionPerformed(ActionEvent e) {
                try {
                    int n = Integer.parseInt(input.getText()); // Lettura del numero inserito
                    output.setText("Numero: " + (n + 1)); // Incremento del numero e stampa
                    input.setText(n + 1 + ""); // Incremento del numero nel campo di input (conversione in stringa
                } catch (NumberFormatException ex) {
                    output.setText("Inserire un numero intero"); // Stampa di un messaggio di errore
                }
            }
        });

        decrement.addActionListener(new ActionListener() { // Quando viene premuto il pulsante di decremento
            public void actionPerformed(ActionEvent e) {
                try {
                    int n = Integer.parseInt(input.getText()); // Lettura del numero inserito
                    output.setText("Numero: " + (n - 1)); // Decremento del numero e stampa
                    input.setText(n - 1 + ""); // Decremento del numero nel campo di input (conversione in stringa
                } catch (NumberFormatException ex) {
                    output.setText("Inserire un numero intero"); // Stampa di un messaggio di errore
                }
            }
        });

        frame.add(panel); // Aggiunta del pannello alla finestra
        frame.setVisible(true); // Visualizzazione della finestra
    }
}