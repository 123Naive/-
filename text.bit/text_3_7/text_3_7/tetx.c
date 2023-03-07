#define _CRT_SECURE_NO_WARNINGS 1

//strncat example 

//#include<stdio.h>
//#include<string.h>

//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	strncat(str1, str2, 6);
//
//	printf("%s\n", str1);
//	return 0;
//}


/* strncmp example */
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "abhud";
//	char arr2[] = "abctrd";
//	int ret = strncmp(arr1, arr2, 3);
//	printf("%d\n", ret);
//
//	return 0;
//}

//
////strstr example
//
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	char* ret = strstr(arr1, arr2);
//	printf("%s\n", ret);
//
//	return 0;
//}

//strtok example

//#include <stdio.h>
//#include<string.h>
//
//int main()
//{
//	char* p = "csdn@H.f";
//	const char* sep = "@.";
//	char arr[30];
//	char* str = NULL;
//	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);    //输出结果为：csdn
//		                        //          H
//			                    //          f
//	}
//
//	return 0;
//}



//strerror example : error list 
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//必须包含的头文件
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//		printf("Error opening file unexist.ent: %s\n", strerror(errno));   
//	//输出结果为:Error opening file unexist.ent: No such file or directory
//	//errno: Last error number
//	return 0;
//}


////memcpy example
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[50] = { 0 };
//	memcpy(arr2, arr1, 16);
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", arr2[i]);   //输出结果为：1 2 3 4
//	}
//
//	return 0;
//}

////memcpy的模拟实现
//#include<stdio.h>
//#include<assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[50] = { 1,2,3,4,5,6,7 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, 16);
//	int i = 0;
//	for (i = 0; i < 7; i++)
//	{
//		printf("%d ", arr1[i]);    //输出结果为：1 2 3 4 5 6 7
//	}
//}


////memmove example
//
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1, arr1 + 2, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);    //输出结果为：3 4 5 6 7 6 7 8 9 10
//	}
//
//	return 0;
//}

//memmove模拟实现
#include<stdio.h>
#include<assert.h>

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


int main()
{
	int arr1[50] = { 1,2,3,4,5,6,7 };
	int arr2[20] = { 0 };
	my_memmove(arr1, arr1 + 2, 20);
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", arr1[i]);    //输出结果为：3 4 5 6 7 6 7
	}
}