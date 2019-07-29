#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	char p = '%';
    set<int> selos;
    set<int>::iterator its;
    map<int, int>::iterator it;
    map <int,int> unicos;
    int k, n, m, a;
    long double totalUnicos, aux;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        selos.clear();
        unicos.clear();
        scanf("%d", &n);
        aux = 0;
        int vet[n+2];
        for (int j = 0; j < n; ++j)
        {
            cin >> m;
            vet[j+1] = 0;
            for (int l = 0; l < m; ++l)
            {
                scanf("%d", &a);
                it = unicos.find(a);
                if(it == unicos.end() && selos.find(a) == selos.end())
                {
                    unicos[a] = j+1;
                    vet[j+1]++;
                    selos.insert(a);
                }
                else
                {
                    if(it != unicos.end() && it->second != j+1)
                    {
                        vet[it->second]--;
                        unicos.erase(it);
                    }
                }

            }
        }
        totalUnicos = 0;

        for (int j = 1; j <= n; ++j)
        {
            totalUnicos += vet[j];
        }
        printf("Case %d: ", i+1);      
        if(totalUnicos > 0)
        {
            for (int j = 1; j <= n; ++j)
            {
                aux = ((vet[j]*100)/totalUnicos);
                printf("%.6Lf%c",aux, p);
                if(j < n) printf(" ");

            }
        }
        puts("");
        //        cout << totalUnicos << endl;


    }
}
