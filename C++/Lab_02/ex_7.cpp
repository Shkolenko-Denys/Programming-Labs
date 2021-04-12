#include <cstdlib>
#include <iostream>
using namespace std;

int main (int argc, char **argv) {
    cout << "argc = " << argc << endl;
    cout << "&argc = " << &argc << endl;
    cout << "argv = " << argv << endl;
    cout << "argv+1 = " << argv+1 << endl;
    cout << "argv[argc-1] = " << argv[argc-1] << endl; 
    cout << "argc[argv-1] = " << argc[argv-1] << endl;
    cout << "&(argv[argc-1]) = " << &(argv[argc-1]) << endl; 
    cout << "&(argc[argv-1]) = " << &(argc[argv-1]) << endl;
    cout << "argc + argv-1 = " << argc + argv-1 << endl;
    return EXIT_SUCCESS;
}
