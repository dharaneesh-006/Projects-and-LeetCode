#include <stdio.h>
#define n 5
int queue[5];
int front=-1,rear=-1;

void enqueue(int element)
{
    if(rear == n-1)
        printf("Overflow");
    else{
        if(front == -1)
            front = 0;
        else{
            rear++;
            queue[rear]=element;
        }
    }
}
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Empty");
    }
    else{
        front++;
    }
}
void peak()
{
    if(front == -1 || front > rear)
    {
        printf("Empty");
    }
    else{
        printf("%d",queue[front]);
    }
}
int isempty()
{
    return (front == -1 || front > rear);
}
int isfull()
{
    return (rear == n-1);
}