#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, int>::iterator mapIter;
struct cmp
{
	bool operator()(mapIter &l , mapIter &r)
	{
		return l->second > r->second; //小顶堆 每次弹出min
//		return l->second < r->second; //大顶堆
	}
};
//time complexity O(N) + O(N' logk） k==1 O(N+N')
vector<string> getTopkV1(const vector<string>& strs, int k)
{
	vector<string> res;
	if(k <= 0) return res;
	unordered_map<string, int> mymap;
	for(size_t i = 0; i < strs.size(); i++)
		mymap[strs[i]]++;

	s

	if(k >= mymap.size())
	{
		for(mapIter it = mymap.begin(); it != mymap.end(); it++)
			myQ.push(it);
	}
	else
	{
		mapIter it = mymap.begin();
		for(int i = 0; i < k; i++, it++)
			myQ.push(it);

		for(; it!= mymap.end(); it++)
		{
			myQ.push(it);
			myQ.pop();
		}
	}
	while(!myQ.empty())
	{
		mapIter it = myQ.top();
		myQ.pop();
		res.push_back(it->first);
	}
	return res;
}

int partition(vector<mapIter>& iters, int start, int end, int pivotIndex)
{
	mapIter pivotValue = iters[pivotIndex];
    swap(iters[pivotIndex], iters[end]);
    int storeIndex = start;
	for(int i = start; i < end; i++)
    {
		if(iters[i]->second < pivotValue->second)
        {
			swap(iters[storeIndex], iters[i]);
            storeIndex++;
		}
	}
    swap(iters[end], iters[storeIndex]);
    return storeIndex;
}

void quickSelect(vector<mapIter>& iters, int start, int end, int k)
{
	if(!(start <= k && k <= end))
         return;
	int pivotIndex = start + rand() % (end - start + 1);
	pivotIndex = partition(iters, start, end, pivotIndex);
    if(k == pivotIndex)
         return;
    else if(k < pivotIndex)
         quickSelect(iters, start, pivotIndex - 1, k);
    else
         quickSelect(iters, pivotIndex + 1, end, k);

}
vector<string> getTopkV2(vector<string> strs, int k)
{
	vector<string> res;
	if(k <= 0) return res;
	unordered_map<string, int> mymap;
	for(size_t i = 0; i < strs.size(); i++)
		mymap[strs[i]]++;

	int j = 0;
	vector<mapIter> iters(mymap.size());
	mapIter it = mymap.begin();
	for( ; it != mymap.end(); it++)
		iters[j++] = it;

	quickSelect(iters, 0, (int)iters.size()-1, (int)iters.size()-k);
	for(size_t i = max((int)iters.size()-k, 0); i < iters.size(); i++)
		res.push_back(iters[i]->first);
	return res;
}

string getRandomLine(string fileName)
{
	ifstream fin(fileName);
	if(!fin) return "";
	string line, res;
	int count = 0;
    while(getline(fin, line))
    {
        count++;
		if (rand() / (float)RAND_MAX <= 1.0 / count)
			res = line;
    }
	return res;
}

int main()
{
	string sss[] = {"sasa", "bb", "dsds", "rty", "dsada", "32", "fdsfds",
					"sasa", "bb", "dsds", "bb", "dsds", "rty", "dsada",
					"bb", "dsds", "rty", "dsada", "rty", "dsada", "32",
					"rty", "dsada", "32", "dsds", "rty", "dsada", "rty",
					"rty", "dsada", "32", "fdsfds", "sasa", "bb", "rty",
					"32", "fdsfds", "sasa", "bb", "dsds", "bb", "dsds",
					"bb", };

	vector<string> strs(sss, sss+43);

	unordered_map<string, int> mymap;
	for(size_t i = 0; i < strs.size(); i++)
		mymap[strs[i]]++;

    for(auto it = mymap.begin(); it != mymap.end(); it++)
        cout << it->first << " " << it->second << endl;
    cout << endl;

	vector<string> tyu = getTopkV1(strs, 5);
	vector<string> tyu1 = getTopkV2(strs, 5);

	for(int i = 0; i < tyu.size(); i++)
        cout << tyu[i] << endl;
    cout << endl;
    for(int i = 0; i < tyu.size(); i++)
        cout << tyu1[i] << endl;

	srand(time(NULL));
	for(int i = 0; i < 10; i++)
		cout<<getRandomLine("yelp.cpp")<<endl;
	return 0;
}
