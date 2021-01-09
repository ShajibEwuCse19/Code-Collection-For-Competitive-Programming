
#include<bits/stdc++.h>
#define N ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX ((int)2e9 + 5)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long

using namespace std;

vector < pair < int , int > > vec[N]; //first element is adj node and second element is distance.

//all comment is applicable for first dfs--> to find farthest node(X) from root(A).

pair < int , int > dfs(int n , int par) //n = root node(A) and par = parent of root node.
{
    pair < int , int > ans = {0,n};
    for(auto p:vec[n]){
        int a = p.first , c = p.second ;
        if(a != par){
            pair < int , int > tmp = dfs(a,n);
            tmp.first += c;
            ans = max(ans , tmp); // distance of farthest node(X).
        }
    }
    return ans;//dfs will return a pair with most distance node and distance.
}

int main()
{
    int n ;
    cin>>n;
    for(int i = 1 ; i<n ; i++){
        int a , b , c;
        cin>>a>>b>>c;
        vec[b].push_back({a,c});
        vec[a].push_back({b,c});
    }
    
    int a = dfs(1,0).second;//to find distance root node(A) to farthest node(X). a = farthest node (X).
    
    pair < int , int > ans = dfs(a,0);//to find distance from (X) to (Y)  which is the Diameter of the Tree.
    return 0;
}
