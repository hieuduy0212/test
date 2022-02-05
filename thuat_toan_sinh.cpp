#include<bits/stdc++.h>
using namespace std;
int n, s, a[20];
vector<vector<int> > res;
void Try(int i) {
	for(int j=0; j<=1; j++) {
		a[i] = j;
		if(i == s) {
			vector<int> z;
			for(int x = 1 ; x <= s ; ++x) z.push_back(a[x]);
			res.push_back(z);
		} else Try(i+1);
	}
}
main() {
	cin >> n;
	s = n/2;
	memset(a, 0, sizeof(a));
	Try(1);
	if(!(n&1)) {
		for(int i=0; i < res.size(); ++i) {
			vector<int> temp(res[i]);
			for(int j = temp.size() - 1 ; j >= 0 ; --j) {
				res[i].push_back(temp[j]);
			}
		}
	} else {
		int old_size = res.size();
		res.reserve(old_size);
		for(int i=0; i<old_size; ++i) {
			res.push_back(res[i]);
		}

			for(int i=0; i < old_size; ++i) {
				vector<int> temp(res[i]);
				res[i].push_back(0);
				for(int j = temp.size() - 1 ; j >= 0 ; --j) {
					res[i].push_back(temp[j]);
				}
				res[i+old_size].push_back(1);
				for(int j = temp.size() - 1 ; j >= 0 ; --j) {
					res[i+old_size].push_back(temp[j]);
				}
			
		}
	}
	sort(res.begin(), res.end());
	for(int i=0; i<res.size(); i++) {
		for(int j =0 ; j<res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
