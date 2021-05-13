/*-------------------------------------------------------------------<Header>-
 Name: ex_21.cpp
 Title: —
 Description: Ниже приведена переработанная версия класса inventory из
 предыдущей Практической работы. Добавьте функции store() и retrieve(). Затем
 создайте небольшой файл, содержащий несколько инвентарных записей. Далее,
 используя произвольный доступ, по номеру записи отобразите на экране информацию
 об одном из элементов.
 #include <iostream>
 #include <fstream>
 #include <cstring>
 using namespace std;
 #define SIZE 40
 class inventory {
 char item[SIZE]; // name of item
 int onhand; // number on hand
 double cost; // cost of item
 public:
     inventory(char *i, int o, double c) {
         strcpy(item, i);
         onhand = o;
         cost = c;
     }
     void store(fstream &stream);
     void retrieve(fstream &stream);
     friend ostream &operator <<(ostream &stream, inventory obj);
     friend istream &operator >>(istream &stream, inventory &obj);
 };
 ostream &operator <<(ostream &stream, inventory obj) {
     stream << obj.item << ": " << obj.onhand;
     stream << " on hand at $" << obj.cost << '\n';
     return stream;
 }
 istream &operator >>(istream &stream, inventory &obj) {
     cout << "Enter item name: ";
     stream >> obj.item;
     cout << "Enter number on hand: ";
     stream >> obj.onhand;
     cout << " Enter cost: ";
     stream >> obj.cost;
     return stream ;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

class inventory {
    string item; // name of item
    int onhand; // number on hand
    double cost; // cost of item
public:
    inventory();
    inventory(string i, int o, double c);
    void store(fstream &stream);
    string retrieve(fstream &stream);
    friend ostream &operator <<(ostream &stream, inventory obj);
    friend istream &operator >>(istream &stream, inventory &obj);
};
inventory::inventory() {
    item = "NULL";
    onhand = 0;
    cost = 0;
}
inventory::inventory(string i, int o, double c) {
    item = i;
    onhand = o;
    cost = c;
}

ostream& operator<< (ostream &stream, inventory obj) {
    stream << setw(20) << obj.item << " : " <<
    setw(4) << obj.onhand << " on hand at $" <<
    setw(5) << obj.cost << "\n";
    return stream;
}
istream& operator>> (istream &stream, inventory &obj) {
    cout << " Enter item name: ";
    stream >> obj.item;
    cout << " Enter number on hand: ";
    stream >> obj.onhand;
    cout << " Enter cost: ";
    stream >> obj.cost;
    cout << "\n";
    return stream ;
}

void inventory::store(fstream &stream) {
    // add the obj to stream.
    // the same functionality with operator<<
    stream << *this;
}
string inventory::retrieve(fstream &stream) {
    // remove the obj from database file
    string line;
    string new_data; // modified data
    stream.seekg(0);

    // collecting new_data without current obj
    while (getline(stream, line)) { // get each line
        if (line.find(item) == string::npos) {
            // if this string has not this->item in it
            // add this string to the end of new_data
            new_data.append(line + "\n");
        }
    }
    return new_data;
}

int get_int(string invitation) {
    int num;
    // validating user input
    while (true) {
        cout << invitation;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid. Please try again.\n\n";
        }
        else {
            cin.ignore(32767, '\n'); // remove unnecessary values
            break;
        }
    }
    return num;
}

int main() {
    inventory obj1("Laptop", 9, 1000), obj2("Smartphone", 5, 400), obj3, obj4, obj5;
    cout << " Start Menu:\n" << obj1 << obj2;

    fstream db("text_doc_ex_21.txt");
    if (!db) {
        cerr << "text_doc_ex_21.txt could not be opened!" << endl;
        exit(1);
    }

    cout << "\n *** Add new objs (3) ***\n\n";
    cin >> obj3 >> obj4 >> obj5;

    // add objs to db:
    obj1.store(db);
    obj2.store(db);
    obj3.store(db);
    obj4.store(db);
    obj5.store(db);

    // remove obj2 from the db (create new_data):
    string new_data = obj2.retrieve(db);
    db.close();

    // Here we have Smartphone in the db

    db.open("text_doc_ex_21.txt", ios::out);
    // rewrite database:
    db.write(new_data.c_str(), new_data.size());
    db.close();

    // Here we don't have Smartphone in the db

    // используя ПРОИЗВОЛЬНЫЙ доступ, по номеру записи отобразите на экране
    // информацию об одном из элементов.

    db.open("text_doc_ex_21.txt", ios::in);

    int num = get_int(" Enter the number of obj: ");
    if (num <= 0 || num > 4) {
        cout << " !!! 0 < num <= 4 !!!\n\n";
    } else {
        string str;
        while (--num) {
            db.seekg(47, ios::cur); // 45 + \0 + \n = 47
        }
        getline(db, str);
        cout << " Result:\n" << str << "\n\n";
    }
    db.close();

     
    return 0;
}