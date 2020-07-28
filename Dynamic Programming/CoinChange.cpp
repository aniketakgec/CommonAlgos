#include<bits/stdc++.h>
using namespace std;
#define ll long  long int 
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


   
 int CoinChange(int amount, vector<int>& coins)
    {
        int n=coins.size();
        int dp[n+1][amount+1];
        
        for(int i=1;i<amount+1;i++)
        {
            
            dp[0][i]=0;
        }
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                dp[i][j]=dp[i-1][j];
                
                if(j>=coins[i-1])
                {
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
                
            }
        }
        
        return dp[n][amount];
        
 }


int main()
{
    #ifndef ONLINE_JUDGE


         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout); 

    #endif


    int amount,n;
    cin>>n>>amount;
    vector<int> coins;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        coins.pb(x);
    }

    cout<<CoinChange(amount,coins);
    
return 0;
}

