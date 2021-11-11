#define PROBLEM "https://atcoder.jp/contests/abc167/tasks/abc167_d"
#include "../../test/template/template.hpp"
#include "../../lib/util/doubling.hpp"

int main(){
	lint n, k; cin>>n>>k;
	vector<lint>a(n); for(int i = 0; i<n; ++i)cin>>a[i], --a[i];
	Doubling f(a, 1e18+1);
	cout<<f(k, 0)+1<<endl;
}
