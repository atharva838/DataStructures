#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Array is empty.\n");
    }
    else
    {
        printf("Array elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}




#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("Element inserted successfully.\n");
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Array is empty.\n");
    }
    else
    {
        printf("Array elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

