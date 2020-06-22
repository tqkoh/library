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


# :warning: Ncr O(r)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/ncr-or.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 16:37:39+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/util/ncr-or.hpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

