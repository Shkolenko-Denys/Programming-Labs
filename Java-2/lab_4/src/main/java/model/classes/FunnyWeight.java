package model.classes;

import model.interfaces.Gravity;

public class FunnyWeight extends OptionDecorator {

    public FunnyWeight(Gravity gravity) {
        super(gravity, "Кумедність", 3);
    }
}
