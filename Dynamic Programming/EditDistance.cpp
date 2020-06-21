#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int editDistance(string str1,string str2,int n,int m)
{

	int dp[n+1][m+1],i,j;

    for(i=0;i<=n;i++)
    {
    	for (j=0;j<=m;j++)
    	{
    		if(i==0 && j==0)
    			dp[i][j]=0;
    		else if(i==0)
    		{
    			dp[i][j]=dp[i][j-1]+1;

    		}
    		else if(j==0)
    		{
    			dp[i][j]=dp[i-1][j]+1;
    		}
    		else
    		{
    			if(str1[i-1]==str2[j-1])
    			{
    					dp[i][j]=dp[i-1][j-1];
    			}
    			else
    			{
    				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
    			}

    		}
    	}
    }

return dp[n][m];


}

int main()
{

	
	#ifndef ONLINE_JUDGE

		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 

	#endif

   fastio;
   ll t;
   cin>>t;
   while(t--)
   {
   	  string str1,str2;
   	  cin>>str1>>str2;
   	  cout<<editDistance(str1,str2,str1.size(),str2.size());
   }
	   	
	   	


  
     
  
	return 0;
}



