#include<bits/stdc++.h>

using namespace std;

string needle, haystack;

void preprocess( int l2, int p[]) 
{
	p[0] = -1;
	
	for( int i = 0 ; i < l2 ; i++ ){
		p[i+1] = p[i];
		while( p[i+1] > -1 && needle[p[i+1]] != needle[i] ){
			p[i+1] = p[p[i+1]];
		}
		p[i+1]++;
	}
};

void kmp( int l1, int l2, int p[]){
	int seen = 0;
	
	for( int i = 0 ; i < l1 ; i++ ){
		while( seen > -1 && needle[seen] != haystack[i] ) 
			seen = p[seen];
		seen++;
		//cout << i << " " << seen << endl;
		if( seen == l2 ){
			cout << i-seen+1 << endl;
			seen = p[l2];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	
	int l2;
	while( cin >> l2 )
	{
		cin >> needle >> haystack;
		int l1 = haystack.length(), p[l2+10];
		preprocess( l2, p);
		
		kmp( l1, l2, p);
	}
	
	return 0;
};
