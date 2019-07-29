#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> pilha;
    vector <char> s;
    string p;
    int j = 1;
    while(cin >> p && p != "end")
    {
        s.clear();
        int tam = p.size();
        for (int i = 0; i < tam; ++i)
        {
            pilha.push(p[i]);
        }
        char aux;
        bool ans = 0;
        int i = 0;
        while (!pilha.empty())
        {
			aux = pilha.top();
            pilha.pop();
            
			for(i=0; i < s.size() && s[i] > aux; i++);
			if(i < s.size())
			{
				s[i] = aux;
			}
			else
			{
				s.push_back(aux);
			}			
        }
        if (s.size() > 0) printf("Case %d: %d\n", j, s.size());
        else printf("Case %d: %d\n", j, 1);
        j++;
    }
}
