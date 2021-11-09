#pragma once
template<class vFe >
void bfs(int n, int s, Weighted g, vFe dtmn){
	vector<int>vis(n);
	queue<int>q({ s });
	while(q.size()){
		int c = q.front(); q.pop();
		if(vis[c])continue;
		vis[c] = 1;
		each(g[c])if(!vis[e.to])dtmn(e), q.push(e.to);
	}
}

/*
* @title bfs
*/
