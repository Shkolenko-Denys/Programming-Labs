import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.Objects;


/**
 * Вывод строки заданным шрифтом и заданного цвета в графическом окне.
 * В верхней панели (JPanel) "Управление выводом" задается  надпись (JLabel)
 * "Текст:" и текстовое поле (JTextField), надпись (JLabel) "Гарнитура:",
 * вращающийся список (JSpinner) со значениями "Times New Roman"
 * (шрифт по умолчанию), "Arial" и "Verdana",  надпись (JLabel)
 * "Цвет:" и вращающийся список  (JSpinner) со значениями "Черный"
 * (цвет по умолчанию),  "Красный", "Зеленый" и "Синий", а также кнопка
 * (JButton) "Вывести строку". В нижней панели (JPanel) "Вывод строки"
 * выводится в графическом контексте (с помощью метода drawString()) в
 * произвольном месте пустая строка. При задании текста строки в текстовом поле,
 * параметров строки во вращающихся списках верхней панели и нажатии кнопки
 * "Вывод строки" строка заданного содержимого и цвета выводится заданным
 * шрифтом в нижней панели.
 */
public class Task5 extends JFrame {

    private static String text = "";
    private static String fontString = "Times New Roman";
    private static String colorString = "Черный";
    private static final int fontSize = 28;

    static class DrawComponent extends JComponent {
        public void paintComponent(Graphics g) {
            Font f = new Font(fontString, Font.BOLD, fontSize);
            g.setFont(f);
            if (Objects.equals(colorString, "Черный")) {
                g.setColor(Color.BLACK);
            } else if (Objects.equals(colorString, "Красный")) {
                g.setColor(Color.RED);
            } else if (Objects.equals(colorString, "Зеленый")) {
                g.setColor(Color.GREEN);
            } else if (Objects.equals(colorString, "Синий")) {
                g.setColor(Color.BLUE);
            }
            g.drawString(text, 100, 100);
        }
    }

    public Task5() {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("Task 5");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel jPanelControl = new JPanel();
        jPanelControl.setLayout(new GridLayout(4,2));
        TitledBorder borderControl = BorderFactory.createTitledBorder("Управление выводом");
        jPanelControl.setBorder(borderControl);

        jPanelControl.add(new JLabel("Текст:"));
        JTextField textField = new JTextField(25);
        jPanelControl.add(textField);

        jPanelControl.add(new JLabel("Гарнитура:"));
        String[] fonts = {"Times New Roman", "Arial", "Verdana"};
        SpinnerModel font = new SpinnerListModel(fonts);
        JSpinner spinFont = new JSpinner(font);
        jPanelControl.add(spinFont);

        jPanelControl.add(new JLabel("Цвет:"));
        String[] colors = {"Черный", "Красный", "Зеленый", "Синий"};
        SpinnerModel color = new SpinnerListModel(colors);
        JSpinner spinColor = new JSpinner(color);
        jPanelControl.add(spinColor);

        JPanel jPanelButton = new JPanel();
        JButton enterButton = new JButton("Вывести строку");
        jPanelButton.add(enterButton);

        JPanel jPanelOutput = new JPanel();
        jPanelOutput.add(new JLabel(textField.getText()));
        TitledBorder borderOutput = BorderFactory.createTitledBorder("Вывод строки");
        jPanelOutput.setBorder(borderOutput);

        frame.getContentPane().add(jPanelControl, BorderLayout.NORTH);
        frame.getContentPane().add(jPanelButton, BorderLayout.SOUTH);


        enterButton.addActionListener(e -> {
            text = textField.getText();
            fontString = (String) spinFont.getValue();
            colorString = (String) spinColor.getValue();
            DrawComponent comp = new DrawComponent();
            frame.getContentPane().add(comp);
            frame.pack();
        });

        frame.setPreferredSize(new Dimension(500, 500));
        frame.setLocation(500, 100);
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Task5::new);
    }
}
