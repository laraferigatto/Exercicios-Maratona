#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> v;
	vector <int> aux;
	map<vector<int>, int> m;
	int n, a;
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	aux.clear();
	while(scanf("%d", &n) && n)
	{
		m.clear();
		int maior = 1;
		for (int i = 0; i < n; i++)
		{
			v.clear();
			for (int j = 0; j < 5; j++)
			{
				scanf("%d", &a);
				v.push_back(a);			
			}
			sort(v.begin(), v.end());
			m[v]++;				
		}		
		map<vector<int>, int>::iterator it;	
		aux.clear();
		for(it = m.begin(); it != m.end(); it++)
		{
			aux.push_back(it->second);
		}	
		sort(aux.begin(), aux.end());
		maior = aux[aux.size()-1];
		int cont = 0;	
		for (int i = 0; i < aux.size()-1; i++)
		{
			if(aux[i] == aux[i+1] && maior <= aux[i])
			{
				if(cont) 
				{
					cont += aux[i];
				}
				else cont = aux[i] + aux[i+1];
			}				
		}
		if(cont > maior) maior = cont;	
		printf("%d\n", maior);
}
	
}
