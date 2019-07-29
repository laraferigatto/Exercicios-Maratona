#include <bits/stdc++.h>
using namespace std;
bool visit[1100];
int main()
{
	
	int m[1100][1100];
	int l, c, e;
	scanf("%d%d%d", &l, &c, &e);
	for (int i = 0; i < l; i++)
	{
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}
	bool flag = 1;
	int num, k, cont;
	for (int i = 0; i < c; i++)
	{
		for(int j = 0; j < l; j++)
		{			
			if(m[j][i] != 0)
			{
				visit[i+1] = 1;
				if(!visit[i])
				{
					num = m[j][i];
					k = j+1;
					cont = 0;
					while(k < l && m[k][i] == 0)
					{
						cont++;
						k++;
					}
					if(k < l && cont < e && num == m[k][i])
					{
						flag = 0;
						j = l;
						i = c;
					}
					j = k-1;
				}
				else
				{
					flag = 0;
					j = l;
					i = c;
				}
				
			}
		}
	}
	printf("%c\n", flag ? 'S' : 'N');
	
}
