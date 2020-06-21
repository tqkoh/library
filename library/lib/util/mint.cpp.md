---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Mint

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/mint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:46:24+09:00


* see: <a href="https://noshi91.hatenablog.com/entry/2019/03/31/174006">https://noshi91.hatenablog.com/entry/2019/03/31/174006</a>


## Required by

* :warning: <a href="ncr.cpp.html">Ncr</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define md_tmp template<uint_fast64_t md=mod>
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
// inline modint<> operator""m(const unsigned long long n){ return modint<>(n); }
using mint = modint<>;
#endif

/*
* @title Mint
* @see https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/util/mint.cpp"
﻿#define md_tmp template<uint_fast64_t md=mod>
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
// inline modint<> operator""m(const unsigned long long n){ return modint<>(n); }
using mint = modint<>;
#endif

/*
* @title Mint
* @see https://noshi91.hatenablog.com/entry/2019/03/31/174006
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

