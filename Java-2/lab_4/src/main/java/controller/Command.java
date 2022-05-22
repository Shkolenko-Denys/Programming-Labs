package controller;

import model.classes.MixedFraction;
import view.Calculator;

/**
 * the Command interface
 */
public interface Command {
    MixedFraction execute(Calculator calculator);
}
