#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


int main()
{
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
   map<string, set<string> > tipos;
    map<string, set<string> >::iterator it;
    map<string, set<string> > ans;
    map<string, int> minimo;
    map<string, set<string> >::iterator it2;
    vector <string> ordem;
    int n, c, w, p;
    scanf("%d", &n);
    string s, a;
    for (int i = 0; i < n; ++i)
    {
        tipos.clear();
        ans.clear();
        minimo.clear();
        ordem.clear();
        scanf("%d", &c);        
        for (int j = 0; j < c; ++j)
        {
            cin >> s >> w >> p;

            ans[s];
            minimo[s] = p;
            ordem.push_back(s);
            for (int k = 0; k < w; ++k)
            {
                cin >> a;
                tipos[s].insert(a);
            }
        }
        string b;
        string aux;
        cin.ignore();
        bool  flag;
        while(getline(cin, b), b != "\0")
        {
            flag = 0;
            aux = "";
            int tam = b.size();
            for (int j = 0; j < tam; ++j)
            {
                flag = 0;
                if(b[j] >= 'a' && b[j] <= 'z' || b[j] >= 'A' && b[j] <= 'Z')
                {
                    aux += b[j];
                }
                else
                {
                    flag = 1;
                    if(aux != "")
                    {
                        for (it= tipos.begin(); it != tipos.end(); it++)
                        {
                            if(it->second.find(aux) != it->second.end())
                            {
                                ans[it->first].insert(aux);
                            }
                        }
                    }
                    aux = "";
                }
                if(!flag && j+1 == tam)
                {
                    if(aux != "")
                    {
                        for (it= tipos.begin(); it != tipos.end(); it++)
                        {
                            if(it->second.find(aux) != it->second.end())
                            {
                                ans[it->first].insert(aux);
                            }
                        }
                    }
//                    cout << aux << endl;
                }

            }
        }
        set<string> resp;
        set<string>::iterator it3;

        for (it2 = ans.begin(); it2 != ans.end(); it2++)
        {            
            if(it2->second.size() >= minimo[it2->first] )
            {
                resp.insert(it2->first);
            }
        }
        bool virgula = 0;
        if(resp.empty()) printf("SQF Problem.\n");
        else
        {
			
			if(resp.size() > 1)
			{
				for (int j = 0; j < ordem.size(); ++j)
				{
					it3 = resp.find(ordem[j]);
					if(it3 != resp.end())
					{
						virgula = 1;
						cout << ordem[j];
						resp.erase(it3);
					}
					if(resp.size() > 0 && virgula) cout << ",";
					virgula = 0;


				}
				puts("");
			}
			else
			{
				cout << *resp.begin() << endl;
			}
		}

    }
}
