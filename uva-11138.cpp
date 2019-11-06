// A C++ program to find maximal
// Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;
int M,N;
bool bpGraph[1000][1000];
bool visit[1000];
int matchR[1000];
bool bpm( int u)
{
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !visit[v])
        {
            visit[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v]))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM()
{

    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        memset(visit, 0, sizeof(visit));
        if (bpm(u))
            result++;
    }
    return result;
}


int main()
{
    int T;;
    cin >> T;
    int k = 1;
    while(T--)
    {
        cin >> M >> N;

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> bpGraph[i][j];
            }
        }

        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", k, maxBPM());
        k++;
    }
    return 0;
}
