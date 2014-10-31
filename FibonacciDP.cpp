//from dao
#include <iostream>
#include <vector>
using namespace std;

int getFib(int n, vector<int>& cache){
	if(n<0) return 0;
	if(n<=1) return n;
	if(cache[n] == -1)
		cache[n] = getFib(n-1, cache) + getFib(n-2, cache);
	return cache[n];
}

int main()
{
	int n = 9;
	vector<int> cache(n+1, -1);
	cout<<getFib(n,cache);
	return 0;
}



