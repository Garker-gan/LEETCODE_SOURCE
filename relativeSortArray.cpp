/* 
    1122. 数组的相对排序(简单)   哈希map
    Garker-gan
    2020-11-14
 */
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>Hash;
        // 将arry1的放入map中，以便直接对arry1原地修改
        for(int i = 0;i < arr1.size();i++)
        {
            Hash[arr1[i]]++;
        }   
        // 计数
        int count = 0;
        // 先按arr2的相对顺序排序
        for(int i = 0;i < arr2.size();i++)
        {
            int temp =  Hash[arr2[i]];
            for(int j = 0;j < temp;j++){
                arr1[count++] = arr2[i];
                // 已经排过序的数置0
                Hash[arr2[i]] = 0;
            }
        }
        map<int,int>::iterator it = Hash.begin();
        // 将剩余的数从小到大排序
        while(it != Hash.end())
        {
            if(it->second != 0)
            {
                for(int i = 0;i < it->second;i++)
                    arr1[count++] = it->first;
            }
            it++;
        }
        return arr1;
    }
};

int main()
{
    vector<int>arr1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int>arr2{2,1,4,3,9,6};
    Solution s;
    vector<int>arr = s.relativeSortArray(arr1,arr2);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"  ";
    }
    
}