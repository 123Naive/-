#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//	if (*str == '\0')
//		return 1;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen1(const char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//		return 1;
//	else
//		return 1 + my_strlen(1 + str);
//}
//
//int my_strlen2(const char* str)
//{
//	const char* start = str;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}
//
//
//int main()
//{
//	char arr[] = "abcde";
//	int len = my_strlen(arr);
//	printf("%d", len);
//
//	return 0;
//}
//



//strcpy模拟实现
char* my_strcpy(char* str, const char* src)
{
	assert(str && src);
	char* ret = str;
	while (*str++ = *src++)
	{
		;
	}
	return ret;

}

//int main()
//{
//	char arr1[20] = "hiugjbub";
//	char arr2[] = "xxx";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}

//strcat模拟实现
//字符串追加

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//int main()
//{
//	char arr[20] = "hello ";
//	my_strcat(arr, "world");
//	printf("%s\n", arr);
//	return 0;
//}

//strcmp模拟实现
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '0')
			return 0;
		str1++;
		str2++;
	}
	//if (*str1 > *str2)
	//	return 1;
	//else
	//	return -1;
	return *str1 - *str2;
}

//int main()
//{
//	char arr1[] = "xcv";
//	char arr2[] = "abc";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d\n", ret);
//
//	return 0;
//
//}

//strstr模拟实现
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 !='\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}


int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);

	return 0;
}