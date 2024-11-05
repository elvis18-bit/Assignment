#include <stdio.h>

#define MAX 100

int stack[MAX], item;
int ch, top = -1, count = 0, status = 0;

/* PUSH FUNCTION */
void push(int stack[], int item) {
    if (top == (MAX - 1))
        printf("\n\nStack is Overflow");
    else {
        stack[++top] = item;
        status++;
    }
}

int pop(int stack[]) {
    int ret;
    if (top == -1)
        printf("\n\nStack is Underflow");
    else {
        ret = stack[top--];
        status--;
        printf("\nPopped element is \n%d", ret);
    }
    return ret;
}

/* FUNCTION TO CHECK STACK IS PALINDROME OR NOT */
void palindrome(int stack[]) {
    int i, temp;
    temp = status;
    for (i = 0; i < temp; i++) {
        if (stack[i] == pop(stack))
            count++;
    }
    if (temp == count)
        printf("\nStack contents are Palindrome");
    else
        printf("\nStack contents are not palindrome");
}

/* FUNCTION TO DISPLAY STACK */
void display(int stack[]) {
    int i;
    printf("\n\nThe stack contents are:");
    if (top == -1)
        printf("\nStack is Empty");
    else {
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
}

/* MAIN PROGRAM */
int main() {
    do {
        printf("\n\n----MAIN MENU ---\n");
        printf("\n 1. PUSH (Insert) in the Stack");
        printf("\n 2. POP (Delete) from the Stack");
        printf("\n 3. PALINDROME check using Stack");
        printf("\n 4. Exit (End the Execution)");
        printf("\n Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter an element to be pushed:");
                scanf("%d", &item);
                push(stack, item);
                display(stack);
                break;
            case 2:
                item = pop(stack);
                display(stack);
                break;
            case 3:
                palindrome(stack);
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice, please try again.");
                break;
        } // end switch
    } while (ch != 4);
    
    return 0;
}