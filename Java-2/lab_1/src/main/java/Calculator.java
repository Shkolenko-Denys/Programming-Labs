import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.VolatileImage;
import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
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
                System.out.println(command.name());
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

        addButton.addActionListener(e ->
                currentCommand = mathCommands.get("Mixed Fraction Addition")
        );

        subButton.addActionListener(e ->
                currentCommand = mathCommands.get("Mixed Fraction Subtraction")
        );

        mulButton.addActionListener(e ->
                currentCommand = mathCommands.get("Mixed Fraction Multiplication")
        );

        divButton.addActionListener(e ->
                currentCommand = mathCommands.get("Mixed Fraction Division")
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

            message.append("\nArithmetic Methods:\n");
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

    public static void main(String[] args) {
        JFrame frame = new Calculator("Fraction Calculator");
        frame.setVisible(true);
    }
}
