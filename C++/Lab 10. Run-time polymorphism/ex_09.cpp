/*-------------------------------------------------------------------<Header>-
 Name: ex_09.cpp
 Title: —
 Description: Расширьте пример со списком, (см. Example 11.6 ) так, чтобы в нем
 перегружались операторы + и -. Используйте оператор + для внесения элемента в
 список, а оператор - для выборки элемента из списка.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>

using namespace std;

class IList {
public:
    IList *head;
    IList *tail;
    IList *next;
    int num;
    IList(int num = 0);
    virtual ~IList() {}
    friend IList* operator+ (IList &obj, int i);
    friend IList* operator- (IList &obj, int i);
};

class queue: public IList {
public:
    queue(int num = 0) : IList(num) {}
    virtual ~queue() {}
};

void show_list(IList *head);

int main() {
    IList *p;
    queue q_ob;

    p = &q_ob;

    // add new items
    for (int i = 1; i < 5; i++) {
        p = *p + i;
    }
    
    show_list(p);

    p = &q_ob;

    // remove elements
    char ch;
    while (p) {
        cout << " Remove element? (y/n): ";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 'y') {
            p = *p - 0;
            show_list(p);
        }
        else {
            break;
        }
    }

    cout << "\n\n";
    return 0;
}

IList::IList(int num) {
    head = nullptr;
    tail = nullptr;
    next = nullptr;
    this->num = num;
}

IList* operator- (IList &obj, int i) {
    // update pointer to head in the whole IList
    IList *tmp;
    for (tmp = obj.next; tmp != nullptr; tmp = tmp->next) {
        tmp->head = obj.next;
    }

    tmp = obj.next;
    delete &obj;
    return tmp;
}

IList* operator+ (IList &obj, int i) {
    IList *item;
    item = new queue(i);
    if (!item) {
        cout << " Allocation error.\n";
        exit(1);
    }

    if (!obj.head) { obj.head = &obj; }

    // update pointer to tail in the whole queue
    IList *tmp;
    for (tmp = &obj; tmp->next != nullptr; tmp = tmp->next) {
        tmp->tail = item;
    }

    // set penult node
    tmp->head = &obj;
    tmp->tail = item;
    tmp->next = item;

    // set last node
    item->head = &obj;
    item->tail = item;
    return &obj;
}

void show_list(IList *head) {
    // create header
    cout << setw(11) << "num" << setw(11) << "head" << setw(11) << "p" <<
    setw(11) << "next" << setw(11) << "tail" << "\n";

    IList *p;
    for (p = head; p != nullptr; p = p->next) {
        cout << setw(11) << p->num <<
        setw(11) << p->head <<
        setw(11) << p <<
        setw(11) << p->next <<
        setw(11) << p->tail << "\n";
    }
    cout << "\n";
}