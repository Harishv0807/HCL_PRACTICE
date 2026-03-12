#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[100];

int main()
{
    int n, m;
    cout << "Enter nodes and edges: ";
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back({v,0}); 
        adj[v].push_back({u,1}); 
    }

    vector<int> dist(n+1, 1e9);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto x : adj[node])
        {
            int next = x.first;
            int cost = x.second;

            if(dist[node] + cost < dist[next])
            {
                dist[next] = dist[node] + cost;
                q.push(next);
            }
        }
    }

    cout << "Minimum Reversals: " << dist[n];
}