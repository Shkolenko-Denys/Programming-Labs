/*-------------------------------------------------------------------<Header>-
 Name: ex_11.cpp
 Title: —
 Description: Просмотрите документацию на ваш компилятор. Проверьте,
 поддерживает ли он функции terminate() и unexpected(). Как правило, эти
 функции можно конфигурировать так, чтобы из них вы могли вызвать любую
 необходимую вам функцию. Если в случае с вашим компилятором это так,
 постарайтесь создать собственный набор функций завершения программы, который
 обеспечил бы возможность обработки необрабатываемых до этого исключительных
 ситуаций.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <exception>

void my_terminate() {
    std::cerr << " terminate handler called\n";
    abort();
}

void my_unexpected() {
    std::cerr << " unexpected called\n";
    throw 100;
}

void myfunction() throw (int) {
    throw 'a';
}

int main() {
    std::set_terminate (my_terminate);
    std::set_unexpected(my_unexpected);
    try {
        myfunction();
    }
    catch (int) {
        std::cerr << " caught int\n";
    }
    catch (double) {
        // ...
    }

    try {
        throw 'a';
    }
    catch (int) {
        std::cerr << " caught int\n";
    }
    catch (double) {
        // ...
    }

    return 0;
}