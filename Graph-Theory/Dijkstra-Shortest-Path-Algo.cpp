const int mx = 1e5+123;
vector<pair<int,int>>adj[mx];///node->{weight,adj node}
int vis[mx];
int dis[mx];///level or distance count.
int n,m;

void dijkstra(int src)
{
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)dis[i] = INT_MAX;
    dis[src] = 0;

    priority_queue<pair<int,int>>pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(vis[u])continue;
        vis[u] = 1;

        for(auto i : adj[u])
        {
            int v = i.first; ///adj node
            int w = i.second;///distance -> u to b ( Source to

            if(dis[u] + w < dis[v]) /// source to u cost = dis[u]. u to v cost (dis[u) + w) and dis[v]. Choose the min cost.
            {
                dis[v] = dis[u] + w;

                pq.push({-dis[v] , v});
            }
        }
    }

}

int main()
{
    FAST;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        ///adj[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++)
    cout<<"Distance "<<1<<" to "<<i<<" is =>"<<dis[i]<<endl;

}

/* Input= node edge weight/distance
5 5
1 2 5
1 3 10
2 3 4
3 5 2
2 4 6
Distance 1 to 1 is =>0
Distance 1 to 2 is =>5
Distance 1 to 3 is =>9
Distance 1 to 4 is =>11
Distance 1 to 5 is =>11
*/


