#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//struct S1
//
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};

//
//int main()
//{
//	//printf("%d\n", sizeof(struct S1));
//	//printf("%d\n", sizeof(struct S2));
//	//printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//
//
//}



#include <stdio.h>
#pragma pack(8)//设置默认对齐数为8

struct S1
{
	char c1;
	int i;
	char c2;
};

#pragma pack()//取消设置的默认对齐数，还原为默认

#pragma pack(1)//设置默认对齐数为1

struct S2
{
	char c1;
	int i;
	char c2;
};

#pragma pack()//取消设置的默认对齐数，还原为默认

//int main()
//{
//	//输出的结果是什么？
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//
//	return 0;
//}



struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

int main()
{
	printf("%d\n", sizeof(struct A));

	return 0;
}