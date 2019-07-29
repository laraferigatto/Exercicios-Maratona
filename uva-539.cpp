#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int v, a;
vector <int> g[100];
bool visit[100];
int dist[100];
int fixo;
void bfs(int t)
{
	queue<int> fila;
	visit[t] = 1;
	dist[t] = 0;
	fila.push(t);
	while(!fila.empty())
	{
		int atual = fila.front();
		fila.pop();
		for (int i = 0; i < g[atual].size(); i++)
		{
			int u = g[atual][i];
			if(dist[u] <= dist[atual] && u != fixo)
			{				
				dist[u] = dist[atual] + 1;			
			}	
			if(!visit[u])
			{
				fila.push(u);
				visit[u] = 1;
			}		
		}
		
	}
		
}
int main()
{
	int b,c;
	while(scanf("%d%d", &v, &a), v && a)
	{
		for (int i = 0; i < a; i++)
		{
			scanf("%d%d", &b, &c);
			g[b].push_back(c);
			g[c].push_back(b);
		}
		memset(dist, 0, sizeof dist);
		fixo = 0;
		bfs(0);
		for (int i = 0; i < v; i++)
		{
			printf("%d ", dist[i]);
		}
		puts("");
		
		
	}
	
}
