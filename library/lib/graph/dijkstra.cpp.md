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
    - Last commit date: 2020-06-21 18:24:14+09:00




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
* @param[in] g 負辺のないグラフ, s 始点
* @param[out] (s から各頂点への最短パスの長さ, 前の頂点番号) 
* @brief O(E log V)
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
* @param[in] g 負辺のないグラフ, s 始点
* @param[out] (s から各頂点への最短パスの長さ, 前の頂点番号) 
* @brief O(E log V)
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

