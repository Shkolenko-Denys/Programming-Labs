/*
Задача 7.15. У вас есть класс:
class three_d {
 int x, y, z;
public:
 three_d(int i, int j, int k) { x=i; y=j; z=k; }
 three_d(){ x=0; y=0; z=0; }
 void get(int &i, int &j, int &k) { i=x; j=y; k=z; }
};
Перегрузите для этого класса операторы +, -, ++ и --. Для операторов инкремента и
декремента перегрузите только префиксную или только постфиксную форму.
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
    three_d operator++ () {
        x++; y++; z++;
        return *this;
    }
    three_d operator-- () {
        x--; y--; z--;
        return *this;
    }
};

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

    return 0;
}