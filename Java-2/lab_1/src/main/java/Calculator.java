import javax.swing.*;
import java.awt.*;
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

    private int whole1 = 0;
    private int numerator1 = 0;
    private int denominator1 = 1;

    private int whole2 = 0;
    private int numerator2 = 0;
    private int denominator2 = 1;

    // key - name of the math command
    // value - function that will process the math command
    private final Map<String, Method> mathCommands = new HashMap<>();

    private Method currentCommand;

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

        for (Method m : MixedFraction.class.getDeclaredMethods()) {
            if (m.isAnnotationPresent(Arithmetic.class)) {
                Arithmetic command = m.getAnnotation(Arithmetic.class);
                mathCommands.put(command.name(), m);
            }
        }
        currentCommand = mathCommands.get("Addition");  // default command

        resultButton.addActionListener(e -> {
            try {
                whole1 = Integer.parseInt(whole1TextField.getText());
                numerator1 = Integer.parseInt(numerator1TextField.getText());
                denominator1 = Integer.parseInt(denominator1TextField.getText());

                whole2 = Integer.parseInt(whole2TextField.getText());
                numerator2 = Integer.parseInt(numerator2TextField.getText());
                denominator2 = Integer.parseInt(denominator2TextField.getText());

                MixedFraction mixedFraction_1 = new MixedFraction(whole1, numerator1, denominator1);
                MixedFraction mixedFraction_2 = new MixedFraction(whole2, numerator2, denominator2);

                currentCommand.invoke(mixedFraction_1, mixedFraction_2);

                resultWholeTextField.setText(Integer.toString(mixedFraction_1.getWhole()));
                int numerator = mixedFraction_1.getNumerator();
                if (numerator != 0) {
                    resultNumeratorTextField.setText(Integer.toString(numerator));
                    resultDenominatorTextField.setText(Integer.toString(mixedFraction_1.getDenominator()));
                }
            }
            catch (Exception ex) {
                JOptionPane.showMessageDialog(Calculator.this,
                        "Check your fractions carefully!\n Error: " + ex);
            }
        });

        addButton.addActionListener(e -> currentCommand = mathCommands.get("Addition"));

        subButton.addActionListener(e -> currentCommand = mathCommands.get("Subtraction"));

        mulButton.addActionListener(e -> currentCommand = mathCommands.get("Multiplication"));

        divButton.addActionListener(e -> currentCommand = mathCommands.get("Division"));
    }

    public static void main(String[] args) {
        JFrame frame = new Calculator("Fraction Calculator");
        frame.setVisible(true);
    }
}
