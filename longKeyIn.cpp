/* 
        925:长按键入；字符串问题，双指针
        Garker-gan
        2020-10-21
 */
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0; 
        while (j < typed.size())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if(j > 0&&typed[j-1] == typed[j])
            {
                j++;
            }
            else return false;
        }
        return i == name.size();
    }
};

int main()
{
    string name = "saeed";
    string typed = "ssaaedd";
    Solution s;
    cout<<s.isLongPressedName(name,typed)<<endl;

    return 0;
}
