#include <stdio.h>

struct node{
    int data;
    struct node *next,*prev;
};
struct node *head=NULL,*tail=NULL;

//delete at front
void delete_begin()
{
    if(head == NULL)
    {
        printf("No element to Display...");
    }
    else{
        struct node *del;
        del = head;
        head = head->next;
        head->prev=NULL;
        free(del);
        display();
    }
}
//delete at end
void delete_end()
{
    if(head == NULL)
    {
        printf("list is empty");
    }
    else{
        struct node *temp;
        temp = tail;
        tail = tail->prev;
        tail->next=NULL;
        free(temp);
        display();
    }
    
}
//delete at position
void delete_pos(){
    if(head == NULL)
    {
        printf("list is empty");
    }
    else{
        struct node *temp,*del;
        temp = head;
        int pos;
        printf("Enter the POsition ");
        scanf("%d",&pos);
        if(pos == 0)
        {
            printf("Cant delete");
        }
        else{
            pos--;
            for (int i = 0; i < pos-1; i++)
            {
               temp = temp->next;
            }
            del = temp->next;
            temp->next = del ->next;
            del->next = NULL;
            free(del); 
            display();
        }
    }
}


//insert at front
void insert_begin (int element)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
        display();
    }
}

//insertion at end

void insert_end (int element)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next=NULL;
    newnode->prev = NULL;
    if(head==NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        display();
    }
}


//insert at position
void insert_pos(int element,int pos)
{
    struct node *newnode,*temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;
    pos--;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else{
        while(pos != 1)
        {
            temp = temp->next;
            pos--;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        display();
    }

}

void displayrev(){
    struct node *temp;
    temp = tail;
    if(head == NULL)
        printf("List is Empty");
    else{
        printf("Elements :");
        while (temp != NULL)
        {
            printf("%d",temp->data);
            temp = temp->prev;
        }  
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
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
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
                printf("Deleting from the beginning...\n");
                delete_begin();
                break;

            case 5:
                printf("Deleting from the end...\n");
                delete_end();
                break;

            case 6:
                printf("Deleting from a position...\n");
                delete_pos();
                break;

            case 7:
                printf("Linked List: ");
                display();
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            case 8:
                printf("Reverse");
                displayrev();
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
