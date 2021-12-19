import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.Objects;

/**
 * Изменение размера изображения в графическом окне. В верхней панели окна
 * (JPanel) "Размер изображения"  заданы следующие компоненты: надпись (JLabel)
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
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Task16::new);
    }
}