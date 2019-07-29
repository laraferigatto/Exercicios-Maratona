#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a, aux;
	map<int, int> m;
	vector <int> v;
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		m.clear();
		scanf("%d", &n);
		int ans = 0;		
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a);
			v.push_back(a);
		}
		int k = 0,  s = 0;
		while(k < n)
		{
			if(m.find(v[k]) != m.end() && m[v[k]] >= s && m[v[k]] != k)
			{								
				aux = k;										
				ans = max(ans, (abs(k-s)));
				k = m[v[k]]+1;
				s = k;
				if(s >= aux) m[v[aux]] = aux; 
			}			
			else m[v[k]] = k;
			k++;
						
		}
		ans = max(ans, (abs(k-s)));
		printf("%d\n",  ans);
	}
}
	
