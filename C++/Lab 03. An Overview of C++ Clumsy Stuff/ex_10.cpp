#include <iostream>
using namespace std;

class myclass {
    int num;
public:
    myclass(int n);
    void show();
};
myclass::myclass(int n) {
    num = n;
}
void myclass::show() {
    cout << "Number: " << num << endl;
}
myclass copy(myclass *obj) {
    myclass *obj2 = obj;
    // delete obj;
    return *obj2;
}

int main() {
    myclass *obj;
    myclass *new_obj;
    obj = new myclass(100);
    *new_obj = copy(obj);
    new_obj->show();
    return 0;
}