/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: Напишите программу, в которой базовый класс Dist используется для
 хранения в переменной типа double расстояния между двумя точками. В классе Dist
 создайте виртуальную функцию trav_time(), которая выводит на экран время,
 необходимое для прохождения этого расстояния с учетом того, что расстояние
 задано в милях, а скорость равна 60 миль в час. В производном классе Metric
 переопределите функцию trav_time() так, чтобы она выводила на экран время,
 необходимое для прохождения этого расстояния, считая теперь, что расстояние
 задано в километрах, а скорость равна 100 километров в час.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class Dist {
protected:
    double distance;
public:
    Dist() { distance = 0; }
    Dist(const double &dist) { distance = dist; }
    virtual void trav_time() const {
        cout << " Time: " << distance / 60 << " hours." << endl;
    }
};

class Metric : public Dist {
public:
    Metric() { distance = 0; }
    Metric(const double &dist) { distance = dist; }
    virtual void trav_time() const override {
        cout << " Time: " << distance / 100 << " hours." << endl;
    }
};

int main() {
    Dist dist(10000);
    Metric metric(10000);

    dist.trav_time();
    metric.trav_time();

    Dist &refDist = metric;
    refDist.trav_time();
    return 0;
}