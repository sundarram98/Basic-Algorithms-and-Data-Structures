#include<bits/stdc++.h>
 
typedef long long int ll;
typedef long double ld;
 
#define rel( i, a, b) for( ll i = a ; i <= b ; i++ )
#define pow(b) for( ll k = a ; k <= b ; k+=2*k )
#define rev( i, a, b) for( ll i = b ; i >= a ; i-- )
#define M 100000007
#define pll pair<ll,ll>
#define vll vector<int>
#define vpll vector<pll>
#define mll map<ll,ll>
#define sll set<ll>
#define F first
#define S seconnd
#define pb push_back
#define mp make_pair
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
using namespace std;
 
inline void create( int low, int high, int pos);
inline void update( int qlow, int qhigh, int low, int high, int pos);
inline int traverse( int qlow, int qhigh, int low, int high, int pos);
 
int n, t, a[1000008], b[1000008], d, e, f, m, c[1000008];
vll seg;
 
int main()
{
	FIO;
	
	cin >> t;
	
	for( int i = 1 ; i < 1000005 ; i += 2 ) b[i] = 1, b[i+1] = 2, c[i+1] = (i+1)/2, c[i] = 1;
	
	c[1] = c[2] = 1;
	
	for( int i = 3 ; i < 1003 ; i+=2 ){
	
		if( b[i] == 1 ){
			b[i] = i;
			c[i] = 1;
			
			for( int j = i*i ; j < 1000005 ; j += i ){
				if( b[j] == 1 && j % i == 0 ){
					b[j] = i;
					c[j] = j/i;
				}
			}
		}
	} 
	
	for( int i = 1003 ; i < 1000005 ; i+=2 ) if( b[i] == 1 ) b[i] = i, c[i] = 1;
	
	while( t-- )
	{
		cin >> n >> m;
		
		seg.erase( seg.begin(), seg.end() );
		seg.resize(4*n+2);
		
		rel( i, 1, n) cin >> a[i];
			
		create( 1, n, 1);
		
		while( m-- ){
			cin >> d >> e >> f;
			
			if( d == 1 ) cout << traverse( e, f, 1, n, 1) << " ";
			else if ( d == 0 ) update( e, f, 1, n, 1);
		}
		cout << endl;
	}
	
	return 0;
}
 
inline void create( int low, int high, int pos){
	if( low == high ){
		seg[pos] = b[a[low]];
		return ;
	}
	
	int mid = (low+high)/2;
	
	create( low, mid, 2*pos);
	create( mid+1, high, 2*pos+1);
	
	seg[pos] = max( seg[2*pos], seg[2*pos+1]);
	
};
 
inline int traverse( int qlow, int qhigh, int low, int high, int pos){
	 
	if( (low > qhigh) || ( high < qlow ) || (seg[pos] == 1) ) return 1;
 
	if( low >= qlow && high <= qhigh ) return seg[pos];
 
	
	int mid = (low+high)/2;
	
	return max( traverse( qlow, qhigh, low, mid, 2*pos), traverse( qlow, qhigh, mid+1, high, 2*pos+1) );
};
 
inline void update( int qlow, int qhigh, int low, int high, int pos){
	
	if( (low > qhigh) || ( high < qlow ) || (seg[pos] == 1) ){
		return ;
	}
	
	if( low == high ){
		a[low] = c[a[low]];
		seg[pos] = b[a[low]];
		
		return ;
	}
	
	int mid = (low+high)/2;
	
	update( qlow, qhigh, low, mid, 2*pos);
	update( qlow, qhigh, mid+1, high, 2*pos+1);
	
	seg[pos] = max( seg[2*pos], seg[2*pos+1]);
};
