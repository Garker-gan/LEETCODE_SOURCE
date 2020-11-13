/* 
        排序合集：归并，选择，插入，堆，快速，冒泡，希尔
        堆排序好像还有bug，不记得了，问题不大
        Garker-gan
        2019-09-20
 */
#include<stdio.h>

int array[10];
int len;


//输出排好序的数组
void printArray(int *array,int len)
{
	for(int i = 0;i < len;i++)			//打印排序完成的数组 
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}


//以下是归并排序
void merge(int *array,int low,int mid,int high)			//用于归并两个数组
{	
	int n1 = mid -low + 1;
	int n2 = high - mid;
	int Right[10],Left[10];
	int temp[10];
	for(int i = 0;i < n1;i++)
	{
		Left[i] = array[i];
	} 
	for(int i = 0;i < n2;i++)
	{
		Right[i] = array[i+mid+1];
	}

	int k = 0,i= 0,j = 0;
	while(i<n1&&j<n2)
	{
		if(Left[i] > Right[j])
			temp[k++] = Right[j++];
		else 
			temp[k++] = Left[i++];
	}
	
	while (i < n1)
	{
		temp[k++] = Left[i++];
	}
	
	while(j < n2)
	{
		temp[k++] = Right[j++];	
	} 
	
	for(int m = 0;m < len;m++)
		array[m] = array[m];
		
} 

//以下是归并排序2
void mergeSort(int *array ,int len)
{
	int l = 1;
	int low,mid,high;
	while(l <= len)
	{
		for(int i = 0;i +l < len;i *= 2)
		{
			low = i;
			mid = i+len - 1;
			high = i + 2*len -1;
			if(high > len -1)
			{
				high = len - 1;
			}
			merge(array,low,mid,high);
		}
		l = 2*l;
	}
	printf("归并排序：");
	printArray(array,len);
}

//选择排序
void selectSort(int *array,int len)
{
	int min;			//用来存放开始遍历的第一个数，用来和他后面的数比较 
	for(int i = 0;i < len; i++)			 
	{
		min = i;
		for(int j = i+1;j<len;j++)			//遍历后面的无序数列 找到最小值 
		{
			if(array[min] > array[j])		
			{
				min = j;
			}
			
			if(min != i)			//如果找到最小值，则将最小值交换到前面形成有序列 
			{
				int temp; 
				temp = array[min];
				array[min] = array[i];
				array[i] = temp;
			}
		}
	}
	printf("选择排序：");
	printArray(array,len);
} 
 

//插入排序
void insertSort(int *array ,int len)
{
	int j;
	for(int i = 1;i <= len-1;i++)			//从第二个开始到最后一个分别判断前后大小关系 
	{
		if(array[i-1] > array[i])			//如果后面小于前面，则当前值与前面有序列比较，找到插入位置 
		{
			int temp;
			temp = array[i]; 
			for(j = i-1;j>=0&&temp < array[j];j--)			//如果在当前值小于有序列的值则进入循环。直到大于有序列某一个值时结束循环 
			{
				array[j+1] = array[j];			//后移一位 
			}
			array[j+1] = temp;			//将当前序列插入找到的大于他的值之前 
		}
	}
	printf("插入排序：");
	printArray(array,len);
} 

//冒泡排序 
void bubbleSort(int *array,int len)
{
	int temp;
	for(int i = len;i >= 1;i--)			//分别进行了len趟 
	{
		for(int j = 1;j < i;j++)		//从第二个到当前趟数开始冒泡 
		{
			if(array[j-1] >array[j])			//交换	 
			{
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
				
		}
	}
	printf("冒泡排序："); 
	printArray(array,len);
}


//以下两个函数为堆排序
void Shift(int *array,int low ,int high)
{
	int i = low,j = 2*i;			//j为i的左孩子
	int temp = array[i];
	
	while(j<=high) 
	{
		while(j < high&&array[j] < array[j+1]) j++;			//如果存在右兄弟节点，且该左孩子节点的值小于右兄弟 ，则j指向右孩子 
		if(temp < array[j])			//如果父亲节点的值大于孩子节点，则交换 
		{
			array[i] = array[j];			//交换后继续指向下一个孩子节点 
			i = j;
			j = 2*i;
		}
		else 
			break;
	}
	array[i] = temp;
}

void heapSort(int *array,int len) 
{
	int temp;
	for(int i = len/2;i>= 1;i--)
		Shift(array,i,len);
	for(int j = len;j >= 2;j--)
	{
		temp = array[1];
		array[1] = array[j];
		array[j] = temp;
		Shift(array,2,j-1);
	}
	printf("堆 排 序：");
	printArray(array,len);
}


void quickSort(int *array,int low ,int high)			//快速排序 
{
	int i = low,j = high;			//两个变量分别指向头和尾 
	int temp = array[i];			//中间变量存储第一个数值 
	while (i < j)			 
	{
		if(low < high)
		{
			while(i<j&&array[j] >= temp) j--;			//后面的大于前面的则进入循环，j向上 
			if(i < j)			//后面小于则交换 
			{
				array[i] = array[j];
				i++;
			}
			
			while(i<j&&array[i] <= temp) i++;			//同前 
			if(i < j)
			{
				array[j] = array[i];
				j--;
			}
			array[i] = temp;			//i向下移动到中间时，讲temp赋值给i 
			quickSort(array,low,i-1);			//递归，继续对前后两半部分循环 
			quickSort(array,j+1,high);
		}
	}
}


void shellSort(int *array)			//希尔排序 
{
	int step;
	
	for(int step = len/2;step > 0;step /=2)			//将间隔不断的二等分 
	{
		for(int i = step; i < len;i++)			//循环一半的部分 
		{
			int temp = array[i];
			int j ; 
			for(j = i;j >= step&&array[j-step] >temp;j -= step)			//前后对比 
			{
				array[j] = array[j-step];			//前面大于后面则交换 
			}
			array[j] = temp;			//此处j为前半部分 j-step 
		}
	}
	printf("希尔排序："); 
	printArray(array,len);
}



int main()
{
	scanf("%d",&len);			//输入数组长度 
	for(int i = 0;i < len;i++)			//输入数组 
	{
		scanf("%d",&array[i]);
	}

	shellSort(array);			//希尔排序 
	quickSort(array,0,len-1);	printf("快速排序: ");	printArray(array,len);
	heapSort(array,len);
    bubbleSort(array,len);
	insertSort(array,len);
	selectSort(array,len);
	mergeSort(array,len);
	printArray(array,len);
}