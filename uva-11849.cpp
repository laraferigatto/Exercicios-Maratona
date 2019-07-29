#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int ja, ji,a;
	set < int > cd;
	while(scanf("%d%d", &ja, &ji), ja || ji)
	{
		cd.clear();
		for (int i = 0; i < ja; i++)
		{
			cin >> a;
			cd.insert(a);
		}
		int cont = 0;
		for (int i = 0; i < ji; i++)
		{
			cin >> a;
			if(cd.find(a) != cd.end())
				cont++;
			
		}
		printf("%d\n", cont);
}
}
	
	
