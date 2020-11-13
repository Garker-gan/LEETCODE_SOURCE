/* 
        ����ϼ����鲢��ѡ�񣬲��룬�ѣ����٣�ð�ݣ�ϣ��
        �����������bug�����ǵ��ˣ����ⲻ��
        Garker-gan
        2019-09-20
 */
#include<stdio.h>

int array[10];
int len;


//����ź��������
void printArray(int *array,int len)
{
	for(int i = 0;i < len;i++)			//��ӡ������ɵ����� 
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}


//�����ǹ鲢����
void merge(int *array,int low,int mid,int high)			//���ڹ鲢��������
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

//�����ǹ鲢����2
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
	printf("�鲢����");
	printArray(array,len);
}

//ѡ������
void selectSort(int *array,int len)
{
	int min;			//������ſ�ʼ�����ĵ�һ����������������������Ƚ� 
	for(int i = 0;i < len; i++)			 
	{
		min = i;
		for(int j = i+1;j<len;j++)			//����������������� �ҵ���Сֵ 
		{
			if(array[min] > array[j])		
			{
				min = j;
			}
			
			if(min != i)			//����ҵ���Сֵ������Сֵ������ǰ���γ������� 
			{
				int temp; 
				temp = array[min];
				array[min] = array[i];
				array[i] = temp;
			}
		}
	}
	printf("ѡ������");
	printArray(array,len);
} 
 

//��������
void insertSort(int *array ,int len)
{
	int j;
	for(int i = 1;i <= len-1;i++)			//�ӵڶ�����ʼ�����һ���ֱ��ж�ǰ���С��ϵ 
	{
		if(array[i-1] > array[i])			//�������С��ǰ�棬��ǰֵ��ǰ�������бȽϣ��ҵ�����λ�� 
		{
			int temp;
			temp = array[i]; 
			for(j = i-1;j>=0&&temp < array[j];j--)			//����ڵ�ǰֵС�������е�ֵ�����ѭ����ֱ������������ĳһ��ֵʱ����ѭ�� 
			{
				array[j+1] = array[j];			//����һλ 
			}
			array[j+1] = temp;			//����ǰ���в����ҵ��Ĵ�������ֵ֮ǰ 
		}
	}
	printf("��������");
	printArray(array,len);
} 

//ð������ 
void bubbleSort(int *array,int len)
{
	int temp;
	for(int i = len;i >= 1;i--)			//�ֱ������len�� 
	{
		for(int j = 1;j < i;j++)		//�ӵڶ�������ǰ������ʼð�� 
		{
			if(array[j-1] >array[j])			//����	 
			{
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
				
		}
	}
	printf("ð������"); 
	printArray(array,len);
}


//������������Ϊ������
void Shift(int *array,int low ,int high)
{
	int i = low,j = 2*i;			//jΪi������
	int temp = array[i];
	
	while(j<=high) 
	{
		while(j < high&&array[j] < array[j+1]) j++;			//����������ֵܽڵ㣬�Ҹ����ӽڵ��ֵС�����ֵ� ����jָ���Һ��� 
		if(temp < array[j])			//������׽ڵ��ֵ���ں��ӽڵ㣬�򽻻� 
		{
			array[i] = array[j];			//���������ָ����һ�����ӽڵ� 
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
	printf("�� �� ��");
	printArray(array,len);
}


void quickSort(int *array,int low ,int high)			//�������� 
{
	int i = low,j = high;			//���������ֱ�ָ��ͷ��β 
	int temp = array[i];			//�м�����洢��һ����ֵ 
	while (i < j)			 
	{
		if(low < high)
		{
			while(i<j&&array[j] >= temp) j--;			//����Ĵ���ǰ��������ѭ����j���� 
			if(i < j)			//����С���򽻻� 
			{
				array[i] = array[j];
				i++;
			}
			
			while(i<j&&array[i] <= temp) i++;			//ͬǰ 
			if(i < j)
			{
				array[j] = array[i];
				j--;
			}
			array[i] = temp;			//i�����ƶ����м�ʱ����temp��ֵ��i 
			quickSort(array,low,i-1);			//�ݹ飬������ǰ�����벿��ѭ�� 
			quickSort(array,j+1,high);
		}
	}
}


void shellSort(int *array)			//ϣ������ 
{
	int step;
	
	for(int step = len/2;step > 0;step /=2)			//��������ϵĶ��ȷ� 
	{
		for(int i = step; i < len;i++)			//ѭ��һ��Ĳ��� 
		{
			int temp = array[i];
			int j ; 
			for(j = i;j >= step&&array[j-step] >temp;j -= step)			//ǰ��Ա� 
			{
				array[j] = array[j-step];			//ǰ����ں����򽻻� 
			}
			array[j] = temp;			//�˴�jΪǰ�벿�� j-step 
		}
	}
	printf("ϣ������"); 
	printArray(array,len);
}



int main()
{
	scanf("%d",&len);			//�������鳤�� 
	for(int i = 0;i < len;i++)			//�������� 
	{
		scanf("%d",&array[i]);
	}

	shellSort(array);			//ϣ������ 
	quickSort(array,0,len-1);	printf("��������: ");	printArray(array,len);
	heapSort(array,len);
    bubbleSort(array,len);
	insertSort(array,len);
	selectSort(array,len);
	mergeSort(array,len);
	printArray(array,len);
}