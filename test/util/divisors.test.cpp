#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "../../test/template/template.hpp"
#include "../../lib/util/divisors.hpp"

int main(){
	lint a,b,c,ans=0; cin>>a>>b>>c;
	auto s=divisors(c);
	for(auto e:s)ans+=a<=e&&e<=b;
	cout<<ans<<endl;
}
