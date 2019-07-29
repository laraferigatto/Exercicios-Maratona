#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, t, s, d;
	string a;
	map <string, int> ma;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ma.clear();
		scanf("%d", &m);
		for(int j = 0; j <m ; j++)
		{		
			cin >> a >> t;
			ma[a] = t;
		}
		scanf("%d", &d);
		cin >> a;
		if(ma.find(a) == ma.end())
		{
			printf("Case %d: Do your own homework!\n", i+1);
		}
		else if(ma[a] <= d) printf("Case %d: Yesss\n", i+1);
		else if(ma[a] <= d+5) printf("Case %d: Late\n", i+1);
		else printf("Case %d: Do your own homework!\n", i+1);
	}
}

	
	
