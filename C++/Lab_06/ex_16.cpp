/*
Задача 7.16. Измените ваше решение Задачи 7.15 так, чтобы в оператор-функциях
вместо параметров-значений использовать параметры-ссылки.
Подсказка: Для операторов инкремента и декремента потребуются дружественные
функции.
Перегрузите операторы ==, !=, || и + относительно класса three_d Задачи 7.15 так, чтобы
иметь возможность выполнять следующие типы операций:
obj + int;
int + obj;
*/

#include <iostream>

using namespace std;

class three_d {
    int x, y, z;
public:
    three_d() { x = 0; y = 0; z = 0; }
    three_d(int i, int j, int k) { x = i; y = j; z = k; }
    void get_xyz(int &i, int &j, int &k) { i=x; j=y; k=z; }

    three_d operator+ (const three_d &obj) {
        three_d temp;
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        temp.z = z + obj.z;
        return temp;
    }
    three_d operator- (const three_d &obj) {
        three_d temp;
        temp.x = x - obj.x;
        temp.y = y - obj.y;
        temp.z = z - obj.z;
        return temp;
    }
    friend three_d operator++ (three_d &obj);
    friend three_d operator-- (three_d &obj);
    friend three_d operator+ (const three_d &obj, int i);
    friend three_d operator+ (int i, const three_d &obj);
    friend bool operator== (const three_d &obj1, const three_d &obj2);
    friend bool operator!= (const three_d &obj1, const three_d &obj2);
    friend bool operator|| (const three_d &obj1, const three_d &obj2);
};

three_d operator++ (three_d &obj) {
    obj.x++; obj.y++; obj.z++;
    return obj;
}

three_d operator-- (three_d &obj) {
    obj.x--; obj.y--; obj.z--;
    return obj;
}

bool operator== (const three_d &obj1, const three_d &obj2) {
    return ( (obj1.x == obj2.x) && (obj1.y == obj2.y) && (obj1.z == obj2.z) );
}

bool operator!= (const three_d &obj1, const three_d &obj2) {
    return ( (obj1.x != obj2.x) || (obj1.y != obj2.y) || (obj1.z != obj2.z) );
}

bool operator|| (const three_d &obj1, const three_d &obj2) {
    return ( (obj1.x || obj2.x) && (obj1.y || obj2.y) && (obj1.z || obj2.z) );
}

three_d operator+ (const three_d &obj, int i){
    three_d temp;
    temp.x = obj.x + i;
    temp.y = obj.y + i;
    temp.z = obj.z + i;
    return temp;
}

three_d operator+ (int i, const three_d &obj){
    three_d temp;
    temp.x = i + obj.x;
    temp.y = i + obj.y;
    temp.z = i + obj.z;
    return temp;
}

int main() {
    three_d obj1(10, 30, 40), obj2(5, 3, 10), obj3;
    int x, y, z;

    obj3 = obj1 + obj2;
    obj3.get_xyz(x, y, z);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    obj3 = obj1 - obj2;
    obj3.get_xyz(x, y, z);
    cout << "(obj1 - obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    ++obj1;
    obj1.get_xyz(x, y, z);
    cout << "(++obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    --obj1;
    obj1.get_xyz(x, y, z);
    cout << "(--obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    obj1 = obj1 + 100;
    obj1.get_xyz(x, y, z);
    cout << "(obj1 = obj1 + 100) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    obj1 = 100 + obj1;
    obj1.get_xyz(x, y, z);
    cout << "(obj1 = 100 + obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n\n";

    if (obj3 == obj1) {
        cout << "obj1 == obj3" << "\n\n";
    }
    if (obj3 != obj1) {
        cout << "obj1 != obj3" << "\n\n";
    }
    if (obj3 || obj1) {
        cout << "obj1 || obj3" << "\n\n";
    }

    return 0;
}