import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;


@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface Arithmetic {

    /** Name of the arithmetic function */
    String name();

    /** Minimum number of arguments */
    int minArgs() default 1;

    /** Maximum number of arguments */
    int maxArgs() default 1;

    /** Array of argument names */
    String[] args() default {};

    /** Full description */
    String desc();
}
