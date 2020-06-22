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


# :warning: Ncr

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/ncr.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 16:37:39+09:00




## Depends on

* :warning: <a href="mint.hpp.html">Mint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/util/mint.hpp"
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
#line 3 "lib/util/ncr.hpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

