#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next; // this is
};
struct SLL *first, *last = NULL;
struct SLL *create_newnode(int element)
{

    struct SLL *newnode = (struct SLL *)malloc(sizeof(struct SLL));
    if (newnode == NULL)
        return NULL;
    else
    {

        newnode->data = element;
        newnode->next = NULL;
        return newnode;
    }
};
void display()
{
    struct SLL *temp;
    if (first == NULL)
        printf("Empty List!\n");
    else
    {
        temp = first;
        do
        {

            printf("%d-->", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("Null\n");
    }
}

void insert_at_beginning(int element)
{
    struct SLL *newnode = create_newnode(element);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        newnode->next = first;
        first = newnode;
    }
    printf("Element inserted successfully at the beginning \n");
}
void insert_at_end(int element)
{
    struct SLL *newnode = create_newnode(element);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
    printf("Element inserted successfully at the end \n");
}
void deletion_at_beginning()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
        printf("Element deleted successfully at beginning\n");
    }
}
void deletion_at_end()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(last);
        last = temp;
        printf("Element deleted successfully at end \n");
    }
}
void deletion_at_specific_position(int position)
{
    struct SLL *temp, *prev;
    int i;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = first;
        for (i = 1; i < position; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("Element deleted successfully at position %d\n", position);
    }
}
void insertion_at_specific_position(int position, int element)
{
    struct SLL *newnode, *temp, *prev;
    int i;
    newnode = create_newnode(element);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        temp = first;
        for (i = 1; i < position; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
        printf("Element inserted successfully at position %d\n", position);
    }
}
int main()
{
    int element;
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_end(30);
    display();
    deletion_at_specific_position(2);
    display();
    return 0;
}