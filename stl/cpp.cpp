#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n; cin >> n;
	vector<int> a(n); for(auto &x : a) cin >> x;
	vector<int> b(n); for(auto &x : b) cin >> x;

	vector<int> indices(n);
	// iota(indices.begin(), indices.end(), 0);
	for(int i=0; i < n; i++) indices[i] = i;

	sort(indices.begin(), indices.end(), [&](int i, int j){
		if(a[i] == a[j]) b[i] > b[j];
		return a[i] < a[j];
	});

	for(auto &x : indices)
		cout << x << ' ';
}