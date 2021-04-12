#include <iostream>
#include <ctime>
using namespace std;

class timer {
    clock_t prog_start;
    clock_t mystart;
    clock_t myfinish;
    clock_t prog_end;
    public:
        timer();
        ~timer();
        void start();
        void stop();
        void show();
};

timer::timer () {
    prog_start = clock();
}
void timer::start () {
    mystart = clock();
}
void timer::stop () {
    myfinish = clock();
}
void timer::show () {
    cout << "\nYour time: " << (double)(myfinish - mystart)/CLOCKS_PER_SEC << endl;
}
timer::~timer(){
    prog_end = clock();
    cout << "Elapsed time: " << (double)(prog_end - prog_start)/CLOCKS_PER_SEC << endl;
}

int main () {
    timer ob;
    char ch;
    cout << "Enter s to start: ";
    cin >> ch;
    ob.start();
    cout << "Enter f to finish: ";
    cin >> ch;
    ob.stop();
    ob.show();
    return 0;
}