#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=0; i < n; i++){
			for(int j=0; j < i; j++)
				cout << "(";
			for(int j=0; j < n-i; j++)
				cout << "()";
			for(int j=0; j < i; j++)
				cout << ")";
			
			cout << endl;
		}	
	}
	return 0;
}
