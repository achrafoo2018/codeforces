#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define INF (ll)(2e31)
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "

const int N = 1e4+7;
bool visited[N];
int distances[N];
vi graph[N];
void bfs(int n, int m){
    visited[n] = true;
    queue<int> q;
    q.push(n);
    distances[n] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(auto child:graph[parent]){
            if(!visited[child]){   
                distances[child] = distances[parent] + 1;
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return;
}
int main(){
	int n, m;
	cin >> n >> m;
	if(n == m)
		cout << 0 << endl;
	else if(n > m)
		cout << n-m << endl;
	else{
        memset(visited, false, sizeof(visited));
        memset(distances, INF, sizeof(distances));
        int nMax = (m-1)*2;
        for(int i=1; i <= nMax; i++){
            if(i-1 > 1)
                graph[i].push_back(i-1);
            if(2*i <= nMax)
                graph[i].push_back(2*i);
        }
        bfs(n, m);
        cout << distances[m] << endl;
	}
	return 0;
}
