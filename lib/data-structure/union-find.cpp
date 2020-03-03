class UnionFind{
public:
	vector<int>par,rank;
	UnionFind(int n){
		par.resize(n);rank.resize(n,0);
		for(int i=0;i<n;++i)par[i]=i;
	}
	int root(int x){
		return x==par[x]?x:par[x]=root(par[x]);
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
	void unite(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y)return;
		if(rank[x]<rank[y])par[x]=y;
		else{
			par[y]=x;
			if(rank[x]==rank[y])++rank[x];
		}
	}
};

/**
* @title Union Find
* @brief 集合の合併を扱うデータ構造
*/