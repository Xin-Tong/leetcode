//dp[i] the longest length from index i
//j : the potential valid string-end index starting from index i
//valid parentheses starting from i, s[i] must be '(', ending in j, s[j] must be ')'
//need to add the longest valid parentheses from index j+1. ()() 2+2 = 4

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len < 2) return 0;
        
        vector<int> dp(len);
        int longest = 0;
        for(int i = len-2; i >= 0; i--){
            if(s[i] == '('){
                int j = i+dp[i+1]+1;
                if(j < len && s[j] == ')'){
                    dp[i] = dp[i+1] + 2;
                    if((j+1) < len){
                        dp[i] += dp[j+1];
                    }
                }
                longest = max(longest, dp[i]);
            }
        }
        return longest;
    }
};