#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string, int> persons;
	int n;
	cin >> n;
	while(n--){
		string name;
		int age;
		cout << "Enter name & age :" ;
		cin >> name >> age;
		persons.insert(make_pair(name, age));
	}
	for(map<string, int>::iterator it = persons.begin(); it  !=  persons.end(); it++){
		cout << it->first << it->second << endl;
	}
	return 0;
}
