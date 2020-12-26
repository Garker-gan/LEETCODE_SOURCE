/* 
    470. 用 Rand7() 实现 Rand10() 拒绝采样
    Garker-gan
    2020-12-26
 */

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true)
        {
            int a = rand7();
            int num = (a-1)*7+rand7();
            if(num <= 40)   
                return num%10+1;

            a = num - 40;
            num = (a-1)*7+rand7();
            if(num <= 60)   
                return num%10+1;

            a = num - 60;
            num = (a-1)*7+ rand7();
            if(num <= 20)   
                return num%10+1;
        }
    }
};