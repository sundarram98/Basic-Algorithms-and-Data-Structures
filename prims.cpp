#include<bits/stdc++.h>
 
using namespace std;
 
const long long inf = 1e15;
 
#define pb push_back
#define F first
#define S second
#define mp make_pair
 
struct edge{
	long long v1, v2, wt;
};
 
struct comp{
	bool operator()( edge a, edge b)
	{
		return a.wt>b.wt;
	};
};
 
priority_queue< edge, vector<edge>, comp> my;
 
int main()
{
	long long n, m, t;
	t = 1;
	
	while( t-- ){
		cin >> n >> m;
		long long i, wt = 0;
		vector< pair< long long, long long> > v[n+20];
		bool vis[n+20];
		
		for( i = 0 ; i <= n+3 ; i++ ) vis[i] = 0;
		
		for( i = 0 ; i < m ; i++ ){
			int e, f, w;
			cin >> e >> f >> w;
			v[e].pb(mp(f,w));
			v[f].pb(mp(e,w));
		}
		struct edge e;
		e.v1 = 1;
		e.v2 = 1;
		e.wt = 0;
		my.push(e);
		
		while( !my.empty() ){
			e = my.top();
			my.pop();
			
			if( vis[e.v1] == 1 && vis[e.v2] == 1 ) continue;
			wt += e.wt;
			if( vis[e.v1] == 0 ){
				vis[e.v1] = 1;
				for( i = 0 ; i < v[e.v1].size() ; i++ ){
					struct edge e1;
					e1.v1 = e.v1;
					e1.v2 = v[e.v1][i].F;
					e1.wt = v[e.v1][i].S;
					my.push(e1);
				}
			}
			
			if( vis[e.v2] == 0 ){
				vis[e.v2] = 1;
				for( i = 0 ; i < v[e.v2].size() ; i++ ){
					struct edge e1;
					e1.v1 = e.v2;
					e1.v2 = v[e.v2][i].F;
					e1.wt = v[e.v2][i].S;
					my.push(e1);
				}
			}
		}
		
		
		cout << wt << endl;
	}
	
	return 0;
}

