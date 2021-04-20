#include <iostream>
#include <ctime>
using namespace std;

class Dice {
    int n;
public:
    void roll();
};
void Dice::roll() {
    n = (rand() % 6) + 1; // without 0
    cout << n << ' ';
}

int main() {
    Dice cube;
    srand(time(0));
    for(int i = 0; i < 5; i++) {
        cube.roll();
    }
    return 0;
}