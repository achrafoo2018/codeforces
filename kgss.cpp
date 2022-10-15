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
    int from, to, mx1, mx2;
    segment_tree(int from, int to)
        : from(from), to(to), left(NULL), right(NULL), mx1(0), mx2(0) {}
};


segment_tree *build(const vector<int> &arr, int l, int r){
    if (l > r)
        return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r){
        res->mx1 = arr[l];
    }
    else{
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL){
            vi mx = {res->mx1, res->mx2, res->left->mx1, res->left->mx2};
            sort(all(mx));
            res->mx1 = mx[3];
            res->mx2 = mx[2];
        }
        if (res->right != NULL){
            vi mx = {res->mx1, res->mx2, res->right->mx1, res->right->mx2};
            sort(all(mx));
            res->mx1 = mx[3];
            res->mx2 = mx[2];
        }
    }
    return res;
}


segment_tree* update(segment_tree *tree, int i, int val){
    if (tree == NULL)
        return tree;
    if (tree->to < i)
        return tree;
    if (i < tree->from)
        return tree;
    if (tree->from == tree->to && tree->from == i){
        tree->mx1 = val;
    }
    else{
        segment_tree *left = update(tree->left, i, val);
        segment_tree *right = update(tree->right, i, val);
        vector<int> mx = {left->mx1, left->mx2, right->mx1, right->mx2};
        sort(all(mx));
        int n = mx.size();
        tree->mx1 = mx[n-1];
        tree->mx2 = mx[n-2];
    }
    return tree;
}


pii query(segment_tree *tree, int l, int r) {
    if (tree == NULL)
        return make_pair(0, 0);
    if (l <= tree->from && tree->to <= r){
        return make_pair(tree->mx1, tree->mx2);
    }
    if (tree->to < l) 
        return make_pair(0, 0);
    if (r < tree->from) 
        return make_pair(0, 0);
    pii x = query(tree->left, l, r);
    pii y = query(tree->right, l, r);
    vi mx = {x.first, x.second, y.first, y.second};
    sort(all(mx));
    return make_pair(mx[3], mx[2]);
}

void solve(){
    int n; cin >> n;
    vi arr(n);
    For(i, n)
        cin >> arr[i];
    segment_tree *seg_tree = build(arr, 0, n-1);
    int m; cin >> m;
    For(i, m){
        char q; cin >> q;
        int x, y; cin >> x >> y;
        x--;
        if(q == 'Q'){
            y--;
            pii ans = query(seg_tree, x, y);
            cout << ans.first + ans.second << endl;
        }else{
            update(seg_tree, x, y);
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
	while(t--)
        solve();
	return 0;
}
