/* 
    398. 随机数索引  蓄水池抽样问题（k/i） 
    Garker-gan
    2020-12-24
 */
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums; 
    }
    
    int pick(int target) {
        int count = 0;
        int ans = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == target)
            {
                //统计当前target数量
                count++;
                // 当随机数为count的是概率即为1/n
                if(rand()%count == 0)   ans = i;
            }
        }
        return ans;
    }

private:
        vector<int>nums;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */