//Given a non-negative number represented as an array of digits, plus one to the number.

//The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result(digits.size(), 0);  //need to init to visit result[i]
        int car=1; //plus one
        int sum=0;
        for(int i=digits.size()-1; i>=0; i--){
            sum=digits[i]+car;
            car=sum/10;
            result[i]=sum%10;
        }
        if(car>0){
            result.insert(result.begin(), car);
        }
        return result;
    }
};