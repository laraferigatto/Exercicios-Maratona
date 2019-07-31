#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n, m;
long long vet[1001000];
typedef pair<int,int> ii;
map <ii, int> pd;
//~ int pd[1000000][1100];
bool soma(int d)
{
	if(d%m == 0) return 1;
	return 0;
}
int f(int item, int s, bool flag)
{
	if(flag) return 1;
	if(item == n) return 0;	
	if(pd.find(ii(item,s)) != pd.end()) return pd[ii(item,s)];
	return pd[ii(item,s)] = f(item+1, (s + vet[item])%m, soma(s + vet[item])) || f(item+1, s, flag);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &vet[i]);
	}

	printf("%s\n", f(0,0,0) ? "YES" : "NO");
	
 
}
