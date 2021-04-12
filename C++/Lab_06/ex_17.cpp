/*
Задача 7.17. Создайте свой вариант класса strtype, который допускает следующие типы
операций:
• Конкатенацию строк с помощью оператора +
• Присваивание строк с помощью оператора =
• Сравнение строк с помощью операторов <, > и ==
Разрешено пользоваться строками фиксированной длины. На первый взгляд это может
показаться непростой задачей, но, немного подумав и поэкспериментировав, вы
обязательно справитесь. ВВ. в вас верит! :)
*/

#include <iostream>
#include <cstring>

using namespace std;

class strtype {
    char *string;
    int len;
public:
    strtype() { string = NULL; len = 0; }
    strtype(const char *str) {
        len = strlen(str);
        string = new char[len + 1];
        strcpy(string, str);
    }
    ~strtype() { delete[] string; }

    strtype& operator= (const strtype &str);
    friend strtype operator+ (const strtype &str1, const strtype &str2);
    friend bool operator== (const strtype &str1, const strtype &str2);
    friend bool operator> (const strtype &str1, const strtype &str2);
    friend bool operator< (const strtype &str1, const strtype &str2);
    friend ostream& operator<< (ostream& out, const strtype &s);
};

strtype& strtype::operator= (const strtype &str) {
    len = str.len;
    delete[] string;
    string = new char[len + 1];
    strcpy(string, str.string);
    return *this;
}

strtype operator+ (const strtype &str1, const strtype &str2) {
    strtype temp;
    temp.len = str1.len + str2.len;
    temp.string = new char[temp.len + 1];
    for (int i = 0; i < str1.len; ++i) {
        temp.string[i] = str1.string[i];
    }
    for (int i = str1.len, j = 0; i < temp.len; ++i, ++j) {
        temp.string[i] = str2.string[j];
    }
    temp.string[temp.len] = '\0';
    return temp;
}

bool operator== (const strtype &str1, const strtype &str2) {
    return !strcmp(str1.string, str2.string);
}

bool operator> (const strtype &str1, const strtype &str2) {
    if (strcmp(str1.string, str2.string) > 0) {
        return true;
    }
    return false;
}

bool operator< (const strtype &str1, const strtype &str2) {
    if (strcmp(str1.string, str2.string) < 0) {
        return true;
    }
    return false;
}

ostream& operator<< (ostream& out, const strtype &s) {
    out << s.string << "\n";
    return out;
}

int main() {
    strtype str1("Hello");
    strtype str2("World!");
    cout << "str1 = " << str1;
    cout << "str2 = " << str2;
    cout << "\n / strtype str3 = str1; / " << "\n";
    strtype str3 = str1;
    cout << "str3 = " << str3;
    cout << "\n / str3 = str1 + str2; / " << "\n";
    str3 = str1 + str2;
    cout << "str3 = " << str3;

    if (str3 > str1) {
        cout << "str3 > str1 " << "\n";
    } else if (str3 < str1) {
        cout << "str3 > str1 " << "\n";
    } else {
        cout << "str3 == str1 " << "\n";
    }

    cout << "\n / str2 = str1; / " << "\n";
    str2 = str1;
    if (str2 > str1) {
        cout << "str2 > str1 " << "\n";
    } else if (str2 < str1) {
        cout << "str2 > str1 " << "\n";
    } else {
        cout << "str2 == str1 " << "\n";
    }
    return 0;
}