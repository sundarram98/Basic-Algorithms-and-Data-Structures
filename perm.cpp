#include<bits/stdc++.h>

using namespace std;

int a[1005], n;
bool f[1005];

void perm( int c, int l, int n ){
	if( c == l ){
		for( int i = 1 ; i <= l ; i++ ){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else{
		for( int i = 1 ; i <= n ; i++ ){
			if( f[i] == 1 ) continue;
			
			f[i] = 1;
			a[c+1] = i;
			perm( c+1, l, n);
			f[i] = 0;
		}
	}
}

int main()
{
	int n, l1, l;
	
	
	cin >> n >> l1;
	for( l = 0 ; l <= n ; l++ ) 
		f[l] = 0;
	perm( 0, l1, n);
	
	return 0;
}
