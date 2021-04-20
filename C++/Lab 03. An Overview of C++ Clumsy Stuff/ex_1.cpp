#include <iostream>
#include <cstring>
using namespace std;
enum color {red, yellow, green, orange};
enum choice {no, yes};
void out(bool x);
void out(choice x);
char const *c[] = {"red", "yellow", "green", "orange"};

class Fruit {
public:
    choice annual;
    choice perennial;
    choice tree;
    choice tropical;
    color clr;
    char name[40];
};
class Apple: public Fruit {
    choice cooking;
    choice crunchy;
    choice eating;
public:
    void seta(char const *n, color c, choice ck, choice crchy, choice e);
    void show();
};
class Orange: public Fruit {
    choice juice;
    choice sour;
    choice eating;
public:
    void seto(char const *n, color c, choice j, choice sr, choice e);
    void show();
};
void out(choice x) {
    cout << ( x ? "yes" : "no") << endl;
}
void out(bool x) {
    cout << ( x ? "yes" : "no") << endl;
}
void Apple::seta(char const *n, color c, choice ck, choice crchy, choice e) {
    strcpy(name, n);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = no;
    clr = c;
    cooking = ck;
    crunchy = crchy;
    eating = e;
}
void Orange::seto(char const *n, color c, choice j, choice sr, choice e) {
    strcpy(name, n);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = yes;
    clr = c;
    juice = j;
    sour = sr;
    eating = e;
}
void Apple::show() {
    cout << name <<" apple is: " << endl;
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << endl;
    cout << "Good for cooking: "; out(cooking);
    cout << "Crunchy: "; out(crunchy);
    cout << "Good for eating: "; out(eating);
    cout << endl;
}
void Orange::show() {
    cout << name <<" orange is: " << endl;
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << endl;
    cout << "Good for juice: "; out(juice);
    cout << "Sour: "; out(sour);
    cout << "Good for eating: "; out(eating);
}
int main() {
    Apple a2;
    Orange o2;
    a2.seta("Jonathan", red, yes, no, yes);
    o2.seto("Valencia", orange, yes, yes, no);
    a2.show();
    o2.show();
    return 0;
}