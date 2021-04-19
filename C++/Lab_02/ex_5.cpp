#include <iostream>
using namespace std;

class q_type {   
    int size, index;
    int head, tail;
    int *queue;
public:
    q_type(int size);
    ~q_type();
    void q(int);
    int deq();
};

q_type::q_type (int size) {
    this->size = size;
    queue = new int[size];
    index = 0;
    head = 0;
    tail = 0;
}

q_type::~q_type(){
    delete[] queue;
}

void q_type::q (int num) {
    if (index > size) {
        cout << "Queue is FULL" << endl;
    } else {
        queue[tail] = num;
        if (tail + 1 < size)
            tail++;
        else
            tail = 0;
        index++;
    }
}

int q_type::deq () {
    if (index <= 0) {
        return -1;
    }
    if (head + 1 < size) {
        head++;
        index--;
        return queue[head - 1];
    } else {
        index--;
        return queue[head];
    }
}

int main () {
    q_type q_type(100);
    for(int j = 0; j < 100; j++)
        q_type.q(j);
    for(int j = 0; j < 100; j++)
        cout << q_type.deq() << "   ";
    return 0;
}
