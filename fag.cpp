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

void solve(){
int n;
	cin>>n;
	int a[n+5];
	unordered_set<int> se;
	map<int, int> mp;
	for(int i =1;i<=n;i++)
		se.insert(i);
	for(int i =0 ;i< n;i++){
		cin>>a[i];
		if(a[i] != 0)
			se.erase(a[i]);
	}
	For(i, n){
		if(a[i] == 0){
			if(se.find(i+1) != se.end()){
				se.erase(i+1);
				mp[i+1] = *se.begin();
				se.insert(i+1);
				se.erase(mp[i+1]);
			}
		}
	}
	for(int i = 0;i<n;i++){
		if(a[i] != 0)
			cout<< a[i] << ' ';
		else{
			if(mp.find(i+1) != mp.end())
				cout << mp[i+1] << " ";
			else{
				int x = *se.begin();
				cout << x << " ";
				se.erase(x);
			}
		}
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}