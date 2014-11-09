//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int len=num.size();
        for(int i=0; i<=len-4; i++){
            if(i>0 && (num[i] == num[i-1])) continue;
            for(int j=i+1; j<=len-3; j++){
                if(j>i+1 && (num[j] == num[j-1])) continue;
                int start = j+1;
                int end = len-1;
                while(start < end){
                    int sum = num[i] + num[j] + num[start] + num[end];
                    if(sum == target){
                        vector<int> temp(4);
                        temp[0] = num[i];
                        temp[1] = num[j];
                        temp[2] = num[start];
                        temp[3] = num[end];
                        res.push_back(temp);
                        int small = num[start++];
                        while(start<end && num[start] == small) start++;
                        int big = num[end--];
                        while(start<end && num[end] == big) end--;
                    }
                    else if(sum < target){
                        int small = num[start++];
                        while(start<end && num[start] == small) start++;
                    }
                    else {
                        int big = num[end--];
                        while(start<end && num[end] == big) end--;
                    }
                }
            }
        }
        return res;
    }
};