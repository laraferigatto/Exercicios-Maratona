#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	vector <int> ans;
	char c;
	int j, n;
	j=0;
	map<int, int> m;
	while (scanf ("%d", &n) != EOF)
	{
		
		if(m.find(n) == m.end())
		{
			ans.push_back(n);
			j++;
		}
		m[n]++;
		c = getchar ();
		
	}
	
			for(int i =0; i < j; i++)
			{				
				printf("%d %d\n", ans[i], m[ans[i]] );
			}
			
		
			
	
		
	
	
	
}
