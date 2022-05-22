package model;

import model.classes.Fraction;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Timeout;

import java.util.concurrent.TimeUnit;

import static org.junit.jupiter.api.Assertions.*;

class FractionTest {

    @Test
    @DisplayName("Reduce positive & positive")
    void reducePositivePositive() {
        Fraction fraction = new Fraction(3, 9);
        assertEquals(new Fraction(1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Reduce negative & positive")
    void reduceNegativePositive() {
        Fraction fraction = new Fraction(-3, 9);
        assertEquals(new Fraction(-1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Reduce positive & negative")
    void reducePositiveNegative() {
        Fraction fraction = new Fraction(3, -9);
        assertEquals(new Fraction(-1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Reduce negative & negative")
    void reduceNegativeNegative() {
        Fraction fraction = new Fraction(-3, -9);
        assertEquals(new Fraction(1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Already reduced positive & positive")
    void reducedPositivePositive() {
        Fraction fraction = new Fraction(1, 3);
        assertEquals(new Fraction(1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Already reduced negative & positive")
    void reducedNegativePositive() {
        Fraction fraction = new Fraction(-1, 3);
        assertEquals(new Fraction(-1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Already reduced positive & negative")
    void reducedPositiveNegative() {
        Fraction fraction = new Fraction(1, -3);
        assertEquals(new Fraction(-1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Already reduced negative & negative")
    void reducedNegativeNegative() {
        Fraction fraction = new Fraction(-1, -3);
        assertEquals(new Fraction(1, 3), fraction.reduce());
    }

    @Test
    @DisplayName("Reduce zero & positive")
    void reduceZeroPositive() {
        Fraction fraction = new Fraction(0, 3);
        assertEquals(new Fraction(0, 1), fraction.reduce());
    }

    @Test
    @DisplayName("Reduce zero & negative")
    void reduceZeroNegative() {
        Fraction fraction = new Fraction(0, -3);
        assertEquals(new Fraction(0, 1), fraction.reduce());
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD positive & positive")
    void gcdPositivePositive() {
        assertEquals(3, Fraction.gcd(3, 9));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD negative & positive")
    void gcdNegativePositive() {
        assertEquals(-3, Fraction.gcd(-3, 9));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD positive & negative")
    void gcdPositiveNegative() {
        assertEquals(3, Fraction.gcd(3, -9));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD negative & negative")
    void gcdNegativeNegative() {
        assertEquals(-3, Fraction.gcd(-3, -9));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD zero & positive")
    void gcdZeroPositive() {
        assertEquals(3, Fraction.gcd(0, 3));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD zero & positive")
    void gcdZeroNegative() {
        assertEquals(-3, Fraction.gcd(0, -3));
    }

    @Test
    @Timeout(value=200, unit=TimeUnit.MILLISECONDS)
    @DisplayName("GCD zero & zero")
    void gcdZeroZero() {
        assertEquals(0, Fraction.gcd(0, 0));
    }

    @Test
    @DisplayName("Set numerator without reducing")
    void setNumerator() {
        Fraction fraction = new Fraction(3, 10);
        assertEquals(new Fraction(7, 10), fraction.setNumerator(7));
    }

    @Test
    @DisplayName("Set numerator and reduce")
    void setReduceNumerator() {
        Fraction fraction = new Fraction(3, 10);
        assertEquals(new Fraction(2, 5), fraction.setNumerator(4));
    }

    @Test
    @DisplayName("Set denominator without reducing")
    void setDenominator() {
        Fraction fraction = new Fraction(3, 10);
        assertEquals(new Fraction(3, 7), fraction.setDenominator(7));
    }

    @Test
    @DisplayName("Set denominator and reduce")
    void setReduceDenominator() {
        Fraction fraction = new Fraction(3, 10);
        assertEquals(new Fraction(1, 3), fraction.setDenominator(9));
    }

    @Test
    @DisplayName("Set negative denominator")
    void setNegativeDenominator() {
        Fraction fraction = new Fraction(3, 10);
        assertEquals(new Fraction(-3, 10), fraction.setDenominator(-10));
    }

    @Test
    @DisplayName("Set zero denominator")
    void setZeroDenominator() {
        Fraction fraction = new Fraction(3, 10);
        Exception exception = assertThrows(IllegalArgumentException.class,
                () -> fraction.setDenominator(0));
        assertTrue(exception.getMessage().contains("the denominator is zero"));
    }

    @Test
    @DisplayName("Get double and check rounding")
    void getDoubleAndCheckRounding() {
        Fraction fraction = new Fraction(1, 3);
        double epsilon = 0.000001d;
        assertEquals(0.33, fraction.getDouble(), epsilon);
    }

    @Test
    @DisplayName("Comparing equals fractions")
    void compareEqualsFractions() {
        Fraction fraction1 = new Fraction(1, 3);
        Fraction fraction2 = new Fraction(1, 3);
        assertTrue(fraction1.equals(fraction2));
    }

    @Test
    @DisplayName("Comparing not equals fractions")
    void compareNotEqualsFractions() {
        Fraction fraction1 = new Fraction(1, 3);
        Fraction fraction2 = new Fraction(2, 3);
        assertFalse(fraction1.equals(fraction2));
    }

    @Test
    @DisplayName("Compare with other obj")
    void compareOtherObj() {
        Fraction fraction1 = new Fraction(1, 3);
        double obj = 0.33;
        assertFalse(fraction1.equals(obj));
    }

    @Test
    @DisplayName("To string model.classes.Fraction where denominator is 1")
    void toStringWholeFraction() {
        Fraction fraction = new Fraction(3, 1);
        assertEquals("3", fraction.toString());
    }

    @Test
    @DisplayName("To string model.classes.Fraction where denominator is not 1")
    void toStringRationalFraction() {
        Fraction fraction = new Fraction(1, 3);
        assertEquals("1/3", fraction.toString());
    }

    @Test
    @DisplayName("Add positive integer")
    void addPositiveInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(17, 7), fraction.add(2));
    }

    @Test
    @DisplayName("Add negative integer")
    void addNegativeInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(-11, 7), fraction.add(-2));
    }

    @Test
    @DisplayName("Add positive fraction")
    void addPositiveFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.add(new Fraction(2, 5));
        assertEquals(new Fraction(29, 35), fraction);
    }

    @Test
    @DisplayName("Add negative fraction")
    void addNegativeFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.add(new Fraction(-2, 5));
        assertEquals(new Fraction(1, 35), fraction);
    }

    @Test
    @DisplayName("Sub positive integer")
    void subPositiveInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(-11, 7), fraction.sub(2));
    }

    @Test
    @DisplayName("Sub negative integer")
    void subNegativeInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(17, 7), fraction.sub(-2));
    }

    @Test
    @DisplayName("Sub positive fraction")
    void subPositiveFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.sub(new Fraction(2, 5));
        assertEquals(new Fraction(1, 35), fraction);
    }

    @Test
    @DisplayName("Sub negative fraction")
    void subNegativeFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.sub(new Fraction(-2, 5));
        assertEquals(new Fraction(29, 35), fraction);
    }

    @Test
    @DisplayName("Mul positive integer")
    void mulPositiveInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(6, 7), fraction.mul(2));
    }

    @Test
    @DisplayName("Mul negative integer")
    void mulNegativeInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(-6, 7), fraction.mul(-2));
    }

    @Test
    @DisplayName("Mul positive fraction")
    void mulPositiveFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.mul(new Fraction(2, 5));
        assertEquals(new Fraction(6, 35), fraction);
    }

    @Test
    @DisplayName("Mul negative fraction")
    void mulNegativeFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.mul(new Fraction(-2, 5));
        assertEquals(new Fraction(-6, 35), fraction);
    }

    @Test
    @DisplayName("Div positive integer")
    void divPositiveInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(3, 14), fraction.div(2));
    }

    @Test
    @DisplayName("Div negative integer")
    void divNegativeInteger() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(-3, 14), fraction.div(-2));
    }

    @Test
    @DisplayName("Div zero integer")
    void divZeroInteger() {
        Fraction fraction = new Fraction(3, 7);
        Exception exception = assertThrows(IllegalArgumentException.class,
                () -> fraction.div(0));
        assertTrue(exception.getMessage().contains("the denominator is zero"));
    }

    @Test
    @DisplayName("Div positive fraction")
    void divPositiveFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.div(new Fraction(2, 5));
        assertEquals(new Fraction(15, 14), fraction);
    }

    @Test
    @DisplayName("Div negative fraction")
    void divNegativeFraction() {
        Fraction fraction = new Fraction(3, 7);
        fraction.div(new Fraction(-2, 5));
        assertEquals(new Fraction(-15, 14), fraction);
    }

    @Test
    @DisplayName("Div zero integer")
    void divZeroFraction() {
        Fraction fraction = new Fraction(3, 7);
        Exception exception = assertThrows(ArithmeticException.class,
                () -> fraction.div(new Fraction(0, 1)));
        assertTrue(exception.getMessage().contains("division by zero"));
    }

    @Test
    @DisplayName("Find neg for positive fraction")
    void negPositive() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(-3, 7), fraction.neg());
    }

    @Test
    @DisplayName("Find neg for negative fraction")
    void negNegative() {
        Fraction fraction = new Fraction(-3, 7);
        assertEquals(new Fraction(3, 7), fraction.neg());
    }

    @Test
    @DisplayName("Invert fraction where numerator is positive")
    void invertPositive() {
        Fraction fraction = new Fraction(3, 7);
        assertEquals(new Fraction(7, 3), fraction.invert());
    }

    @Test
    @DisplayName("Invert fraction where numerator is negative")
    void invertNegative() {
        Fraction fraction = new Fraction(-3, 7);
        assertEquals(new Fraction(-7, 3), fraction.invert());
    }

    @Test
    @DisplayName("Invert fraction where numerator is zero")
    void invertZero() {
        Fraction fraction = new Fraction(0, 1);
        Exception exception = assertThrows(ArithmeticException.class, fraction::invert);
        assertTrue(exception.getMessage().contains("division by zero"));
    }
}