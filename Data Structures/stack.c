#include <stdio.h>

int n = 5;
int stack[];
int TOP = -1;

void push(int x)
{
    if(TOP == n-1)
        printf("Stack Overflow");
    else{
        TOP=TOP+1;
        stack[TOP] = x;
    }
}

void pop()
{
    if(TOP == -1)
        printf("Stack Empty");
    else{
        TOP = TOP - 1;
    }
}

void peak()
{
    if(TOP == -1)
        printf("Stack Empty");
    else{
        printf("%d",stack[TOP]);
    }
}

int isempty()
{
    if(TOP == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(TOP == n-1)
        return 1;
    else
        return 0;
}

void display()
{
    if (TOP == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack Elements: ");
        for (int i = 0; i <= TOP; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, element;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peak\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                peak();
                break;

            case 4:
                if (isempty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is Not Empty\n");
                break;

            case 5:
                if (isfull())
                    printf("Stack is Full\n");
                else
                    printf("Stack is Not Full\n");
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}