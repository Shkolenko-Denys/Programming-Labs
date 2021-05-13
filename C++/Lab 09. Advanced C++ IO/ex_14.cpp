/*-------------------------------------------------------------------<Header>-
 Name: ex_14.cpp
 Title: —
 Description: Это задача для размышления. Вам уже известно, что при выполнении
 вывода данные не сразу записываются на связанное с потоком физическое
 устройство, а информация временно сохраняется во внутреннем буфере. Только
 после заполнения буфера его содержимое переписывается на устройство хранения
 (например, диск). Вызов специальной функции flush() вызывает физическую запись
 информации на диск до заполнения буфера (в Unit 10 эту функцию мы не
 рассматривали). Прототип функции flush(), являющейся членом потоковых классов
 вывода имеет вид: ostream &flush();
 Вызовы функции flush() оправданы при работе в неблагоприятной обстановке
 (например, в ситуациях, когда часто случаются сбои по питанию).
 Поразмышляйте о ситуациях, в которых может оказаться полезным вызов функции
 flush().
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

void cp_sleep(int seconds) { // Cross-platform sleep function
    clock_t time_end;
    time_end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < time_end);
}

int main() {
    cout.sync_with_stdio(false);
    // std::cout now has its own separate buffer. This buffer too, when flushed, 
    // writes the characters to the device associated with stdout

    cout << "1" /*<< flush*/;

    cp_sleep(5);

    cout << "2" << endl;
    cout << "3" << endl;

     
    return 0;
}