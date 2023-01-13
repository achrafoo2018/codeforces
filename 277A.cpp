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
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N=1e3+7;
bool visited[N];
vvi graph;
vvi langage;

void dfs(int parent){
	visited[parent] = true ;
	for(auto child: graph[parent]){
		if(!visited[child])
            dfs(child);
	}

	return ;
}

int main(){
	int n,m;
	cin>>n>> m;
	langage.resize(m);
	graph.resize(n);
	memset(visited, false, sizeof visited);
	int zerolangage=0;

	for(int i=0; i < n; i++){
		int nl;
		cin >> nl;
		if(nl == 0)
			zerolangage++;
		
		for(int j=0; j < nl; j++){
			int x;	
			cin >> x;				
			langage[x-1].push_back(i);
		}
	}
	if(zerolangage == n){
		cout << n << endl;
		return 0;
	}
	for(int i=0; i < m; i++){
		int nb = langage[i].size();
		for(int j=0; j < nb-1;j++){
			graph[langage[i][j]].push_back(langage[i][j+1]);
			graph[langage[i][j+1]].push_back(langage[i][j]);
		}
	}
	int res = 0;
	for(int i=0; i < n; i++){
		if(!visited[i]){
			dfs(i);
			res++;
		}
	}
	cout << res-1 << endl;
	return 0;
}
