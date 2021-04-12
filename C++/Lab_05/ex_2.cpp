#include <iostream>
#include <ctime>
using namespace std;

class stopwatch {
    clock_t prog_start;
    clock_t mystart;
    clock_t myfinish;
    clock_t prog_end;
    public:
        stopwatch();
        stopwatch(const time_t time);
        // stopwatch(clock_t time) { prog_start = time; }
        ~stopwatch();
        void start();
        void stop();
        void show();
};

stopwatch::stopwatch () {
    prog_start = clock();
}

stopwatch::stopwatch (const time_t time) {
    cout << ctime(&time);
    prog_start = clock();
}

void stopwatch::start () {
    mystart = clock();
}

void stopwatch::stop () {
    myfinish = clock();
}

void stopwatch::show () {
    cout << "\nYour time: " << (double)(myfinish - mystart)/CLOCKS_PER_SEC << endl;
}

stopwatch::~stopwatch(){
    prog_end = clock();
    cout << "Elapsed time: " << (double)(prog_end - prog_start)/CLOCKS_PER_SEC << endl;
}

int main() {
    stopwatch timer(time(NULL));
    // stopwatch timer(clock());
    char ch;
    cout << "Enter s to start: ";
    cin >> ch;
    timer.start();
    cout << "Enter f to finish: ";
    cin >> ch;
    timer.stop();
    timer.show();
    return 0;
}