#include "bits/stdc++.h"
/***************************************************/
/***************************************************/
/******************* 3ak3ek ************************/
/***************************************************/
/***************************************************/
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; i++)

int getMaxRecursive(vi v, int pos=0){
	if(v.size()-1 == pos)
		return v[pos];
	int ans = getMaxRecursive(v, pos+1);
	if(v[pos] > ans)
		return v[pos];
	else
		return ans;
}

void solve(){
	vi v;
	for(int i=1; i < 21; i++){
		v.push_back(rand() % 100+1);
	}
	For(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "Max = " << getMaxRecursive(v) << endl;
}

int main(){
	srand (time(NULL));
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
