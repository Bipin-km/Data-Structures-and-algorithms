#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;

int isFull()
{
    if ((rear + 1) % SIZE == front)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == rear)
        return 1;
    return 0;
}

void enQueue(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        queue[rear] = element;
        printf("\n Inserted -> %d \n", element);
        rear = (rear + 1) % SIZE;
    }
}

void deQueue()
{
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
    }
    else
    {
        printf("\n Deleted element -> %d \n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

int size()
{
    if (isEmpty())
    {
        return 0;
    }
    else if (front <= rear)
    {
        return rear - front;
    }
    else
    {
        return (SIZE - front + rear) % SIZE;
    }
}

void display()
{
    int i;
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", queue[i]);
        }
        printf("\n Rear -> %d \n", rear);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf(" 1 to Enqueue \n 2 to Dequeue \n 3 to peek front\n 4 to view size \n 5 to display all elements \n 6 to exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int a;
            printf("Enter the element to enqueue : \t");
            scanf("%d", &a);
            enQueue(a);
            break;
        }
        case 2:
            deQueue();
            break;
        case 3:
            printf("%d \n", queue[front]);
            break;

        case 4:
            printf("size -> %d\n", size());
            break;

        case 5:
            display();
            break;

        case 6:
            return (0);
            break;
        case 7:
            printf("%d \n", queue[(((rear - 1) + SIZE) % SIZE)]);
            break;

        default:
            printf("Invalid input!!\n");
            break;
        }
    } 
}