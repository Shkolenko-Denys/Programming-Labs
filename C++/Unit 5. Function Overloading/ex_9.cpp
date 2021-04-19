#include <iostream>
#include <cstdio> // sscanf
#include <ctime>

using namespace std;

class Date {
    int day, month, year;
public:
    Date(int m, int d, int y) {
        day = d;
        month = m;
        year = y;
    }

    Date(char const *str) {
        sscanf(str, "%d%*c%d%*c%d", &month, &day, &year);
    }

    Date(time_t time) {
        tm* now = localtime(&time);
        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day = now->tm_mday;
    }

    void show() {
        cout << month << '/' << day << '/' << year << '\n';
    }
};

int main() {
    Date strdate("03/21/2021");
    strdate.show();

    Date intdate(03, 21, 2021);
    intdate.show();

    Date tm_date(time(NULL));
    tm_date.show();

    return 0;
}
