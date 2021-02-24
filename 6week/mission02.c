#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    // 이 부분을 구현해 주세요!
    StackNode* node = createStackNode(data);

    if ((*root) == NULL) { // root 노드가 NULL 일 경우
        (*root) = node;
    }

    node->next = (*root); // node 가 root 노드는 가리킨다.
    (*root) = node;       // root 노드에 node 를 할당해준다. = root 노드를 node 로 옮겨준다.

    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    int popped;
    // 이 부분을 구현해 주세요!
    StackNode* tmp = (*root); // 임시로 root 노드를 저장해둔다.

    popped = tmp->data; // 꺼낼 값을 저장한다.
    (*root) = tmp->next; // root 노드를 다음 값의 위치로 옮겨준다.

    free(tmp); // 메모리를 해제해주면서 노드를 삭제한다.

    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
