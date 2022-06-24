package view;

import model.classes.FunnyWeight;
import model.classes.Memento;
import model.interfaces.Gravity;
import model.classes.MagicWeight;
import model.classes.MixedFraction;

public class Runner {

    public static Calculator frame;

    public static void main(String[] args) {
//        frame = Calculator.getInstance("Fraction Calculator");
//        frame.setVisible(true);

        Gravity mf = new MixedFraction(2, 3, 5);
        Gravity magic = new MagicWeight(mf);
        Gravity funny = new FunnyWeight(magic);

        System.out.println(funny.getLabel() + ": " + funny.getWeight() + "г");

        MixedFraction mf1 = new MixedFraction(1, 2, 3);
        Memento memento1 = mf1.save();

        System.out.println(mf1);

        mf1.add(4);
        System.out.println(mf1);

        System.out.println(mf1.restore(memento1));
    }
}
