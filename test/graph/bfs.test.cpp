#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include "../../test/template/template.hpp"
#include "../../lib/graph/graph-template.hpp"
#include "../../lib/graph/bfs.hpp"

int main(){
	lint n; cin>>n;
	Graph g(n);
	for(int i = 0; i<n; ++i){
		int u, k; cin>>u>>k; --u;
		for(int j = 0; j<k; ++j){
			int v; cin>>v; --v;
			g.add_edge(u, v, 0, 1);
		}
	}
	vector<lint> d(n, linf); d[0] = 0;
	bfs(n, 0, g, [&](edge e){
		d[e.to] = d[e.src]+1;
	});
	for(int i = 0; i<n; ++i){
		cout<<i+1<<" "<<(d[i]>=linf?-1:d[i])<<endl;
	}
	return 0;
}
