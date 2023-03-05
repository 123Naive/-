#include<stdio.h>
//memcpy模拟实现
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)//从前往后
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}

	return ret;
}

void text2()
{
	int arr1[50] = { 1,2,3,4,5,6,7 };
	int arr2[20] = { 0 };
	//my_memcpy(arr2, arr1, 16);
	my_memmove(arr1, arr1 + 2, 20);
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", arr1[i]);
	}

}

int main()
{
	text2();
	return 0;
}




//memset

//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, 'x', 2);
//	printf("%s", arr);
//
//	return 0;
//}



//strlen模拟实现

int my_strlen(char arr[])
{
	int i = 0;
	int count = 0;
	while (arr[i])
	{
		count++;
		i++;
	}

	return count;
}

//int main()
//{
//	char arr[] = "abcddef";
//	int len = my_strlen(arr);
//	printf("%d", len);
//
//	return 0;
//}