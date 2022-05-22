package controller;

import model.interfaces.Arithmetic;
import model.classes.MixedFraction;
import view.Calculator;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

public class Calculation {

    // key - name of the math command
    // value - function that will process the math command
    private final Map<String, Method> mathCommands = new HashMap<>();

    private Method currentCommand;

    private static Calculation instance = null;

    private Calculation() {
        for (Method m : MixedFraction.class.getDeclaredMethods()) {
            if (m.isAnnotationPresent(Arithmetic.class)) {
                Arithmetic command = m.getAnnotation(Arithmetic.class);
                mathCommands.put(command.name(), m);
            }
        }

        currentCommand = mathCommands.get("Mixed model.classes.Fraction Addition");  // default command
    }

    public static Calculation getInstance() {
        if (instance == null) {
            instance = new Calculation();
        }
        return instance;
    }

    public MixedFraction getMixedFraction1(Calculator calc) {
        int whole1 = 0;
        int numerator1 = 0;
        int denominator1 = 1;
        String whole1text = calc.getWhole1Text();
        String numerator1text = calc.getNumerator1Text();
        String denominator1text = calc.getDenominator1Text();

        if (whole1text != null && !whole1text.isEmpty()) {
            whole1 = Integer.parseInt(whole1text);
        }
        if (numerator1text != null && !numerator1text.isEmpty()) {
            numerator1 = Integer.parseInt(numerator1text);
        }
        if (denominator1text != null && !denominator1text.isEmpty()) {
            denominator1 = Integer.parseInt(denominator1text);
        }

        return new MixedFraction(whole1, numerator1, denominator1);
    }

    public MixedFraction getMixedFraction2(Calculator calc) {
        int whole2 = 0;
        int numerator2 = 0;
        int denominator2 = 1;
        String whole2text = calc.getWhole2Text();
        String numerator2text = calc.getNumerator2Text();
        String denominator2text = calc.getDenominator2Text();

        if (whole2text != null && !whole2text.isEmpty()) {
            whole2 = Integer.parseInt(whole2text);
        }
        if (numerator2text != null && !numerator2text.isEmpty()) {
            numerator2 = Integer.parseInt(numerator2text);
        }
        if (denominator2text != null && !denominator2text.isEmpty()) {
            denominator2 = Integer.parseInt(denominator2text);
        }

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
