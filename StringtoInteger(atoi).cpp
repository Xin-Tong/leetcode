class Solution {
public:
    int atoi(const char *str) {
        int res = 0;
        int len = strlen(str);
        int sign = 1; 
        int i = 0;
        while(str[i] == ' ' && i < len) i++;
        
        if(str[i] == '-' && i < len){
            sign = -1;
            i++;
        }
        else if(str[i] == '+' && i < len){
            i++;
        }
        
        for(; i<len; i++){
            if (str[i] == ' ') break;
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            if(res > INT_MAX/10 || (res == INT_MAX/10 && (str[i] - '0') > INT_MAX%10)){
                return sign == -1? INT_MIN : INT_MAX; 
            }
            res = res*10 + str[i] - '0';
        }
        return res*sign;
    }
};