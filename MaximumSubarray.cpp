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

