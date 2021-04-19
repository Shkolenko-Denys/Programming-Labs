#include <iostream>
using namespace std;

double ato_all (const char *s) {
    return atof(s);
}
// long ato_all (const char *s) {
//     return atol(s);
// }
// int ato_all (const char *s) {
//     return atoi(s);
// }

int main () {
    double a = ato_all("2020");
    cout << a + 1 << endl;
    return 0;
}