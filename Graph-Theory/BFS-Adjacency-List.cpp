#define MX 110

vector < int > adj[MX];
bool vis[MX];
int dist[MX];

void bfs(int source){

    queue < int > Q;

    // initialization
    vis[source] = 1;
    dist[source] = 0;

    Q.push(source);

    while(!Q.empty()){

        int node = Q.front();
        Q.pop();

        for (int i = 0; i < adj[node].size(); i++){

            int next = adj[node][i];

            if (vis[next] == 0){

                vis[next] = 1; // visit
                dist[next] = dist[node] + 1; // update
                Q.push(next); // push to queue
            }
        }
    }
}
