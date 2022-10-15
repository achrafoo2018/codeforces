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
#define no cout << "NO" << endl;
#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge
{
    c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifdef LOCAL
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for (int i = 0; i < n; ++i)

struct segment_tree{
    segment_tree *left, *right;
    ll from, to, value, occ;
    segment_tree(ll from, ll to)
        : from(from), to(to), left(NULL), right(NULL), value(LONG_LONG_MAX), occ(0) {}
};

segment_tree *build(const vector<ll> &arr, ll l, ll r){
    if (l > r)
        return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r){
        res->value = arr[l];
        res->occ = 1;
    }
    else{
        ll m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        ll ans = 0;
        if (res->left != NULL){
            res->value = min(res->value, res->left->value);
            if(res->value > res->left->value){
                ans = res->left->occ;
            }else if(res->value == res->left->value)
                ans = res->left->occ + res->occ;
        }
        if (res->right != NULL){
            res->value = min(res->value, res->right->value);
            if(res->value > res->left->value){
                ans = res->left->value;
            }else if(res->value == res->left->value){
                ans += res->left->occ;
            }
        }
        res->occ = ans;
    }
    return res;
}

pll update(segment_tree *tree, ll i, ll val){
    if (tree == NULL)
        return make_pair(LONG_LONG_MAX, 0);
    if (tree->to < i || i < tree->from)
        return make_pair(tree->value, tree->occ);
    if (tree->from == tree->to && tree->from == i){
        tree->value = val;
        tree->occ = 1;
    }
    else{
        pll x = update(tree->left, i, val);
        pll y = update(tree->right, i, val);
        if(x.first > y.first){
            tree->value = y.first;
            tree->occ = y.second;
        }else if(x.first < y.first){
            tree->value = x.first;
            tree->occ = x.second;
        }else{
            tree->value = x.first;
            tree->occ = x.second + y.second;
        }
    }
    return make_pair(tree->value, tree->occ);
}

pll query(segment_tree *tree, ll l, ll r){
    if (tree == NULL)
        return make_pair(LONG_LONG_MAX, 0);
    if (l <= tree->from && tree->to <= r)
        return make_pair(tree->value, tree->occ);
    if (tree->to < l)
        return make_pair(LONG_LONG_MAX, 0);
    if (r < tree->from)
        return make_pair(LONG_LONG_MAX, 0);
    pll x = query(tree->left, l, r);
    pll y = query(tree->right, l, r);
    if(x == y){
        return make_pair(x.first, x.second+y.second);
    }else if(x > y){
        return make_pair(y.first, y.second);
    }else{  
        return make_pair(x.first, x.second);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vll arr(n);
    For(i, n)
    {
        cin >> arr[i];
    }
    segment_tree *seg = build(arr, 0, n-1);
    For(i, m)
    {
        ll q, u, v;
        cin >> q >> u >> v;
        if (q == 1)
        {
            update(seg, u, v);
        }
        else
        {
            pll ans = query(seg, u, v - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}

int main()
{
    fastio;
    // cout << setprecision(9);
    // cout << fixed;
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
