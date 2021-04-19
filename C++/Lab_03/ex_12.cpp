#include <iostream>
using namespace std;

class planet {
    int moons;
    double dist_from_sun; // in miles
    double diameter;
    double mass;
    const double milpersec = 186000;
    public:
        planet(int dist);
        friend double light(planet a);
};
planet::planet(int dist) {
    dist_from_sun = dist;
}
double light(planet x) {
    return (x.dist_from_sun / x.milpersec);
}

int main() {
    planet Earth(93000000);
    cout << "Earth -> Sun = " << light(Earth) << " sec."<< endl;
    return 0;
}