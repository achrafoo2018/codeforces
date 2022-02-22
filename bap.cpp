#include "bits/stdc++.h"
 
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

#define For(i, j, n) for (int i = j; i < n; i++)
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 1e5+7;
ll a[N];
vvi graph;
bool visited[N];

void dfs(int parent){
	visited[parent] = true;
	cout << parent << " ";
	for(int child : graph[parent]){
		if(!visited[child]){
			dfs(child);
		}
	}
	return;
}


int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		graph.resize(n+1);
		memset(visited, false, sizeof(visited));
		bool c = true;
		For(i, 0, n){
			cin >> a[i];
			if(i > 0 && a[i-1] != a[i])
				c = false;
		}
		For(i, 0, n-1){
			ll u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ll ans = 0;
		For(i, 0, n)
			ans ^= a[i];
		cout << ((ans == 0 || c) ? "YES" : "NO") << endl;
	}	
	return 0;
}
