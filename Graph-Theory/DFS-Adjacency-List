const int mx = 1e5+123;
bool vis[mx]; // Array for visited node
vector<int> adj[mx]; // vector for adj list

void dfs ( int u ) // u is the source node
{
    vis[u] =  1; // visited node will be 1

    for ( auto v : adj[u] ) { //adj node of u

        if ( vis[v] == 0 ) {//not visited yet
            dfs ( v ); // dfs the node

        }
    }

    return;
}

int main()
{

    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back ( v );
        adj[v].push_back ( u );
    }

    dfs ( 1 );


 }
