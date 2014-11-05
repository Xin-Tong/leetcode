class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, int> mp; //string: sorted string, int: position
        int len = strs.size();
        for(int i=0; i<len; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                res.push_back(strs[i]);
                if(mp[temp] != -1){    //get map value []
                    res.push_back(strs[mp[temp]]);
                    mp[temp] = -1;
                }
            }
            else
            mp[temp] = i;
        }
        return res;
    }
};