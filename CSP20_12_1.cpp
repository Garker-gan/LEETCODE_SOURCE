/* 
    CCF CSP 2020-12 第一题 100分
    Garker-gan
    2020-12-24
 */
#include<stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n < 2||n > 100000)   return 0;
    int w[100000];
    int score[100000];
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d",&w[i],&score[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += w[i]*score[i];
    }
    if(sum > 0)
        printf("%d",sum);
    else
        printf("%d",0);

    return 0;
}