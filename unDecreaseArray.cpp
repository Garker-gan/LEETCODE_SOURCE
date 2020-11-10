/*  
    665. 非递减数列 遍历修改第一个递增的值
    Garker-gan
    2020-11-10
 */
bool checkPossibility(int *nums,int numSize)
{
    int decrese_flag = 0;
    for (int i = 0; i < numSize-1; i++)
    {
        // printf("%d次\n",i);
        if(nums[i] > nums[i+1])
        {
            decrese_flag++;
            if(i < 1)
                nums[i] = nums[i+1];
            else 
            {
                if(nums[i-1] > nums[i+1] )
                    nums[i+1] = nums[i];
                else
                    nums[i] = nums[i+1];
            }
            
        }
    }
    if(decrese_flag > 1)   return false;
    else return true;
}