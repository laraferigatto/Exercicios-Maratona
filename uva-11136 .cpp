#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	map<int, int> m;
	int menor, maior;
	map<int, int>::iterator it;
	long long total = 0;
	while(scanf("%d", &n), n)
	{
		total = 0;
		m.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			for (int j = 0; j < a; j++)
			{
				scanf("%d", &b);
				m[b]++;
			}
			it = m.begin();
			menor = it->first;
			m[menor]--;
			if(m[it->first] == 0) m.erase(it);
			it = m.end();
			it--;
			maior = it->first;
			m[maior]--;
			if(m[maior] == 0) m.erase(it);
			total += (maior-menor);	
		
		}
		printf("%lld\n", total);
}
	
}
