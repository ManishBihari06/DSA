#include <stdio.h>
#include <stdlib.h>

struct Node {
    int songID;
    struct Node* next;
};

struct Node* createNode(int id) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->songID = id;
    new->next = NULL;
    return new;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->songID);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* reverseSegment(struct Node* head, int m, int n) {
    if (!head || m >= n)
        return head;

    struct Node *prev = NULL, *curr = head;
    for (int i = 1; i < m; i++) {
        prev = curr;
        curr = curr->next;
    }

    struct Node* segmentStart = prev;
    struct Node* tail = curr;
    struct Node* next = NULL;

    for (int i = 0; i <= n - m; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (segmentStart)
        segmentStart->next = prev;
    else
        head = prev;

    tail->next = curr;
    return head;
}

int main() {
    struct Node* head = createNode(101);
    head->next = createNode(102);
    head->next->next = createNode(103);
    head->next->next->next = createNode(104);
    head->next->next->next->next = createNode(105);
    head->next->next->next->next->next = createNode(106);
    head->next->next->next->next->next->next = createNode(107);

    printf("Original Playlist:\n");
    printList(head);

    head = reverseSegment(head, 2, 5);

    printf("Modified Playlist:\n");
    printList(head);

    return 0;
}
