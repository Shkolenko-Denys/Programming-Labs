#include <stdio.h>
#include <stdlib.h>
typedef struct queue queue;
typedef struct elem elem;

struct elem {
    int data;
    elem *next;
};

struct queue { 
    elem *head;
    elem *tail; 
}; 

void q (queue *q, int value) { 
    elem *temp = (elem*)malloc(sizeof(elem)); 
    temp->data = value;
    if (q->head == NULL) {
        q->head = temp; 
    } else {
        q->tail->next = temp;
    }
    q->tail = temp; 
    q->tail->next = q->head; 
} 

int deq (queue *q) { 
    if (q->head == NULL) {  
        return 0; 
    }
    int value; 
    if (q->head == q->tail) { 
        value = q->head->data; 
        free(q->head); 
        q->head = NULL; 
        q->tail = NULL; 
    } else { 
        elem *temp = q->head; 
        value = temp->data; 
        q->head = q->head->next; 
        q->tail->next= q->head; 
        free(temp); 
    } 
    return value ; 
}

void show (queue *q) {
    if (!q || !q->head)
        return; 
    elem *temp = q->head; 
    printf("Dates: "); 
    for ( ; temp->next != q->head; temp = temp->next) { 
        printf("%d ", temp->data);  
    } 
    printf("%d\n", temp->data);
} 

int main (void) {
    queue *myqueue = (queue*) malloc(sizeof(queue));
    myqueue->head = NULL;
    myqueue->tail = NULL;

    q(myqueue, 10);
    q(myqueue, 11);
    q(myqueue, 20);
    q(myqueue, 30);
    q(myqueue, 40);
    show(myqueue);

    deq(myqueue);
    show(myqueue);
    deq(myqueue);
    show(myqueue);

    deq(myqueue);
    deq(myqueue);
    show(myqueue);

    free(myqueue);
    return 0;
}