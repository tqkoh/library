#include "lib/util/mint.cpp"

md_tmp modint<md> ncr(lint n,lint r){
	if(n<r||n<0||r<0)return modint<md>(0);
	modint<md>ncr_res=1,ncr_div=1;
	for(int i=0;i<r;++i)ncr_res*=n-i, ncr_div*=r-i;
	return ncr_res/ncr_div;
}
lint ncri(lint n,lint r){
	if(n<r||n<0||r<0)return 0;
	lint ncr_res=1,ncr_div=1;
	for(int i=0;i<r;++i)ncr_res*=n-i, ncr_div*=r-i;
	return ncr_res/ncr_div;
}
md_tmp class Bigncr{
	lint m;
public:
	mint fa[10000010],rfa[10000010];
	Bigncr(lint n):m(n){
		fa[0] = 1;
		for(int i=1;i<m;++i)fa[i] = (fa[i-1]*i);
		rfa[m-1] = mint(1)/fa[m-1];
		for(int i=m-2;i>=0;--i)rfa[i] = rfa[i+1]*(i+1);
	}
	inline mint get(lint n,lint r){ if(n<r||n<0||r<0)return 0m; return(fa[n]*rfa[r]*rfa[n-r]); }
};
Bigncr<> c(10000010);

/*
* @title Ncr
*/