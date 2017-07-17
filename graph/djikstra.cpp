#include<bits/stdc++.h>
 
using namespace std;
 
const long long inf = 1e15;
 
#define pb push_back
#define F first
#define S second
#define mp make_pair
 
struct edge{
	long long v, wt;
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
	long long n, m, u, t;
	cin >> t;
	
	while( t-- ){
		cin >> n >> m >> u;
		long long d[n+20], i;
		vector< pair< long long, long long> > v[n+20];
		
		for( i = 0 ; i <= n+3 ; i++ ) d[i] = inf;
		
		for( i = 0 ; i < m ; i++ ){
			int e, f, w;
			cin >> e >> f >> w;
			v[e].pb(mp(f,w));
			v[f].pb(mp(e,w));
		}
		struct edge e;
		e.v = u;
		e.wt = 0;
		my.push(e);
		
		while( !my.empty() ){
			e = my.top();
			my.pop();
			
			if( d[e.v] < e.wt ) continue;
			d[e.v] = e.wt;
			
			for( i = 0 ; i < v[e.v].size() ; i++ ){
				struct edge e1;
				e1.v = v[e.v][i].F;
				e1.wt = e.wt+v[e.v][i].S;
				my.push(e1);
			}
		}
		
		for( i = 1 ; i <= n ; i++ ) cout << d[i] << " ";
		cout << endl;
	}
	
	return 0;
}
