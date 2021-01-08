int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 25;
string adj[mx];
int lev[mx][mx];//distance

void bfs(int x, int y)//source
{
    memset(lev,-1,sizeof lev);
    lev[x][y] = 0;//source distance is 0

    queue<pair<int,int>>q;
    q.push({x,y});

    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int x1 = a + dx[i];
            int y1 = b + dy[i];

            if(min(x1,y1)<0 || x1>=n || y1>=m || lev[x1][y1]!=-1) continue;

            lev[x1][y1] = lev[a][b] + 1; //dis[present] = dis[prev]+1
            q.push({x1,y1});

        }
    }
}
