#include <bits/stdc++.h>
using namespace std;
struct voiture{
	int puissance;
	int nbPortes;
	voiture(int p, int np){
		puissance = p;
		nbPortes = np;
	}
};

bool compare(voiture v1, voiture v2) {
	return v1.puissance < v2.puissance;
}

vector<voiture> arr;
int main(){
	int n;
	cout << "Nb voiture:";
	cin >> n;
	while(n--){
		int a,b;
		cout << "Entrer la puissance et le nombre des portes : ";
		cin >> a >> b; 
		arr.push_back(voiture(a, b));
	}
	sort(arr.begin(), arr.end(), compare);
	for(voiture v : arr)
		cout << "Puissance:" << v.puissance << " | Nb Porte:" << v.nbPortes << endl;
	return 0;
}
