#define md_tmp template<uint_fast64_t md=mod>
md_tmp class modint{
public:
	uint_fast64_t a;

	constexpr modint(const lint x = 0) noexcept: a((x+md)%md){}
	constexpr uint_fast64_t &value() noexcept{ return a; }
	constexpr const uint_fast64_t &value() const noexcept{ return a; }
	constexpr modint operator+(const modint rhs) const noexcept{
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept{
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept{
		return modint(*this) *= rhs;
	}
	constexpr modint operator^(const lint rhs) const noexcept{
		return modint(*this) ^= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept{
		return modint(*this) /= rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept{
		a += rhs.a;
		if(a>=md)a -= md;
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept{
		if(a<rhs.a)a += md;
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept{
		a = a*rhs.a%md;
		return *this;
	}
	constexpr modint &operator^=(const lint rhs) noexcept{
		if(!rhs)return *this = 1;
		u64 exp = rhs-1;
		modint base = this->a;
		while(exp){
			if(exp&1)*this *= base;
			base *= base;
			exp >>= 1;
		}
		return *this;
	}
	constexpr modint &operator/=(const modint rhs) noexcept{
		a = (*this*(rhs^(md-2))).a;
		return *this;
	}
};
md_tmp istream& operator>>(istream& os,modint<md>& m){
	os>>m.a,m.a %= md;
	return os;
}
md_tmp ostream& operator<<(ostream& os,const modint<md>& m){
	return os<<m.a;
}
#ifndef _AOJ_
inline modint<> operator""m(const unsigned long long n){ return modint<>(n); }
using mint = modint<>;
#endif

/*
* @title Mint
*/