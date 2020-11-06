/* 
    1356. 根据数字二进制下 1 的数目排序 公式法
    bit[i] = bit[i>>1] + (1&i); i>>1是除2的意思，&1是判断是否有余数
    写一个函数，统计一个数的二进制数有几个1
    求当前数除以 2 的余数，如果余数是 1，说明当前二进制位是 1，count++
    然后将当前数除以 2，继续求与 2 的余数，继续统计。
    直到数字为 0 。其实就是做 int 数的二进制转换，顺便统计 1。
    求除以 2 的余数可以用位与运算符：n & 1
    除以 2 可以用移位运算符：n >> 1
    Garker-gan
    2020-11-06
 */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>bit(10001,0);
        //递推式求出1-10000的二进制1的个数
        for(int i = 1;i <= 10000;i++)
        {
            bit[i] = bit[i>>1] + (i&1);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if(bit[x] < bit[y])
                return true;
            else if(bit[x] > bit[y])
                return false;
            return x < y;
        }); 
        return arr;
    }
};