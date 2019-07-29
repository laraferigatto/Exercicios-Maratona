#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> ii;
bool ordena(string a, string b)
{
    if(a[0] == b[0])
    {
        if(a.size() < b.size() ) return true;
        if(a.size() > b.size() ) return false;
        if(a.size() == b.size() && a < b) return true;
        if(a.size() == b.size() && a > b) return false;
    }
    if(a[0] != b[0] && a < b) return true;
    if(a[0] != b[0] && a > b) return false;
    
}
int main()
{
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    int t;
    map <string, string> velho;
    map <string, string>::iterator it;
    map <int, string>::iterator it2;
    map<string, string>novo;
    scanf("%d", &t);
    vector <string> impAdd, impRet, impAlt;
    
    
    string  chave, num, cadeia;
    
    for (int i = 0; i < t; i++)
    {
        novo.clear();
        velho.clear();
        impAdd.clear();
        impAlt.clear(); impRet.clear();
        
        
        chave = num = "";
        cin >> cadeia;
        for (int j = 1; j < cadeia.size(); )
        {
            while(j < cadeia.size() && cadeia[j] != ':' && cadeia[j] != '}')
            {
                chave += cadeia[j];
                j++;
            }
            j++;
            while(j < cadeia.size() && cadeia[j] != ',' && cadeia[j] != '}')
            {
                num += cadeia[j];
                j++;
            }
            if(j < cadeia.size()) velho[chave] = num;
            chave = num = "";
            j++;
        }
        cin >> cadeia;
        for (int j = 1; j < cadeia.size(); )
        {
            while(j < cadeia.size() && cadeia[j] != ':' && cadeia[j] != '}')
            {
                chave += cadeia[j];
                j++;
            }
            j++;
            while(j < cadeia.size() && cadeia[j] != ',' && cadeia[j] != '}')
            {
                num += cadeia[j];
                j++;
            }
            if(j < cadeia.size()) novo[chave] = num;
            chave = num = "";
            j++;
        }
        
        for(it = velho.begin(); it != velho.end(); it++)
        {
            if(novo.find(it->first) == novo.end())
            {
                impRet.push_back( it->first);
                
            }
            else
            {
                if(it->second != novo[it->first])
                {
                    impAlt.push_back(it->first);
                }
            }
        }
        for(it = novo.begin(); it != novo.end(); it++)
        {
            if(velho.find(it->first) == velho.end())
            {
                impAdd.push_back(it->first);
            }
            
        }
        
        
        bool a = 0;
        int tam;
        tam = impAdd.size();
        if(tam > 0)
        {
            a = 1;
            sort(impAdd.begin(),  impAdd.end());
            printf("+");
            for (int l = 0; l < tam; ++l)
            {
                cout << impAdd[l];
                if(l+1 < tam) printf(",");
            }
            puts("");
        }
        tam = impRet.size();
        if(tam > 0)
        {
            a = 1;
            sort(impRet.begin(),  impRet.end());
            printf("-");
            for (int l = 0; l < tam; ++l)
            {
                cout << impRet[l];
                if(l+1 < tam) printf(",");
            }
            puts("");
        }
        tam = impAlt.size();
        if(tam > 0)
        {
            a = 1;
            sort(impAlt.begin(),  impAlt.end());
            printf("*");
            for (int l = 0; l < tam; ++l)
            {
                cout << impAlt[l];
                if(l+1 < tam) printf(",");
            }
            puts("");
        }
        
        if(!a) puts("No changes");
        puts("");
        
        
    }
    
}
