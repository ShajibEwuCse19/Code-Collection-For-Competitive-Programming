Capacity Max to min:
=====================

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
#define err              1e-9
#define MAXL ((ll)1e18 + 5)
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 1e5+123;
ll dp[105][mx];
int vol[105],pro[mx],n; ///vol = volume, pro = profit/weight, n = total index;

ll Knapsack(int idx , int rem)
{
    if(rem < 0) return -MAXL; /// Capacity will not be negative.(Impossible Answer).
    
    if(idx > n)return dp[idx][rem] = 0; ///Current index > Max index then return back; (Base Case).

    if(dp[idx][rem] != -1)return dp[idx][rem]; ///if the value is calculated before.

    ll ans = -MAXL; /// initial ans negative (small value).

    if(rem >= vol[idx]) ///Remaining Capacity >= Capacity of Current index.
    {
        int tmp = rem - vol[idx]; /// Remaining Capacity will be updated.

        ans = pro[idx] + Knapsack(idx + 1 , tmp); /// Ans will be updated.
    }

    ans = max (ans , Knapsack(idx + 1 , rem)); ///Restore Max Ans from all possible Ans.

    return dp[idx][rem] = ans; ///Return Max Ans.
}

int main()
{
    FAST;

    int capacity;
    cin >> n >> capacity;///total index and Max Capacity(volume).

    for(int i = 1; i <= n; i++)cin >> pro[i] >> vol[i];

    memset(dp , -1 , sizeof dp);

    cout << Knapsack(1 , capacity) << endl; ///start from index 1 and Max Cap.

    return 0 ;
}

/// O ( n * Capacity )


Capacity Min to Max:
======================
    #include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;
long long dp[123][mx];

int p[123], w[123];
int Sz, n;

long long solve ( int i, int curW ) ///curW =  Current Weight(Capacity)--> Initially 0.
{
    if ( i > n ) return 0;///Current Index(i) > Max Index(n)
    if ( dp[i][curW] != -1 ) return dp[i][curW]; ///Already Calculated.

    long long ret1 = 0, ret2 = 0;

    if ( w[i] + curW <= Sz ) ret1 = p[i] + solve ( i+1, w[i] + curW ); ///Increast Current Weight and Add the Profit to Ans for the weight.
    ret2 = solve ( i+1, curW ); /// If w[i] + CurW > Sz then go to next index.

    return dp[i][curW] = max ( ret1, ret2 ); ///Return the max answer from ret1 and ret2.
}


int main()
{
    cin >> n >> Sz; ///n = max Index and Sz = Total Capacity.
    for ( int i = 1; i <= n; i++ ) {
        cin >> w[i] >> p[i]; ///Input Weight and Profit.
    }

    memset ( dp, -1, sizeof ( dp ) );
    cout << solve ( 1, 0 ) << endl; ///from index 1 and Capacity 0.

    
}


