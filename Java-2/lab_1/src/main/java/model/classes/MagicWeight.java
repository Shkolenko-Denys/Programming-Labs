package model.classes;

import model.interfaces.Gravity;

public class MagicWeight extends OptionDecorator {

    public MagicWeight(Gravity gravity) {
        super(gravity, "Магічність", 2);
    }
}
