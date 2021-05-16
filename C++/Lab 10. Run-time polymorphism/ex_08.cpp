/*-------------------------------------------------------------------<Header>-
 Name: ex_08.cpp
 Title: —
 Description: Программа из Example 11.6 при компиляции при помощи команды g++
 -Wall ex116.cpp выдает предупреждения. Объясните причину появления этих
 предупреждений и для их устранения внесите необходимые правки в код данного
 примера.
 Совет 1: Функция main() в программе со списками (см. Example 11.6)
 только иллюстрирует работу классов. Для изучения динамического полиморфизма
 попробуйте использовать в этой программе следующую функцию main().
 Добавьте список другого типа к программе из Example 11.6 . Эта версия должна
 поддерживать отсортированный (в порядке возрастания) список. Назовите список
 sorted.
 Совет 2: Обдумайте случаи, в которых следует использовать динамический
 полиморфизм, чтобы упростить решение разного рода проблем.
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
    virtual IList* store(int i) = 0;
    IList* retrieve();
};

class queue: public IList {
public:
    queue(int num = 0) : IList(num) {}
    virtual ~queue() {}
    virtual IList* store(int i) override;
};

class stack: public IList {
public:
    stack(int num = 0) : IList(num) {}
    virtual ~stack() {}
    virtual IList* store(int i) override;
};

class sorted: public IList {
public:
    sorted(int num = 0) : IList(num) {}
    virtual ~sorted() {}
    virtual IList* store(int i) override;
};

void show_list(IList *head);

int main() {
    IList *p;
    queue q_ob;
    stack s_ob;
    sorted sorted_ob;

    // select type of list
    char ch;
    cout << " Stack or Queue or SortedList? (S/Q/L): ";
    cin >> ch;
    ch = tolower(ch);
    if (ch == 's') {
        p = &s_ob;
    }
    else if (ch == 'q') {
        p = &q_ob;
    }
    else {
        p = &sorted_ob;
    }

    // add new items
    for (int i = 1; i < 5; i++) {
        p = p->store(i);
    }
    
    show_list(p);

    // restore the pointer to the head of the list
    if (ch == 's') {
        p = &(*s_ob.head);
    }
    else if (ch == 'q') {
        p = &q_ob;
    }
    else {
        p = &sorted_ob;
    }

    // remove elements
    while (p) {
        cout << " Remove element? (y/n): ";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 'y') {
            p = p->retrieve();
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

IList* IList::retrieve() {
    if (!head) {
        cout << " IList empty.\n";
        return nullptr;
    }

    // update pointer to head in the whole IList
    IList *tmp;
    for (tmp = next; tmp != nullptr; tmp = tmp->next) {
        tmp->head = next;
    }

    tmp = next;
    delete this;
    return tmp;
}

IList* queue::store(int i) {
    IList *item;
    item = new queue(i);
    if (!item) {
        cout << " Allocation error.\n";
        exit(1);
    }

    if (!head) { head = this; }

    // update pointer to tail in the whole queue
    IList *tmp;
    for (tmp = this; tmp->next != nullptr; tmp = tmp->next) {
        tmp->tail = item;
    }

    // set penult node
    tmp->head = this;
    tmp->tail = item;
    tmp->next = item;

    // set last node
    item->head = this;
    item->tail = item;
    return this;
}

IList* stack::store(int i) {
    IList *item;
    item = new stack(i);
    if (!item) {
        cout << " Allocation error.\n";
        exit(1);
    }

    // push the new item to the top-of-stack
    if (!head) {
        head = this;
        tail = this;
    }
    item->tail = head->tail;
    item->next = head;
    item->head = item;

    // update point to head in the whole stack
    IList *tmp;
    for (tmp = this; tmp != nullptr; tmp = tmp->next) {
        tmp->head = item;
    }

    return item;
}

IList* sorted::store(int i) {
    IList *item;
    item = new sorted(i);
    if (!item) {
        cout << " Allocation error.\n";
        exit(1);
    }

    if (!head) {
        head = this;
        tail = this;
    }

    // if the new item is the smallest
    if (i < num) {
        item->next = this;
        item->tail = tail;

        // update pointer to head in the whole stack
        IList *tmp;
        for (tmp = item; tmp != nullptr; tmp = tmp->next) {
            tmp->head = item;
        }
        
        return item;
    }

    // if the new item is the biggest
    else if (i >= tail->num) {
        tail->next = item;
        item->head = head;

        // update pointer to tail in the whole stack
        IList *tmp;
        for (tmp = this; tmp != nullptr; tmp = tmp->next) {
            tmp->tail = item;
        }
    }

    else {
        item->head = head;
        item->tail = tail;
        IList *tmp;
        for (tmp = this; tmp->next != nullptr; tmp = tmp->next) {
            if (i < tmp->next->num) {
                item->next = tmp->next;
                tmp->next = item;
                break;
            }
        }
    }
    return this;
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