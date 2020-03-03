#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../template/template.cpp"
#include "lib/graph/graph-template.cpp"
#include "lib/graph/dijkstra.cpp"

int main(){
	lint V,E,r; cin>>V>>E>>r;
	vector<lint>s(E),t(E),d(E);  for(int i=0;i<E;++i) cin>>s[i]>>t[i]>>d[i];
	Edges ge(E);
	for(int i=0;i<E;++i)ge[i]=edge(s[i],t[i],d[i]);
	Weighted g(V); e2w(g,ge,1); //Edges to Weighted

	for(auto& e:dijkstra(g,r).first){
		if(e.dist==linf)cout<<"INF"<<endl;
		else cout<<e.dist<<endl;
	}
}