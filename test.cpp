//============================================================================
// Name        : Brahmi Zied
// Author      : brahZied
// Version     : 2022
// Description : Road to expert
//============================================================================
/*
    STAY ORGANIZED
    CHANGE YOUR APPROACH
    BE CONFIDENT
*/
// when you train write the algos from 0
//Think different approaches 
//(trace TestCase,think with symbols,think with PICS,
//numberTheory,bs,dp,greedy,graphs,shortest paths,mst,
//dsu,LCA(binary lifting?),hashing(strings))
//Stay Calm
// IN TRAINING DO NOT SEE WRONG TEST CASES AFTER SUBMITTING!
//Look for special cases
//Beware of overflow and array bounds
//Think the problem backwards
#include <bits/stdc++.h>
using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
typedef long double ld;
ll n,k,m,d;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

const int MAXN = 1e6;
const ll MOD = 1e9 + 7;
ll INF=2e18;
const int nax=7;
vector<int> adj[nax];
vector<int> res(nax);
vector<int> ss(nax);
void dfs(int node,int par,int height){
	//cout <<"---"<<"\n";
	debug() << imie(res) imie(ss);
	debug() << imie(node) imie(par) imie(height) imie(res[node]) imie(ss[node]);
	if(height%2==1 && ss[node]<ss[par]){
		cout <<"-1" << "\n";
		exit(0);
	}
	if(height%2==0 && (int)adj[node].size()==1){
		res[node]=0;
		return;
	}else if((int)adj[node].size()==1 && par!=-1){
		res[node]=ss[node]-ss[par];
		return;
	}
	if(height%2==1){
		res[node]=ss[node]-((height>1)?ss[par]:0);
		for(int i=0;i<(int)adj[node].size();i++){
			if(adj[node][i]==par) continue;
			dfs(adj[node][i],node,height+1);
		}
	}else{
		bool eq=true;
		bool assigned=false;
		int val;
		for(int i=0;i<(int)adj[node].size();i++){
			if(adj[node][i]==par) continue;
			if(!assigned) {
				val=ss[adj[node][i]];
				assigned=true;
			}
			else{
				if(val!=ss[adj[node][i]]){
					eq=false;
					break;
				}
			}
			
		}
		
		
		if(!eq){
			cout <<"-1"<< "\n";
			exit(0);
		}
		
		res[node]=val-ss[par];
		if(res[node]<0){
			cout <<"-1"<< "\n";
			exit(0);
		}
		ss[node]=ss[par]+res[node];
		debug() << imie(node) imie(res[node]) imie(val);
		for(int i=0;i<(int)adj[node].size();i++){
			if(adj[node][i]==par) continue;
			dfs(adj[node][i],node,height+1);
		}
		
		
	}
	
	
	
}
void solve(){
	cin >> n;
	
	for(int i=2;i<=n;i++){
		int val;
		cin >> val;
		adj[i].push_back(val);
		adj[val].push_back(i);
	}
	
	for(int i=1;i<=n;i++){
		cin >> ss[i];
	}
	dfs(1,-1,1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=res[i];
	}
	
	cout << sum << "\n";
}


 
int main() {
	fastInp;

	//freopen("chess.in","r",stdin);
	//freopen("t.out","w",stdout);
	int tc=1;
	//debug() << imie(sieve);
	//cin >> tc;
	//int i=0;
	//cout << setprecision(10)<<fixed;
	while(tc--){
		//i++;
		//cout <<"Test " << i << ":" << "\n";
		solve();
		
	}

	return 0;
}

/*
   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
 
 
 */
