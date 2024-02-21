#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* top = NULL;

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return 0;
    }

    int data = top->data;
    Node* P = top;
    top = top->next;
    free(P);
    return data;
}

int isEmpty() {
    return (top == NULL);
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return 0;
    }

    return top->data;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node* P = top;
    printf("Stack: ");
    while (P != NULL) {
        printf("%d ", P->data);
        P = P->next;
    }
    printf("\n");
}

int main() {
    int option, value;

    while (option != 4) {
        printf("\n\nOption 1: Push \nOption 2: Pop \nOption 3: Display \nOption 4: Exit \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                if (isEmpty()) {
                    printf("Stack is empty. Cannot pop.\n");
                } else {
                    printf("Popped value: %d\n", pop());
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nCode exited\n");
                break;

            default:
                printf("Incorrect option value, please re-enter.\n");
                break;
        }
    }

    return 0;
}
