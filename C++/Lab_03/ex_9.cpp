#include <iostream>
using namespace std;

class who {
    char id;
public:
    who(char id);
    ~who();       
};

who::who(char code) {
    id = code;
    cout << "Constructing who #" << id << endl;
}
who::~who() {
    cout << "Destroing who #" << id << endl;
}

who make_who(who obj) {
    return obj;
}

int main() {
    who apple('a');
    who apple2 = make_who(apple);
    who box('b');
    who city('c');
    who dell('d');
    who elem('e');
    return 0;
}