#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class Stack
{
    int *arr;
    int top = -1;

public:
    Stack()
    {
        arr = new int[MAX];
    }
    void push(int data)
    {
        if (top == MAX)
        {
            cout << "Stack is full" << endl;
            return;
        }
        if (top == -1)
        {
            top = 0;
            arr[top] = data;
            top++;
            return;
        }
        arr[top] = data;
        top++;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }
};

int main()
{

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(1);
}