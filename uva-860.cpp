
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    map<string, int> palavras;
    map<string, int>::iterator it;

    string b;
    string aux;
    //cin.ignore();
    bool  flag;
    int cont;

    while(true)
    {
        cont = 0;
        palavras.clear();
        while(getline(cin, b), b != "****END_OF_TEXT****" && b != "****END_OF_INPUT****")
        {
            flag = 0;
            aux = "";
            int tam = b.size();
            for (int j = 0; j < tam; ++j)
            {
                flag = 0;
                //if(b[j] >= 'a' && b[j] <= 'z' || b[j] >= 'A' && b[j] <= 'Z' || b[j] >= '0' && b[j] <= '9' || b == "'" || b == '-')
                if(b[j] != ',' && b[j] != '.' && b[j] != ':'&& b[j] != '!'&& b[j] != '?'&& b[j] != '"'&& b[j] != '('&& b[j] != ')'&& b[j] != ' ')
                {
                    aux += tolower(b[j]);
                }
                else
                {
                    flag = 1;
                    if(aux != "")
                    {
                        cont++;
                        palavras[aux]++;
                    }
                    aux = "";
                }
                if(!flag && j+1 == tam)
                {
                    if(aux != "")
                    {
                        cont++;
                        palavras[aux]++;
                    }
                }
            }
        } 
        if(b !=  "****END_OF_INPUT****")
        {
            cout <<cont << " ";
            long double et;
            et = 0;
            
            for (it = palavras.begin(); it!= palavras.end();it++)
            {
                et += it->second *(log10((int)cont) - log10(it->second));
            }
            et = et*(1.0/cont);
            printf("%.1Lf ", et);

            long double emax;
            emax = 0;
            for (int i = 0; i < cont; ++i)
            {
                emax += 1*(log10((int)cont) - log10(1));
            }
            emax = emax * (1.0/cont);

            long double erel;
            erel = (et/emax)*100;
           erel = round(erel);
            printf("%d\n", (int)erel);
        }
        else break;
    }
}
