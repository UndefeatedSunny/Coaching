#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;                                                    // Self Referential Structure.
    int info;
};


void traverse(struct node *head)                                          // Traverse Linked List.
{
    struct node *temp = head;

    printf("\n Start");

    while(temp != NULL)
    {
        printf(" -> %d",temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insert(struct node **head, int data, int pos, int size)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    struct node *current;

    if(pos<1 || pos>(size+1))
    {
        printf("Invalid Position");
        return;
    }
    else
    {
        if(pos == 1)                            // Starting.
        {
            new_node->next = *head;
            new_node->prev = NULL;
            *head = new_node;
            return;
        }
        else if(pos == size)                    // End.
        {
            struct node *last = *head;
            if(*head == NULL)
            {
                *head = new_node;
                return;
            }
            else
            {
                while(last->next != NULL)
                {
                    last->next = new_node;
                }
                last->next = new_node;
                new_node->prev = last;
                return;
            }
        }
        else                                    //  Any Position.
        {
            struct node *temp = *head;
            for(int i=0;i<pos-2;i++)
            {
                temp = temp->next;
            }
            
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next = new_node;
            temp->next->prev = new_node;
        }
    }
}



void delete1(struct node **head, int key)                        //  Deletion of node(input value dependent).
{
    if(*head == NULL)
    {
        printf("No element in the List");
        return;
    }
    
    struct node *temp=*head;
    
    while(temp != NULL && temp->info != key)
    {
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        printf("\nElement not Found\n");
        return;
    }
    else if(temp == *head)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    else if(temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
}


int search(struct node *head, int key)                             // Search in Linked List.
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->info == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


void reverse(struct node **head)
{
    struct node *current = *head;
    struct node *temp = NULL;
    
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }
    if(temp != NULL)
    {
        *head = temp->prev;
    }
}


int main()
{
    int size=0;
    int opt,item,pos;

    struct node *head = NULL;
    struct node *temp = NULL;

    while(1)
    {
        printf("\nLinked List Options:");                           // Options
        printf("\n\tTraverse: 1");
        printf("\n\tInseration: 2");
        printf("\n\tDeletion: 3");
        printf("\n\tSearch: 4");
        printf("\n\tExit: 5");
        printf("\n\tReverse: 6");

        printf("\n\nEnter your option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                traverse(head);
                break;
            case 2:
                printf("\n\t\tEnter item to insert and position: ");
                scanf("%d%d", &item, &pos);
                insert(&head, item, pos, size);                                // Most Important Statement
                size++;
                break;
            case 3:
                printf("\n\t\tEnter item to delete: ");
                scanf("%d", &item);
                delete1(&head, item);
                size--;
                break;
            case 4:
                printf("\n\t\tEnter item to search: ");
                scanf("%d", &item);
                item = search(head, item);
                item ? printf("\nItem found.") : printf("\nItem not found");
                break;
            case 5:
                printf("\n\t\tExiting...");
                exit(0);
            case 6:
                reverse(&head);
                break;
            default:
                printf("\n\t\tInvalid Option");
                break;
        }
    }
}
