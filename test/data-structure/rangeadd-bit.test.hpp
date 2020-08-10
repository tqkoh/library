#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "../../test/template/template.hpp"
#include "../../lib/data-structure/rangeadd-bit.hpp"

int main(){
	lint n,q; cin>>n>>q;
	BIT<lint> ki(n+2);
	while(q--){
		lint ty; cin>>ty;
		if(ty){
			lint s,t; cin>>s>>t;
			cout<<ki.sum(s,t+1)<<endl;
		}
		else{
			lint s,t,x; cin>>s>>t>>x;
			ki.add(s,t+1,x);
		}
	}
}
