#include <stdio.h>
#define MAX 100

int undo[MAX];
int redo[MAX];
int top_Undo = -1;
int top_Redo = -1;

void clearRedo() {
    top_Redo = -1;
}

void performOperation(int op) {
    top_Undo = top_Undo + 1;
    undo[top_Undo] = op;
    clearRedo();
    printf("Performed operation %d\n", op);
}

void undoOperation() {
    if (top_Undo == -1) {
        printf("Nothing to undo!\n");
    } else {
        int op = undo[top_Undo];
        top_Undo = top_Undo - 1;
        top_Redo = top_Redo + 1;
        redo[top_Redo] = op;
        printf("Undo operation %d\n", op);
    }
}

void redoOperation() {
    if (top_Redo == -1) {
        printf("Nothing to redo!\n");
    } else {
        int op = redo[top_Redo];
        top_Redo = top_Redo - 1;
        top_Undo = top_Undo + 1;
        undo[top_Undo] = op;
        printf("Redo operation %d\n", op);
    }
}

void displayStacks() {
    int i;
    printf("\nUndo Stack: ");
    if (top_Undo == -1)
        printf("Empty");
    else
        for (i = 0; i <= top_Undo; i++)
            printf("%d ", undo[i]);

    printf("\nRedo Stack: ");
    if (top_Redo == -1)
        printf("Empty");
    else
        for (i = 0; i <= top_Redo; i++)
            printf("%d ", redo[i]);

    printf("\n");
}

int main() {
    performOperation(10);
    performOperation(20);
    performOperation(30);

    undoOperation();
    redoOperation();

    displayStacks();

    return 0;
}
