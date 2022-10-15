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

struct segment_tree{
    segment_tree *left, *right;
    int from, to, opening, closing;
    segment_tree(int from, int to)
        : from(from), to(to), left(NULL), right(NULL), opening(0), closing(0) {}
};


segment_tree *build(const vector<char> &arr, int l, int r){
    if (l > r)
        return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r){
        res->opening = (arr[l] == '(');
        res->closing = (arr[l] == ')');
    }
    else{
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL && res->right != NULL){
            int diff = res->left->opening - res->right->closing;
            if(diff > 0){
                res->opening = diff + res->right->opening;
                res->closing = res->right->closing + res->left->closing;
            }else{
                res->opening = res->right->opening;
                res->closing = -diff + res->right->closing;
            }
        }
    }
    return res;
}


segment_tree* update(segment_tree *tree, int i){
    if (tree == NULL)
        return tree;
    if (tree->to < i)
        return tree;
    if (i < tree->from)
        return tree;
    if (tree->from == tree->to && tree->from == i){
        if(tree->opening == 1){
            tree->opening = 0;
            tree->closing = 1;
        }else{
            tree->opening = 1;
            tree->closing = 0;
        }
    }
    else{
        segment_tree* left = update(tree->left, i);
        segment_tree* right = update(tree->right, i);
        int diff = left->opening - right->closing;
        if(diff > 0){
            tree->opening = diff + tree->right->opening;
            tree->closing = tree->right->closing + tree->left->closing;
        }else{
            tree->opening = tree->right->opening;
            tree->closing = -diff + tree->right->closing;
        }
    }
    return tree;
}


bool query(segment_tree *tree, int l, int r) {
    if (tree == NULL) return 0;
    if (l <= tree->from && tree->to <= r) 
        return tree->opening == 0 && tree->closing == 0;
    if (tree->to < l) 
        return 0;
    if (r < tree->from) 
        return 0;
    return query(tree->left, l, r) || query(tree->right, l, r);
}

void solve(){
	int n; cin >> n;
    vector<char> arr(n);
    For(i, n)
        cin >> arr[i];
    segment_tree *seg_tree = build(arr, 0, n-1);
    int m; cin >> m;
    For(i, m){
        int k; cin >> k;
        if(n % 2 == 1){
            no;
            continue;
        }
        if(k == 0){
            if(query(seg_tree, 0, n-1)){
                yes;
            }else{
                no;
            }
        }else{
            update(seg_tree, --k);
        }
    }
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t = 1;
	// cin >> t;
	For(i, t){
        cout << "Test " << (i+1) << ":" << endl;
        solve();
    }
	return 0;
}
