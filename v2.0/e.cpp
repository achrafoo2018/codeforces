#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0;i < n; i++){
        cin >> arr[i];
    }
    for(long long i=0; i < n; i++){
        long long root = sqrt(arr[i]);
        if(!(root * root == arr[i])){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    long long t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}