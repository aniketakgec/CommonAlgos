// 0/1 knapsack dynamic programming problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

// recursive top down aprroach without DP 0(2^N) solution

int knapsack(int value[],int weight[],int n,int W)
{
	if(n==0 || W==0)
	  return 0;
	int include=0;
	int exclude=0;

	// including the current item
	if(weight[n-1]<=W)
	 include=value[n-1]+knapsack(value,weight,n-1,W-weight[n-1]);

	//excluding the current item
	exclude= 0 + knapsack(value,weight,n-1,W);

	return max(include,exclude);

}


//BOTTOM UP DP APPROACH   0(N*W) solution

int knapsackBottomUp(int value[],int weight[],int n,int W)
{
	int dp[n+1][W+1]={0};
	

	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				dp[i][w]=0;
			else
			{
				int include=0,exclude=0;
				
				if(weight[i-1]<=w)
				{
					include=value[i-1]+dp[i-1][w-weight[i-1]];
				}

				exclude=dp[i-1][w];
				

				dp[i][w]=max(include,exclude);

			}

			

		}
	}


	return dp[n][W];

}


int main()
{
	
	#ifndef ONLINE_JUDGE
		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 
	#endif

	/*
		W if the  max capacity of knapsack
		 n is the no of items available
		
	*/
	
	ll t,n,W,i;
	cin>>t;	

	while(t--)
	{
		cin>>n>>W;		
		int weight[n];
		int value[n];					
		for(i=0;i<n;i++)
		  cin>>value[i];   									
	    for(i=0;i<n;i++)
		  cin>>weight[i];   


		cout<<knapsackBottomUp(value,weight,n,W)<<endl;	


		
	}

	return 0;
}