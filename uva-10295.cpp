#include <bits/stdc++.h>
using namespace std;
int main()
{
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	int n, m, b;
	string a;
	scanf("%d%d", &n, &m);
	map <string, int> ma;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		ma[a] = b;
	}
	int q = 0;
	for (int i = 0; i < m; i++)
	{
		q = 0;
		while(cin >> a && a != ".")
		{
			if(ma.find(a) != ma.end())
			{
				q += ma[a];
			}			
		}	
		printf("%d\n", q); 
	}
	
	
	
}
