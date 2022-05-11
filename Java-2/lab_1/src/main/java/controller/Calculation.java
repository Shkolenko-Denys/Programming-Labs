package controller;

import model.Arithmetic;
import model.MixedFraction;
import view.Runner;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

public class Calculation {

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

    public Calculation() {
        for (Method m : MixedFraction.class.getDeclaredMethods()) {
            if (m.isAnnotationPresent(Arithmetic.class)) {
                Arithmetic command = m.getAnnotation(Arithmetic.class);
                mathCommands.put(command.name(), m);
            }
        }

        currentCommand = mathCommands.get("Mixed model.Fraction Addition");  // default command
    }

    public MixedFraction getMixedFraction1() {
        whole1 = Integer.parseInt(Runner.frame.getWhole1TextField().getText());
        numerator1 = Integer.parseInt(Runner.frame.getNumerator1TextField().getText());
        denominator1 = Integer.parseInt(Runner.frame.getDenominator1TextField().getText());
        return new MixedFraction(whole1, numerator1, denominator1);
    }

    public MixedFraction getMixedFraction2() {
        whole2 = Integer.parseInt(Runner.frame.getWhole2TextField().getText());
        numerator2 = Integer.parseInt(Runner.frame.getNumerator2TextField().getText());
        denominator2 = Integer.parseInt(Runner.frame.getDenominator2TextField().getText());
        return new MixedFraction(whole2, numerator2, denominator2);
    }

    public MixedFraction getResult(MixedFraction mf1, MixedFraction mf2) throws InvocationTargetException, IllegalAccessException {
        currentCommand.invoke(mf1, mf2);
        return mf1;
    }

    public void setCurrentCommand(String command) {
        currentCommand = mathCommands.get(command);
    }
}
