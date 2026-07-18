#include<bits/stdc++.h>
using namespace std ; 

struct Stack
{
    int top;
    int size;
    int *arr;
};

Stack* createStack(int size)
{
    Stack *stack = new Stack;

    stack->top = -1;
    stack->size = size;
    stack->arr = new int[size];

    return stack;
}

void push(Stack *s, int value)
{
    if(s->top == s->size - 1)
    {
        cout << "Overflow\n";
        return;
    }

    s->top++;
    s->arr[s->top] = value;

    cout << value << " Pushed !!!!!!" << endl;
}

int pop(Stack *s)
{
    if(s->top == -1)
    {
        cout << "Stack is Empty!!" << endl;
        return -1;
    }

    int value = s->arr[s->top];
    s->top--;

    return value;
}

int peek(Stack *s)
{
    if(s->top == -1)
    {
        cout << "Stack is Empty!!" << endl;
        return -1;
    }

    return s->arr[s->top];
}

bool is_empt(Stack *s)
{
    return s->top == -1;
}

bool is_full(Stack*s)
{
    return s->top == s->size - 1;
}

void display(Stack*s)
{
    if(s->top == -1)
    {
        cout << "Stack is Empty!!" << endl;
        return;
    }

    cout << "Stack Elements : " << endl;

    for(int i = s->top; i >= 0; i--)
    {
        cout << s->arr[i] << endl;
    }
}

void free_memory(Stack*s)
{
    delete[] s->arr;
    delete s;
}

int main()
{
    Stack *s1 = createStack(5);

    push(s1,12);
    push(s1,13);
    push(s1,14);
    push(s1,16);
    push(s1,13);

    cout << endl;   display(s1);        cout << endl;

    int r = pop(s1);
    int r2 = pop(s1);

    cout << "First Pop : " << r << endl;
    cout << "Second Pop : " << r2 << endl;

    cout << "Top Element : " << peek(s1) << endl;

    if(is_empt(s1))
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is NOT Empty" << endl;

    if(is_full(s1))
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is NOT Full" << endl;

    free_memory(s1);

    return 0;
}