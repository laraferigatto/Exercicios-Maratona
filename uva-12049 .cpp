#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int t, n,m,a;
	map <int, int> na;
	map<int, int> ma;
	map<int, int>::iterator it;
	map<int, int>::iterator itm;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		ma.clear();
		na.clear();
		scanf("%d%d", &n, &m);
		for(int j =0; j < n; j++)
		{
			scanf("%d", &a);
			na[a]++;
		}
		int cont = 0;
		for(int j =0; j < m; j++)
		{
			scanf("%d", &a);
			if(na.find(a) != na.end())
			{
				ma[a]++;
			}
			else
				cont++;
		}
		vector <int > aux;
		if(ma.size() > 0)
		{
			for(it = na.begin(); it != na.end(); it++)
			{
				aux.push_back(it->first);							
			}	
			for(int j = 0; j < aux.size(); j++)
			{
				it = ma.find(aux[j]);
				if(it == ma.end())
				{	
					it = na.find(aux[j]);		
					cont += it->second;
					na.erase(it);
				}	
			}		
			for(it = na.begin(), itm = ma.begin(); it != na.end(); it++, itm++)
			{
				if(it->second != itm->second)
				{
					cont += abs(it->second - itm->second);
				}
			}
			printf("%d\n", cont);
		}
		else 
		{
			for(it = na.begin(); it != na.end(); it++)
			{
				cont += it->second;
			}
			printf("%d\n", cont);
		}
	}	
}
