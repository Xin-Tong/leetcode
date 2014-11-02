/*O(n)����һάDP.
����A(0, i)�������k��ʹ��[k, i]��������i��β��������ֵ�� ����ΪMax[i], ���������ȡMax[i+1]ʱ��
Max[i+1] = Max[i] + A[i+1],  if (Max[i] + A[i+1] >0)
                = 0, if(Max[i]+A[i+1] <0)�������С���㣬A[i+1]��Ϊ������û��Ҫ������������
Ȼ���������ɨ�裬��ȡMax���ֵ����ֵ��Ϊ����
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
