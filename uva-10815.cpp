#include <bits/stdc++.h>
using namespace std;
int main()
{
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    string a, aux, aux2, aux3;
    set <string> s;
    string ifen;
    bool flag = 0, flag2=0;
    while(cin >> a)
    {
        if(a != " " && a != "\n" )
        {
            if(a[a.size()-1] == '-')
            {
                for(int i = 0; i < a.size()-1; ++i)
                {
                    if(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z'|| a[i] == '-')
                    {
                        ifen += tolower(a[i]);
                    }
                    else if(i < a.size()-1 && a[i+1]  >= 'a' && a[i+1]  <= 'z' || a[i+1]  >= 'A' && a[i+1]  <= 'Z'|| a[i+1] == '-')
                    {
						if(ifen != "")
                        s.insert(ifen);
                        ifen = "";
                    }
                }
            }
            else
            {
                if(ifen == "")
                {
                    aux = "";
                    for(int i = 0; i < a.size(); ++i)
                    {
                        if(a[i] >= 'a' && a[i] <= 'z' || (a[i] >= 'A' && a[i] <= 'Z') || a[i] == '-')
                            aux += tolower(a[i]);
                        else if(i < a.size()-1 && a[i+1]  >= 'a' && a[i+1]  <= 'z' || a[i+1]  >= 'A' && a[i+1]  <= 'Z'|| a[i+1] == '-')
                        {
							if(aux != "")
                            s.insert(aux);
                            aux = "";
                        }
                    }
					if(aux != "")
                    s.insert(aux);
                }
                else
                {

                    for(int i = 0; i < a.size(); ++i)
                    {
                        if(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z' || a[i] == '-')
                        {
                            ifen += tolower(a[i]);
                        }
                        else if(i < a.size()-1 && a[i+1]  >= 'a' && a[i+1]  <= 'z' || a[i+1]  >= 'A' && a[i+1]  <= 'Z'|| a[i+1] == '-')
                        {
							if(ifen != "")
                            s.insert(ifen);
                            ifen = "";
                        }
                    }
                    if(ifen != "")
                    s.insert(ifen);
                    //~ cout << ifen << endl;
                    ifen = "";
                }
            }
        }


    }
    set <string>::iterator it;
    for(it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }



}
