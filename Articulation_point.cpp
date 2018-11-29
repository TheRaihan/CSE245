#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool art[100], visited[100];
int low[100], d[100], parent[100], t;

void articulating(int s, bool root)
{
    t++;
    low[s] = d[s] = t;
    visited[s] = true;
    int child = 0;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int v = adj[s][i];

        if (visited[v])
            low[s] = min(low[s], d[v]);

        else
        {
            parent[s] = v;
            articulating(v, false);

            if (d[s] <= low[v] && !root)
                art[s] = true;

            low[s] = min(low[s], low[v]);
            child++;
        }
        
        if (child > 1 && root)
            art[s] = true;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
        if (visited[i] == 0)
            articulating(i, true);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (art[i])
            cnt++;

    cout << cnt << endl;
}