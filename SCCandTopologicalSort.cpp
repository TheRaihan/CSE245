#include <bits/stdc++.h>
#define N 100
#define white 10
#define grey 11
#define black 12

using namespace std;

int graph[N][N], graphT[N][N], color[N], d[N], f[N], pr[N], V, t, T;
int colorT[N];
int a, b, scc = 0;
bool visited[N];

vector<int>topo;
typedef pair<int,int> iPair;

void dfsT(int vertex)
{
    visited[vertex] = true;
    colorT[vertex] = grey;
    T = T + 1;

    // cout << vertex << " ";

    for(int i=1; i<=V; i++)
    {
        if(colorT[i] == white && graphT[vertex][i] == 1)
        {
            cout << i << " ";
            dfsT(i); 
        }
    }


    T = T + 1;
    colorT[vertex] = black;
}

void SCC()
{
    priority_queue< iPair, vector<iPair> > pq;
    for(int i=1; i<=V; i++)
    {
        pq.push(make_pair(f[i], i));    //Pair(finishing time of the node, node)
    }

    for(int x : visited)
    {
        visited[x] = false;
    }

    cout << "Strongly connected componets: " << endl;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(visited[u] == false){
            cout << u << ": ";
            scc++; 
            dfsT(u);
            cout << endl;
        }  
        
    }

     cout << "Number of Strongly connected componets: " << scc << endl;

    

}



void dfs(int vertex)
{
    color[vertex] = grey;
    t = t + 1;
    d[vertex] = t;

    // cout << vertex << " ";

    for(int i=1; i<=V; i++)
    {
        if(color[i] == white && graph[vertex][i] == 1)
        {
            pr[i] = vertex;
            dfs(i); 
        }
    }


    t = t + 1;
    color[vertex] = black;
    f[vertex] = t;

    topo.insert(topo.begin(), vertex);
    
}


void dfsSearch()
{

    for(int i=1; i<=V; i++)
    {
        if(color[i] == white)
        dfs(i);

    }
}


int main()
{

    for(int i=0; i<N; i++)
    {
        d[i] = f[i] = INT_MAX;
        pr[i] = -1;
        color[i] = white;
        colorT[i] = white;
    }

    FILE *fi = fopen("data.txt", "r");

    fscanf(fi, "%d", &V);

    while(1)
    {
        

        fscanf(fi, "%d%d", &a, &b);

        if(a <= 0 || b <= 0)
            break;

        if(a > V || b > V)
        {
            cout << "Invalid input " << endl;
            continue;
        }

        graph[a][b] = 1;
        graphT[b][a] = 1;
    }


    
    dfsSearch();


    cout << endl << "Topologically sorted: ";
    for(int i=0; i<topo.size(); i++)
    {
        cout << topo[i] << " ";
    }

    cout << endl;

    SCC();

    cout << "Finishing time: ";
    for(int i=1; i<=V; i++)
    {
        cout << f[i] << " ";
    }

    return 0;
}