/* 
    134. 加油站  动态规划
    Garker-gan
    2020-11-18
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int len = gas.size();
        vector<int>dp(gas.size());
        int total = 0;
        if(gas.size() == 0) return -1;
        for(int i = 0;i < dp.size();i++)
        {
            dp[i] = gas[i] - cost[i];
            total += dp[i];
        }
        if(total < 0)
        {
            return -1;
        }
        int index = -1;
        int sum = 0;
        for(int i = 0;i < dp.size();i++)
        {
            if(sum + dp[i] < 0)
            {
                index = -1;
                sum = 0;
            }
            else
            {
                sum += dp[i];
                // 如果-1就更新为当前遍历到的值，重新开始
                index = index == -1 ? i : index;
            }
        }
        return index;
    }
};