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

const int N = 2000;
bool visited[N];
int levels[N];
vector<vi> graph;
vi roots;
int maxLevel = 0;


void bfs(int pos){
	visited[pos] = true;
	queue<int> q;
	q.push(pos);
	while(!q.empty()){
		int parent = q.front();
		q.pop();
		for(auto child : graph[parent]){
			if(!visited[child]){
				q.push(child);
				visited[child] = true;
				levels[child] = levels[parent] + 1;
				maxLevel = max(maxLevel, levels[child]);
			}
		}
	}
	return;
}


int main(){
	int n;
	cin >> n;
	graph.clear();
	graph.resize(n);
	memset(visited, false, sizeof(visited));
	memset(levels, 0, sizeof(levels));
	for(int i=0; i < n; i++){
		int x;
		cin >> x;
		if(x == -1)
			roots.push_back(i);
		else
			graph[x-1].push_back(i);
	}
	for(int i : roots){
		levels[i] = 1;
		bfs(i);
	}
	cout << max(maxLevel, 1) << endl;
	return 0;
}
