/* 
    922. 按奇偶排序数组 II（容易）   双指针
    Garker-gan
    2020-11-12
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        int j = 1;  //j指向奇数位置
        for(int i = 0; i < len;i+=2)    //i指向偶数位置
        {
            if(A[i]%2 == 1)     //如果偶数位置是奇数
            {   
                while(A[j]%2 == 1)  //则寻找在奇数位置上的偶数
                {
                    j += 2;
                }
                swap(A[i],A[j]);    //交换奇数位置上的偶数，和偶数位置上的奇数
            }
        }
        return A;
    }
};