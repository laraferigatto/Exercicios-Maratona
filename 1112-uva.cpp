
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int g[110][110];
int N;
void bfsd()
{
    for (int i = 0 ; i < N; i++)
    {
        g[i][i]= 0;
    }

    for(int k = 0;  k < N; k++)
    {
        for(int i = 0;  i < N; i++)
        {
            for(int j = 0;  j < N; j++)
            {
               g[i][j] = min(g[i][j], (g[i][k] + g[k][j]));
            }
        }
    }

}

int main()
{
	 freopen("in", "r", stdin);
      freopen("out", "w", stdout);
    int T;
    int n,m,s, c, a,b, w, E;
    scanf("%d", &c);
    bool flag = false;
    for (int k = 0; k < c; ++k)
    {
        if(flag) puts("");
        memset(g, inf, sizeof g);
        scanf("%d%d%d%d", &N, &E, &T, &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &w);
            a--;b--;
            g[a][b] = w;
            g[b][a] = w;
        }
        bfsd();
        E--;
        int cont = 0;
        for (int i = 0; i < N; ++i)
        {
            if(g[E][i] <= T)cont++;
        }
        printf("%d\n", cont);
        flag = true;
    }

}







