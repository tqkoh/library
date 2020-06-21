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


# :x: Dijkstra

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 18:44:56+09:00


* see: <a href="https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95">https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95</a>


## Verified with

* :x: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿struct status{
	lint dist;
	status(lint n){
		if(!n)dist=0; //initial
		else dist=linf; //infinity
	}
};
constexpr bool operator<(const status& lhs,const status& rhs){
	return lhs.dist<rhs.dist;
}
status operator+(status cur,length& cost){
	cur.dist+=cost;
	return cur;
}


pair<vector<status>,vector<int>> dijkstra(Weighted g,int s){
	vector<int> prv(g.size());
	vector<status> d(g.size(),linf);
	using cont=pair<status,int>;
	priority_queue<cont,vector<cont>,greater<cont> > q;

	d[s]=0;q.push({0,s});
	while(q.size()){
		status cd=q.top().first;
		int cv=q.top().second;
		q.pop();
		if(d[cv]<cd)continue;
		for(edge& e:g[cv])if(cd+e.cost<d[e.to]){
			d[e.to]=cd+e.cost;
			prv[e.to]=cv;
			q.push({d[e.to],e.to});
		}
	}
	return {d,prv};
}

/*
* @title Dijkstra
* @docs docs/data-structure/dijkstra.md
* @see https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/dijkstra.cpp"
﻿struct status{
	lint dist;
	status(lint n){
		if(!n)dist=0; //initial
		else dist=linf; //infinity
	}
};
constexpr bool operator<(const status& lhs,const status& rhs){
	return lhs.dist<rhs.dist;
}
status operator+(status cur,length& cost){
	cur.dist+=cost;
	return cur;
}


pair<vector<status>,vector<int>> dijkstra(Weighted g,int s){
	vector<int> prv(g.size());
	vector<status> d(g.size(),linf);
	using cont=pair<status,int>;
	priority_queue<cont,vector<cont>,greater<cont> > q;

	d[s]=0;q.push({0,s});
	while(q.size()){
		status cd=q.top().first;
		int cv=q.top().second;
		q.pop();
		if(d[cv]<cd)continue;
		for(edge& e:g[cv])if(cd+e.cost<d[e.to]){
			d[e.to]=cd+e.cost;
			prv[e.to]=cv;
			q.push({d[e.to],e.to});
		}
	}
	return {d,prv};
}

/*
* @title Dijkstra
* @docs docs/data-structure/dijkstra.md
* @see https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

