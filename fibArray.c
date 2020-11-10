/*  
    剑指 Offer 10- I. 斐波那契数列 非递归实现
    Garker-gan
    2020-11-10
 */
//非递归
int fib(int n){
    int a = 0;
    int b = (n == 0) ? 0 : 1;
    int c = 1e9 + 7;
    int res = a+b;
    for(int i = 0 ; i < n-1 ; i++)
    {
        res = (a + b)%c;
        a = b;
        b = res;
    }
    return res;
}