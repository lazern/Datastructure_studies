#include <stdio.h>
#include <stdlib.h>

// For Queue Size
#define SIZE 50

// A tree node
struct node{
    int data;
    struct node *left, *right;
};

struct Queue{
    int front, rear;
    int size;
    struct node* *array;
};

// A utility function to create a new Queue
struct Queue* createQueue(int size){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node**)malloc(queue->size*sizeof(struct node));

    for(int i=0; i< size; i++)
        queue->array[i] = NULL;

    return queue;
};


int isFull(struct Queue* queue){
    return queue->rear == queue->size -1;

}

int isEmpty(struct Queue* queue){
    return queue->front == -1;
}

int hasOnlyOneItem(struct Queue* queue){
    return queue->front == queue->rear;
}


struct node* getFront(struct Queue* queue){
    return queue->array[queue->front];
}

void Enqueue(struct node *root, struct Queue* queue){

    if(isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if(isEmpty(queue))
        ++queue->front;
}

struct node* Dequeue(struct Queue* queue){

    if(isEmpty(queue))
        return NULL;

    struct node* tmp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
		queue->front = queue->rear = -1;
	else
		++queue->front;

	return tmp;
}

struct node* newNode(int data){

    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
};

// Function to insert a new node in complete binary tree
void insert(struct node** root, int data, struct Queue* queue){

    // Create a new node for given data
    struct node* tmp = newNode(data);

    // If the tree is empty, initialize the root with new node.
    if (!*root){
        *root = tmp;
    }

    else {
        //get the front of the queue
        struct node* front = getFront(queue);

        // If the left child of this front node does not exist, set the
		// left child as the new node
        if(front->left == NULL)
            front->left = tmp;

        // If the right child of this front node does not exist, set the
		// right child as the new node
        else if(front->right == NULL)
            front->right = tmp;

        // If the front node has both the left child and right child,
        else
            Dequeue(queue);
    }

    // Enqueue() the new node for later insertions
        Enqueue(tmp,queue);
}

int main()
{
    struct node *root = NULL;
    struct Queue *queue = createQueue(SIZE);

    for(int i=1; i < 12; i++)
        insert(&root,i,queue);

    return 0;
}
