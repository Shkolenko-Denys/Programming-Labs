/*-------------------------------------------------------------------<Header>-
 Name: ex_10.cpp
 Title: —
 Description: Замените в следующей программе функцию show() пользовательской
 функцией вывода:
 #include <iostream>
 using namespace std;
 class planet {
 protected:
     double distance; // расстояние в милях от Солнца
     int revolve; // полный оборот в днях
 public:
     planet(double d, int r) {
         distance = d;
         revolve = r;
     }
 };
 class earth : public planet {
     double circumference; // окружность орбиты
 public:
     earth(double d, int r) : planet(d, r) {
         circumference = 2 * distance * 3.1416;
     }
     // Rewrite this so that it displays the information using an inserter
     // function.
     void show() {
         cout << "Distance from sum: " << distance << '\n';
         cout << "Days in orbit: " << revolve << '\n';
         cout << "Circumference of orbit: " << circumference << '\n';
     }
 };
 int main() {
     earth obj(93000000, 365);
     cout << obj;
     return 0;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib> // system()

using namespace std;

int main() {

    system("pause");
    return 0;
}