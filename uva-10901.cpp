#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main()
{
    
    freopen("in", "r", stdin);
     freopen("out", "w", stdout);

    int c, t, cap, m, atual;
    int aux;
    scanf("%d", &c);
    int min;
    string direcao;
    for (int i = 0; i < c; ++i)
    {
        queue<ii> left;
        queue<ii> right;

        scanf("%d%d%d", &cap, &t, &m);
        int vet[m+1];
        for (int j = 0; j < m; ++j)
        {
            cin >> min >> direcao;
            if(direcao == "left")
                left.push(ii(min, j));
            else
                right.push(ii(min,j));
        }
        int cont;
        bool r, l,  atr, atl ;
        r = 0;l = 0;

        if(!right.empty() && !left.empty())
        {
            if(left.front().first <= right.front().first)
            {
                atual = left.front().first;
                atl = 1;
            }
            else
            {
                atual = right.front().first + t;
                atl = 0;

            }
        }
        else
        {
           if(left.empty() && !right.empty())
           {
               atual = right.front().first + t;
               atl = 0;
           }
           else
           {
               atual = left.front().first;
               atl = 1;
           }
        }
      while(!right.empty() || !left.empty())
        {
            if(atl)
            {
                if(left.empty()) atl = 0;
                else
                {
                    if(right.empty() && atual < left.front().first) atual = left.front().first;
                    if(r) atual += t;
                    cont = cap;
                    aux = atual + t;
                    while(!left.empty() && left.front().first  <= atual && cont)
                    {
                        vet[left.front().second] = aux;
                        left.pop();
                        cont--;
                        r = 1;
                        l = 0;
                        atl = 0;
                    }
                    if(r) atual += t;
                    else 
                    {
                        if(!right.empty() && !left.empty())
                        {
                            if(left.front().first <= right.front().first)
                            {
								if(left.front().first > atual)
                                {
                                    atual = left.front().first;                                    
                                }							
                                
                                atl = 1;
                            }
                            else
                            {
								if(right.front().first > atual)
									atual = right.front().first;
                                atl = 0;                
                            }
                        }                       
                    }

                }
            }
            else
            {
                if(right.empty()) atl = 1;
                else
                {
                    if(left.empty() && atual < right.front().first) atual = right.front().first;
                    if(l) atual += t;
                    cont = cap;
                    aux = atual + t;
                    while(!right.empty() &&  right.front().first <= atual && cont)
                    {
                        vet[right.front().second] = aux;
                        right.pop();
                        cont--;
                        r = 0;
                        l = 1;
                        atl = 1;
                    }
                    if(l) atual += t;
                    else 
                    {
                        if(!right.empty() && !left.empty())
                        {
                            if(left.front().first < right.front().first)
                            {
								if(left.front().first > atual)
                                {
                                    atual = left.front().first;                                    
                                }  
                                atl = 1;
                            }
                            else
                            {
                                if(right.front().first > atual)
									atual = right.front().first;
                                atl = 0;                
                            }
                        }                       
                    }
                }
            }
        }


        for (int k = 0; k < m; ++k)
        {
            printf("%d\n", vet[k]);
        }
        if(i+1 != c)puts("");
    }

}
