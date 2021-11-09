#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../../test/template/template.hpp"
#include "../../lib/graph/graph-template.hpp"
#include "../../lib/graph/warshall-floyd.hpp"

int main(){
	lint V,E; cin>>V>>E;
	Matrix g(V);
	vector<lint>s(E), t(E), d(E);  for(int i = 0; i<E; ++i) cin>>s[i]>>t[i]>>d[i];
	for(int i = 0; i<E; ++i)g.add_edge(s[i], t[i], d[i], 1);
	if(warshall_floyd(g, 2*linf))return cout<<"NEGATIVE CYCLE\t", 0;
	for(int i = 0; i<V; ++i){
		for(int j = 0; j<V; ++j){
			cout<<(g[i][j]==2*linf?"INF":to_string(g[i][j]));
			if(j!=V-1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
