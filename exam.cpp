#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
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
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)

int Global1 = 0;
int Global2 = 0;

int F1(int *ptr){
	(*ptr)++;
	return *ptr;
}

int &F2(int *ptr){
	(*ptr)++;
	ptr = &Global2;
	return *ptr;
}

int F3(int G(int *ptr)){
	return G(&Global2);
}

int &F4(int &i){
	i++;
	return i;
}

int F5(int i){
	static int u=0;
	i++;
	u = u+i;
	Global2 = u+Global2;
	return u;
}

int main(){
	int NoLigne=0;
	int *ptr=&Global1;
	int &j=F4(F2(ptr));
	int &k=*ptr;
	j++;
	printf("%d : Global 1 = %d; Global 2 = %d\n", ++NoLigne, Global1, Global2);
	Global1 = 0, Global2 = 0;
	ptr = &F4(k);
	(*ptr)++;
	printf("%d : Global 1 = %d; Global 2 = %d\n", ++NoLigne, Global1, Global2);
	Global1 = 0, Global2 = 0;
	ptr=&Global1;
	k = F3(F1);
	k++;
	printf("%d : Global 1 = %d; Global 2 = %d\n", ++NoLigne, Global1, Global2);
	Global1=0, Global2=0;
	Global1 += F5(F5(Global2));
	printf("%d : Global 1 = %d; Global 2 = %d\n", ++NoLigne, Global1, Global2);
	return 0;
}
