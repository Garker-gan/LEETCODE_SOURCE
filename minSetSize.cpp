/* 
    1338. 数组大小减半   贪心（从出现次数最多的数字开始删除）
    Garker-gan
    2020-12-24
 */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>myMap;
        for(int i = 0;i < arr.size();i++)
        {
            myMap[arr[i]]++;
        }
        map<int,int>::iterator it;
        vector<int>myVector;
        for(auto& [k,v]:myMap)
            myVector.push_back(v);
        sort(myVector.begin(),myVector.end(),greater<int>());
        int count = 0;
        int ans = 0;
        for(int c:myVector)
        {
            ans += 1;
            count += c;
            if(count*2 >= arr.size())
                break;
        }
        return ans;
    }
};