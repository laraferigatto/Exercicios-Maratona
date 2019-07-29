#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
map <string, vs> adjlist;
typedef pair<string, string> ii;
map <string, string> m;
void dfs(string filho)
{
    for(int i = 0; i < adjlist[filho].size(); i++)
    {
        string u = adjlist[filho][i];
        if(m.find(u) == m.end())
        {
            dfs(u);
        }
    }
    if((m[adjlist[filho][0]] == "dominant"  && m[adjlist[filho][1]] == "dominant" )||
            (m[adjlist[filho][0]] == "dominant"  && m[adjlist[filho][1]] == "recessive")||
            (m[adjlist[filho][0]] == "recessive" && m[adjlist[filho][1]] == "dominant" ))
    {
        m[filho] = "dominant";
    }
    else
    {
         if((m[adjlist[filho][0]] == "recessive"  && m[adjlist[filho][1]] == "non-existent") ||
            (m[adjlist[filho][0]] == "non-existent"  && m[adjlist[filho][1]] == "recessive") ||
            (m[adjlist[filho][0]] == "non-existent"  && m[adjlist[filho][1]] == "non-existent"))
            m[filho] = "non-existent";
        else
            m[filho] = "recessive";
    }


}
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    map <string, ii> filhos;
    map <string, ii>::iterator it;
    map <string, string>::iterator it2;
    string nome, gene;
    vs fi;
    for (int i = 0; i < t; ++i)
    {
        cin >> nome >> gene;
        if(gene == "recessive" || gene == "dominant" || gene == "non-existent") m[nome] = gene;
        else fi.push_back(gene);
        adjlist[gene].push_back(nome);

    }
    for (int j = 0; j < fi.size(); j++)
    {
       dfs(fi[j]);
    }

    //o gene da criança é dominante se, e somente se, o gene for dominante em ambos os
    //pais ou dominante em um e recessivo no outro genitor.

   
    for (it2 = m.begin(); it2 != m.end(); ++it2)
    {
        cout << it2->first << " " << it2->second << "\n";
    }

}
