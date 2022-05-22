package controller;

import model.classes.MixedFraction;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import view.Calculator;

import static org.junit.jupiter.api.Assertions.*;

class CalculationTest {

    @Test
    @DisplayName("Get Mixed Fraction 1 with no args")
    void getMixedFraction1withNoArgs() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("");
        Mockito.when(calc.getNumerator1Text()).thenReturn("");
        Mockito.when(calc.getDenominator1Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with whole")
    void getMixedFraction1withWhole() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("2");
        Mockito.when(calc.getNumerator1Text()).thenReturn("");
        Mockito.when(calc.getDenominator1Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(2, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with numerator")
    void getMixedFraction1withNumerator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("");
        Mockito.when(calc.getNumerator1Text()).thenReturn("5");
        Mockito.when(calc.getDenominator1Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(5, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with denominator")
    void getMixedFraction1withDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("");
        Mockito.when(calc.getNumerator1Text()).thenReturn("");
        Mockito.when(calc.getDenominator1Text()).thenReturn("4");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with whole and numerator")
    void getMixedFraction1withWholeNumerator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("2");
        Mockito.when(calc.getNumerator1Text()).thenReturn("3");
        Mockito.when(calc.getDenominator1Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(5, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with whole and denominator")
    void getMixedFraction1withWholeDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("2");
        Mockito.when(calc.getNumerator1Text()).thenReturn("");
        Mockito.when(calc.getDenominator1Text()).thenReturn("3");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(2, 0, 1),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 1 with numerator and denominator")
    void getMixedFraction1withNumeratorDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole1Text()).thenReturn("");
        Mockito.when(calc.getNumerator1Text()).thenReturn("2");
        Mockito.when(calc.getDenominator1Text()).thenReturn("3");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 2, 3),
                calculation.getMixedFraction1(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with no args")
    void getMixedFraction2withNoArgs() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("");
        Mockito.when(calc.getNumerator2Text()).thenReturn("");
        Mockito.when(calc.getDenominator2Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with whole")
    void getMixedFraction2withWhole() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("2");
        Mockito.when(calc.getNumerator2Text()).thenReturn("");
        Mockito.when(calc.getDenominator2Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(2, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with numerator")
    void getMixedFraction2withNumerator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("");
        Mockito.when(calc.getNumerator2Text()).thenReturn("5");
        Mockito.when(calc.getDenominator2Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(5, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with denominator")
    void getMixedFraction2withDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("");
        Mockito.when(calc.getNumerator2Text()).thenReturn("");
        Mockito.when(calc.getDenominator2Text()).thenReturn("4");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with whole and numerator")
    void getMixedFraction2withWholeNumerator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("2");
        Mockito.when(calc.getNumerator2Text()).thenReturn("3");
        Mockito.when(calc.getDenominator2Text()).thenReturn("");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(5, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with whole and denominator")
    void getMixedFraction2withWholeDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("2");
        Mockito.when(calc.getNumerator2Text()).thenReturn("");
        Mockito.when(calc.getDenominator2Text()).thenReturn("3");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(2, 0, 1),
                calculation.getMixedFraction2(calc));
    }

    @Test
    @DisplayName("Get Mixed Fraction 2 with numerator and denominator")
    void getMixedFraction2withNumeratorDenominator() {
        Calculator calc = Mockito.mock(Calculator.class);
        Mockito.when(calc.getWhole2Text()).thenReturn("");
        Mockito.when(calc.getNumerator2Text()).thenReturn("2");
        Mockito.when(calc.getDenominator2Text()).thenReturn("3");

        Calculation calculation = Calculation.getInstance();
        assertEquals(new MixedFraction(0, 2, 3),
                calculation.getMixedFraction2(calc));
    }
}