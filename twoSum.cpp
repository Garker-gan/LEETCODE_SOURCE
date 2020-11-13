/* 
    1.两数之和  哈希
    Garker-gan
    2020-11-13
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>myMap;

        for(int i = 0;i < nums.size();i++)
        {   
            // 先查找哈希表中有没有他的另一个加数，避免和自己重复
            auto it = myMap.find(target-nums[i]);
            //如果找到了就返回
            if(it != myMap.end())
            {
                return {it->second,i};
            }
            // 没有找到就放在哈希表中
            myMap[nums[i]] = i;
        }
        // 一次遍历什么也没找到返回空
        return {};
    };
};
