#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "test/template/template.hpp"
#include "lib/data-structure/union-find.hpp"

int main(){
	lint n,q; cin>>n>>q;
	UnionFind uf(n);
	while(q--){
		lint t,u,v; cin>>t>>u>>v;
		if(t)cout<<uf.same(u,v)<<endl;
		else uf.unite(u,v);
	}
}