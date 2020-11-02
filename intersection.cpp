/* 
    349:两个数组的交集  排序+双指针
    Garker-gan
    2020-11-2
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index1 = 0;
        int index2 = 0;
        vector<int>temp;
        int num1;
        int num2;
        while(index1 < nums1.size()&&index2 < nums2.size())
        {
            num1 = nums1[index1];
            num2 = nums2[index2];
            if(num1 == num2)
            {
                if(!temp.size()||num1 != temp.back())
                    temp.push_back(num1);
                index1++;
                index2++;
            }
            else if(num1 < num2)
                index1++;
            else
                index2++;
        }
        return temp;
    }
};
