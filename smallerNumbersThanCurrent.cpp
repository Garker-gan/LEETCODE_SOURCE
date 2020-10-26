/* 
    1365:有多少小于当前数字的数字   计数排序
    Garker-gan
    2020-10-26
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>cnt(101,0);
        for(int i = 0; i < nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        for(int j = 1;j <= 100;j++)
        {
            cnt[j] += cnt[j-1];
        }
        vector<int>temp;
        for(int k = 0;k < nums.size();k++)
        {
            temp.push_back(nums[k] == 0 ? 0:cnt[nums[k]-1]);
        }
        return temp;
    }
};
//写过之后最不想看的代码