#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<ll> adj[10001];
int in[10001];
vector<ll> res;

void toposort(int n)	// based on kahn algorithm
{
	queue<ll> q;
	for (int i = 1; i <=n; ++i)
	{
		if(in[i]==0)
			q.push(i);
	}

	//function like bfs

	while(!q.empty())
	{
		ll cur_node=q.front();
		res.push_back(cur_node);
		q.pop();

		for(ll forwardNeighbour:adj[cur_node])
		{
			in[forwardNeighbour]--;
			if(in[forwardNeighbour]==0)
				q.push(forwardNeighbour);
		}
	}

	cout<<"TOPOSORT :"<<endl;
	for(auto it:res)
		cout<<it<<" ";
}

int main()
{
	#ifndef ONLINE_JUDGE


		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 

	#endif
	ll n,m,u,v;
	cin>>n>>m;
	memset(in,0,sizeof(in));
	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		in[v]++;

	}


	toposort(n);
	return 0;
}



	




