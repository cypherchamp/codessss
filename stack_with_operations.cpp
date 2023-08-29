#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *prev;
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{

    Node *top;
    int size;
    Node *mid;

public:
    Stack()
    {
        top = mid = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = mid = newNode;
            size++;
            return;
        }
        newNode->next = top;
        top->prev = newNode;
        top = newNode;
        size++;
        if (size % 2 == 0)
        {
            mid = mid->prev;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack empty" << endl;
            return;
        }
        top = top->next;
        size--;
        if (size % 2 == 0)
        {
            mid = mid->next;
        }
    }
    int middle()
    {
        if (top == NULL)
        {
            return -1;
        }
        return mid->data;
    }
    void del()
    {
        if (top == NULL)
            return;
        Node *toDel = mid;
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;
        if (size % 2 == 0)
        {
            mid = mid->next;
        }
        else
        {
            mid = mid->prev;
        }
        delete toDel;
    }
    void print()
    {
        if (top == NULL)
            return;
        // while(top!=NULL)
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.middle() << endl;
    st.print();
    st.del();
    st.print();

    cout << st.middle() << endl;
}