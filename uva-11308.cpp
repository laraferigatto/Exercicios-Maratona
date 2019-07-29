#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> ii;


int main()
{
	int t, p , k, u;
	map <string, int> ingre;
	vector <ii> s;
	map <string, int>::iterator it;
	string fichario, nome, receita;
	int n,m, orc;
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	scanf("%d ", &t);
	for (int i = 0; i < t; i++)
	{
		ingre.clear();
		s.clear();
		
		getline(cin, fichario);
		scanf("%d%d%d", &m, &n, &orc);
		for (int j = 0; j < m; j++)
		{
			cin.ignore();
			cin >> nome >> p;
			ingre[nome] = p;
		}
		
		for (int j = 0; j < n; j++)
		{
			cin.ignore();
			getline(cin,receita);
			scanf("%d", &k);
			int qt = 0;
			for (int l = 0; l < k; l++)
			{
				cin >> nome >> u;
				qt += (ingre[nome] * u);
				
			}
			if(qt <= orc) 
			{
				s.push_back(ii(qt, receita));
			}
		}
		
		string aux;
		aux = "";
		for (int j = 0; j < fichario.size(); j++)
		{
			if(fichario[j] != ' ' && fichario[j] >= 'a' && fichario[j] <='z')
				aux += (fichario[j]-32);
			else 	aux += fichario[j];
		}
		cout << aux << endl;
		if(s.size() == 0) puts("Too expensive!");
		else
		{
			sort(s.begin(), s.end());
			for(int g = 0; g < s.size(); g++)
			{
				cout << s[g].second << endl;
			}
			
		}
		puts("");
		cin.ignore();
	}
}



