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
#include <cassert>

void my_terminate() {
    std::cerr << " my_terminate handler called\n";
    // abort();
    exit(EXIT_FAILURE);
}

void my_unexpected() {
    std::cerr << " my_unexpected called\n";
}

void my_function() throw() {
    throw 100; // called unexpected()
}

int main() {
    std::set_terminate(my_terminate);
    std::set_unexpected(my_unexpected);
    
    my_function();
    
    throw 'c';
    // called terminate()

    return 0;
}