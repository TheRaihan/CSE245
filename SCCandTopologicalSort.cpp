//Singly Connected Component and Topological sort for Directed graph

#include<bits/stdc++.h>
using namespace std;

#define White 0
#define Grey 1
#define Black 2
#define inf 1/0.0

int a,b,i,vertex,edge,d[100],f[100],color[100],colorT[100],adj[100][100],t,pre[100],SCC,graphT[100][100];
vector<int>topo;
void dfs(int node)
{
    d[node] = ++t;
    color[node] = Grey;

    for(int i=1;i<=vertex;i++)
    {
        if(adj[node][i])
            if(color[i] == White){
                pre[i] = node;
                dfs(i);
                // printf("%d-",i);
            }
    }
    topo.insert(topo.begin(),node);

    color[node] = Black;
    f[node] = ++t; 

}

void dfsT(int node, bool scc)
{
    colorT[node] = Grey;
    if(!scc) cout << node << " " ;
    for(int i=1;i<=vertex;i++)
    {
        if(graphT[node][i])
            if(colorT[i] == White){
                dfsT(i,false);
                // printf("%d-",i);
            }
    }

    colorT[node] = Black;

}

void  transpose()
{
    for(int i=1;i<=vertex;i++)
        for(int j=1;j<=vertex;j++)
            if(adj[i][j])
                graphT[j][i] = 1;

}

int main()
{
    freopen("data.txt","r",stdin);
    memset(pre,-1,sizeof(pre));
    memset(d,inf,sizeof(pre));
    memset(f,inf,sizeof(pre));
    
    cout << "Input Number of vertex: " ;
    cin >> vertex;

    while(1)
    {
        cout << "Edge " << i+1 << ": " ;

        cin >> a >> b;
        if(a==0 || b==0) break;
        if(a>vertex || b > vertex)
            cout << "Invalid Input" << endl;

        else{
            adj[a][b] = 1;
            // adj[b][a] = 1;
            i++;
        }
    }
    cout << endl<< endl ;

    transpose();


    for(int i=1;i<=vertex;i++)
        if(color[i]==White)
            dfs(i);

    for(int i=0;i<topo.size();i++)
        if(colorT[topo[i]] == White)
        {
            cout << topo[i] << ": " ;
            dfsT(topo[i],true);
            cout << endl;
            SCC++;
        }

    cout << "\nTotal SCC: " << SCC <<endl;

    // for(int i =1;i<=vertex;i++)
    //     cout << "Discovering and finishing time of node " << i 
    //         << "---> " << d[i] << "/" << f[i] << endl ;

    cout << "\nTopological Sort: ";
    for(int i = 0; i<topo.size();i++)
        cout << topo[i] << " ";
    cout << endl << endl;



    return 0;
}