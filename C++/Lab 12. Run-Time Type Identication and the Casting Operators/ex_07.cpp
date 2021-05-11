/*-------------------------------------------------------------------<Header>-
 Name: ex_07.cpp
 Title: —
 Description: Создайте иерархию классов с абстрактным классом DataStruct на ее
 вершине (См. материал Unin 11). В основании иерархии создайте два производных
 класса. В одном должен быть реализован стек, в другом - очередь. Создайте также
 функцию DataStructFactory() со следующим прототипом:
 DataStruct *DataStructFactory(char what);
 Функция DataStructFactory() должна создавать стек, если параметр what равен s,
 и очередь, если параметр what равен q. Возвращаемым значением функции должен
 быть указатель на созданный объект. Продемонстрируйте работоспособность вашей
 программы.
 Совет. Попробуйте поэкспериментировать с RTTI. Хотя польза от динамической
 идентификации типа в контексте приведенных в Unit 13 простых примеров может
 показаться не слишком очевидной, тем не менее это мощный инструмент управления
 объектами во время работы программы.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

class DataStruct {
public:
    DataStruct *head;
    DataStruct *tail;
    DataStruct *next;
    int num;
    DataStruct(int i) {
        head = tail = next = nullptr;
        num = i;
    }
    virtual ~DataStruct() {}
    virtual void store(const int &i) = 0;
    virtual int retrieve() = 0;
};

class Queue: public DataStruct {
public:
    Queue(int num = 0) : DataStruct(num) {}
    virtual ~Queue() {}
    void store(const int &i);
    int retrieve();
};

class Stack: public DataStruct {
public:
    Stack(int num = 0) : DataStruct(num) {}
    virtual ~Stack() {}
    void store(const int &i);
    int retrieve();
};

void Queue::store(const int &i) {
    DataStruct *newItem;
    newItem = new Queue(i);
    if (tail) {
        tail->next = newItem;
    }
    tail = newItem;
    newItem->next = nullptr;
    if (!head) {
        head = tail;
    }
}

int Queue::retrieve() {
    int i;
    DataStruct *node;
    if (!head) {
        throw "Queue is empty.";
    }
    i = head->num;
    node = head;
    head = head->next;
    delete node;
    return i;
}


void Stack::store(const int &i) {
    DataStruct *newItem;
    newItem = new Stack(i);
    if (head) {
        newItem->next = head;
    }
    head = newItem;
    if (!tail) {
        tail = head;
    }
}

int Stack::retrieve() {
    int i;
    DataStruct *temp;
    if (!head) {
        throw "Stack is empty.";
    }
    i = head->num;
    temp = head;
    head = head->next;
    delete temp;
    return i;
}

DataStruct *DataStructFactory(const char &what) {
    switch (what) {
        case 'S': case 's': return new Stack;
        case 'Q': case 'q': return new Queue;
    }
    return nullptr;
}

void retrieve_obj(DataStruct *p, const int &n) {
    try {
        for (int i = 0; i < n; i++) {
            std::cout << p->retrieve() << " ";
        }
    } catch (const char *exception) {
        std::cerr << "\nError: " << exception;
    }
    std::cout << "\n";
}

int main() {
    DataStruct *p1, *p2;
    try {
        p1 = DataStructFactory('q');
        p2 = DataStructFactory('s');
    } catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << "\n";
        return 1;
    }
    p1->store(1);
    p1->store(2);
    p1->store(3);
    std::cout << "Queue: ";
    retrieve_obj(p1, 4);

    p2->store(1);
    p2->store(2);
    p2->store(3);
    std::cout << "Stack: ";
    retrieve_obj(p2, 4);
    return 0;
}