/* 
    31.下一个排列   两次遍历
    从后向前遍历，第一次遍历找到出现递减的那个数i
    第二次遍历还是从后往前，找到第一个比i大的数
    Garker-gan
    2020-11-10
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0&&nums[i] >= nums[i+1])
        {
            i--;
        } 
        if(i >= 0)
        {
            int j = nums.size() - 1;
            while(j >= 0&&nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }  
        reverse(nums.begin()+i+1,nums.end());
    }
};