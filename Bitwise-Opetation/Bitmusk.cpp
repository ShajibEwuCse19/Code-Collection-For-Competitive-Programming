
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

int main()
{
    FAST;
   int n;cin>>n;
   int a[n];

   for(int i=0;i<n;i++)cin>>a[i];

  for(int musk = 0; musk<(1<<n); musk++)
  {
      int sum = 0;

      for(int i=0;i<n;i++)
      {
          if((musk&(1<<i)))sum+=a[i];//check all combination using AND. If we get 1 the we'll add it to sum.
          else sum-=a[i];
      }

      if(sum%360 == 0){cout<< "YES" <<endl;return 0;}
  }

   cout<< "NO" <<endl;
}
