#include <bits/stdc++.h>
using namespace std;
int n;
int pd[110][110];
string a, b;


int sub(int i, int j, int ta, int tb)
{
    if(i == ta || j == tb) return 0;
    if(pd[i][j] != -1) return pd[i][j];
    if(a[i] == b[j]) return pd[i][j] = 1+sub(i+1,j+1,ta,tb);
    return pd[i][j] = max(sub(i+1, j, ta, tb),  sub(i, j+1, ta, tb));

}

int main()
{
    int t = 1;
    while(getline(cin, a), a != "#")
    {
        getline(cin, b);
        memset(pd, -1, sizeof pd);
        cout <<"Case #" << t << ": " << "you can visit at most " << sub(0,0,a.size(),b.size()) << " cities.\n";
        t++;
    }

}
