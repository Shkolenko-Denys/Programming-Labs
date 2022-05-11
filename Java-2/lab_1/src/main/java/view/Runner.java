package view;

import controller.Calculation;

import javax.swing.*;

public class Runner {

    public static Calculator frame;

    public static void main(String[] args) {
        frame = new Calculator("Fraction Calculator");
        frame.setVisible(true);
    }
}
