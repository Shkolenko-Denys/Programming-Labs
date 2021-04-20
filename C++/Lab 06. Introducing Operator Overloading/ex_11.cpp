/*
Задача 7.11. Сравните реализацию strtype, использующую конструктор копий (См. Unit6
"Copy Constructor To Allow Objects To Be Passed To Functions", и реализацию strtype,
использующую ссылку в качестве параметра и ссылку в качестве возвращаемого
значения функции (См. Unit7 "A Closer Look At The Assignment Operator"). Объясните чем
одно из решений лучше другого.
*-(Для продвинутых) создайте пример, в котором продемонстрируйте ситуацию, в
которой конструктор копий окажется более предпочтительным решением.
Подсказка: Как вы узнали из Unit6, создание конструктора копий - это другой путь
решения проблем, описанных в Unit7. Конструктор копий может оказаться не столь
эффективным решением, как ссылка в качестве параметра + ссылка в качестве
возвращаемого значения функции. Это происходит потому, что использование ссылки
исключает затраты ресурсов, связанные с копированием объекта в каждом из двух
указанных случаев. В C++ часто имеется несколько способов достижения одной и той же
цели. Понимание их преимуществ и недостатков есть часть процесса вашего
становления как профессионального программиста C++.
*/

// The copy constructor and the assignment operator do almost identical work:
// both copy values ​​from one object to the values ​​of another object.
// However, the copy constructor is used when initializing new objects,
// while the assignment operator replaces the contents of already existing objects.
// It's simple:

// If a new object is created before performing a copy operation,
// then the copy constructor is used (passing or returning objects is performed by value).

// If there was no creation of a new object, and the work is carried out
// with an already existing object, then the assignment operator is used.

#include <iostream> 
#include <cassert>

class Rectangle {
    int length;
    int height;
public:
    // Normal constructor
    Rectangle(int l = 1, int h = 1) :
    length(l), height(h)
    {
        assert( (length != 0) && (height != 0) );
    }

    // Copy constructor
    Rectangle(const Rectangle &copy) :
    length(copy.length), height(copy.height)
    {
        // std::cout << "Copy constructor is working...\n";
    }

    // Overloading the assignment operator
    Rectangle& operator= (const Rectangle &rect) {
        length = rect.length;
        height = rect.height;
        return *this;
   }

   friend std::ostream& operator<< (std::ostream& out, const Rectangle &r);

};

std::ostream& operator<< (std::ostream& out, const Rectangle &r) {
    out << "Rectangle " <<r.length << " by " << r.height;
    return out;
}

int main() {
    Rectangle six_by_seven(6, 7);
    Rectangle r;
    r = six_by_seven; // the overloaded assignment operator is called
    std::cout << r << "\n";
    Rectangle r_copy(six_by_seven); // the Copy constructor is called
    std::cout << r_copy << "\n";

    return 0;
}