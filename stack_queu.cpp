#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> v{5, 4, 3, 2, 1};
    queue<int> q1;
    queue<int> q2;
    for (int i = 0; i < v.size(); i++)
    {
        q1.push(v[i]);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    return 0;
}