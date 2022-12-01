#include <bits/stdc++.h>
using namespace std;

void lamportsClock(int e1, int e2, vector<vector<int>> m)
{

    cout << "Displaying schedule of events and messages : \n";
    vector<int> p1(e1, -1);
    vector<int> p2(e2, -1);
    for (int i = 0; i < e2; i++)
    {
        cout << "\te2" << i + 1;
    }
    for (int i = 0; i < e1; i++)
    {
        cout << "\ne1" << i + 1 << "\t";
        for (int j = 0; j < e2; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }

    for (int i = 0; i < e1; i++)
    {
        p1[i] = i + 1;
    }

    for (int i = 0; i < e1; i++)
    {
        p2[i] = i + 1;
    }

    for (int i = 0; i < e1; i++)
    {
        for (int j = 0; j < e2; j++)
        {
            if (m[i][j] == 1)
            {
                p2[j] = max(p2[j], p1[i] + 1);
                for (int k = j + 1; k < e2; k++)
                {
                    p2[k] = p2[k - 1] + 1;
                }
            }

            if (m[i][j] == -1)
            {
                p1[i] = max(p1[i], p2[j] + 1);
                for (int k = i + 1; k < e1; k++)
                {
                    p1[k] = p1[k - 1] + 1;
                }
            }
        }
    }
    cout << "Time stamps of events in proess P1:"
         << "\n";
    for (int i = 0; i < e1; i++)
    {
        cout << p1[i] << " ";
    }
    cout << "\n";

    cout << "Time stamps of events in proess P2:"
         << "\n";
    for (int i = 0; i < e2; i++)
    {
        cout << p2[i] << " ";
    }
    cout << "\n";
}

void NTP(int h1, int m1)
{
    cout << "Hours and minutes in UTC are : " << h1 << " :  " << m1 << '\n';

    int t1, t2, t3, t4;
    cout << "Enter t1 : ";
    cin >> t1;
    cout << "Enter t2 : ";
    cin >> t2;
    cout << "Enter t3 : ";
    cin >> t3;
    cout << "Enter t4 : ";
    cin >> t4;

    float delay = 9999, offset = 9999;

    for (float i = -0.3; i < 0.4; i += 0.1)
    {
        float del = (float)(((t4 + i) - (t1 + i)) - ((t3 + i) - (t2 + i))) / (float)2;
        float offs = (float)(((t2 + i) - (t1 + i)) + ((t3 + i) - (t4 + i))) / (float)2;

        if (delay > abs(del))
        {
            delay = abs(del);
            offset = offs;
        }
    }

    cout << "Delay for secondary server is  : " << int(delay) << "\n";
    cout << "offset for secondary server is  : " << int(offset) << "\n";

    m1 += offset;

    while (abs(m1) >= 60)
    {
        h1++;
        m1 = abs(m1) - 60;
    }

    cout << "New time for Secondary server after adding offset : " << h1 << " : " << m1;
}

int main()
{
    vector<vector<int>> m;
    int ch;

    int h1, m1;

    cout << "Enter choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:

        int ele;
        int e1, e2;
        cout << "Enter number of events in P1: ";
        cin >> e1;
        // cout << "\n";
        cout << "Enter number of events in P2: ";
        cin >> e2;

        cout << "Enter scheduling of events and messages: " << endl;
        for (int i = 0; i < e1; i++)
        {
            vector<int> temp;
            for (int j = 0; j < e2; j++)
            {
                cin >> ele;
                temp.push_back(ele);
            }
            m.push_back(temp);
        }

        lamportsClock(e1, e2, m);
        break;

    case 2:

        cout << "Hours in UTC : ";
        cin >> h1;

        cout << "minute in UTC : ";
        cin >> m1;

        NTP(h1, m1);
        break;
    default:
        break;
    }
}