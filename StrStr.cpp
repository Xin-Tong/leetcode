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

//more clear code
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        //int i,j;
        for(int i=0;;i++){
            for(int j=0;;j++){
                if(j == strlen(needle)) return i; //the order is important
                if(i+j == strlen(haystack)) return -1;
                if(needle[j] != haystack[i+j]) break;
            }
        }
    }
};