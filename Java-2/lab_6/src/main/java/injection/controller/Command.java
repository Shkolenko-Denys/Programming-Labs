package injection.controller;

import injection.model.classes.MixedFraction;
import injection.view.Calculator;

/**
 * the Command interface
 */
public interface Command {
    MixedFraction execute(Calculator calculator);
}
