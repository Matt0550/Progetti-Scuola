/*
La famiglia Rossi ha a disposizione una somma di denaro da investire e vuole valutare su quale tipo di investimento indirizzarsi tenuto conto che: 
    Vuole differenziare l’investimento nei seguenti 3 prodotti finanziari. 
 
    —------------------------------------------------------------------------------------------------------------- 
    | Codice Prodotto |     Investimento                   |  %Reddito annuo  |  Rate Risk  |  Indice Rischio    | 
    —------------------------------------------------------------------------------------------------------------- 
    | PiA             | Piano di Investimento Assicurativo | 1.5%             | 3           |                    | 
    -------------------------------------------------------------------------------------------------------------- 
    | BTC             | BitCoin                            | 2.80%            | 7           |                    | 
    -------------------------------------------------------------------------------------------------------------- 
    | Fiv             | Fondi di Investimento              | 1.7%             | 2           |                    | 
    -------------------------------------------------------------------------------------------------------------- 
 
    Realizzare un algoritmo che permetta di: 
    1) Dare in input la somma da investire; 
    2) Dare in input l’indice di rischio che non si vuole superare (200<>600); 
    3) Distribuisca in maniera Random l’importo dato input nei tre tipi di finanziamento con un 
        minimo di 2000€ per ogni investimento; 
    4) Calcoli il rendimento annuo maturato per ogni prodotto di investimento; 
    5) Calcoli la somma dei tre rendimenti; 
    6) Calcoli l’indice del rischio per ogni prodotto finanziario così calcolato: 
        Rendimento*Rate Risk/%Rendimento annuo; 
    7) Sommi il totale degli indici di rischio 
    8) Confronti che il totale degli indici di rischio rientri nel Range 200<>600; 
    9) Il ciclo si conclude dopo che verranno visualizzate 3 ipotesi valide. 
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Main {
    // Crea una finestra con due input e un pulsante
    public static void main(String[] args) {
        JFrame frame = new JFrame("Investimenti");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);
        frame.setLayout(new FlowLayout());
        frame.setLocationRelativeTo(null);
        JLabel label1 = new JLabel("Somma da investire");
        JTextField input1 = new JTextField(10);
        JLabel label2 = new JLabel("Indice di rischio");
        JTextField input2 = new JTextField(10);
        JButton button = new JButton("Calcola");

        frame.add(label1);
        frame.add(input1);
        frame.add(label2);
        frame.add(input2);
        frame.add(button);

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int somma = Integer.parseInt(input1.getText());
                int rischio = Integer.parseInt(input2.getText());
                System.out.println("Somma da investire: " + somma);
                System.out.println("Indice di rischio: " + rischio);

                Agenzia agenzia = new Agenzia(somma, rischio);
                agenzia.calcolo(somma, rischio);
            }
        });

        frame.setVisible(true);
    }   
}