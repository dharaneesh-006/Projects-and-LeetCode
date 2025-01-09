#include <stdio.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;

//insert at front

void insert_begin (int element)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

//insertion at end

void insert_end (int element)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next=NULL;
    if(head=NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}


//insert at position
void insert_pos(int element,int pos)
{
    struct node *newnode,*temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    pos--;
    if(head == NULL)
    {

    }
    else{
        while(pos != 1)
        {
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}

void display(){
    struct node *temp;
    temp = head;
    if(temp == NULL)
        printf("List is Empty");
    else{
        printf("Elements :");
        while (temp != NULL)
        {
            printf("%d",temp->data);
            temp = temp->next;
        }  
    }
}
int main()
{
    int choice, element, pos;

    while (1) {
        printf("\n\n--- Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at beginning: ");
                scanf("%d", &element);
                insert_begin(element);
                break;

            case 2:
                printf("Enter the element to insert at end: ");
                scanf("%d", &element);
                insert_end(element);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insert_pos(element, pos);
                break;

            case 4:
                printf("Linked List: ");
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
