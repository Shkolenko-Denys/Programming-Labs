/*-------------------------------------------------------------------<Header>-
 Name: ex_13.cpp
 Title: —
 Description: Вопрос для размышления: поскольку библиотека исходного C++
 содержится в глобальном пространстве имен и для старых программ на C++ это
 уже свершившийся факт, какая польза от размещения указанной библиотеки в
 пространстве имен std "задним числом"?
 -------------------------------------------------------------------</Header>-*/

/*
Поскольку пространство имен позволяет локализовать область видимости объектов,
объявленных внутри него, одно и то же имя, упомянутое в разных контекстах, больше
не вызывает конфликтов. Наибольшую пользу это нововведение принесло стандартной
библиотеке языка C++.
Раньше вся стандартная библиотека языка C++ находилась в глобальном пространстве
имен (которое, собственно говоря, было единственным). Теперь стандартная
библиотека определена внутри своего собственного пространства имен std, что
НАМНОГО УМЕНЬШАЕТ ВЕРОЯТНОСТЬ КОНФЛИКТОВ. Программист может
создавать свои собственные пространства имен и самостоятельно локализовать
имена. Это особенно важно при разработке классов или библиотек функций.
*/

/*
When C++ was originally designed, all of the identifiers in the C++ standard
library (including std::cin and std::cout) were available to be used without
the std:: prefix (they were part of the global namespace). However, this meant
that any identifier in the standard library could potentially conflict with
any name you picked for your own identifiers (also defined in the global namespace).
Code that was working might suddenly have a naming conflict when you #included a
new file from the standard library. Or worse, programs that would compile under
one version of C++ might not compile under a future version of C++, as new
identifiers introduced into the standard library could have a naming conflict
with already written code. So C++ moved all of the functionality in the standard
library into a namespace named “std” (short for standard).
*/