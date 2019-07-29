#include <bits/stdc++.h>
using namespace std;
typedef  pair<int, int> ii;
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    int t, x;
   int a, qb, qg;
   scanf("%d",  &t);
   for (int i = 0; i < t; i++)
   {
       priority_queue <int> b;
       priority_queue <int> g;
       scanf("%d%d%d", &a, &qg, &qb);
       for (int j = 0; j < qg; ++j)
       {
           scanf("%d", &x);
           g.push(x);

       }
       for (int j = 0; j < qb; ++j)
       {
           scanf("%d", &x);
           b.push(x);
       }

       ii vet[a+1];

       while(!g.empty() && !b.empty())
       {
           int cont = 0;
           for (int j = 0; j < a && !b.empty() && !g.empty(); ++j)
           {

//               cout << "itb: " << itb->first << "\n";
//               cout << "itg: " <<  itg->first << "\n";
               if (b.top() > g.top())
               {
                   vet[cont] = ii(b.top() - g.top(), 2);
               }
               else if(b.top() < g.top())
               {
                   vet[cont] = ii(g.top() - b.top(), 1);
               }
               else vet[cont] = ii(0,0);
                cont++;

                b.pop();
                g.pop();

           }
           for (int j = 0; j < cont; ++j)
           {
               if(vet[j].first != 0)
               {
                   if(vet[j].second == 1)
                   {
                       g.push(vet[j].first);
                   }
                   else b.push(vet[j].first);
               }
           }
       }
       if(!g.empty())
       {
           printf("green wins\n");
           while(!g.empty())
           {
               printf("%d\n", g.top());
               g.pop();
           }
       }
       else if(!b.empty())
       {
           printf("blue wins\n");
           while(!b.empty())
           {
               printf("%d\n",b.top());
               b.pop();
           }
       }
       else printf("green and blue died\n");
       if(i+1 != t)puts("");
   }


}
