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
		long long i, wt = 0, dsu[n+20];
		
		for( i = 0 ; i <= n+3 ; i++ ) dsu[i] = i;
		
		for( i = 0 ; i < m ; i++ ){
			int v1, v2, w;
			cin >> v1 >> v2 >> w;
			struct edge e;
			e.v1 = v1;
			e.v2 = v2;
			e.wt = w;
			my.push(e);
		}
		
		
		while( !my.empty() ){
			struct edge e = my.top();
			my.pop();
			
			if( dsu[e.v1] == dsu[e.v2] ) continue;
			wt += e.wt;
			for( i = 1 ; i <= n ; i++ ){
				if( dsu[i] == dsu[e.v2] && i != e.v2 ){
					dsu[i] = dsu[e.v1];
				}
			}
			dsu[e.v2] = dsu[e.v1];
		}
		
		cout << wt << endl;
	}
	
	return 0;
}

