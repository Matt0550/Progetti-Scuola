import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    public Main() {
        setTitle("Simple GUI");
        setSize(300, 200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.LIGHT_GRAY);
        add(panel);

        JLabel label = new JLabel("Hello World!");
        panel.add(label);

        setVisible(true);
    }

    public static void main(String[] args) {
        new Main();
    }
}