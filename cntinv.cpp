#include<bits/stdc++.h>
using namespace std;
     
int b[2000006];
long long c;
void merge( int a[], int s, int e){
	
	if( e-s == 1 ) 
		return ;		int mid = (s+e)/2;
	merge( a, s, mid); merge(a, mid, e);
    	
	int c1 = s, c2 = mid, pos = s;
    
    while( c1 != mid && c2 != e ){	
		if( a[c1] <= a[c2] ) b[pos++] = a[c1++];
		else{
			b[pos++] = a[c2++];
			c += mid-c1;
    	}
    }
    	
	while( c2 != e ) b[pos++] = a[c2++];
	while( c1 != mid ) b[pos++] = a[c1++];
    	
    for( int i = s ; i < e ; i++ ) a[i] = b[i];
    	
    return ;	
};
     
int main(){
   	
   	int n, t;
   	cin >> t;
   	
   	while( t-- ){
   		cin >> n;
   		int a[n+5], i;		
   		for( i = 0 ; i < n ; i++ ) cin >> a[i], b[i] = a[i];
   		c = 0;
   		merge( a, 0, n);
   		cout << c << endl;
   	}
   	
   	return 0;
} 
