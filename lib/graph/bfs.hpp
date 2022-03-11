#pragma once
template<class veFi, class vFe >
void bfs(int n, int s, veFi g, vFe dtmn){
	vector<int>vis(n); vis[s] = 1;
	queue<int>q({ s });
	while(q.size()){
		int c = q.front(); q.pop();
		for(auto e: g(c))if(!vis[e.to])vis[e.to] = 1, dtmn(e), q.push(e.to);
	}
}

/*
* @title BFS
*/
