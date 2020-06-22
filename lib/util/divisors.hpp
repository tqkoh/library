#pragma once
set<lint>divisors(lint n){
	set<lint>ret;
	for(int i=1; i*i<=n; ++i){
		if(n%i==0){
			ret.insert(i);
			if(i*i!=n)ret.insert(n/i);
		}
	}
	return ret;
}

/*
* @title Divisors
*/
