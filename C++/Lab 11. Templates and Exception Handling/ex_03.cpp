/*-------------------------------------------------------------------<Header>-
 Name: ex_03.cpp
 Title: —
 Description: Создайте и продемонстрируйте родовые классы, реализующие очередь
 и стек. Подсказка: вот начало родового класса, реализующего стек. Посмотрите
 Example 2.6 из Unit 2 и закончите написание кода.
 template <class StackType> class Stack {
    StackType stck[size]; // holds the stack
    int len; // index of len of stack
 public:
    void init(); // initialize stack
    void push(StackType ch); // push object on stack
    StackType pop(); // pop object from stack
    };
 template <class StackType>
 void Stack<StackType> :: push(StackType obj) {
 ...
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

template <class StackType = int, int size = 10>
class Stack {
    StackType stck[size];
    int len;
public:
    Stack() { len = 0; }
    void push(const StackType &obj);
    StackType pop();
};

template <class QueueType = int, int size = 10>
class Queue {
    QueueType q[size];
    int first;
    int last;
public:
    Queue() { first = -1; last = -1; }
    void push(const QueueType &obj);
    QueueType pop();
};

int main() {
    Stack<char> s1;
    Stack<> s2;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s2.push(111);
    s2.push(222);
    s2.push(333);
    for (int i = 0; i < 3; ++i) {
        std::cout << " Pop s1: " << s1.pop() << "\n";
        std::cout << " Pop s2: " << s2.pop() << "\n";
    }
    std::cout << "\n";

    Queue<char> q1;
    Queue<> q2;
    q1.push('a');
    q1.push('b');
    q1.push('c');
    q2.push(111);
    q2.push(222);
    q2.push(333);
    for (int i = 0; i <= 3; ++i) {
        std::cout << " Pop q1: " << q1.pop() << "\n";
        std::cout << " Pop q2: " << q2.pop() << "\n";
    }
    return 0;
}

// Stack
template <class StackType, int size>
void Stack<StackType, size>::push(const StackType &obj) {
    if (len == size) {
        std::cerr << " Stack Overflow\n";
        exit(EXIT_FAILURE);
    }
    stck[len] = obj;
    len++;
}
template <class StackType, int size>
StackType Stack<StackType, size>::pop() {
    if (len == 0) {
        std::cerr << " Stack is empty\n";
        exit(EXIT_FAILURE);
    }
    len--;
    return stck[len];
}

// Queue
template <class QueueType, int size>
void Queue<QueueType, size>::push(const QueueType &obj) {
    if (last == size - 1) {
        std::cerr << " Queue Overflow\n";
        exit(EXIT_FAILURE);
    }
    q[++last] = obj;
    if (first == -1) {
        first = 0;
    }
}
template <class QueueType, int size>
QueueType Queue<QueueType, size>::pop() {
    if (first > last || first == -1) {
        std::cerr << " Queue is empty\n";
        exit(EXIT_FAILURE);
    }
    return q[first++];
}