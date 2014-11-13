//Given two sorted integer arrays A and B, merge B into A as one sorted array.

//Note:
//You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

//because A have enough space we can use it from the end.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=n+m-1;
        int i=m-1; //A
        int j=n-1; //B
        for(; i>=0 && j>=0; k--){
            if(A[i]>B[j]){
                A[k]=A[i];
                i--;
            }
            else{
                A[k]=B[j];
                j--;
            }
        }
        while(j>=0){
            A[k]=B[j];
            j--;
            k--;
        }
        // while(i>=0){
        //     A[k]=A[i];
        //     i--;
        //     k--;
        // }
        //we can comment this part because it is just copy A to A at the same position.
    }
};