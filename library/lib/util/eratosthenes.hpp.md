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


# :warning: eratosthenes

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/eratosthenes.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-25 18:07:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
int cn[MAXN]; // prime:0
void erat(lint n){
	for(int i=2; i<=n ++i){
		if(!cn[i]){
			for(int j=2*i; j<=n; j+=i)cn[j]=1;
			//i is prime
		}
	}
}

/*
* @title eratosthenes
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/util/eratosthenes.hpp"
int cn[MAXN]; // prime:0
void erat(lint n){
	for(int i=2; i<=n ++i){
		if(!cn[i]){
			for(int j=2*i; j<=n; j+=i)cn[j]=1;
			//i is prime
		}
	}
}

/*
* @title eratosthenes
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

