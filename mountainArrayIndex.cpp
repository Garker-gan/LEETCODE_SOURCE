/* 
    852：山脉数组的峰顶索引
    Garker-gan
    2020-11-3
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int i = 0;
        while(i+1 < len&&arr[i]<arr[i+1])
        {
            i++;
        }
        int temp = i;
        // if(i == 0||i == len - 1)    return false;
        return temp; 
    }
};