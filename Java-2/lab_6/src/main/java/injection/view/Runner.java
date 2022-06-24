package injection.view;

import injection.Config;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Runner {

    public static Calculator frame;

    public static void main(String[] args) {
        ApplicationContext javaConfigContext = new AnnotationConfigApplicationContext(Config.class);
        frame = javaConfigContext.getBean(Calculator.class);
        frame.setVisible(true);
    }
}
