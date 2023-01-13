#include <bits/stdc++.h>
using namespace std;

bool table[64][64];
void fractale(int n, int x, int y){
    if(n == 1){
        table[x][y] = true;
        return;
    }
    fractale(n/2, x, y);
    fractale(n/2, x+n/2, y);
    fractale(n/2, x, y+n/2);
}

int main(){
    int n;
    cin >> n;
    fractale(n, 0, 0);
    for(int i=0; i < n; i++){
        for(bool j : table[i])
            cout << (j ? "#" : " ");
        cout << endl;
    }
    return 0;
}