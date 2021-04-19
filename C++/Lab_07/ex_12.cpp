/* Задача 8.12. Здесь представлена переработанная версия класса coord из
предыдущего Практического занятия. Форматирование кода нарушено. Теперь этот
класс используется в качестве базового для класса quad, в котором помимо
координат хранится номер квадранта, к которому принадлежит точка с этими
координатами. Запустите программу и попытайтесь понять и объяснить полученный
результат.
#include <iostream>
using namespace std;
class coord {
public:
    int x, y; // coordinate values
    coord () { x=0; y=0; }
    coord (int i, int j) { x=i; y=j; }
    void get_xy (int &i, int &j) { i=x; j=y; }
    coord operator +( coord ob2);
    coord operator -( coord ob2);
    coord operator =( coord ob2);
};
// Overload + relative to coord class .
coord coord :: operator +( coord ob2)
{
    coord temp ; cout << " Using coord operator +() \n"; temp .x = x + ob2 .x; temp .y = y +
ob2 .y; return temp ; } // Overload - relative to coord class . coord coord :: operator -(
coord ob2) {
    coord temp ;
    cout << " Using coord operator -() \n";
    temp .x = x - ob2 .x;
    temp .y = y - ob2 .y;
    return temp ;
}
// Overload = relative to coord .
coord coord :: operator =( coord ob2)
{
    cout << " Using coord operator =() \n";
    x = ob2.x;
    y = ob2.y;
return * this ; // return the object that is assigned to
}
class quad : public coord
{
    int quadrant ;
    public :
    quad ()
    {
        x = 0;
        y = 0;
        quadrant = 0;
    }
    quad (int x, int y) : coord (x, y)
    {
        if(x >=0 && y >= 0)
            quadrant = 1;
        else if(x <0 && y >=0) quadrant = 2; else if(x <0 && y <0) quadrant = 3;
        else quadrant = 4;
    }
    void showq ()
    {
        cout << " Point in Quadrant : " << quadrant << '\n';
    }
    quad operator =( coord ob2 );
};
quad quad :: operator =( coord ob2 )
{
    cout << " Using quad operator =() \n";
    x = ob2.x;
    y = ob2.y;
    if(x >=0 && y >= 0)
        quadrant = 1;
    else if(x <0 && y >=0)
        quadrant = 2;
    else if(x <0 && y <0)
        quadrant = 3; else
    quadrant = 4; return * this ; }
    int main ()
    {
        quad o1 (10 , 10) , o2 (15 , 3) , o3;
        int x, y;
o3 = o1 + o2; // add two objects - this calls operator +()
o3. get_xy (x, y);
o3. showq ();
cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
o3 = o1 - o2; // subtract two objects o3. get_xy (x, y);
o3. showq (); cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";
o3 = o1; // assign an object o3. get_xy (x, y); o3. showq (); cout << "(o3=o1) X: " << x
<< ", Y: " << y << "\n"; return 0;
}
Переработайте эту программу, чтобы в ней использовались дружественные оператор-функции. */

#include <iostream>

using namespace std;

class coord {
    int x, y; // coordinate values
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }

    int get_x() const { return x; }
    int get_y() const { return y; }
    void set_x(int i) { x = i; }
    void set_y(int j) { y = j; }

    friend coord operator+ (const coord &obj1, const coord &obj2);
    friend coord operator- (const coord &obj1, const coord &obj2);
    coord operator= (const coord &obj) {
        cout << " Using coord operator= ()" << "\n";
        x = obj.x;
        y = obj.y;
        return *this;
    }
};

// Overload + relative to coord class.
coord operator+ (const coord &obj1, const coord &obj2) {
    cout << " Using coord operator+ ()" << "\n";
    coord temp;
    temp.x = obj1.x + obj2.x;
    temp.y = obj1.y + obj2.y;
    return temp;
}

// Overload - relative to coord class.
coord operator- (const coord &obj1, const coord &obj2) {
    cout << " Using coord operator- ()" << "\n";
    coord temp;
    temp.x = obj1.x - obj2.x;
    temp.y = obj1.y - obj2.y;
    return temp;
}

class quad : public coord {
    int quadrant;
public:
    quad() : coord () {
        quadrant = 0;
    }
    quad(int x, int y) : coord (x, y) {
        if (x >= 0 && y >= 0) {
            quadrant = 1;
        }
        else if (x < 0 && y >= 0) {
            quadrant = 2;
        }
        else if (x < 0 && y < 0) {
            quadrant = 3;
        }
        else {
            quadrant = 4;
        }
    }
    void showq () {
        cout << " Point in Quadrant : " << quadrant << "\n";
    }
    quad operator= (const coord &obj);
};

quad quad::operator= (const coord &obj) {
    cout << " Using quad operator= ()" << "\n";
    set_x(obj.get_x());
    set_y(obj.get_y());
    if (get_x() >= 0 && get_y() >= 0) {
        quadrant = 1;
    }
    else if (get_x() < 0 && get_y() >= 0) {
        quadrant = 2;
    }
    else if (get_x() < 0 && get_y() < 0) {
        quadrant = 3;
    }
    else {
        quadrant = 4;
    }
    return *this;
}

int main() {
    quad o1(10, 10), o2(15, 3), o3;

    o3 = o1 + o2; // add two objects - this calls operator +()
    o3.showq();
    cout << "(o1 + o2) X: " << o3.get_x() << ", Y: " << o3.get_y() << "\n\n";

    o3 = o1 - o2; // subtract two objects o3. get_xy (x, y);
    o3.showq();
    cout << "(o1 - o2) X: " << o3.get_x() << ", Y: " << o3.get_y() << "\n\n";

    o3 = o1; // assign an object
    o3.showq();
    cout << "(o3 = o1) X: " << o3.get_x() << ", Y: " << o3.get_y() << "\n\n";

    return 0;
}