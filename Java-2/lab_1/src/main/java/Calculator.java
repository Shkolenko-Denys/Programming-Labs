import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

/**
 * Варіант 21
 * Базовий клас - дріб (чисельник, знаменник, арифметичні операції,
 * перетворення в дійсний тип). Похідний клас - ціле число з дробовою частиною.
 */
public class Calculator extends JFrame {

    private JPanel mainPanel;

    private JFormattedTextField whole1TextField;
    private JFormattedTextField numerator1TextField;
    private JFormattedTextField denominator1TextField;

    private JRadioButton addButton;
    private JRadioButton mulButton;
    private JRadioButton subButton;
    private JRadioButton divButton;

    private JFormattedTextField whole2TextField;
    private JFormattedTextField numerator2TextField;
    private JFormattedTextField denominator2TextField;

    private JButton resultButton;

    private JFormattedTextField resultWholeTextField;
    private JFormattedTextField resultNumeratorTextField;
    private JFormattedTextField resultDenominatorTextField;

    private static int whole1 = 0;
    private static int numerator1 = 0;
    private static int denominator1 = 1;

    private static int whole2 = 0;
    private static int numerator2 = 0;
    private static int denominator2 = 1;

    // key - name of the math command
    // value - function that will process the math command
    private static final Map<String, Method> mathCommands = new HashMap<>();

    enum Command {
        ADD, SUB, MUL, DIV
    }

    Command current = Command.ADD;

    public Calculator(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.setPreferredSize(new Dimension(1000, 300));
        this.setLocation(500, 100);
        this.pack();

        ButtonGroup groupOperators = new ButtonGroup();
        groupOperators.add(addButton);
        groupOperators.add(subButton);
        groupOperators.add(mulButton);
        groupOperators.add(divButton);

        resultButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    whole1 = Integer.parseInt(whole1TextField.getText());
                    numerator1 = Integer.parseInt(numerator1TextField.getText());
                    denominator1 = Integer.parseInt(denominator1TextField.getText());

                    whole2 = Integer.parseInt(whole2TextField.getText());
                    numerator2 = Integer.parseInt(numerator2TextField.getText());
                    denominator2 = Integer.parseInt(denominator2TextField.getText());

                    MixedFraction mixedFraction_1 = new MixedFraction(whole1, numerator1, denominator1);
                    MixedFraction mixedFraction_2 = new MixedFraction(whole2, numerator2, denominator2);

                    switch (current) {
                        case ADD -> mixedFraction_1.add(mixedFraction_2);
                        case SUB -> mixedFraction_1.sub(mixedFraction_2);
                        case MUL -> mixedFraction_1.mul(mixedFraction_2);
                        case DIV -> mixedFraction_1.div(mixedFraction_2);
                    }

                    resultWholeTextField.setText(Integer.toString(mixedFraction_1.getWhole()));
                    int numerator = mixedFraction_1.getNumerator();
                    if (numerator != 0) {
                        resultNumeratorTextField.setText(Integer.toString(numerator));
                        resultDenominatorTextField.setText(Integer.toString(mixedFraction_1.getDenominator()));
                    }
                }
                catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(Calculator.this,
                            "Error: " + ex);
                }
            }
        });

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current = Command.ADD;
            }
        });

        subButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current = Command.SUB;
            }
        });

        mulButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current = Command.MUL;
            }
        });

        divButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current = Command.DIV;
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new Calculator("Fraction Calculator");
        frame.setVisible(true);
    }
}
