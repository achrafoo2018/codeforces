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

const int mod = 1e9+7;
const int maxn = 2e5+5;
typedef long long ll;
queue<pair<int,int> > q;
map<int,bool> vis;
vector<int> v;
void solve(){
	int n,m;
	cin >> n >> m;
	while(n--){
		ll x;
		cin >> x;
		vis[x] = 1;
		q.push(make_pair(1, x+1));
		q.push(make_pair(1, x-1));
	}
	ll ans = 0;
	while(m > 0 && !q.empty()){
		pair<int, int> cur = q.front() ;
		q.pop() ;
		if(vis[cur.second] != 1){
			m--;
			v.push_back(cur.second ); 
			ans += cur.first;
			vis[cur.second] = 1;
			if(vis[cur.second+1] != 1) 
				q.push(make_pair(cur.first+1,cur.second+1));
			if(vis[cur.second-1] != 1)
				q.push(make_pair(cur.first+1,cur.second-1)); 
		}
	}
	cout<<ans<<endl;
	for(int i = 0;i<v.size() ;i++){
		cout<<v[i]<<" ";
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
