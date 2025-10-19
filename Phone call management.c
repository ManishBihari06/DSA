#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void addCall(int customerID) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue is full. Please wait.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = customerID;
    printf("Call added: %d\n", customerID);
}

void removeCall() {
    if (front == -1) {
        printf("No calls to remove.\n");
        return;
    }

    printf("Removed customer: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void displayQueue() {
    if (front == -1) {
        printf("No customers in queue.\n");
        return;
    }

    printf("Customers in queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    addCall(101);
    addCall(102);
    addCall(103);
    addCall(104);
    addCall(105);
    displayQueue();

    addCall(106);

    removeCall();
    removeCall();
    displayQueue();

    addCall(106);
    addCall(107);
    displayQueue();

    return 0;
}
