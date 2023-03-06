#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>



//strlen example
//int main()
//{
//	char arr[] = "abdcbuhe";
//	int len = strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//strlen的模拟实现--my_strlen
int my_strlen(const char* str)
{
	int count = 0; //计数
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//int main()
//{
//	char arr[] = "abdcbuhe";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//strcpy example
//#include<string.h>;
//int main()
//{
//	char arr1[] = "abcey";
//	char arr2[] = "xxx";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

#include<string.h>
int main()
{
	char arr1[] = "ncueuj";
	char arr2[] = "xxxxx";
	strncpy(arr1, arr2, 3);
	printf("%s\n", arr1);

	return 0;
}