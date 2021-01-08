#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector < int > graph[MX];
bool vis[MX];
int dist[MX];

void bfs(vector<int> sources){
    queue < int > Q;
    // initialization
    for (int i = 0; i < sources.size(); i++){
        int source = sources[i];
        vis[source] = 1;
        dist[source] = 0;
        Q.push(source);
    }

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                vis[next] = 1; // visit
                dist[next] = dist[node] + 1; // update
                Q.push(next); // push to queue
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int numberOfSources;
    cin >> numberOfSources;

    vector<int> sources;
    for (int i = 1; i <= numberOfSources; i++){
        int source; cin >> source;
//        mark[source] = 1; // mark as telephone booth
        sources.push_back(source);
    }

    bfs(sources);

//    cout << "From node " << source << endl;
    for (int i = 1; i <= nodes; i++){
        if (dist[i] == 0) continue; // it is a telephone booth
        cout << "Distance of " << i << " is : " << dist[i] << endl;
    }

    return 0;
}
