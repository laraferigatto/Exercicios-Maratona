#include <iostream>
#include<algorithm>

#define ll long long

using namespace std;


int n, dollars;
int v[1001000];





int main()
{

    int t; scanf("%d", &t);
    for(int c = 0; c < t; c++)
    {
        scanf("%d%d", &n, &dollars);

        for(ll i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(dollars - v[i] >= 0)
            {
                dollars -= v[i];
                ans++;
            }
            else i = n;
        }


        printf("Case #%d: %d\n", c+1, ans);

    }
}
