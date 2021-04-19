#include <iostream>
#include <ctime>
using namespace std;

class time_and_date {
    tm *now;
public:
    time_and_date (time_t *tp);
    void show();
};

time_and_date::time_and_date (time_t *tp) {
    now = localtime(tp);
}

void time_and_date::show () {
    cout << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << endl;
    cout << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << endl;
}

int main () {
    time_t t = time(0);
    time_and_date tnd(&t);
    tnd.show();
    return 0;
}