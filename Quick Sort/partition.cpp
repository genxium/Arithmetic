#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int pivotIndex, std::vector<int>& array){
	int n=array.size();
	int targetIndex=0;
	// get pivotValue
	int pivotValue=array[pivotIndex];
	// move pivot to the end
	swap(array[pivotIndex], array[n-1]);

	for(int i=0;i<n-1;i++){
		if(pivotValue>array[i]){
			swap(array[targetIndex], array[i]);
			++targetIndex;
		}
	}
	// put pivotValue to proper position
	swap(array[targetIndex], array[n-1]);

	return targetIndex;
}

int main(){
	// testArray from wikiPedia
	int testArray[]={3,7,8,5,2,1,9,5,4};
	std::vector<int> v;
	v.assign(testArray, testArray+sizeof(testArray)/sizeof(testArray[0]));
	int targetIndex=partition(3, v);
	for(int i=0;i<v.size();i++){
		printf("%d ", v[i]);
	}puts("");
	return 0;
}