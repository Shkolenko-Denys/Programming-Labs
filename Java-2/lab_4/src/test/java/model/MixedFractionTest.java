package model;

import model.classes.Fraction;
import model.classes.MixedFraction;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MixedFractionTest {

    @Test
    @DisplayName("Already reduced positive fraction")
    void reducedPositiveFraction() {
        MixedFraction mf = new MixedFraction(0, 2, 3);
        assertEquals(new MixedFraction(0, 2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Already reduced negative fraction")
    void reducedNegativeFraction() {
        MixedFraction mf = new MixedFraction(0, -2, 3);
        assertEquals(new MixedFraction(0, -2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced positive fraction")
    void reducePositiveFraction() {
        MixedFraction mf = new MixedFraction(0, 3, 2);
        assertEquals(new MixedFraction(1, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced negative fraction")
    void reduceNegativeFraction() {
        MixedFraction mf = new MixedFraction(0, -3, 2);
        assertEquals(new MixedFraction(-1, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Already reduced positive fraction with positive whole")
    void reducedPositiveFractionWithPositiveWhole() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(1, 2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Already reduced negative fraction with positive whole")
    void reducedNegativeFractionWithPositiveWhole() {
        MixedFraction mf = new MixedFraction(1, -2, 3);
        assertEquals(new MixedFraction(1, -2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Already reduced negative fraction with negative whole")
    void reducedNegativeFractionWithNegativeWhole() {
        MixedFraction mf = new MixedFraction(-1, -2, 3);
        assertEquals(new MixedFraction(-1, -2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Already reduced positive fraction with negative whole")
    void reducedPositiveFractionWithNegativeWhole() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(-1, 2, 3), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced positive fraction with positive whole")
    void reducePositiveFractionWithPositiveWhole() {
        MixedFraction mf = new MixedFraction(1, 3, 2);
        assertEquals(new MixedFraction(2, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced negative fraction with positive whole")
    void reduceNegativeFractionWithPositiveWhole() {
        MixedFraction mf = new MixedFraction(1, -3, 2);
        assertEquals(new MixedFraction(0, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced negative fraction with negative whole")
    void reduceNegativeFractionWithNegativeWhole() {
        MixedFraction mf = new MixedFraction(-1, -3, 2);
        assertEquals(new MixedFraction(-2, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Not reduced positive fraction with negative whole")
    void reducePositiveFractionWithNegativeWhole() {
        MixedFraction mf = new MixedFraction(-1, 3, 2);
        assertEquals(new MixedFraction(0, 1, 2), mf.reduce());
    }

    @Test
    @DisplayName("Set zero whole")
    void setWhole() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(0, 2, 3), mf.setWhole(0));
    }

    @Test
    @DisplayName("Set numerator without reducing")
    void setNumerator() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(1, 1, 3), mf.setNumerator(1));
    }

    @Test
    @DisplayName("Set numerator and reduce")
    void setReduceNumerator() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(2, 1, 3), mf.setNumerator(4));
    }

    @Test
    @DisplayName("Set denominator without reducing")
    void setDenominator() {
        MixedFraction mf = new MixedFraction(1, 4, 5);
        assertEquals(new MixedFraction(1, 4, 7), mf.setDenominator(7));
    }

    @Test
    @DisplayName("Set denominator and reduce")
    void setReduceDenominator() {
        MixedFraction mf = new MixedFraction(1, 4, 5);
        assertEquals(new MixedFraction(3, 0, 1), mf.setDenominator(2));
    }

    @Test
    @DisplayName("Get fraction part")
    void getFraction() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new Fraction(2, 3), mf.getFraction());
    }

    @Test
    @DisplayName("Get double with positive whole")
    void getPositiveDouble() {
        MixedFraction mf = new MixedFraction(1, 1, 3);
        double epsilon = 0.000001d;
        assertEquals(1.33, mf.getDouble(), epsilon);
    }

    @Test
    @DisplayName("Get double with negative whole")
    void getNegativeDouble() {
        MixedFraction mf = new MixedFraction(-1, 1, 3);
        double epsilon = 0.000001d;
        assertEquals(-1.33, mf.getDouble(), epsilon);
    }

    @Test
    @DisplayName("Comparing equals mixed fractions")
    void compareEqualsMixedFractions() {
        MixedFraction mf1 = new MixedFraction(-1, 1, 3);
        MixedFraction mf2 = new MixedFraction(-1, 1, 3);
        assertTrue(mf1.equals(mf2));
    }

    @Test
    @DisplayName("Comparing not equals mixed fractions")
    void compareNotEqualsFractions() {
        MixedFraction mf1 = new MixedFraction(-1, 1, 3);
        MixedFraction mf2 = new MixedFraction(1, 1, 3);
        assertFalse(mf1.equals(mf2));
    }

    @Test
    @DisplayName("Compare with other obj")
    void compareOtherObj() {
        MixedFraction mf1 = new MixedFraction(-1, 1, 3);
        double obj = -1.33;
        assertFalse(mf1.equals(obj));
    }

    @Test
    @DisplayName("To string whole and fraction")
    void toStringWholeFraction() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals("1(2/3)", mf.toString());
    }

    @Test
    @DisplayName("To string whole")
    void toStringWhole() {
        MixedFraction mf = new MixedFraction(1, 0, 1);
        assertEquals("1", mf.toString());
    }

    @Test
    @DisplayName("To string fraction")
    void toStringFraction() {
        MixedFraction mf = new MixedFraction(0, 2, 3);
        assertEquals("2/3", mf.toString());
    }

    @Test
    @DisplayName("Add integer to positive mixed fraction")
    void addIntegerToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(3, 2, 3), mf.add(2));
    }

    @Test
    @DisplayName("Add integer to negative mixed fraction")
    void addIntegerToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(0, 1, 3), mf.add(2));
    }

    @Test
    @DisplayName("Add fraction to positive mixed fraction")
    void addFractionToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(2, 1, 3), mf.add(fraction));
    }

    @Test
    @DisplayName("Add fraction to negative mixed fraction")
    void addFractionToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(-1, 0, 1), mf.add(fraction));
    }

    @Test
    @DisplayName("Add mixed fraction")
    void addMixedFraction() {
        MixedFraction mf1 = new MixedFraction(1, 2, 5);
        MixedFraction mf2 = new MixedFraction(2, 1, 5);
        assertEquals(new MixedFraction(3, 3, 5), mf1.add(mf2));
    }

    @Test
    @DisplayName("Sub integer to positive mixed fraction")
    void subIntegerToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(0, -1, 3), mf.sub(2));
    }

    @Test
    @DisplayName("Sub integer to negative mixed fraction")
    void subIntegerToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(-3, 2, 3), mf.sub(2));
    }

    @Test
    @DisplayName("Sub fraction to positive mixed fraction")
    void subFractionToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(1, 0, 1), mf.sub(fraction));
    }

    @Test
    @DisplayName("Sub fraction to negative mixed fraction")
    void subFractionToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(-1, 0, 1), mf.add(fraction));
    }

    @Test
    @DisplayName("Sub mixed fraction")
    void subMixedFraction() {
        MixedFraction mf1 = new MixedFraction(1, 2, 5);
        MixedFraction mf2 = new MixedFraction(2, 1, 5);
        assertEquals(new MixedFraction(-1, 1, 5), mf1.sub(mf2));
    }

    @Test
    @DisplayName("Mul integer to positive mixed fraction")
    void mulIntegerToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(3, 1, 3), mf.mul(2));
    }

    @Test
    @DisplayName("Mul integer to negative mixed fraction")
    void mulIntegerToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(-3, 1, 3), mf.mul(2));
    }

    @Test
    @DisplayName("Mul fraction to positive mixed fraction")
    void mulFractionToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(1, 1, 9), mf.mul(fraction));
    }

    @Test
    @DisplayName("Mul fraction to negative mixed fraction")
    void mulFractionToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(-1, -1, 9), mf.mul(fraction));
    }

    @Test
    @DisplayName("Mul mixed fraction")
    void mulMixedFraction() {
        MixedFraction mf1 = new MixedFraction(1, 2, 5);
        MixedFraction mf2 = new MixedFraction(2, 1, 5);
        assertEquals(new MixedFraction(3, 2, 25), mf1.mul(mf2));
    }

    @Test
    @DisplayName("Div integer to positive mixed fraction")
    void divIntegerToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(0, 5, 6), mf.div(2));
    }

    @Test
    @DisplayName("Div integer to negative mixed fraction")
    void divIntegerToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(0, -5, 6), mf.div(2));
    }

    @Test
    @DisplayName("Div zero integer")
    void divZeroInteger() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Exception exception = assertThrows(IllegalArgumentException.class,
                () -> mf.div(0));
        assertTrue(exception.getMessage().contains("the denominator is zero"));
    }

    @Test
    @DisplayName("Div fraction to positive mixed fraction")
    void divFractionToPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(2, 1, 2), mf.div(fraction));
    }

    @Test
    @DisplayName("Div fraction to negative mixed fraction")
    void divFractionToNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        Fraction fraction = new Fraction(2, 3);
        assertEquals(new MixedFraction(-2, -1, 2), mf.div(fraction));
    }

    @Test
    @DisplayName("Div zero fraction")
    void divZeroFraction() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Exception exception = assertThrows(ArithmeticException.class,
                () -> mf.div(new Fraction(0, 1)));
        assertTrue(exception.getMessage().contains("division by zero"));
    }

    @Test
    @DisplayName("Div mixed fraction")
    void divMixedFraction() {
        MixedFraction mf1 = new MixedFraction(1, 2, 5);
        MixedFraction mf2 = new MixedFraction(2, 1, 5);
        assertEquals(new MixedFraction(0, 7, 11), mf1.div(mf2));
    }

    @Test
    @DisplayName("Div zero mixed fraction")
    void divZeroMixedFraction() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        Exception exception = assertThrows(ArithmeticException.class,
                () -> mf.div(new MixedFraction(0, 0, 1)));
        assertTrue(exception.getMessage().contains("division by zero"));
    }

    @Test
    @DisplayName("Find neg for positive mixed fraction")
    void negPositive() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(-1, 2, 3), mf.neg());
    }

    @Test
    @DisplayName("Find neg for negative mixed fraction")
    void negNegative() {
        MixedFraction mf = new MixedFraction(-1, 2, 3);
        assertEquals(new MixedFraction(1, 2, 3), mf.neg());
    }

    @Test
    @DisplayName("Reset the mixed fraction to zero")
    void resetToZero() {
        MixedFraction mf = new MixedFraction(1, 2, 3);
        assertEquals(new MixedFraction(0, 0, 1), mf.reset());
    }

    @Test
    @DisplayName("Get improper from positive mixed fraction")
    void getImproperFromPositive() {
        MixedFraction mf = new MixedFraction(2, 3, 5);
        assertEquals(new Fraction(13, 5), MixedFraction.getImproper(mf));
    }

    @Test
    @DisplayName("Get improper from negative mixed fraction")
    void getImproperFromNegative() {
        MixedFraction mf = new MixedFraction(-2, 3, 5);
        assertEquals(new Fraction(-13, 5), MixedFraction.getImproper(mf));
    }

    @Test
    @DisplayName("Get improper from negative improper mixed fraction")
    void getImproperFromNegativeImproper() {
        MixedFraction mf = new MixedFraction(-2, -9, 5);
        assertEquals(new Fraction(-19, 5), MixedFraction.getImproper(mf));
    }

//    @Test
//    @DisplayName("Get improper from negative improper mixed fraction [HACK]")
//    void getImproperFromNegativeImproperHack() {
//        MixedFraction mf = Mockito.mock(MixedFraction.class);
//        Mockito.when(mf.getWhole()).thenReturn(-2);
//        Mockito.when(mf.getNumerator()).thenReturn(-9);
//        Mockito.when(mf.getDenominator()).thenReturn(5);
//
//        assertEquals(new Fraction(-19, 5), MixedFraction.getImproper(mf));
//    }
}