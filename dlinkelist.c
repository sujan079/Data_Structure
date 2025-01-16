#include <stdio.h>
#include <stdlib.h>
struct DDL
{
    int data;
    struct DDL *next;
    struct DDL *prev;
};
struct DDL *first, *last = NULL;
struct DDL *create_newnode(int element)
{

    struct DDL *newnode = (struct DDL *)malloc(sizeof(struct DDL));

    if (newnode == NULL)
        return NULL;
    else
    {
        newnode->data = element;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }
};
void display()
{
    struct DDL *temp;
    if (first == NULL)
        printf("Emptylist\n");
    else
    {
        temp = first;
        do
        {
            printf("%d-->", temp->data);
            temp = temp->next;

        } while (temp != NULL);
        printf("NUll\n");
    }
}

void insertion_at_begin(int element)
{
    struct DDL *newnode = create_newnode(element);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    if (first == NULL) // if the list is already empty
    {
        first = last = newnode;
    }
    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    printf("Element inserted successfully at the beginning\n");
}
void insert_at_end(int element)
{

    struct DDL *newnode = create_newnode(element);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    printf("Element sucessfully at the end\n");
}
int deletion_at_begin()
{
    int element;

    struct DDL *temp;
    if (first == NULL)
    {
        printf("list is empty");
        return -1;
    }
    else if (first == last) // if there is only one element
    {
        temp = first;
        first = last = NULL;
    }

    else

    {
        temp = first;
        first = first->next;
        first->prev = NULL;
        element = temp->data;
    }
    free(temp);
    return element;
}

int deletion_at_end()
{
    struct DDL *temp;
    if (first == NULL)
    {
        printf("list is empty");
    }
    else if (first->next == NULL) // if there is only one element
    {
        temp = first;
        first = last = NULL;
        int element = temp->data;
        free(temp);
        return element;
    }
    else
    {
        temp = last;
        last = last->prev;
        last->next = NULL;
        int element = temp->data;
        free(temp);
        return element;
    }
}
int deletion_from_spos(int pos)
{
    struct DDL *temp, *prev, *tempp;
    int i;
    if (first == NULL)
    {
        printf("list is empty\n");
        return -2;
    }

    if (pos == 1)
    {
        deletion_at_begin();
    }
    if (pos < 1)
    {
        printf("Invalid position\n");
    }
    else
    {
        temp = first;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid position\n");
        }
        if (temp->next == last)
        {
            deletion_at_end();
        }
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            (temp->next)->prev = temp;
            int element = tempp->data;
            free(tempp);

            return element;
        }
    }
}

int main()
{
    insertion_at_begin(10);
    insertion_at_begin(50);
    insertion_at_begin(70);

    display();

    insertion_at_begin(20);
    display();

    insert_at_end(30);
    display();

    printf("Element deleted is  from begining:%d\n", deletion_at_begin());

    display();
    printf("Element deleted at end i.e.%d\n", deletion_at_end());
    display();
    printf("Element deleted position 2 i.e.%d\n", deletion_from_spos(2));
    display();

    return 0;
}