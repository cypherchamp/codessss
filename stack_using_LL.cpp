#include <iostream>
using namespace std;

class Node
{

public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            top->next = NULL;
            return;
        }
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        Node *toDelete = top;
        top = top->next;
        delete toDelete;
    }
    void print()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    return 0;
}