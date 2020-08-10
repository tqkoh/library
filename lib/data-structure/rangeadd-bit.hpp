#pragma once
template<typename T>
class BIT{
public:
	vector<T> b,a;
	BIT(int sz){ sz+=2;a.assign(sz,0);b.assign(sz,0); }
	void updateAB(int k,T na,T nb){
		for(;k<a.size();k+=k&-k){
			a[k]+=na;
			b[k]+=nb;
		}
	}
	T query(int k){
		T A=0;
		T B=0;
		int start=k;
		for(;k>0;k-=k&-k){
			A += a[k];
			B += b[k];
		}
		return A*--start+B;
	}
	void add(int l,int r,T x){
		updateAB(l,x,-x*(l-1));
		updateAB(r,-x,x*(r-1));
	}
	T sum(int l,int r){
		return query(r)-query(l);
	}
};

/*
* @title Rangeadd Binary Indexed Tree
*/
