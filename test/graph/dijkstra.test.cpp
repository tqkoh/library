#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../test/template/template.hpp"
#include "../../lib/graph/graph-template.hpp"
#include "../../lib/graph/dijkstra.hpp"

int main(){
	lint V,E,r; cin>>V>>E>>r;
	Graph g(V);
	vector<lint>s(E), t(E), d(E);  for(int i = 0; i<E; ++i) cin>>s[i]>>t[i]>>d[i];
	for(int i = 0; i<E; ++i)g.add_edge(s[i], t[i], i, 1);

	for(auto& e:dijkstra(g, r, d).first){
		if(e.dist==linf)cout<<"INF"<<endl;
		else cout<<e.dist<<endl;
	}
	return 0;
}
