/* 
    1207：独一无二的出现次数  用第一个哈希表记录数字出现的次数，用第二个哈希表记录数字出现次数的次数
    2020-10-28
    Garker-gan
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>hash1(2001,0);       //存放arr数组中的数出现的次数
        vector<int>hash2(1001,0);       //存放出现次数的次数
        for(int i = 0 ;i < arr.size();i++)
        {
            if(arr[i] >= 0)
                hash1[arr[i]]++;
            //若为负数，则取模成正数，方便下面遍历寻址
            else
                hash1[arr[i]+2000]++;
        }
        //计算次数的次数
        for(int i = 0;i <= 2000;i++)
        {
            //非0意思是，只计算出现的数出现的次数
            if(hash1[i] != 0)
            {
                hash2[hash1[i]]++;
            }
            //如果遍历没结束前已经出现重复次数，直接false
            if(hash2[hash1[i]] > 1)
                return false;
        }
        //遍历结束没有出现重复次数
        return true;
    }
};


int main()
{
    // int n[] = {1,2};
    int n[] = {-3,0,1,-3,1,1,1,-3,10,0};
    // int n[] = {1,2,2,1,1,3};
    vector<int>arr(n,n+10);
    Solution s;
    cout<<s.uniqueOccurrences(arr)<<endl;
    return 0;
}

