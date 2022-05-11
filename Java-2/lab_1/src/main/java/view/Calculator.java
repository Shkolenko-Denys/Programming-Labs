package view;

import controller.Calculation;
import model.Arithmetic;
import model.MixedFraction;
import model.Number;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.lang.reflect.*;
import java.util.Arrays;
import java.util.stream.Collectors;

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
    private JButton infoButton;

    public JFormattedTextField getWhole1TextField() {
        return whole1TextField;
    }

    public JFormattedTextField getNumerator1TextField() {
        return numerator1TextField;
    }

    public JFormattedTextField getDenominator1TextField() {
        return denominator1TextField;
    }

    public JFormattedTextField getWhole2TextField() {
        return whole2TextField;
    }

    public JFormattedTextField getNumerator2TextField() {
        return numerator2TextField;
    }

    public JFormattedTextField getDenominator2TextField() {
        return denominator2TextField;
    }

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

        Calculation calculation = new Calculation();

        resultButton.addActionListener(e -> {
            try {
                MixedFraction result = calculation.getResult(calculation.getMixedFraction1(),
                        calculation.getMixedFraction2());

                resultWholeTextField.setText(Integer.toString(result.getWhole()));
                int numerator = result.getNumerator();
                if (numerator != 0) {
                    resultNumeratorTextField.setText(Integer.toString(numerator));
                    resultDenominatorTextField.setText(Integer.toString(result.getDenominator()));
                }
            }
            catch (UndeclaredThrowableException ex) {
                JOptionPane.showMessageDialog(Calculator.this,
                        "Oops!\nError: " + ex);
            }
            catch (Exception ex) {
                JOptionPane.showMessageDialog(Calculator.this,
                        "Check your fractions carefully!\nError: " + ex);
            }
        });

        addButton.addActionListener(e ->
                calculation.setCurrentCommand("Mixed model.Fraction Addition")
        );

        subButton.addActionListener(e ->
                calculation.setCurrentCommand("Mixed model.Fraction Subtraction")
        );

        mulButton.addActionListener(e ->
                calculation.setCurrentCommand("Mixed model.Fraction Multiplication")
        );

        divButton.addActionListener(e ->
                calculation.setCurrentCommand("Mixed model.Fraction Division")
        );

        infoButton.addActionListener(e -> {
            StringBuilder message = new StringBuilder("Class "
                    + Modifier.toString(MixedFraction.class.getModifiers()) + " "
                    + MixedFraction.class.getName() + "\n");

            message.append("Fields:\n");
            for (Field field : MixedFraction.class.getDeclaredFields()) {
                if (field.isAnnotationPresent(Number.class)) {
                    message.append("// ").append(field.getAnnotation(Number.class).name())
                            .append(" -- ").append(field.getAnnotation(Number.class).definition())
                            .append("\n");
                }
                message.append(Modifier.toString(field.getModifiers()))
                        .append(" ").append(field.getType().getSimpleName())
                        .append(" ").append(field.getName()).append("\n");
            }

            message.append("\nSuperclass ").append(MixedFraction.class.getSuperclass().getSimpleName())
                    .append(" implements ")
                    .append(Arrays.stream(MixedFraction.class.getSuperclass().getInterfaces())
                            .map(Class::getSimpleName)
                            .collect(Collectors.joining(", ")));

            message.append("\nFields:\n");
            for (Field field : MixedFraction.class.getSuperclass().getDeclaredFields()) {
                if (field.isAnnotationPresent(Number.class)) {
                    message.append("// ").append(field.getAnnotation(Number.class).name())
                            .append(" -- ").append(field.getAnnotation(Number.class).definition())
                            .append("\n");
                }
                message.append(Modifier.toString(field.getModifiers()))
                        .append(" ").append(field.getType().getSimpleName())
                        .append(" ").append(field.getName()).append("\n");
            }

            message.append("\nConstructors:\n");
            for (Constructor<?> constructor : MixedFraction.class.getConstructors()) {
                message.append("- ").append(constructor.getName())
                        .append(" (").append(getConstructorParameters(constructor)).append(");\n");
            }

            message.append("\nmodel.Arithmetic Methods:\n");
            for (Method method : MixedFraction.class.getDeclaredMethods()) {
                if (method.isAnnotationPresent(Arithmetic.class)) {
                    if (Modifier.isVolatile(method.getModifiers())) {
                        continue;
                    }
                    message.append(Modifier.toString(method.getModifiers())).append(" ")
                            .append(method.getReturnType().getSimpleName()).append(" ")
                            .append(method.getName()).append(" (")
                            .append(getMethodParameters(method)).append(");\n");
                }
            }

            JOptionPane.showMessageDialog(Calculator.this, message.toString());
        });
    }

    public String getConstructorParameters(@NotNull Constructor<?> ctor) {
        return Arrays.stream(ctor.getParameters())
                .map(param -> param.getType() + " " + param.getName())
                .collect(Collectors.joining(", "));
    }

    private String getMethodParameters(@NotNull Method method) {
        return Arrays.stream(method.getParameters())
                .map(param -> param.getType() + " " + param.getName())
                .collect(Collectors.joining(", "));
    }
}
