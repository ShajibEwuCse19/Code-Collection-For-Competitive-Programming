Exercise: Given n and r. Determine cCr using Dynamic Programming.

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
#define err              1e-9
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 105;
ll dp[mx][mx];

ll ncr(ll n, ll r)
{
    if(n < 0 || r < 0)return 0; ///-1C3 = inf (impossible).

    if(dp[n][r] != -1)return dp[n][r];

    if(r > n)return 0; ///3C4 = 0.
    else if(r==0)return 1; ///0C0 = 1 , nc0 = 1 etc.
    else return dp[n][r] = ncr(n - 1 , r) + ncr(n - 1 , r - 1); /// ncr = (n-1)Cr + (n-1)C(r-1) -> formula.
}

int main()
{
    FAST;
    memset(dp , -1 , sizeof dp);
    ll n , r;
    cin >> n >> r;

    cout<<ncr(n,r)<<endl;
}


/// O(n*n*4)
