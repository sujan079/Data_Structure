#include <stdio.h>
#include <stdlib.h>

struct DDL
{
    int data;
    struct DDL *next;
    struct DDL *prev;
};

struct DDL *first = NULL, *last = NULL;

struct DDL *create_newnode(int element)
{
    struct DDL *newnode = (struct DDL *)malloc(sizeof(struct DDL));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void display()
{
    if (first == NULL)
    {
        printf("Empty list\n");
        return;
    }

    struct DDL *temp = first;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertion_at_begin(int element)
{
    struct DDL *newnode = create_newnode(element);
    if (first == NULL) // Empty list
    {
        first = last = newnode;
    }
    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    printf("Element inserted successfully at the beginning: %d\n", element);
}

void insert_at_end(int element)
{
    struct DDL *newnode = create_newnode(element);
    if (first == NULL) // Empty list
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    printf("Element inserted successfully at the end: %d\n", element);
}

int deletion_at_begin()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    struct DDL *temp = first;
    int element = temp->data;

    if (first == last) // Single element
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
        first->prev = NULL;
    }

    free(temp);
    return element;
}

int deletion_at_end()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    struct DDL *temp = last;
    int element = temp->data;

    if (first == last) // Single element
    {
        first = last = NULL;
    }
    else
    {
        last = last->prev;
        last->next = NULL;
    }

    free(temp);
    return element;
}

int deletion_from_spos(int pos)
{
    struct DDL *temp, *tempp;
    int i;

    if (first == NULL)
    {
        printf("List is empty\n");
        return -2;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return -2;
    }

    if (pos == 1) // Deletion at beginning
    {
        return deletion_at_begin();
    }

    temp = first;
    for (i = 1; i < pos - 1; i++)
    {
        if (temp == NULL || temp->next == NULL) // Invalid position
        {
            printf("Invalid position\n");
            return -2;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) // Invalid position
    {
        printf("Invalid position\n");
        return -2;
    }

    if (temp->next == last) // Deletion at end
    {
        return deletion_at_end();
    }

    // Deletion at specific position
    tempp = temp->next;
    temp->next = tempp->next;
    if (tempp->next != NULL) // Adjust prev pointer if not the last node
    {
        tempp->next->prev = temp;
    }
    int element = tempp->data;
    free(tempp);

    return element;
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

    printf("Element deleted from beginning: %d\n", deletion_at_begin());
    display();

    printf("Element deleted from end: %d\n", deletion_at_end());
    display();

    printf("Element deleted from position 2: %d\n", deletion_from_spos(2));
    display();

    return 0;
}
