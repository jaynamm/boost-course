#include <stdio.h>
#include <cs50.h>

#define MAX 10

// 함수 선언하기
bool isEmpty();
bool isFull();
void push(int value);
void pop();
void display();

// 전역 변수 선언 및 초기화
int front = 0;
int rear = 0;
int queue[MAX];

int main(int argc, char *argv[]) {
    int value;

    while(1) {
        printf("1. 삽입\n2. 삭제\n3. 조회\n4. 종료\n");

        int select = get_int("입력 : ");

        switch(select) {
            case 1:
                value = get_int("입력할 값 : ");
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("종료\n");
                return 0;
        }
        printf("\n");
    }

    return 0;
}

// 큐가 비어있는지 확인하는 함수
bool isEmpty() {
    // front 와 rear 가 같으면 큐가 비어있는 상태를 의미한다.
    if (front == rear) return true;
    else return false;
}

// 큐가 꽉 차있는지 확인하는 함수
bool isFull() {
    // 처음 값과 마지막에 넣어준 다음의 값이 같다면 가득 찬 것을 의미한다.
    if(((rear+1) % MAX) == front) return true;
    else return false;
}

// 큐에 숫자를 넣어주는 함수
void push(int value) {
    // 큐가 꽉 찼는지 확인한다.
    if(isFull()) {
        printf("큐가 꽉 찼습니다.\n");
    } else {
        // rear 위치에 값을 넣어주고
        queue[rear] = value;
        // rear 위치를 하나 증가시켜줍니다.
        rear++; // rear+1 과 같음
    }
}

// 큐에서 숫자를 빼주는 함수
void pop() {
    // 큐가 비어있는지 확인한다.
    if (isEmpty()) {
        printf("큐가 비어있습니다.\n");
    } else {
        // 가장 앞에 있는 값을 꺼낸다.
        printf("꺼내기 : %d\n", queue[front]);
        // front 위치를 하나 증가시켜준다.
        front++;
    }
}

// 큐에 들어있는 숫자를 보여주는 함수
void display() {
    printf("큐 : ");
    for(int i=front; i<rear; i++) {
        //printf("%d\t", i);
        printf("%d ", queue[i]);
    }
    printf("\n");
}
