#include <bits/stdc++.h>
using namespace std;

struct user{
	int id;
	string name;
	string password;
};

int main(){
	user users[2];
	for(int i=0; i < 2; i++){
		user user;
		cout << "User NB " << i+1 << endl;
		cout << "ID:";
		cin >> user.id;
		cout << "Name:";
		cin >> user.name;
		cout << "Password:";
		cin >> user.password;
	}
	for(user user: users){
		cout << user.id << " | " << user.name << " | " << user.password << endl;
	}
	return 0;
}
