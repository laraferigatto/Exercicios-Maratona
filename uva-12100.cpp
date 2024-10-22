
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


int main()
{

   int t, n, m;

   scanf("%d", &t);
   for (int i = 0; i < t; ++i)
   {
       queue <ii> fila;
       scanf("%d%d", &n, &m);
       int vet[n+1];
       for (int j = 0; j < n; ++j)
       {
           scanf("%d", &vet[j]);
           fila.push(ii(vet[j], j));
       }
       ii aux = ii(vet[m], m);
       sort(vet, vet + n);
       int tempo = 0;

       int k = n-1;
       while (!fila.empty())
       {
           if(fila.front().first == vet[k])
           {
               tempo++;
               if(fila.front() == aux) break;
               fila.pop();
                k--;
           }
           else
           {
               fila.push(fila.front());
               fila.pop();
           }
           if(fila.front() == aux && vet[k] < fila.front().first)
           {
               break;
           }

       }
       if(!tempo) tempo = 1;
       printf("%d\n", tempo);
   }
}
