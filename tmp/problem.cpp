#include <bits/stdc++.h>
using namespace std;

int main(void){
	
	// Reading input
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(auto &row : grid) for(auto &cell : row) cin >> cell;

	int gans = INT_MAX;
	for(int i=0; i < n; i++){
		int l=0, r=m-1, ans=INT_MAX;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(grid[i][mid] == 1){
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		gans = min(gans, ans);
	}

	if(gans == INT_MAX) cout << -1 << '\n';
	else cout << gans+1 << '\n';
}
