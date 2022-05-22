package model.handlers;

import model.interfaces.IntegerNumber;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class IntegerNumberInvocationHandler implements InvocationHandler {

    private final IntegerNumber integerNumber;

    public IntegerNumberInvocationHandler(IntegerNumber integerNumber) {
        this.integerNumber = integerNumber;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if (method.getName().startsWith("get")) {
            return method.invoke(integerNumber, args);
        }
        throw new IllegalAccessException("Not allowed");
    }
}
