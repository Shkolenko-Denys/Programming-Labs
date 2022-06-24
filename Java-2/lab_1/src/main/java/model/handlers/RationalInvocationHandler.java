package model.handlers;

import model.interfaces.Rational;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class RationalInvocationHandler implements InvocationHandler {

    private final Rational rational;

    public RationalInvocationHandler(Rational rational) {
        this.rational = rational;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if (method.getName().startsWith("get")) {
            return method.invoke(rational, args);
        }
        throw new IllegalAccessException("Not allowed");
    }
}
