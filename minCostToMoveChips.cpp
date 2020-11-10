/*  
    1217. 玩筹码 阅读理解题
    理解成求数组中的奇偶数个数即可
    Garker-gan
    2020-11-10
 */
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int m=0,n=0;
        for(auto i=0;i<chips.size();++i)
        {
            if(chips[i]%2==0)m++;
            else n++;
        }
        return (m<n)?m:n;
    }
};