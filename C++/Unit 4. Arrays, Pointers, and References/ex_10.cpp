#include <iostream>

using namespace std;

class List;
List* create(string name, int age);
void addend(List *students, List* new_person); // adding a node to the end OR merge lists
void remove(List *students, string name);
List* copy (List *students, string name);
List* unmerge(List *students, string name);
void insert(List *students, string name, List *new_person);
void insert(List *students, List *new_person, string name);
void print_list(List *students);
void free_all(List *students);

int main() {
    List *students = NULL;
    List *kids = NULL;

    students = create("Den", 17);
    addend(students, create("Ivan", 18));
    addend(students, create("Fred", 19));
    addend(students, create("Bob", 18));
    addend(students, create("Jack", 20));

    kids = create("Harry", 10);
    addend(kids, create("Lily", 11));
    addend(kids, create("Emily", 9));

    cout << "\tStudents:" << "\n";
    print_list(students);

    remove(students, "Ivan");
    cout << "Removing Ivan..." << "\n";

    cout << "\tStudents:" << "\n";
    print_list(students);
    cout << "\tKids:" << "\n";
    print_list(kids);

    addend(students, kids);

    cout << "\tStudents + Kids:" << "\n";
    print_list(students);

    kids = unmerge(students, "Fred");
    cout << "Unmerging..." << "\n";
    cout << "\tStudents:" << "\n";
    print_list(students);
    cout << "\tKids:" << "\n";
    print_list(kids);

    List *clon1 = copy(students, "Den");
    cout << "Inserting \"Den\" before/after \"Jack\"" << "\n";
    insert(kids, "Jack", clon1);
    List *clon2 = copy(students, "Den");
    insert(kids, clon2, "Jack");

    cout << "\tKids:" << "\n";
    print_list(kids);

    free_all(students);
    free_all(kids);
    return 0;
}

class List {
    string *p_name;
    int *p_age;
    List *next;
public:
    List(string name, int age);
    ~List();

    void set_name(string name) { *p_name = name; }
    void set_age(int age) { *p_age = age; }
    void set_next(List *next) { this->next = next; }

    string get_name() { return *p_name; }
    int get_age() { return *p_age; }
    List *get_next() { return next; }
};

List::List(string name, int age) {
    p_name = new string(name);
    p_age = new int(age);
    next = NULL;
}

List::~List() {
    delete p_name;
    delete p_age;
}

List* create(string name, int age) {
    List *new_person = new List(name, age);
    return new_person;
}

void addend(List *students, List* new_person) {
    // adding a node to the end
    // merge lists
    List *p = NULL;
    for (p = students; p->get_next() != NULL; p = p->get_next());
    p->set_next(new_person);
}

void remove(List *students, string name) {
    List *p = NULL;
    for (p = students; p->get_next()->get_name() != name; p = p->get_next());
    if (!p) {
        cout << "Not found" << "\n";
    } else {
        List *temp = p->get_next();
        p->set_next(p->get_next()->get_next());
        delete temp;
    }
}

List* copy (List *students, string name) {
    List *p = NULL;
    for (p = students; p->get_name() != name; p = p->get_next());
    if (!p) {
        cout << "Not found, returned first in the list" << "\n";
        return students;
    } else {
        List *p_clon = create(name, p->get_age());
        return p_clon;
    }
}

List* unmerge(List *students, string name) {
    List *p = NULL;
    for (p = students; p->get_next()->get_name() != name; p = p->get_next());
    if (!p) {
        cout << "Not found, returned first in the list" << "\n";
        return NULL;
    } else {
        List *temp = p->get_next();
        p->set_next(NULL);
        return temp;
    }
}

void insert(List *students, string name, List *new_person) {
    List *p = NULL;
    for (p = students; p->get_name() != name; p = p->get_next());
    if (!p) {
        cout << "Not found, returned first in the list" << "\n";
    } else {
        List *temp = p->get_next();
        p->set_next(new_person);
        new_person->set_next(temp);
    }
}

void insert(List *students, List *new_person, string name) {
    List *p = NULL;
    for (p = students; p->get_next()->get_name() != name; p = p->get_next());
    if (!p) {
        cout << "Not found, returned first in the list" << "\n";
    } else {
        List *temp = p->get_next();
        p->set_next(new_person);
        new_person->set_next(temp);
    }
}

void print_list(List *students) {
    for (List *p = students; p != NULL; p = p->get_next()) {
        cout << p->get_name() << " " << p->get_age() << "\n";
    }
}

void free_all(List *students) {
    List *next;
    for ( ; students != NULL; students = next) {
        next = students->get_next();
        delete students;
    }
}