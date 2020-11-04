/* 
    57.插入区间（A） 模拟
    不在区间左边或者右边的话，就有交集，重新计算他们的并集。
    Garker-gan
    2020-11-4
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int left = newInterval[0];
            int right = newInterval[1];
            bool placed = false;

            //存放结果
            vector<vector<int>>ans;
            for(const auto &interval:intervals)
            {
                //左边
                if(interval[0] > right)
                {
                    if(!placed)
                    {
                        ans.push_back({left,right});
                        placed = true;
                    }
                    ans.push_back(interval);
                }
                // 右边
                else if(interval[1] < left)
                {
                    ans.push_back(interval);
                }
                // 有交集
                else
                {
                    left = min(left,interval[0]);
                    right = max(right,interval[1]);
                }
            }
            if(!placed) ans.push_back({left,right});
            return ans;
    }
};