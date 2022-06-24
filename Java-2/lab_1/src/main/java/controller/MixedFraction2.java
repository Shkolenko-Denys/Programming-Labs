package controller;

import model.classes.MixedFraction;
import view.Calculator;

/**
 * the Command for getting the second mixed fraction from Calculator
 */
public class MixedFraction2 implements Command {

    private final Calculation theCalculation;

    public MixedFraction2(Calculation calculation) {
        this.theCalculation = calculation;
    }

    public MixedFraction execute(Calculator calculator) {
        return theCalculation.getMixedFraction2(calculator);
    }
}
