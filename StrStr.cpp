//Implement strStr() 
//brute force solution
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL) return -1;
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        if(hLen < nLen) return -1;
        for(int i=0; i<=hLen-nLen; i++){
            char *tmp = &haystack[i];
            int j=0;
            for(; j<nLen; j++){
                if(*tmp != needle[j]){
                    break;
                }
                tmp++;
            }
            if(j == nLen){
                return i;
            }
        }
        return -1;
    }
};