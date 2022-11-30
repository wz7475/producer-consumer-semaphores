#include <stdio.h>
#include <stdlib.h>

struct QueueNode
{
    int key;
    struct QueueNode *next;
};

struct Queue
{
    struct QueueNode *front, *rear;
};

/*create new node*/
struct QueueNode *newNode(int value)
{
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    temp->key = value;
    temp->next = NULL;
    return temp;
}

/*init empty queue*/
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void dequeue(struct Queue *queue)
{
    struct QueueNode *temp;
    /*empty queue*/
    if (queue->front == NULL)
        return;

    /*move front one position*/
    temp = queue->front;
    queue->front = queue->front->next;

    /*if queue becomes empty*/
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
}

void enqueue(struct Queue *queue, int value)
{
    struct QueueNode *temp = newNode(value);

    /*case with empty queue*/
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        return;
    }

    /*put at the end*/
    queue->rear->next = temp;
    queue->rear = temp;
}

int getFirst(struct Queue *queue)
{
    return queue->front->key;
}

 int main()
{
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    dequeue(queue);
    int first = getFirst(queue);
    printf("Queue Front : %d \n", first);
    printf("Queue Rear : %d", queue->rear->key);
    return 0;
}