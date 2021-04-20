#include <iostream>
#include <cstring>
using namespace std;

class card {
    char author[50];
    char head[50];
    int count;
public:
    void store(char *name, char *h, int count);
    void show();
};
void card::store (char *name, char *h, int cnt) {
    strcpy(head, h);
    strcpy(author, name);
    count = cnt;
}
void card::show () {
    cout << author << ' ' << head << ' ' << count << endl;
}

int main () {
    card mycard;
    char myauthor[50];
    char myhead[50];
    int count;

    cout << "Enter author: ";
    cin.getline(myauthor, 50);
    cout << "Enter head: ";
    cin.getline(myhead, 50);
    cout << "Enter count of this book: ";
    cin >> count;
    cout << endl;
    
    mycard.store(myauthor, myhead, count);
    mycard.show();
    return 0;
}