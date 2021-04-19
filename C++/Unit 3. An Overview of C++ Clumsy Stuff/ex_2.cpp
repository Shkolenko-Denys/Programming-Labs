#include <iostream>
#include <cmath>
using namespace std;

class Area {
    public:
        double height;
        double width;
        Area(double h, double w);
};
Area::Area(double h, double w) {
    height = h;
    width = w;
}

class Rectangle : public Area {
    public:
        using Area::Area; // с++11
        // Rectangle(double h, double w) : Area(height, width) {};
        double area();
};
class Isosceles : public Area {
    public:
        using Area::Area; // с++11
        // Isosceles(double h, double w) : Area(height, width) {};
        double area();
};
class Cylinder : public Area {
    public:
        using Area::Area; // с++11
        // Cylinder(double h, double w) : Area(height, width) {};
        double area();
};

double Rectangle::area() {
    return height * width;
}
double Isosceles::area() {
    return 0.5 * height * width;
}
double Cylinder::area() { // 2*pi*R*R + pi*2*R*h = 2*pi*R(R + h)
    return  2*M_PI*width*(width + height);
}

int main() {
    Rectangle myRectangle(2, 3);
    Isosceles myIsosceles(4, 5);
    Cylinder myCylinder(6, 7);
    cout << "Rectangle " << myRectangle.area() << endl;
    cout << "Isosceles " << myIsosceles.area() << endl;
    cout << "Cylinder " << myCylinder.area() << endl;
    return 0;
}