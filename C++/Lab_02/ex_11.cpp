#include <iostream>
#include <ctime>
using namespace std;

void sleep (const size_t seconds){
    clock_t start = clock();
    while ((double)(clock() - start)/CLOCKS_PER_SEC < seconds);
}

void sleep (const char *seconds){
    clock_t start = clock();
    while ((double)(clock() - start)/CLOCKS_PER_SEC < atoi(seconds));
}

int main () {
    cout << "Counting: ";
    for (size_t i = 0; i < 10; i++){
        sleep(1);
        cout << i << " ";
    }
    cout << endl <<"Wait 10 sec ..." << endl;
    sleep("10");
    cout << "Finish" << endl;
    return 0;
}