
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> ii;

bool ordena(ii a, ii b)
{
	if(a.first > b.first ) return true;
	if(a.first < b.first) return false;
	if(a.first == b.first)
	{
		if (a.second < b.second) return true;
	}
	return false;

}
int main()
{
	vector <ii> im;
	string a,  chave;
	set <string> erros;
	map <string,  set<string> > m;
	map <string,  set<string> >::iterator it;
	set<string>::iterator it2;
	set<string>::iterator achar;
	
	while(getline(cin,a) && a != "0")
	{
		erros.clear();
		m.clear();
		
		while(a != "1")
		{
			if(a[0] >= 'A' && a[0] <= 'Z')
			{
				chave = a;
				m[chave];
			}
			else
			{
				bool flag = 1;
				if(m.size() > 1)
				{	
					if (erros.find(a) != erros.end()) 
					{
						flag = 0;
					}		
					else
					{		
						for (it = m.begin(); it != m.end(); it++)
						{
							for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
							{	
								achar = it->second.find(a);						
								if((achar != it->second.end()) && chave != it->first)
								{
									erros.insert(*achar);							
									it->second.erase(achar);
									flag = 0;
								}
								
							}
						}
				  }
				}
				if(flag)
					m[chave].insert(a);
			}
			getline(cin, a);
		}
		
		
		
		im.clear();
		for (it = m.begin(); it != m.end(); it++)
		{
			im.push_back(ii(it->second.size(), it->first));
		}
		
		sort(im.begin(), im.end(), ordena);
		for (int i = 0; i < im.size(); i++)
		{
			cout << im[i].second << " " << im[i].first << endl;
		}
	}	
	
}
