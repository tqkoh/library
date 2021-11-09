#pragma once
int warshall_floyd(Matrix& g, length inf = 2*linf){
	int n = g.size();
	for(int k = 0; k<n; ++k){
		for(int i = 0; i<n; ++i){
			for(int j = 0; j<n; ++j){
				if(g[i][k]==inf||g[k][j]==inf)continue;
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
	for(int i = 0; i<n; ++i){
		if(g[i][i]<0)return 1;
	}
	return 0;
}
/*
* @title Warshall Floyd
* @brief returns 1 if negative cycle exists
*/
