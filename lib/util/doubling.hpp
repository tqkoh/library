#pragma once

class Doubling{
public:
	vector<vector<lint>>d;
	lint l = 0;
	Doubling(vector<lint>f, lint maxpow = -1){
		if(maxpow<0)maxpow = f.size();
		l = log2(maxpow)+1;
		d.resize(l, f);
		for(int p = 0; p<l-1; ++p)for(int i=0; i<f.size(); ++i)d[p+1][i] = d[p][d[p][i]];
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
