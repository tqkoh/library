#pragma once
template<class Int,uint_fast64_t md=mod>
Int ncr(lint n,lint r){
	if(n<r||n<0||r<0)return Int(0);
	Int ncr_res=1,ncr_div=1;
	for(int i=0; i<r; ++i)ncr_res*=(n-i),ncr_div*=(r-i);
	return ncr_res/ncr_div;
}

/*
* @title Ncr O(r)
*/
