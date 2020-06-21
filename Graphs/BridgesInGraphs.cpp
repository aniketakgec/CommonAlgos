//  Finding Bridges in graphs

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

vector<int> adj[100];
int in[101],low[101],vis[101];
int timer;

void dfs(int node,int parent)
{
	vis[node]=1;
	in[node]=low[node]=timer;
	timer++;

	for(int child:adj[node])
	{
		if(child==parent)
		  continue;

		if(vis[child]==1)
		{
			// This edge node->child is a back edge


			low[node]=min(low[node],in[child]);
		}
		else
		{
			// This edge node->child is a forward edge
			dfs(child,node); 

			
          /* Bridge Condition  "node" is the node throught which dfs call was 
			made and child is present in its adjacency list*/
		
			if(low[child]>in[node])  	 
			cout<<node<<"-->"<<child<<" is a Bridge"<<endl;

			low[node]=min(low[node],low[child]);
		}

	}
}


int main()
{
	
	#ifndef ONLINE_JUDGE
		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 
	#endif


	int n,m,x,y;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
		

	dfs(1,-1);  // passing parent as a second parameter to dfs call initally it is -1;


	return 0;
}