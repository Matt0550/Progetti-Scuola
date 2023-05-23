/*
1. Implementare un programma GUI che dato un numero in ingresso, fornisce due numeri in uscita : il quadrato e la radice. I calcoli devono essere comandati da un solo pulsante.
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Esercizio 1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Cosa deve fare quando l'utente chiude la finestra
        frame.setSize(300, 300); // Impostazione delle dimensioni della finestra

        JTextField input = new JTextField(); // Creazione del campo di input
        JLabel output = new JLabel(); // Creazione del campo di output
        JButton button = new JButton("Calcola"); // Creazione del pulsante

        JPanel panel = new JPanel(); // Creazione del pannello
        panel.setLayout(new GridLayout(3, 1)); // Impostazione del layout del pannello
        panel.add(input); // Aggiunta del campo di input al pannello
        panel.add(output); // Aggiunta del campo di output al pannello
        panel.add(button); // Aggiunta del pulsante al pannello

        button.addActionListener(new ActionListener() { // Quando viene premuto il pulsante
            public void actionPerformed(ActionEvent e) {
                try {
                    int n = Integer.parseInt(input.getText()); // Lettura del numero inserito
                    output.setText("Quadrato: " + n * n + " Radice: " + Math.sqrt(n)); // Calcolo e stampa del quadrato e della radice
                } catch (NumberFormatException ex) {
                    output.setText("Inserire un numero intero"); // Stampo un messaggio di errore se il numero inserito non è un intero
                }
            }
        });

        frame.add(panel); // Aggiunta del pannello alla finestra
        frame.setVisible(true); // Visualizzazione della finestra
        
    }



}