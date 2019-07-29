#include <bits/stdc++.h>

using namespace std;
typedef  pair<int,int> ii;
int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    map <string, map<string, vector <int> > > reg;
    map <string, map<string, vector <int> > >::iterator it;
    map<string, vector <int> >::iterator it2;

    int n;
    scanf("%d", &n);
    int h[24];
    char placa[50], s[50];
    int km;

    for (int i = 0; i < n; ++i)
    {
        reg.clear();
        for (int j = 0; j < 24; ++j)
        {
            scanf("%d ", &h[j]);
        }
        char d[20000];
        string c, str;
        int ho, m, dia;
        string aux;
        while (true)
        {


            gets(d);
            if(!strlen(d)) break;
            //            cout << d << endl;
            sscanf(d, " %s %d:%d:%d:%d %s %d", placa, &ho, &dia, &ho, &m, s, &km);
            //            cout << placa << endl;
            if(reg[placa].find(s) == reg[placa].end())
            {
                if((string)s == "enter")
                {
                    aux = "exit";
                    it2 = reg[placa].find(aux);
                    if( it2 != reg[placa].end())
                    {
                        aux = "exit";
                        if(reg[placa][aux][2] >= dia)
                        {
                            reg[placa][s].push_back(ho);
                            reg[placa][s].push_back(km);
                            reg[placa][s].push_back(dia);
                        }
                        else
                        {
                            reg[placa].erase(it2);
                            reg[placa][s].push_back(ho);
                            reg[placa][s].push_back(km);
                            reg[placa][s].push_back(dia);
                        }
                    }
                    else
                    {
                        reg[placa][s].push_back(ho);
                        reg[placa][s].push_back(km);
                        reg[placa][s].push_back(dia);
                    }

                }
                else
                {
                    it2 = reg[placa].find("enter");
                    if(it2 != reg[placa].end() )
                    {
                        if(reg[placa]["enter"][2] <= dia)
                        {
                            reg[placa][s].push_back(ho);
                            reg[placa][s].push_back(km);
                            reg[placa][s].push_back(dia);
                        }
                        else
                        {
                            reg[placa].erase(it2);
                            reg[placa][s].push_back(ho);
                            reg[placa][s].push_back(km);
                            reg[placa][s].push_back(dia);
                        }
                    }
                    else
                    {
                        reg[placa][s].push_back(ho);
                        reg[placa][s].push_back(km);
                        reg[placa][s].push_back(dia);
                    }
                }

            }
            else
            {
                if((string)s== "enter")
                {
                    if(reg[placa][s][0] > ho)
                        reg[placa][s][0] = ho;
                }
                else
                {
                    if(reg[placa][s][0] < ho)
                        reg[placa][s][0] = ho;
                }
            }



        }


        long double cent;
        long double ped;
        map<string, ii>::iterator it2;
        for (it = reg.begin(); it != reg.end(); it++)
        {
            if(it->second.size() == 2)
            {
                cent = h[it->second["enter"][0]];
                cent = cent/100.0;
                km = abs(it->second["exit"][1] - it->second["enter"][1]);
                ped = cent*km;
                cout << it->first;
                printf(" $%.2Lf\n", ped+3);
            }

        }
        puts("");
    }

}
