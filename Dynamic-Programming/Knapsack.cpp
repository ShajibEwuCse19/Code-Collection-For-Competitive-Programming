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




