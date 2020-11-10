/*  
    859. 亲密字符串 枚举
    Garker-gan
    2020-11-10
 */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int Hash_equal[26] = {0};
        int first = -1;
        int second = -1;
        if(A.length() != B.length())  return false;
        else
        {
            //如何AB为完全相同的字符串，判断字符串中是否出现相同的字符。则可以进行交换
            if(A == B)
            {
                for(int i = 0;i < A.length();i++)
                {
                    Hash_equal[A[i] - 'a']++;
                    if(Hash_equal[A[i]-'a'] > 1)
                        return true;
                }
            }
            else
            {
                for (int i = 0; i < A.length(); i++)
                {
                    if(A[i] != B[i])
                    {
                        if(first == -1) first = i;
                        else
                        {
                            if(second == -1) second = i;
                            else return false;
                        }
                    }
                }
                
            }
            return (second != -1&&A[first] == B[second]&&A[second] == B[first]);
        }
        
    }
};