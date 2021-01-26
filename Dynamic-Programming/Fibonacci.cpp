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
ll dp[10005];
ll n;

int fn( int n ) {
    if( n == 0 ) return 0;
    if( n == 1 ) return 1;

    if(dp[n] != -1)return dp[n];

    return dp[n] = ( fn(n - 1) + fn(n - 2) );
}

int main()
{
    FAST;

    cin >> n;

    memset(dp,-1,sizeof(dp));

    cout<<fn(n)<<endl;
}

///O(4*n)
