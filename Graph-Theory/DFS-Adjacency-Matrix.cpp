const int mx = 30;
char a[mx][mx];
int n,m;
int cnt;
bool vis[mx][mx];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


void dfs(int x, int y)
{
    vis[x][y] = 1;

    for(int i=0; i<4; i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if(x1>=1 and x1<=n and y1>=1 and y1<=m and !vis[x1][y1])
            dfs(x1,y1);
    }
}


For Leetcode:
=============
    int mx = 12;
    int a[12][12];
    int n,m;
    int cnt;
    bool vis[12][12];
    
    void dfs(int x, int y)
    {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vis[x][y] = 1;

        for(int i=0; i<4; i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1>=0 and x1<n and y1>=0 and y1<m and !vis[x1][y1] and a[x1][y1]>0)
            {
                cnt = cnt + a[x1][y1];
                
                dfs(x1,y1);
            }
        }
    }
