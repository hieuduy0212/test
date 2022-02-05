#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > res;
int n, k;
vector<int> a(101), x(101);
void Try(int i){
    for(int j=0;j<=1;++j){
        x[i] = j;
        if(i == n) {
            int sum = 0;
            for(int z = 1; z <= n; ++z){
                sum += a[z] * x[z];
            }
            if(sum == k){
                vector<int> t;
                for(int z = 1 ;z <= n; ++z){
                    if(x[z]==1) t.push_back(a[z]);
                }
                res.push_back(t);
            }
        } else Try(i+1);
    }
}
main()
{
    cin >> n >> k;
    a.resize(n+1);
    x.resize(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    Try(1);
    for(int i = 0 ; i < res.size() ; ++i ){
        for(int j = 0 ; j < res[i].size() ; ++j){
            cout << "\t" << res[i][j];
        }
        cout << endl;
    }
    cout << res.size();
    a.clear();
    x.clear();
}