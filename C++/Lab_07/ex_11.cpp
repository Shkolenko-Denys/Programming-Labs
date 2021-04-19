/* Задача 8.11. Иерархия классов из Задача 8.7 с классом vehicle. В программе
имеется ошибка и код не форматирован. Найдите ошибку.
Подсказка: попытайтесь провести компиляцию и изучите сообщения об ошибках.
#include <iostream>
using namespace std;
// A base class for various types of vehicles .
class vehicle
{
int num_wheels ;
int range ;
public :
vehicle (int w, int r)
{
    num_wheels = w;
    range = r;
}
void showv ()
{
cout << " Wheels : " << num_wheels << '\n'; cout << " Range : " << range << '\n';
}
};
enum motor {gas , electric , diesel };
class motorized : public vehicle
{
enum motor mtr ;
public :
motorized ( enum motor m, int w, int r) : vehicle (w, r)
{
    mtr = m;
}
void showm ()
{
    cout << " Motor : ";
    switch (mtr )
    {
        case gas : cout << "Gas \n";
        break ;
        case electric : cout << " Electric \n";
        break ;
        case diesel : cout << " Diesel \n";
        break ;
    }
}
};
class road_use : public vehicle
{
    int passengers ;
    public :
    road_use (int p, int w, int r) : vehicle (w, r)
    {
        passengers = p;
    }
    void showr ()
    {
        cout << " Passengers : " << passengers << '\n';
    }
};
enum steering { power , rack_pinion , manual };
class car : public motorized , public road_use
{
enum steering strng ;
public :
car ( enum steering s, enum motor m, int w, int r, int p) :
road_use (p, w, r), motorized (m, w, r), vehicle (w, r)
{
strng = s; }
void show () { showv (); showr (); showm (); cout << " Steering : "; switch ( strng ) {
case power : cout << " Power \n"; break ; case rack_pinion : cout << " Rack and Pinion
\n";
break ; case manual : cout << " Manual \n";
break ; } } }; int main () { car c(power , gas , 4, 500 , 5);
    c. show ();
    return 0;
}
При компиляции программы вы могли увидеть предупреждающее сообщение
(или, возможно, сообщение об ошибке), связанное с использованием инструкции
switch внутри классов саr и motorised. Почему? */

#include <iostream>

using namespace std;

// A base class for various types of vehicles.
class vehicle {
    int num_wheels;
    int range;
public:
    vehicle(int w, int r) {
        num_wheels = w;
        range = r;
    }

    void showv () {
        cout << " Wheels : " << num_wheels << "\n";
        cout << " Range : " << range << "\n";
    }
};

enum motor { gas, electric, diesel };

class motorized : virtual public vehicle {
    enum motor mtr;
public:
    motorized(int w, int r, enum motor m) : vehicle (w, r) {
        mtr = m;
    }
    void showm() {
        cout << " Motor : ";
        switch (mtr) {
            case gas:
                cout << " Gas" << "\n";
                break;
            case electric:
                cout << " Electric" << "\n";
                break;
            case diesel:
                cout << " Diesel" << "\n";
                break;
        }
    }
};

class road_use : virtual public vehicle {
    int passengers;
public:
    road_use (int w, int r, int p) : vehicle (w, r) {
        passengers = p;
    }

    void showr() {
        cout << " Passengers : " << passengers << "\n";
    }
};

enum steering { power, rack_pinion, manual };

class car : public motorized, public road_use {
    enum steering strng;
public:
    car (int w, int r, enum motor m, int p, enum steering s) :
    vehicle(w, r), motorized (w, r, m), road_use (w, r, p) {
        strng = s;
    }
    void show() {
        showv();
        showr();
        showm();
        cout << " Steering : ";
        switch (strng) {
            case power:
                cout << " Power \n";
                break;
            case rack_pinion:
                cout << " Rack and Pinion\n";
                break;
            case manual:
                cout << " Manual \n";
                break;
        }
    }
};

int main () {
    car c(4, 500, gas, 5, power);
    c.show();
    return 0;
}

// Any enumeration type can assume any value within the number of bits of its
// representation. The representation for a type with an explicit underlying type
// (enum class always has an underlying type; int by default) is the entirety of
// that underlying type. Therefore, an enum class by default can assume the value
// of any int.
// As such, GCC is well within its rights to assume that fun may get any value
// within the range of its underlying type, rather than only one of its enumerators.