#include <vector>
#include <string>
#include <math.h>
using namespace std;

void getPrimeFactor(int N, vector<int>& p, vector<int>& q){
    int store=N;
    int limit=(N>>1);
    for(int i=2;i<=limit;i++){
    	int coefficient=0;
    	while(N%i==0){
    		++coefficient;
    		N/=i;
    	}
    	if(coefficient>0){
    		p.push_back(i);
    		q.push_back(coefficient);
    	}
    }
    if(p.size()==0){
        p.push_back(store);
        q.push_back(1);
    }
}





