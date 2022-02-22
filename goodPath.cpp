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

const int N = 1e5+7;
bool visited[N];
vi graph[N];

ll bfs(int pos, int k){
	visited[pos] = true;
	queue<int> q;
	q.push(pos);
	ll ans = 0;
	bool prev = false;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto child : graph[x]){
			if(!visited[child]){
				if(child >= k && x >= k){
					ans++;
					if(prev)
						ans++;
					prev = true;
				}else
					prev = false;
				visited[child] = true;
				q.push(child);
			}
		}
	}
	return ans;
}
void solve(){
	int n, k;
	cin >> n >> k;
	memset(visited, false, sizeof(visited));
	set<int> nodes;
	while(nodes.size() < n){
		int x, y;
		cin >> x >> y;
		nodes.insert(x);
		nodes.insert(y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ll ans = 0;
	for(int x:nodes)
		if(!visited[x])
			ans += bfs(x, k);
	cout << ans << endl;
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
