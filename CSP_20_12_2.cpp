/* 
    CCF CSP 2020-12 第二题 70分
    Garker-gan
    2020-12-24
 */

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int m;
    scanf("%d",&m);
    // if(n < 2||n > 100000)   return 0;
    int y[100000];
    int result[100000];
    for(int i = 0;i < m;i++)
    {
        scanf("%d %d",&y[i],&result[i]);
    }

    // 避免重复，存放阈值候选值
    map<int,int>myMap;
    for(int i = 0;i < m;i++)
    {
        myMap[y[i]]++;
    }

    // 迭代器遍历map用
    int predict[100000];
    int max_threshold = 0;
    int max_count = 0;
    map<int,int>::iterator it;
    for(it = myMap.begin();it != myMap.end();it++)
    {
        int count = 0;
        int threshold = it->first;
        for(int i = 0;i < m;i++)
        {
            if(y[i] >= threshold)
            {
                predict[i] = 1;
                if(predict[i] == result[i]) count++;
            }
            else
            {
                predict[i] = 0;
                if(predict[i] == result[i]) count++;
            }
        }
        if(count >= max_count)
        {
            max_count = count;
            max_threshold = threshold;
        }
        
    }
    cout<<max_threshold<<endl;
    return 0;
}