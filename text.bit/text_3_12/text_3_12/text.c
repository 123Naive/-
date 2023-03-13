#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>

//#include<stdio.h>
//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}


//char * strncpy ( char * destination, const char * source, size_t num );
//模拟实现strncpy

//char* my_strcpy(char* str, const char* src)
//{
//	assert(str && src);
//	char* ret = str;
//	/*while (*str++ = *src++)
//	{
//		;
//	}*/
//	while (*str && *src)
//	{
//		*str = *src;
//		str++;
//		src++;
//	}
//	return ret;
//
//}

//char * strncpy ( char * destination, const char * source, size_t num );
//#include<stdio.h>
//#include<assert.h>
//char* my_strncpy(char* str, char* src, size_t num)
//{
//	assert(str && src);
//	char* ret = str;
//	while (*str && *src)
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*str = *src;
//			str++;
//			src++;
//		}
//		break;
//
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "hiugjbub";
//	char arr2[] = "xxxxx";
//	my_strncpy(arr1, arr2, 3);
//	printf("%s\n", arr1);
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

//strncat 模拟实现
//char* strncat(char* destination, const char* source, size_t num);

//#include<stdio.h>
//#include<assert.h>
//
//char* my_strncat(char* str, char* src, size_t num)
//{
//	assert(str && src);
//	char* ret = str;
//	while (*str)
//	{
//		str++;
//	}
//
//	while (*src)
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*str = *src;
//			str++;
//			src++;
//		}
//
//		break;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[50] = "hello ";
//	char arr2[20] = "world";
//	size_t num = 3;
//	char* ret = my_strncat(arr1, arr2, num);
//	printf("%s\n", ret);
//
//	return 0;
//}


//#include <stdio.h>
//void FindTwoNum(char arr[], int sz)
//{
//	int eor = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		eor ^= arr[i];
//
//	}                   
//	int onlyone = eor & (~eor + 1);
//
//
//	int eor2 = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if ((arr[i] & onlyone) == 0)
//		{
//			eor2 ^= arr[i];
//		}
//	}
//	printf("%d %d", eor2, eor2 ^ eor);
//}
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,5};
//	FindTwoNum(arr, sizeof(arr));
//	return 0;
//}


////星期
//
//enum DAY
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//
//
////性别
//
//enum SEX
//{
//	FEMALE,
//	MALE,
//	SECRET
//};
//
////颜色
//
//enum Color
//{
//	RED,
//	BLUE,
//	BLACK
//};
//
//#include<stdio.h>
//
//enum Color//颜色
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//
//
//int main()
//{
//	enum Color clr = GREEN;//只能拿枚举常量给枚举变量赋值，才不会出现类型的差异。
//	printf("%d", clr);
//
//	return 0;
//}



	#include<stdio.h>
	////联合类型的声明
	//union Un
	//{
	//	char c;
	//	int i;
	//};

	//int main()
	//{
	//	//联合变量的定义
	//	union Un un;

	//	//计算连个变量的大小
	//	//printf("%d\n", sizeof(un));
	//
	//	//联合的使用
	//	un.i = 4;
	//	printf("%d\n", un.i);

	//	return 0;
	//}


union Un
{
	int i;
	char c;
};

//int main()
//{
//	union Un un;
//	// 下面输出的结果是一样的吗？
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//	//下面输出的结果是什么？
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//}

//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//
//int main()
//{
//	//下面输出的结果是什么？
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	//代码1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0；
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//	return 0;
//}

//void* malloc(size_t size);
//void free (void* ptr);
//
//#include<stdio.h>
//#include<stdlib.h>
//#define NUM 10
//int main()
//{
//	//代码1
//	int arr[NUM] = { 0 };
//
//	//代码2
//	int num = 0;
//	scanf("%d", &num);
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = i + 1;
//		}
//
//		for (i = 0; i < num; i++)
//		{
//			printf("%d ", *(ptr+i));
//		}
//		free(ptr);
//		ptr = NULL;
//		return 0;
//	}
//
//}

//void*  calloc  (size_t  num, size_t  size);
/*#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* ptr = NULL;
	ptr = (int*)calloc(10, 4);
	int i = 0;
	if (ptr != NULL)
	{
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(ptr + i));

		}
	}

	free(ptr);
	ptr = NULL;

return 0;
}*/	


//#include <stdio.h>
//int main()
//{
//	int* ptr = (int*)malloc(100);
//	if (ptr != NULL)
//	{
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//扩展容量
//	//代码1
//	ptr = (int*)realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
//
//	//代码2
//	int* p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//业务处理
//	free(ptr);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int* ptr = NULL;
//	ptr = (int*)malloc(100);
//	if (ptr != NULL)
//	{
//		//.......
//	}
//
//	//如果malloc开辟的空间不够则需要扩展容量
//	//情况一：
//	ptr = (int*)realloc(ptr, 200);
//	//情况二：
//	int* p = NULL;
//	p = (int*)realloc(ptr, 200);
//	if (p != NULL)
//	{
//		ptr = p;
//
//	}
//	free(ptr);
//	ptr = NULL;
//	
//	return 0;
//}

//#define INT_MAX 100
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}
//
////修改之后
//
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	if (p != NULL)
//	{
//		*p = 20;
//		//......
//	}
//	free(p);
//	p = NULL;
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}
//
////修改之后
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//	p = NULL;
//}


void test()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int main()
{
	test();
	while (1);
}

//修改之后
void test()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int main()
{
	test();
	while (1);
}