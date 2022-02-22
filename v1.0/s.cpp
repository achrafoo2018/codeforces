#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int lst[n];
    for(int i=0;i < n; i++){
        cin >> lst[i];
    }
    for(int i=0; i < m; i++){
        int k;
        set<int> s;
        cin >> k;
        cout << "k = "+ k << endl;
        for (int j=sizeof(lst)-1; j >= k - 1;j--) {
            s.insert(lst[j]);
        }
        cout << s.size() << endl;

    }
}