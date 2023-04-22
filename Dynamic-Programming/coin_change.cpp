const int mx = 1e5+123;
int n , dpp[105][mx] , val[105];

int call(int idx , int tot)/// current index and total amount
{
    if(tot < 0) return 0; /// negative total
    if(idx > n){ /// cross the total index
        if(tot == 0) return 1; /// 0+0 = 0
        return 0;
    }
    if(dpp[idx][tot] != -1) return dpp[idx][tot]; /// already calculated [optimization]
    int ans = 0;
    ///call(idx + 1 , tot) -> res from idx+1 to n without taking val[idx]. total will not change here
    ///call(idx + 1 , tot - val[idx]) -> res from idx+1 to n with taking val[idx]. total will be reduce by val[idx]
    ans = call(idx + 1 , tot) | call(idx + 1 , tot - val[idx]); /// If any one get answer, ans will be true
    return dpp[idx][tot] = ans; /// save the result for memorization
}

int main()
{
    int tot;
    cin>>n>>tot;
    for(int i = 1 ; i<=n ; i++) cin>>val[i];
    memset(dpp,-1,sizeof dpp);
    if(call(1,tot)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

Example: If we have coin = 1, 2, 10, 3, 5. Is it possible to create 13 in total using some coins. We can consider one coin exactly one time only.
Ans: vol[] = {1,2,10,3,5}
     total = 13
     
     Possible ans,
     ans = 1 + 2 + 10 = 13
     ans = 10+3 = 13
     So, ans will be "YES" for this input
     
Complexity : O(n*total)
  
 
Test Case:
5 13
1 2 10 3 5
