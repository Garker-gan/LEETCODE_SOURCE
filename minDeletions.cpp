 /* 
        5562. 字符频次唯一的最小删除次数    两次哈希
        Garker-gan
        2020-11-08
  */

 #include<iostream>
 #include<map>
 #include<iterator>
 using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        map<int,int>m1;  //字频
        map<int,int>m2;      //相同的字频
        map<int,int>::iterator it1;
        map<int,int>::iterator it2;
        //统计字频
        for(int i = 0;i < s.length();i++)
        {
            m1[s[i]-'a']++;
        }
        for(it1 = m1.begin();it1 != m1.end();it1++)
        {
            m2[it1->second]++;
        }
        int count = 0;
        int temp = 0;
        int repeat = 0;
        for(it2 = m2.begin();it2 != m2.end();it2++)
        {
            cout<<it2->second<<endl;
            if(it2->second == 0) temp = count;
            if(it2->second > 1)  repeat = it2->second;
            count++;
        }
        cout<<repeat<<" "<<temp<<endl;
        return repeat-temp;
    }
};

int main()
{
    Solution s;
    // a b c d
    // 4 2 4 6
    cout<<s.minDeletions("accdcdadddbaadbc")<<endl;
    return 0;
}