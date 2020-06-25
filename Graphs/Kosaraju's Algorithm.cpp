// WE USE KOSARAJU ALGORITHM TO FIND (STRONGLY CONNECTED COMPONENTS IN A GRAPH)[SCC]

/*
	we will color all the nodes of a SCC and all nodes of another SCC with a different color and so on 
	in the end we can print all strongly connected components .
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<ll> adj[1001]; 		  // storing the graph
vector<ll> reverse_adj[1001]; // storing the reverse graph
ll vis[1001];
vector<ll> order;
vector<ll> strongly_connected_components[1001];

void dfs(ll src)
{
	vis[src]=1;
	for(ll neighbour:adj[src])
	{
		if(vis[neighbour]==0)
		{
			dfs(neighbour);
		}
	}

	order.push_back(src); 
}

void dfs_reverse(ll src,ll col)
{
	strongly_connected_components[col].push_back(src);

	vis[src]=1;
	for(ll neighbour:reverse_adj[src])
	{
		if(vis[neighbour]==0)
		{
			dfs_reverse(neighbour,col);
		}
	}


}
int main()
{
	#ifndef ONLINE_JUDGE


		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 

	#endif
	fastio;
	
	ll n,m,u,v;
	cin>>n>>m; // no of vertices and edges

	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v); 				// storing the graph
		reverse_adj[v].push_back(u);		// storing the reverse graph
	}

	memset(vis,0,sizeof(vis));

	// the graph may be disconnected therefore we run dfs in for loop

	for (int i = 1;i<=n; ++i)
	{
		if(vis[i]==0)
			dfs(i);
	}

	memset(vis,0,sizeof(vis));

	int col=1;
	for(int i=n-1;i>=0;i--)
	{
		if(vis[order[i]]==0)
		{
			dfs_reverse(order[i],col);
			col++;
		}

	}


	for(int i=1;i<col;i++)
	{

		for(auto it:strongly_connected_components[i])
			cout<<it<<" " ;
		
		cout<<endl;
	}


	return 0;
}


/* 


INPUT: 
6 7
1 2
2 3
3 1
3 4
4 5 
5 6
6 4

OUTPUT:
1 3 2 // first SCC
4 6 5 // second SCC 


*/