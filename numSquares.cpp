/* 
    279. 完全平方数 数学方法
    Joseph Louis Lagrange证明了一个定理，称为四平方和定理，也称为 Bachet 猜想，它指出每个自然数都可以表示为四个整数平方和
    Adrien Marie Legendre用他的三平方定理完成了四平方定理，证明了正整数可以表示为三个平方和的一个特殊条件：n=4`k(8m+3)
    Garker-gan
    2020-11-04
 */
class Solution {
public:
    bool isQuart(int n){
        int squ = sqrt(n);
        return n == squ*squ;
    }
    int numSquares(int n) {
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return 4;
        
        if(isQuart(n))
            return 1;
        
        for(int i = 1;i*i < n;i++)
        {
            if(isQuart(n - i*i))
                return 2;
        }
        return 3;
    }
};