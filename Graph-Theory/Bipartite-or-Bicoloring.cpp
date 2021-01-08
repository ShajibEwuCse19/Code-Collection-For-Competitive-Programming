vector<int>adj[mx];
int col[mx];
int n,m;

bool isBipartite(int s)
{
    memset(col,0,sizeof col);

    col[s] = 1;

    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v : adj[u])
        {
            if(!col[v])
            {
                if(col[u] == 1)col[v] = 2;
                else col[v] = 1;
                q.push(v);
            }

            if(col[v] == col[u])return false;

        }
    }

    return true;
}
