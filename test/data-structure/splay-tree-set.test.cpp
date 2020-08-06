#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"
#include "../../test/template/template.hpp"
#include "../../lib/data-structure/splay-tree-set.hpp"

int main(){
	Set s;
	int q; std::cin>>q;
	int t,x;
	for(int i = 0; i<q; ++i){
		std::cin>>t>>x;
		if(t==1){
			s.insert(x);
		}
		else{
			auto ans = s.nth(x-1);
			if(ans)std::cout << ans->val << std::endl;
			if(ans)s.erase(ans->val);
		}
	}
}
