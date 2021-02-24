#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; // 왜 이렇게 초기화 했는지 잘 생각해 보세요!
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    // 이 부분을 구현해 주세요!
    // 처음 enqueue를 하게 되면 rear 위치에 들어가고 그 이후에는 순차적으로 값이 들어가게 된다.
    queue->rear = (queue->rear + 1) % (queue->capacity); // 나머지 연산을 통해 들어갈 위치를 구해준다.
    queue->array[queue->rear] = item;
    queue->size++;

    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -9999;
    }
    int item = 0;
    // 이 부분을 구현해 주세요!
    item = queue->array[queue->front];

    // 나머지 연산을 통해 front 의 값을 증가시켜준다.
    queue->front = (queue->front + 1) % (queue->capacity);
    queue->size--;

    return item;
}

// 큐에 대한 내용을 출력하는 함수를 추가했다.
void print_queue(Queue* queue) {
    printf("print items from queue : ");

    for(int i = queue->front; i<=queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }

    printf("\nFront item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);
}


int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));

    print_queue(queue);

    return 0;
}
