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


# :heavy_check_mark: Divisors

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/divisors.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 13:29:24+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/util/divisors.test.cpp.html">test/util/divisors.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
set<lint>divisors(lint n){
	set<lint>ret;
	for(int i=1; i*i<=n; ++i){
		if(n%i==0){
			ret.insert(i);
			if(i*i!=n)ret.insert(n/i);
		}
	}
	return ret;
}

/*
* @title Divisors
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/util/divisors.hpp"
set<lint>divisors(lint n){
	set<lint>ret;
	for(int i=1; i*i<=n; ++i){
		if(n%i==0){
			ret.insert(i);
			if(i*i!=n)ret.insert(n/i);
		}
	}
	return ret;
}

/*
* @title Divisors
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

