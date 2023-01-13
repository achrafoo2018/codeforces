#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int c, n;
        cin >> c >> n;
        vector<pair<int, int>> vpi;
        for(int i=0; i < n; i++){
            int w, f;
            cin >> w >> f;
            vpi.push_back(make_pair(f, w));
        }
        sort(vpi.begin(), vpi.end(), greater<pair<int, int>>());
        int res = 0;
        for(int i=0; i < n; i++){
            int j=i;
            int r=0, ans = 0;
            while(j < n){
                if(ans + vpi[j].second < c){
                    ans += vpi[j].second;
                    r += vpi[j].first;
                }
                j++;
            }
            res = max(res, r);
        }
        cout << res << endl;
    }
    return 0;
}