#pragma once
int cn[MAXN];// ‡¬”‚È‚ç1, ‘f”‚È‚ç0
void erat(lint n){// O(nlogn)
	for(int i=2; i<=n ++i){
		if(!cn[i]){
			for(int j=2*i; j<=n; j+=i)cn[j]=1;
			//i is prime
		}
	}
}

/*
* @title eratosthenes
*/