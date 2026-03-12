#include <iostream>
#include <stack>
using namespace std;

int adj[100][100];   // adjacency matrix
bool visited[100];
stack<int> st;
int n;

void dfs(int node)
{
    visited[node] = true;

    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }

    st.push(node);
}

int main()
{
    int m;
    cout << "Enter nodes and edges: ";
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;   // edge from u to v
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    cout << "Topological Order: ";

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}