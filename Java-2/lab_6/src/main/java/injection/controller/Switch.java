package injection.controller;

import injection.model.classes.MixedFraction;
import injection.view.Calculator;

/**
 * the Invoker class
 */
public class Switch {

    private final Command MixedFraction1Command;
    private final Command MixedFraction2Command;

    public Switch(Command mf1, Command mf2) {
        this.MixedFraction1Command = mf1;
        this.MixedFraction2Command = mf2;
    }

    public MixedFraction first(Calculator calculator) {
        return MixedFraction1Command.execute(calculator);
    }

    public MixedFraction second(Calculator calculator) {
        return MixedFraction2Command.execute(calculator);
    }
}
