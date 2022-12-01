#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int items[SIZE], front = -1, rear = -1;

int enqueue(int value)
{
	if (rear == SIZE - 1)
		return -1;
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		items[rear] = value;
		return 0;
	}
}

int dequeue()
{
	if (front == -1)
		return -1;
	else
	{
		front++;
		if (front > rear)
			front = rear = -1;
		return 0;
	}
}

int * getFrontPtr(){
	return &items[front];
}

int main()
{
	int element;
	int* front_ptr;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	dequeue();
	dequeue();

	front_ptr = getFrontPtr();
	element = *(front_ptr+1);
	printf("%d\n", element);

	return 0;
}
