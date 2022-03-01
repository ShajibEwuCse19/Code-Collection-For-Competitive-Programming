//Subarray Sum, Max subarray sum, subarray sum when Length of the subarray = 1,2,3,.....,n 
    int n;cin>>n;
    vector<int>v(n);
    for(auto &i : v)cin>>i;

    vector<int>ans;

    int sum1 = 0;
    for(int i=0; i<n; i++)
    {
        sum1 += v[i];dbg(sum1);
        int Sum = sum1;
        int Max = sum1;
        int idx = 0;

        for(int j=i+1; j<n; j++)
        {
            Sum = Sum + v[j];
            Sum = Sum - v[idx];dbg(j,idx,v[j],v[idx],Sum); /// All subArray sum

            idx++;

            Max = max(Max,Sum);
        }
        ans.push_back(Max); /// Max subArray sum for Length = 1, 2, 3,...,n
    }
   
  for(auto i : ans)cout<<ans<<endl; /// Output of Max SubArray sum for 0 to n Length.
}

Complexity : O (n*n) = O(n^2)

/*
3
-2 -7 -1
*/

Explanation:
------------
Input Array = a,b,c,d,e
Sum1 = 0 /// Line-8
Then after Line 10,

Sum1 = a the, a+b then, a+b+c then, a+b+c+d........
Sum = Max = Sum1;
Index, idx = 0 [ 0 to SubArrayLength];
  
From 2nd loop [Line 16],
IF, Sum = a;[SubArray length = 1]
Sum = Sum + b = a + b, Next Line, Sum = (a + b) - a = b, Finally, Sum = b  
IF, Sum = b;
Sum = Sum + c = b + c, Next Line, Sum = (b + c) - b = c, Finally, Sum = c  
-
-
-
-
IF, Sum = a + b + c; [SubArray length = 3]
Sum = Sum + d = (a + b + c) + d, Next Line, Sum = (a + b + c + d) - a = b + c + d, Finally, Sum = b + c + d
-
-
-
It will work like that.
  
  
