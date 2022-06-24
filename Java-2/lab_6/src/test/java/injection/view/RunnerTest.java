package injection.view;

import injection.Config;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.jupiter.api.Assertions.*;

class RunnerTest {

    @Test
    public void AnnotationConfigCalculationExist() {
        ApplicationContext javaConfigContext = new AnnotationConfigApplicationContext(Config.class);
        Calculator calculator = javaConfigContext.getBean(Calculator.class);
        assertNotNull(calculator.getCalculation());
    }

    @Test
    public void XmlConfigCalculationExist() {
        ApplicationContext xmlConfigContext =
                new ClassPathXmlApplicationContext("injection.xml");
        Calculator calculator = xmlConfigContext.getBean(Calculator.class);
        assertNotNull(calculator.getCalculation());
    }
}