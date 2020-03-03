#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "test/template/template.cpp"
#include "lib/graph/graph-template.cpp"
#include "lib/graph/warshall-floyd.cpp"

int main(){
	int V,E; cin>>V>>E;
	vector<lint>s(E),t(E),d(E); for(int i=0;i<E;++i) cin>>s[i]>>t[i]>>d[i];
	Edges ge(E);
	for(int i=0;i<E;++i)ge[i]=edge(s[i],t[i],d[i]);
	Matrix g(V); e2m(g,ge,1,linf); //Edges to Matrix

	warshall_floyd(g,linf);
	bool ok=1;
	for(int i=0;i<V;++i)if(g[i][i]<0)ok=0;
	if(!ok)return cout<<"NEGATIVE CYCLE"<<endl,0;
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(g[i][j]==linf)cout<<"INF";
			else cout<<g[i][j];
			if(j!=V-1)cout<<" ";
		}
		cout<<endl;
	}
}