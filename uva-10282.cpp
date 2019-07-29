
#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	string trad, pala, aux;
	map<string, string> dici;
	int tam;
	while(getline(cin, aux), aux!= "\0")
	{	
		trad = pala = "";
		tam = aux.size();
		for(int i = 0; i < tam; i++)
		{
			if(aux[i] != ' ')
			{
				trad += aux[i];
			}
			else
			{
				i++;
				for(; i < tam; i++)
				{
					pala += aux[i];
				}
			}
		}			
		dici[pala] = trad;	
	}
	while(getline(cin, pala), pala != "\0")
	{
		if(dici.find(pala) == dici.end())
			puts("eh");
		else cout << dici[pala] << "\n";
	}
}
