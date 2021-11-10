#pragma once
template<class vFe >
void bfs(int n, int s, Graph g, vFe dtmn){
	vector<int>vis(n); vis[s] = 1;
	queue<int>q({ s });
	while(q.size()){
		int c = q.front(); q.pop();
		for(auto e: g[c])if(!vis[e.to])dtmn(e), vis[e.to] = 1, q.push(e.to);
	}
}

/*
* @title BFS
*/
