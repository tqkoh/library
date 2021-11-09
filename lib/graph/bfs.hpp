#pragma once
template<class viFi, class vFe >
void bfs(int n, int s, viFi next, vFe dtmn){
	vector<int>vis(n);
	queue<int>q({ s });
	while(q.size()){
		int c = q.front(); q.pop();
		if(vis[c])continue;
		vis[c] = 1;
		each(next(c))if(!vis[e.to])dtmn(e), q.push(e.to);
	}
}

/*
* @title bfs
*/
