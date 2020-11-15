/* 
    402. 移掉K位数字 贪心+队列
    Garker-gan
    2020-11-15
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>v;
        for(auto& digtal:num)
        {
            while(v.size()>0 && v.back() > digtal && k)
            {
                k--;
                v.pop_back();
            }
            v.push_back(digtal);
        }
        // k个数字没有完全退完
        for(;k > 0;k--)
        {
            v.pop_back();
        }
        //判断有无先导0
        bool isLeadingZero = true;
        string ans = "";
        for(auto & digtal:v)
        {
            if(isLeadingZero&&digtal == '0')
            {
                continue;
            }
            isLeadingZero = false;
            ans += digtal;
        }
        return ans == ""? "0":ans;
    }
};