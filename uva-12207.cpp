#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int p, c;
    int j, l=1;
    int posi = 1,  k;  
    char a;   
    while(scanf("%d%d", &p, &c), p && c)
    {
        if(c < p) p = c;
    
        deque<int> teste;
        posi = 1;
        printf("Case %d:\n", l++);
      
        for (int i = 1; i <= p; i++)
            teste.push_back(i);
                    
        for (int i = 0; i < c; i++)
        {
            cin >> a;
            if(a == 'N')
            {
                printf("%d\n", teste.front());
                teste.push_back(teste.front());
                teste.pop_front();
            }
            else
            {
                scanf("%d", &k);
                if(k != teste.front())
                {
                    for(j = 0; j < teste.size() && k != teste[j]; j++);
                    teste.erase(teste.begin() + j);
                    teste.push_front(k);
                }
            }           
        }
	}
}
        
        

    
    
