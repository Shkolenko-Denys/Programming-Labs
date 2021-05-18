/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: В следующей программе сделана попытка создать простой таймер для
 измерения временных интервалов. По истечении каждого такого интервала таймер
 должен подавать звуковой сигнал. В том виде, в котором эта программа здесь
 представлена, она компилироваться не будет. Найдите и исправьте ошибку.
 // This program contains an error:
 #include <iostream>
 using namespace std;
 class CountDown {
     int incr;
     int target;
     int current;
 public:
     CountDown(int delay, int i=1) {
         target = delay;
         incr = i;
         current = 0;
     }
     bool counting () const {
         current += incr;
         if (current >= target) {
             cout << "\a";
             return false;
         }
         cout << current << " ";
         return true;
     }
 };
 int main() {
     CountDown obj(100, 2);
     while (obj.counting());
     return 0;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <ctime>

using namespace std;

void sleep(size_t seconds) { // Cross-platform sleep function
    clock_t time_end;
    time_end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < time_end);
}

class CountDown {
    int incr;
    int target;
    int current;
public:
    CountDown(int delay, int i = 1) {
        target = delay;
        incr = i;
        current = 0;
    }
    bool counting() {
        current += incr;
        if (current >= target) {
            return false;
        }
        cout << current << " \a";
        sleep(1);
        return true;
    }
};
int main() {
    CountDown obj(10);
    while (obj.counting());
    cout << "\n\n";
    return 0;
}