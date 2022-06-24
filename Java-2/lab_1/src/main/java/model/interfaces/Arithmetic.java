package model.interfaces;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;


@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface Arithmetic {

    /** Name of the arithmetic function */
    String name();

    /** Array of argument names */
    String[] args() default {};

    /** Full description */
    String desc();
}
