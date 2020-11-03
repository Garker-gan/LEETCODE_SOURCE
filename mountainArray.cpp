/* 
    941:有效的山脉数组  线性扫描
    Garker-gan
    2020-11-3
 */

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        int i = 0;
        if(len < 3) return false;
        while(i+1<len && A[i] < A[i+1])
        {
            i++;
        }
        if(i == 0||i == len - 1)    return false;
        while(i+1 < len && A[i] > A[i+1])
        {
            i++;
        }
        return i == len-1;
    }
};