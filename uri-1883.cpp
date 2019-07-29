#include <bits/stdc++.h>
using namespace std;
int vet[51000];
int n ;
int ans;
int pd[51000];
bool valida(int i, int num, int j)
{

    if((vet[i] < num) || (vet[j] < num) || (i < 0) || j == n) return 0;
    if(num == 1) return 1;
    if((pd[i] != -1 && pd[i] >= vet[i]))return 1;
    return  valida(i-1, num-1, j+1);


}

int main()
{
	
	//~ freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &vet[i]);
    }
    int ans = 1;
    int num;
    memset(pd, -1, sizeof pd);
    for (int i = 0; i < n; ++i)
    {
        num = vet[i];
        while(num > 0)
        {
            pd[i] = 1;
            if(i-(num-1) >=0 && i+(num-1) < n)
            {
                if(valida(i,num, i))
                {
                    ans = max(ans, num);
                    pd[i] = max(pd[i], num);
                    break;
                }
            }
            num--;
        }
    }
    

    cout << ans << endl;
}
