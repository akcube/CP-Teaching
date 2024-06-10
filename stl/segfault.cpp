#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
	vector<int> a(32);
	int n; cin >> n;
	for(int i=0; i < n; i++) a[i] = 42;
	for(auto &x : a) cout << x << '\n';
}
