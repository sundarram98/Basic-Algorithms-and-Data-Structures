#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define M 1000000007

int add( int a, int b){
	return ((a%M)+(b%M))%M;
};

int sub( int a, int b){
	return ((a%M)-(b%M)+M)%M;
};

int mul( int a, int b){
	return ((a%M)*(b%M))%M;
};

int pwr( int a, int b){
	if( b == 0 ) return 1;
	
	if( b%2 ) return mul( a, mul( pwr(a, b/2), pwr( a, b/2)) );
	else return mul( pwr(a, b/2), pwr( a, b/2));
};

int main()
{
	int a = 5, b = 3;
	cout << add( a, b) << " " << sub( a, b) << " " << mul( a, b) << " " << pwr( a, b);
	
	return 0;
}
