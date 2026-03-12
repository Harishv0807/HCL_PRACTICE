#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int node)
{
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];

        if(!visited[next])
            dfs(next);
    }
}

int main()
{
    int n, m;
    cout << "Enter nodes and edges: ";
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }

    cout << "Connected Components: " << count;
}