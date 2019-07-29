#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> ii;

int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    map<string, long double> m;
    int n, t;
    long double numero;
    string nome, carac, ans;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
    {
        cin >> nome >> numero;
        m[nome] = numero;
    }
    long double  num;
    long double total;
    for (int i = 0; i < t; ++i)
    {
        total = 0;
        cin >> nome >> carac;
        total += m[nome];
        while(carac == "+")
        {
            cin >> nome >> carac;;
            total += m[nome];
        }
        cin >> num;  
        if(carac == "<")
        {
            if((double)total < (double)num) ans = "correct.";
            else ans = "incorrect.";
        }
        else if(carac == "<=")
        {
            if((double)total <= (double)num) ans = "correct.";
            else ans = "incorrect.";
        }
        else if(carac == ">")
        {
            if((double)total > (double)num) ans = "correct.";
            else ans = "incorrect.";
        }
        else if(carac == ">=")
        {
            if((double)total >= (double)num) ans = "correct.";
            else ans = "incorrect.";
        }
        else
        {
            if((double)total == (double)num) ans = "correct.";
            else ans = "incorrect.";
        }
     
        printf("Guess #%d was ", i+1);
        cout << ans << endl;
    }
}








