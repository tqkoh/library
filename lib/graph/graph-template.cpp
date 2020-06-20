using length=lint;
struct edge{
	int src,to;
	length cost;
	edge()=default;
	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

void e2w(Weighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e);
		if(!directed)g[e.to].push_back(edge(e.to,e.src,e.cost));
	}
}
void e2u(UnWeighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e.to);
		if(!directed)g[e.to].push_back(e.src);
	}
}
void e2m(Matrix& g,Edges edges,bool directed,length infinity){
	for(auto& e:g)e.resize(g.size(),infinity);
	for(int i=0;i<g.size();++i)g[i][i]=0;
	for(auto& e:edges){
		g[e.src][e.to]=min(g[e.src][e.to],e.cost);
		if(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);
	}
}


/*
* @title Graph Template
*/