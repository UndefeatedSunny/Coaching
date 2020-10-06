#include<stdio.h>
#include<stdlib.h>

struct node
{
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


void insert(struct node **head, int data, int pos, int size)                // Insertion at any position.
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->next = NULL;

    struct node *current;

    if(pos<0 || pos>(size+1))
    {
        printf("Invalid Position");
        return;
    }
    else
    {
        if(pos==1)
        {
            new_node->next = *head;
            *head = new_node;
            return;

        }
        current = *head;
        for(int i=0;i<pos-2;i++)
        {
            current = current->next;
            if(*head==NULL)
            {
                printf("\nUnable To Insert");
                return;
            }
        }
        if(pos<size)
        {
            new_node->next = current->next;
            current->next = new_node;
        }
        else
        {
           current->next = new_node;
        }
    }
}


void insert_end(struct node **head, int data)                             // Insertion at the end.
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->next = NULL;

    struct node *temp;
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }
    else
    {
        temp = *head;
        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next = new_node;
    }
    return;
}


void delete1(struct node **head, int key)                        //  Deletion of node(input value dependent).
{
    struct node *temp;

    if((*head)->info == key)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    else
    {
        struct node *current = *head;
        while(current->next != NULL)
        {
            if(current->next->info == key)
            {
                temp = current->next;
                current->next = temp->next;
                free(temp);
                return;
            }
            else
            {
                current=current->next;
            }
        }
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
        printf("\n\tInseration End: 2");
        printf("\n\tDeletion: 3");
        printf("\n\tSearch: 4");
        printf("\n\tExit: 5");
        printf("\n\tInseration Any position: 6");

        printf("\n\nEnter your option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                traverse(head);
                break;
            case 2:
                printf("\n\t\tEnter item to insert: ");
                scanf("%d", &item);
                insert_end(&head, item);                                // Most Important Statement
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
                printf("\n\t\tEnter item to insert and position: ");
                scanf("%d%d", &item, &pos);
                insert(&head, item, pos, size);                                // Most Important Statement
                size++;
                break;
            default:
                printf("\n\t\tInvalid Option");
                break;
        }
    }
}
