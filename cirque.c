#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct cirque
{
	int front;
	int rear;
	int data[MAX];
} q;
void enqueue(struct cirque *q, int element)
{
	if (q->front == (q->rear + 1) % MAX)
	{
		printf("Queue is full\n");
		exit(0);
	}
	else
	{
		q->data[q->rear] = element;
		q->rear = (q->rear + 1) % MAX;
	}
}

int main()
{
	int element;
	q.front = 0;
	q.rear = 0;
	int i=5;
	while (i!=0)
	{

		printf("Enter the element that you want to add to the queue:");
		scanf("%d", &element);
		enqueue(&q, element);
		i=i-1;
	}

	return 0;
}
