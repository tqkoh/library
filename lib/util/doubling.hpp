#pragma once

class Doubling{
public:
	vector<vector<lint>>d;
	lint l = 0;
	Doubling(vector<lint>a, lint maxpow = -1){
		if(maxpow<0)maxpow = a.size();
		while((1LL<<l)<=maxpow)++l;
		d.resize(l, a);
		rep(p, l-1)rep(a.size())d[p+1][i] = d[p][d[p][i]];
	}
	lint operator()(lint pow, lint i){
		for(lint j = 0; pow; ++j){
			if(pow%2)i = d[j][i];
			pow >>= 1;
		}
		return i;
	}
};

/*
* @title Doubling
*/
