#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3
vector <int> g[25100];
int cont;
int dist[25100];
int bigger, day, ans;
void dfs(int v)
{
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		cont = 0;; bool flag = 1;
		for (int i = 0; i < (int)g[current].size(); i++)
		{
			int u = g[current][i];						
			//if(dist[u] == inf)			//{
				
				cont++;
				if(dist[u] == inf)
				{
					dist[u] = dist[current]+1;
					q.push(u);
				}
			//}			
		}
		if (bigger < cont)
		{
			bigger = cont;
			ans = dist[current];
		}
	}
}

int main()
{
	int e, n,a;
	scanf("%d", &e);
	for (int i = 0; i < e; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a);
			g[i].push_back(a);

			
		}
		dist[i] = inf;			
	}
	cout << "saiu\n";
	int t;
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &a);
		bigger = day = 0;	
		dfs(a);
		cout << bigger << " " << ans << endl;
		for (int i = 0; i <= e; i++)
		{
			dist[i] = inf;			
		}
		
	}
	
	
}

