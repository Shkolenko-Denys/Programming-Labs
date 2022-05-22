package model.classes;

import model.interfaces.Gravity;

public class OptionDecorator implements Gravity {

    private final Gravity gravity;
    private final String label;
    private final int weight;

    public OptionDecorator(Gravity gravity, String label, int weight) {
        this.gravity = gravity;
        this.label = label;
        this.weight = weight;
    }

    public String getLabel() {
        return this.label + "-" + gravity.getLabel();
    }

    public int getWeight() {
        return Mediator.getWeight(this.weight + gravity.getWeight());
    }
}
