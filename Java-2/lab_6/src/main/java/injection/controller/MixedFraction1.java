package injection.controller;

import injection.model.classes.MixedFraction;
import injection.view.Calculator;

/**
 * the Command for getting the first mixed fraction from Calculator
 */
public class MixedFraction1 implements Command {

    private final Calculation theCalculation;

    public MixedFraction1(Calculation calculation) {
        this.theCalculation = calculation;
    }

    public MixedFraction execute(Calculator calculator) {
        return theCalculation.getMixedFraction1(calculator);
    }
}
