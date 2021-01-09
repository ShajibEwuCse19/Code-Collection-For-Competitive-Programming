//Md. Shajibul Islam..
//East West University, CSE Department'19

#include<bits/stdc++.h>
using namespace std;
#define FAST             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl             '\n'
#define loop(i,n)        for(int i=0;i<n;i++)
#define CASE_PRINT       cout<<"Case "<<C<<": "
#define CASE_PRINT2      cout<<"Case "<<C<<":"<<endl
#define ll               long long
#define ld               long double
#define Pi               2*acos(0.0) // acos(-1.0)
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 1e5+123;
vector<pair<int,int>>adj[mx]; //first element is adj node and second element is distance.

//all comment is applicable for first dfs --> to find farthest node(X) from root(A).

pair<int,int> dfs(int n,int par)
{
    pair<int,int>ans = {0,n};

    for(auto i : adj[n]) //n = root node(A) and par = parent of root node.
    {
        int a = i.first, dis = i.second;

        if(a != par)
        {
            pair<int,int>tmp = dfs(a,n);

            tmp.first = tmp.first + dis; 

            ans = max(ans,tmp); // distance of farthest node(X).
        }
    }

    return ans; //dfs will return a pair with most distance node and distance.
}

int main()
{
    FAST;
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int u,v,w;cin>>u>>v>>w; // u connect with v with w weight.
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int A = dfs(1,0).second; //to find distance root node(A) to farthest node(X). a = farthest node (X).

    pair<int,int>ans = dfs(A,0); //to find distance from (X) to (Y)  which is the Diameter of the Tree.

    cout<<ans.first<<" "<<ans.second<<endl;
}

/*
8
1 2 1
2 3 1
2 4 1
3 5 1
1 6 1
6 8 1
6 7 1
7 9 1

output = 6,5; 6 = distance 5(X) to 9(Y). 5 = X
*/




