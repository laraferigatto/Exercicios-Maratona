
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, amigos;
    map<int, int> am;
    map<int, int>::iterator it;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d", &amigos);
        for (int j = 0; j < amigos; ++j)
        {
            int a, b;
            scanf("%d", &a);
            for (int k = 0; k < a; ++k)
            {
                scanf("%d", &b);
                it = am.find(b);
                if(it != am.end())
                {
                    am.erase(it);
                }
                else
                {
                    am[j] = b;
                }
            }
        }
        for(it = am.begin(); it != am.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }

    }
}
