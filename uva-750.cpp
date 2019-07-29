#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int m[8][8];
int row[8], TC, a, b, lineCounter; 
bool place(int r, int c) 
{
    for (int prev = 0; prev < c; prev++)
    {
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
		
	}
	return true; 
}


int soma;
int ans = 0;
void backtrack(int c) 
{
	
    if (c == 8 ) 
    {  
		soma = 0;      
        for (int j = 0; j < 8; j++) 
        {
			soma += m[row[j]][j];
			
		}
        ans = max(ans, soma);
       
    }
    for (int r = 0; r < 8; r++) 
    {
        if (place(r, c))
        { 
            row[c] = r; backtrack(c + 1);
        } 
	}
 }
int main() 
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    scanf("%d", &TC);
    while (TC--) {
        for (int i = 0; i < 8; i++)
		{
			for(int j =0 ; j < 8; j++)
			{
				scanf("%d", &m[i][j]);
			}
			
		}
		
        memset(row, 0, sizeof row); 
        lineCounter = 0;
     ans = 0;
        backtrack(0);
        
        printf("%5d\n", ans);
    } 
    } 
