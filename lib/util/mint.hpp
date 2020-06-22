#pragma once
#define md_tmp template<uint_fast64_t md=mod>
md_tmp class modint{
	using u64=uint_fast64_t;

public:
	u64 a;

	constexpr modint(const lint x=0) noexcept: a((x+md)%md){}
	constexpr u64 &value() noexcept{ return a; }
	constexpr const u64 &value() const noexcept{ return a; }
	constexpr modint operator+(const modint rhs) const noexcept{
		return modint(*this)+=rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept{
		return modint(*this)-=rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept{
		return modint(*this)*=rhs;
	}
	constexpr modint operator^(const lint rhs) const noexcept{
		return modint(*this)^=rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept{
		return modint(*this)/=rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept{
		a+=rhs.a;
		if(a>=md)a-=md;
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept{
		if(a<rhs.a)a+=md;
		a-=rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept{
		a=a*rhs.a%md;
		return *this;
	}
	constexpr modint &operator^=(const lint rhs) noexcept{
		if(!rhs)return *this = 1;
		u64 exp=rhs-1;
		modint base=a;
		while(exp){
			if(exp&1)*this*=base;
			base*=base;
			exp>>=1;
		}
		return *this;
	}
	constexpr modint &operator/=(const modint rhs) noexcept{
		a=(*this*(rhs^(md-2))).a;
		return *this;
	}
};
md_tmp istream& operator>>(istream& os,modint<md>& m){
	os>>m.a,m.a%=md;
	return os;
}
md_tmp ostream& operator<<(ostream& os,const modint<md>& m){
	return os<<m.a;
}
using mint = modint<>;

/*
* @title Mint
* @see https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/
