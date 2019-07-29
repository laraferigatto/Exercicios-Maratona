#include <bits/stdc++.h>
using namespace std;

int main()
{
   multiset<int>::iterator it;
   int teste, m,n;
   scanf("%d\n", &teste);
   for (int i = 0; i < teste; ++i)
   {
       vector <int> ans;
       multiset<int> ms;
       scanf("%d%d", &m, &n);
       int add[m+1], get[n+1];
       for (int j = 0; j < m; ++j)
       {
           scanf("%d", &add[j]);
       }

       int k = 0, in = 0, p;
       for (int j = 0; j < n; ++j)
       {
           scanf("%d", &get[j]);
           bool flag = 1;
           for(;k < get[j];k++)
           {
               ms.insert(add[k]);
               if(!k){it = ms.begin();}
               else
               {
                   if(add[k] < *it)
                   {
                       if (!flag)
                       {
                           it--;
                       }
                   }
                   else
                   {
                       if (flag)
                           it++;
                   }
               }
               flag = 0;
           }
           if (flag) it++;
           ans.push_back(*it);
       }
       for (int j = 0; j < ans.size(); ++j)
       {
           printf("%d\n",ans[j]);
       }
       if(i+1 != teste)puts("");
   }

}
