void warshall_floyd(Matrix &g){
	rep(k,g.size())rep(g.size())rep(j,g.size())chmin(g[i][j],g[i][k]+g[k][j]);
	for(int k=0;k<g.size();++k){
		for(int i=0;i<g.size();++i){
			for(int j=0;j<g.size();++j){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
/*
* @brief Warshall Floyd
*/