#pragma once
using length = lint;
struct edge{
	int src, to, id;
	edge() = default;
	edge(int src, int to, int id = 0): src(src), to(to), id(id){}
};

using Edges = vector<edge>;
class Weighted: public vector<Edges>{
public:
	Weighted(int n){
		this->resize(n);
	}
	void add_edge(edge e, bool directed = 0){
		(*this)[e.src].push_back(e);
		if(!directed)(*this)[e.to].push_back(edge(e.to, e.src, e.id));
	}
	void add_edge(int src, int to, int id = 0, bool directed = 0){
		(*this)[src].push_back(edge(src, to, id));
		if(!directed)(*this)[to].push_back(edge(to, src, id));
	}
};
class Matrix: public vector<vector<length>>{
public:
	Matrix(int n, length inf = 2*linf){
		this->resize(n, vector<length>(n, inf));
		rep(n)(*this)[i][i] = 0;
	}
};


/*
* @title Graph Template
*/


/*
* @title Graph Template
*/
