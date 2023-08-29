#include <bits/stdc++.h>
using namespace std;

class Arr
{

    int *data;
    int nextIndex;
    int capacity;

public:
    Arr()
    {
        data = new int[1];
        nextIndex = 0;
        capacity = 1;
    }
    Arr(Arr const &a) // copy constructor to avoid shallow copy
    {
        this->nextIndex = a.nextIndex;
        this->capacity = a.capacity;
        this->data = new int[a.capacity];
        for (int i = 0; i <= a.capacity; i++)
        {
            this->data[i] = a.data[i];
        }
    }

    void operator=(Arr const &a) // copy assignment operator
    {
        this->nextIndex = a.nextIndex;
        this->capacity = a.capacity;
        this->data = new int[a.capacity];
        for (int i = 0; i < a.capacity; i++)
        {
            this->data[i] = a.data[i];
        }
    }

    void newArr()
    {
        int *tempArr = new int[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            tempArr[i] = data[i];
        }
        delete[] data;
        data = tempArr;
        capacity *= 2;
    }
    void push(int x)
    {
        if (nextIndex == capacity)
        {
            newArr();
        }

        data[nextIndex] = x;
        nextIndex++;
    }
    int get(int i)
    {
        if (i < nextIndex)
        {

            return data[i];
        }
        return -1;
    }
    void add(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            push(element);
        }
        else
        {
            return;
        }
    }
    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Arr a1;
    a1.push(10);
    a1.push(20);
    a1.push(30);
    a1.print();
    Arr a2 = a1;
    a1.add(0, 100);
    a2.print();
    a1.print();
    return 0;
}