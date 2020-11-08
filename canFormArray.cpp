/* 
    1640:能否连接形成数组   map存放，遍历比较
    遍历pieces里面的数字，如果在map中没有记录，返回false，如果pieces中当前的行不只一个数，则判断相邻两个数是否在arr中从左往右连续，不符合则返回false
    排除所有false情况，则为true
    Garker-gan
    2020-11-08
 */
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int>myMap;
        //第一个元素赋值
        for(int i = 0;i < arr.size();i++)
        {
            myMap[arr[i]] = i+1;
        }
        int x;
        for(int i = 0;i < pieces.size();i++)
        {
            for(int j = 0; j < pieces[i].size();j++)
            {
                if(myMap[pieces[i][j]] == 0)   return false;
                if(j > 0)
                {
                     x = myMap[pieces[i][j]] - myMap[pieces[i][j-1]];
                     if(x != 1)
                         return false;
                }
            }
        }
        return true;
    }
};