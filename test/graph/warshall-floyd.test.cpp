#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../template/template.hpp"
#include "lib/graph/graph-template.cpp"
#include "lib/graph/warshall-floyd.cpp"

void e2m(Matrix &g,Edges edges,bool directed,length infinity){
	for(auto& e:g)e.resize(g.size(),infinity);
	for(int i=0;i<g.size();++i)g[i][i]=0;
	for(auto& e:edges){
		g[e.src][e.to]=min(g[e.src][e.to],e.cost);
		if(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);
	}
}

int main(){
	int V,E; cin>>V>>E;
	vector<lint>s(E),t(E),d(E); for(int i=0;i<E;++i) cin>>s[i]>>t[i]>>d[i];
	Edges ge(E);
	for(int i=0;i<E;++i)ge[i]=edge(s[i],t[i],d[i]);
	Matrix g(V); e2m(g,ge,1,2*linf);
	warshall_floyd(g);

	bool ok=1;
	for(int i=0;i<V;++i)if(g[i][i]<0)ok=0;
	if(!ok)return cout<<"NEGATIVE CYCLE"<<endl,0;
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(g[i][j]>linf)cout<<"INF";
			else cout<<g[i][j];
			if(j!=V-1)cout<<" ";
		}
		cout<<endl;
	}
}