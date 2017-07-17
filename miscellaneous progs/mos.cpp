#include<bits/stdc++.h>

#define F first
#define S second
#define pl pair< int, int>
#define pll pair< pl, int>
#define mp make_pair
#define pb push_back
#define endl '\n'

using namespace std;

int q, n;

bool comp( pll p1, pll p2){
	int sq = sqrt(q);
	
	if( p1.F.F/sq == p2.F.F/sq ){
		return p1.F.S<p2.F.S;
	}
	return ((p1.F.F/sq)<(p2.F.F/sq));
};

int main()
{
	ios::sync_with_stdio(0);
	vector<pll> my;
	
	int i, maxi;
	
	cin >> n;
	int a[300000+5], ans[300000+5];
	for( i = 1 ; i <= n ; i++ ) cin >> a[i], maxi = max( maxi, a[i]);
	int f[10000000+7];
	cin >> q;
	
	for( i = 0 ; i < q ; i++ ){
		int e, f;
		cin >> e >> f;
		my.pb(mp( mp( e, f), i));
	}
	
	sort( my.begin(), my.end(), comp);
	
	int curL = 0, curR = 0, t = 0;
	a[0] = a[n+1] = 0;
	for( i = 0 ; i < my.size() ; i++ ){
		//cout << i << " " << my[i].F.F << " " << my[i].F.S << " " << curL << " " << curR << endl;				
		while( curL > my[i].F.F ){
			curL--;
			f[a[curL]]++;
			if( f[a[curL]] == 1 && a[curL] != 0 ) t++;
		}
		//cout << 1 << " " << t << endl;
		
		while( curR < my[i].F.S ){
			curR++;
			f[a[curR]]++;
			if( f[a[curR]] == 1 && a[curR] != 0 ) t++;
		}
		//cout << 2 << " " << t << endl;
		while( curL < my[i].F.F ){
			f[a[curL]]--;
			if( f[a[curL]] == 0 && a[curL] != 0 ) t--;
			curL++;
		}
		//cout << 3 << " " << t << endl;
		while( curR > my[i].F.S ){
			f[a[curR]]--;
			if( f[a[curR]] == 0 && a[curR] != 0 ) t--;
			curR--;
		}
		//cout << 4 << " " << t << endl;
		//cout << i << " " << my[i].S << " " << t << endl;
		ans[my[i].S] = t;
	}
	
	
	for( i = 0 ; i < q ; i++ )
		cout << ans[i] << endl;
	
	return 0;
}
