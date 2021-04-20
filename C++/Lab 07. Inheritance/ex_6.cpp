/* Задача 8.6. В приведенном ниже фрагменте добавьте конструктор для класса
myderived. Он должен передать указатель на инициализируемую строку конструктору
класса mybase. Кроме того, конструктор myderived() должен инициализировать
переменную len длиной строки.
#include <iostream>
#include <cstring>
using namespace std;
class mybase {
    char str[80];
public:
    mybase(char *s) { strcpy (str, s); }
    char *get() { return str; }
};
class myderived : public mybase {
    int len;
public:
 // add myderived() here...
    int getlen() { return len; }
    void show() { cout << get () << '\n'; }
};
int main() {
    myderived obо("hello");
    obj.show();
    cout << obj.getlen() << '\n';
    return 0;
} */

#include <iostream>
#include <cstring>

using namespace std;

class mybase {
    char str[80];
public:
    mybase(const char *s) { strcpy(str, s); }
    char* get() { return str; }
};

class myderived : public mybase {
    int len;
public:
    myderived(const char *input_str) : mybase(input_str) {
        len = strlen(input_str);
    }
    int getlen() { return len; }
    void show() { cout << get() << "\n"; }
};

int main() {
    char word[] = "hello";
    myderived obj(word);
    obj.show();
    cout << "len: " <<obj.getlen() << "\n";
    return 0;
}