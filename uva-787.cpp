#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    int vet[100], a;
    int k=0;
    while(scanf("%d", &a) != EOF)
    {
        if(a == -999999)
        {
            long long soma, resp, ans;
            soma = 1;
            resp = -99999999;
            ans = -99999999;
            for (int j = 0; j < k; ++j)
            {
                soma = 1;
                resp = -99999999;
                for (int i = j; i < k; ++i)
                {
                    soma *= vet[i];
                    ans = max(ans, soma);
                }
                ans = max(ans, resp);

            }
            cout << ans << endl;
            k = 0;
        }
        else vet[k++] = a;
    }
}
