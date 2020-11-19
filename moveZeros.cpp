/* 
    283.移动零  双指针
    Garker-gan
    2020-11-19
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while(right < nums.size())
        {
            if(nums[right])
            {
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
    }
};