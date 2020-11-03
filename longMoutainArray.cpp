/* 
        845：数组中的最长的山脉 双指针找到其中山脉的两个山脚
        Garker-gan 
        2020-11-3
 */
#include<iostream>
#include<vector>
using  namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0;
        int n = A.size();
        int ans = 0;
        while(left+2 < n)
        {
            int right = left + 1;
            if(A[left] < A[left+1])
            {
                while(right+1 < n && A[right] < A[right+1])
                {
                    right++;   
                }
                if(right+1 < n && A[right] > A[right+1])
                {
                    while(right+1 < n && A[right] > A[right+1])
                    {
                        right++;
                    }
                    ans = max(ans,right-left+1);
                }
                else
                {
                    right++;
                }
            }
            left = right;
        }
        return ans;
    }
};


int main()
{
    vector<int>A = {2,1,4,7,3,2,5};
    Solution s;
    cout<<s.longestMountain(A)<<endl;
    return 0;
}