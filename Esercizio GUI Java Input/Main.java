import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main extends JFrame {
    private JTextField inputField;

    public Main() {
        setTitle("Input con GUI");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.LIGHT_GRAY);
        add(panel);

        JLabel label = new JLabel("Enter your name: ");
        panel.add(label);

        inputField = new JTextField(10);
        panel.add(inputField);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = inputField.getText();
                JOptionPane.showMessageDialog(null, "Hello " + name);
            }
        });
        panel.add(submitButton);

        setVisible(true);
    }

    public static void main(String[] args) {
        new Main();
    }
        
}