using length=lint;
struct edge{
	int src,to;
	length cost;

	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

/*
* @brief Graph Template
*/