#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        next = NULL;
        this->data = data;
    }
};

class Queue
{
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            size++;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        size++;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *toDelete = front;
        front = front->next;
        delete toDelete;
        size--;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty()" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void print()
    {
        Node *temp = front;
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();
    return 0;
}