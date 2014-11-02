/*O(n)就是一维DP.
假设A(0, i)区间存在k，使得[k, i]区间是以i结尾区间的最大值， 定义为Max[i], 在这里，当求取Max[i+1]时，
Max[i+1] = Max[i] + A[i+1],  if (Max[i] + A[i+1] >0)
                = 0, if(Max[i]+A[i+1] <0)，如果和小于零，A[i+1]必为负数，没必要保留，舍弃掉
然后从左往右扫描，求取Max数字的最大值即为所求。
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int max = INT_MIN;
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum > max){
                max = sum;
            }
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};

//try coding another solution using the divide and conquer approach, which is more subtle.
/*
T(n) = O(1) n=1;
T(n) = 2T(n/2) + O(n) n>1;

So T(n) = nlogn
*/
class Solution {
public:
    int Max(int A[], int left, int right, int maxA){
            if(left>right) return maxA;
            if(left == right) return A[left];
            int mid = (left+right)/2;
            int maxl = Max(A, left, mid, maxA);
            int maxr = Max(A, mid+1, right, maxA);
            maxA = max(maxA, maxl);
            maxA = max(maxA, maxr);
            int sum = 0; 
            int maxml = 0;
            for(int i = mid-1; i>= left; i--){
                sum += A[i];
                if(sum > maxml){
                    maxml = sum;
                }
            }
            sum = 0;
            int maxmr = 0;
            for(int i = mid+1; i<= right; i++){
                sum += A[i];
                if(sum > maxmr){
                    maxmr = sum;
                }
            }
            maxA = max(maxA, maxml+maxmr+A[mid]);
            return maxA;
        }
        
    int maxSubArray(int A[], int n) {
        int maxA = INT_MIN;
        maxA = Max(A, 0, n-1, maxA);
        return maxA;
    }
};
