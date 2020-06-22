struct status{
	lint dist;
	status(lint n){
		if(!n)dist=0; //initial
		else dist=linf; //infinity
	}
};
constexpr bool operator<(const status& lhs,const status& rhs){
	return lhs.dist<rhs.dist;
}
status operator+(status cur,length& cost){
	cur.dist+=cost;
	return cur;
}

pair<vector<status>,vector<int>> dijkstra(Weighted g,int s){
	vector<int> prv(g.size());
	vector<status> d(g.size(),linf);
	using cont=pair<status,int>;
	priority_queue<cont,vector<cont>,greater<cont> > q;

	d[s]=0;q.push({0,s});
	while(q.size()){
		status cd=q.top().first;
		int cv=q.top().second;
		q.pop();
		if(d[cv]<cd)continue;
		for(edge& e:g[cv])if(cd+e.cost<d[e.to]){
			d[e.to]=cd+e.cost;
			prv[e.to]=cv;
			q.push({d[e.to],e.to});
		}
	}
	return {d,prv};
}

/*
* @title Dijkstra
* @docs docs/
*/