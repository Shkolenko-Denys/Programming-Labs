import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.Objects;

/**
 * Изменение фигуры в графическом окне.
 * В центре верхней панели (JPanel) "Вывод прямоугольника" в графическом
 * контексте рисуется (с помощью метода drawRoundRect()) прямоугольник со
 * скругленными вершинами. В нижней панели (JPanel) "Параметры прямоугольника"
 * задаются следующие компоненты: надпись (JLabel) "Цвет:", раскрывающее меню
 * (JComboBox) со значениями: "Черный" (цвет по умолчанию), "Красный",
 * "Зеленый" и "Синий", надпись (JLabel) "Ширина закругления", вращающийся
 * список (JSpinner), надпись (JLabel) "Высота закругления:", вращающийся
 * список (JSpinner) и кнопка (JButton) "Изменить прямоугольник". При наборе
 * данных во вращающихся списках, вводе данных в текстовых полях (в пикселях)
 * и при нажатии кнопки "Изменить прямоугольник" прямоугольник перерисовывается
 * заданным цветом и с заданным новыми значениями ширины и высоты закруглений.
 * Диапазон изменения вращающихся списков – от 0 до 30 с шагом 1.
 */
public class Task16 extends JFrame {

    private static String colorString = "Черный";
    private static int roundWidth = 0;
    private static int roundHeight = 0;

    static class DrawComponent extends JComponent {
        public void paintComponent(Graphics g) {
            if (Objects.equals(colorString, "Синий")) {
                g.setColor(Color.BLUE);
            } else if (Objects.equals(colorString, "Красный")) {
                g.setColor(Color.RED);
            } else if (Objects.equals(colorString, "Зеленый")) {
                g.setColor(Color.GREEN);
            } else if (Objects.equals(colorString, "Черный")) {
                g.setColor(Color.BLACK);
            }
            g.drawRoundRect(50, 50, 300, 150, roundWidth, roundHeight);
        }
    }

    public Task16() {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("Task 16");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel jPanelControl = new JPanel();
        jPanelControl.setLayout(new GridLayout(4,2));
        TitledBorder borderControl = BorderFactory.createTitledBorder("Параметры прямоугольника");
        jPanelControl.setBorder(borderControl);

        jPanelControl.add(new JLabel("Цвет:"));
        String[] colors = {"Черный", "Красный", "Зеленый", "Синий"};
        DefaultComboBoxModel<String> cbModel = new DefaultComboBoxModel<>();
        for (String color : colors) cbModel.addElement(color);
        JComboBox<String> cbColor = new JComboBox<>(cbModel);
        cbColor.setSelectedItem("Черный");
        jPanelControl.add(cbColor);

        jPanelControl.add(new JLabel("Ширина закругления:"));
        SpinnerModel numbersWidth = new SpinnerNumberModel(0, 0, 30, 1);
        JSpinner spinWidth = new JSpinner(numbersWidth);
        jPanelControl.add(spinWidth);

        jPanelControl.add(new JLabel("Высота закругления:"));
        SpinnerModel numbersHeight = new SpinnerNumberModel(0, 0, 30, 1);
        JSpinner spinHeight = new JSpinner(numbersHeight);
        jPanelControl.add(spinHeight);

        JPanel jPanelButton = new JPanel();
        JButton enterButton = new JButton("Изменить прямоугольник");
        jPanelButton.add(enterButton);

        frame.getContentPane().add(jPanelControl, BorderLayout.NORTH);
        frame.getContentPane().add(jPanelButton, BorderLayout.SOUTH);

        enterButton.addActionListener(e -> {
            roundWidth = (int)spinWidth.getValue();
            roundHeight = (int)spinHeight.getValue();
            colorString = (String)cbColor.getSelectedItem();
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
        SwingUtilities.invokeLater(Task16::new);
    }
}
