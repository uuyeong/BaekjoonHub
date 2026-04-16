#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// 큐 초기화
void initQueue(Queue *queue, int capacity) {
    queue->data = (int *)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
}

// 큐 정리 (메모리 해제)
void destroyQueue(Queue *queue) {
    free(queue->data);
}

// 큐가 비었는지 확인
int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

// 큐가 가득 찼는지 확인 (순환 큐)
int isFull(Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// 큐에 데이터 추가
void push(Queue *queue, int value) {
    if (isFull(queue)) {
        return; // 큐가 가득 찼으면 무시
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

// 큐에서 데이터 제거
int pop(Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // 큐가 비어있으면 -1 반환
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return value;
}

// 큐의 맨 앞 데이터 반환
int front(Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // 큐가 비어있으면 -1 반환
    }
    return queue->data[queue->front];
}

// 큐의 맨 뒤 데이터 반환
int back(Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // 큐가 비어있으면 -1 반환
    }
    // rear는 다음 위치를 가리키므로, 마지막 데이터를 가져오기 위해 -1 계산
    return queue->data[(queue->rear - 1 + queue->capacity) % queue->capacity];
}

// 큐의 크기 반환
int size(Queue *queue) {
    return (queue->rear - queue->front + queue->capacity) % queue->capacity;
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar(); // 버퍼 클리어

    Queue queue;
    initQueue(&queue, n + 1); // 순환 큐를 위해 +1

    for (int i = 0; i < n; i++) {
        char command[20];
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "push", 4) == 0) {
            int value = atoi(&command[5]);
            push(&queue, value);
        } else if (strcmp(command, "pop\n") == 0) {
            printf("%d\n", pop(&queue));
        } else if (strcmp(command, "size\n") == 0) {
            printf("%d\n", size(&queue));
        } else if (strcmp(command, "empty\n") == 0) {
            printf("%d\n", isEmpty(&queue));
        } else if (strcmp(command, "front\n") == 0) {
            printf("%d\n", front(&queue));
        } else if (strcmp(command, "back\n") == 0) {
            printf("%d\n", back(&queue));
        }
    }

    destroyQueue(&queue);
    return 0;
}
