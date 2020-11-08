 /* 
        5561：获取生成数组中的最大值  模拟
        Garker-gan
        2020-11-08
  */

 #include<iostream>
 #include<queue>
 #include<vector>

 using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        priority_queue<int>q;
        int ans;
        int temp;
        int num[101];
        num[0] = 0;
        num[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            if(i%2 == 0)
                num[i] = num[i/2];
            if(i%2 == 1)
                num[i] = num[i/2] + num[i/2+1];
            q.push(num[i]);
        }   
        ans = q.top();
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.getMaximumGenerated(3)<<endl;
    return 0;
}