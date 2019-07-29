#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, r;
	map <string, string> m;
	string p, s;
	scanf("%d ", &n);

	for (int i = 0; i < n; i++)
	{
		
		getline(cin,p);	
		getline(cin,s);	
		m[p] = s;
	}
		
	scanf("%d ", &r);
	for (int i = 0; i < r; i++)
	{		
		getline(cin,p);
		cout << m[p] << endl;
	}
	
	
}
