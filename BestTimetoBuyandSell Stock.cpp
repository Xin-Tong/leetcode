//keep track of the minimal price in the left
//calculate the difference between current price and the minimal price
//if the current difference larger than the current max difference
//replace it
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = INT_MAX;
        int max = 0;
        int diff;
        int len = prices.size();
        for(int i=0; i<len; i++){
            if(prices[i] < min){
                min = prices[i];
            } 
            diff = prices[i] - min;
            if(diff > max){
                max = diff;
            }
        }
        return max;
    }
};