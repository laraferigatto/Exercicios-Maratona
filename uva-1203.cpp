#include <bits/stdc++.h>

using namespace std;
typedef  pair<int,int> ii;
typedef pair<ii, int> ii2;
typedef vector<ii2> vi;
int main()
{
    priority_queue<ii2, vi, greater<ii2> > fila;
    string r = "";
    int id, t;
    while(cin >> r && r != "#")
    {
        cin >> id >> t;
        fila.push(ii2(ii(t, id), t));
    }
    int cont;
    cin >> cont;
    ii2 aux;
    while(cont--)
    {
        cout << fila.top().first.second << endl;
        aux = fila.top();
        fila.pop();
        fila.push(ii2(ii((aux.first.first + aux.second), aux.first.second), aux.second));
    }

}
