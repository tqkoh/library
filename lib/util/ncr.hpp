#pragma once
#include "../../lib/util/mint.hpp"
#define MAXN 10000010
md_tmp class Ncr{
	lint m;
public:
	mint fa[MAXN],rfa[MAXN];
	Ncr(lint n):m(n){
		fa[0]=1;
		for(int i=1; i<m; ++i)fa[i]=(fa[i-1]*i);
		rfa[m-1]=mint(1)/fa[m-1];
		for(int i=m-2; i>=0; --i)rfa[i]=rfa[i+1]*(i+1);
	}
	inline mint ncr(lint n,lint r){ if(n<r||n<0||r<0)return 0m; return(fa[n]*rfa[r]*rfa[n-r]); }
};
Ncr<> c(MAXN);
#undef MAXN

/*
* @title Ncr
*/
