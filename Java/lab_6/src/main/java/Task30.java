import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.Objects;

/**
 * Изменение размера изображения в графическом окне. В верхней панели окна
 * (JPanel) "Размер изображения" заданы следующие компоненты: надпись (JLabel)
 * "Ширина:", бегунок (JSlider), надпись (JLabel) "Высота:", бегунок
 * (JSlider) и кнопка (JButton): "Вывести изображение". В нижней панели окна
 * (JPanel) окна "Вывод изображения" в компоненте (JLabel) задается произвольное
 * изображение. При установке бегунков размера изображения по ширине и высоте
 * и нажатии кнопки "Вывести изображение" в нижней панели выводится
 * масштабированное изображение с заданными размерами (в пикселях).
 * Первоначально изображение имеет «естественный» размер. Нижние и верхние
 * границы бегунков должны иметь значения 10 и 150.
 */
public class Task30 extends JFrame {

    public Task30() {
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("Task 30");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel jPanelControl = new JPanel();
        jPanelControl.setLayout(new GridLayout(4,2));
        TitledBorder borderControl = BorderFactory.createTitledBorder("Размер изображения");
        jPanelControl.setBorder(borderControl);

        jPanelControl.add(new JLabel("Ширина:"));
        BoundedRangeModel modelWidth = new DefaultBoundedRangeModel(80, 0, 10, 150);
        JSlider sliderWidth = new JSlider(modelWidth);
        sliderWidth.setPaintLabels(true);
        sliderWidth.setMajorTickSpacing(10);
        jPanelControl.add(sliderWidth);

        jPanelControl.add(new JLabel("Высота:"));
        BoundedRangeModel modelHeight = new DefaultBoundedRangeModel(80, 0, 10, 150);
        JSlider sliderHeight = new JSlider(modelHeight);
        sliderHeight.setPaintLabels(true);
        sliderHeight.setMajorTickSpacing(10);
        jPanelControl.add(sliderHeight);

        JPanel jPanelButton = new JPanel();
        JButton enterButton = new JButton("Вывести изображение");
        jPanelButton.add(enterButton);

        JPanel jPanelImage = new JPanel();
        ImageIcon icon = new ImageIcon("");
        JLabel imageLabel = new JLabel();
        imageLabel.setIcon(icon);
        jPanelImage.add(enterButton);

        frame.getContentPane().add(jPanelControl, BorderLayout.NORTH);
        frame.getContentPane().add(jPanelButton, BorderLayout.SOUTH);
        frame.getContentPane().add(jPanelImage);

        frame.setPreferredSize(new Dimension(500, 500));
        frame.setLocation(500, 100);
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Task30::new);
    }
}