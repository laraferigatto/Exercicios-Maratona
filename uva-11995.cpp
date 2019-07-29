#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    bool vet[3];
    int t, f, n;
    while(scanf("%d", &t) != EOF)
    {
        vet[0] = 1;
        vet[1] = 1;
        vet[2] = 1;
        stack <int> pilha;
        queue <int> fila;
        priority_queue<int> pri;
        for (int i = 0; i < t; ++i)
        {
            scanf("%d%d", &f, &n);
            if(f == 1)
            {
                pilha.push(n);
                fila.push(n);
                pri.push(n);
            }
            else
            {
              if(vet[0] && !pilha.empty() && pilha.top() == n)
                {
                    pilha.pop();
                    vet[0] = 1;
                }
                else vet[0] = 0;

                if(vet[1] && !pri.empty() && pri.top() == n)
                {
                    pri.pop();
                    vet[1] = 1;
                }
                else vet[1] = 0;
                if(vet[2] && !fila.empty() && fila.front() == n)
                {
                    fila.pop();
                    vet[2] = 1;
                }
                else vet[2] = 0;
            }


        }
        int cont = 0;
        string ans = "";
        if(vet[0])
        {
            cont++;
            ans = "stack";
        }
        if(vet[1])
        {
            cont++;
            ans = "priority queue";
        }
        if(vet[2])
        {
            cont++;
            ans = "queue";
        }
        if(cont == 1) cout << ans << endl;
        else if(cont > 1) printf("not sure\n");
        else printf("impossible\n");

    }

}
