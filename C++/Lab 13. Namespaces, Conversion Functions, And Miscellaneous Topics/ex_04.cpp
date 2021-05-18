/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: Переделайте Example 14.8 так, чтобы на экране отображался тот
 объект, который осуществляет вывод символов, и тот объект или те объекты, для
 которых из-за занятости буфера вывод запрещен.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>

#define SIZE 20

using namespace std;

class output {
    static char outbuf[SIZE];    // this is the shared resource
    static int inuse;           // buffer available if 0;
    static int oindex;          // index of outbuf
    char str[80];
    int i;      // index of next char in str
    int who;    // identifies the object , must be > 0
public:
    output(int w, const char *s) {
        strcpy(str, s);
        i = 0;
        who = w;
    }
    /* This function returns 0 if it is done outputting,
    and it returns who if it is still using the buffer */
    int putbuf() {
        if (!str[i]) {  // done outputting
            inuse = 0;  // release buffer
            return 0;   // signal termination
        }
        if (!inuse) {
            cout << who << " performs character output.\n";
            inuse = who; // get buffer
        }
        if (inuse != who) {
            cout << "Who: " << who << ". Output is forbidden.\n"; 
            return 0;
        }
        if (oindex == SIZE - 1) {
            inuse = -1;
        }
        if (str[i]) { // still chars to output
            outbuf[oindex] = str[i];
            i++;
            oindex++;
            outbuf[oindex] = '\0'; // always keep null-terminated
            return 1;
        }
        return 0;
    }
    void show() { cout << outbuf << '\n'; }
};

char output::outbuf[SIZE];   // this is the shared resource
int output::inuse = 0;      // buffer available if 0
int output::oindex = 0;     // index of outbuf

int main() {
    output obj1(1, "This "), obj2(2, "is a test");

    while (obj1.putbuf());
    obj1.show();
    cout << "\n";

    while(obj2.putbuf());
    obj1.show();
    cout << "\n";

    output obj3(3, "................");

    while (obj3.putbuf());
    obj3.show();

    output obj4(4, "................");
    while (obj4.putbuf());
    cout << "\n";
    return 0;
}