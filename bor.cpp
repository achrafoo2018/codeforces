#include <bits/stdc++.h>
using namespace std;
const auto N=100;
int a[N][N];
int b[N][N];
int main(){
	int m, n;
	cin >> m >> n;
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			int c;
			cin >> c;
			a[i][j] = 1;
			b[i][j] = c;
		}
	}
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			if(b[i][j] == 0){
				for(int x=0; x < n; x++)
					a[i][x] = 0;
				for(int x=0; x < m; x++)
					a[x][j] = 0;
			}
		}
	}
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			int c = 0;
			for(int x=0; x < n; x++){
				if(a[i][x] == 1)
					c = 1;	
			}
			for(int x=0; x < m; x++){
				if(a[x][j] == 1)
					c = 1;
			}		
			if(b[i][j] != c){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
