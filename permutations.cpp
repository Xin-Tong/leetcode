class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector< vector<int> > res;
        if(num.empty()) return res;
        helper(num, 0, res);
        return res;
    }
    void helper(vector<int> &num, int start, vector<vector<int>> &res){
        if(start == num.size()){
            res.push_back(num);
        }
        else{
            for(int i = start; i<num.size(); i++){
                if(i==start)
                helper(num, start+1, res);
                else{
                    swap(num[i], num[start]);
                    helper(num, start+1, res);
                    swap(num[i],num[start]);
                }
            }
        }
    }
};