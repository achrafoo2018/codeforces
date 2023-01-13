#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case " << i << ": "

int main(){
	int t;
	cin >> t;
	int j = 1;
	while(t--){
		int N;
		cin >> N;
		int mile = 0, juice = 0;
		for(int i=0; i < N; i++){
			int k;
			cin >> k;
			mile += ceil((k+0.1) / 30.0)*10;
			juice += ceil((k+0.1) / 60.0)*15;
		}
		case(j);
		if(mile > juice)
			cout << "Juice " << juice << endl;
		else if(mile < juice)
			cout << "Mile " << mile << endl; 
		else
			cout << "Mile Juice " << mile << endl;
		j++;
	}	
	return 0;
}
