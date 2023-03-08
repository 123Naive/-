#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录函数实现

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//增加联系人函数的实现
void AddContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}

	//增加一个联系人的信息
	printf("请输入联系人的名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入联系人的年龄:>");
	scanf("%d",&(pc->data[pc->sz].age));
	printf("请输入联系人的性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入联系人的地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入联系人的电话:>");
	scanf("%s", pc->data[pc->sz].tele);

	pc->sz++;
}

//显示联系人的函数实现
void ShowContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}

int FindByName(const Contact* pc, char name[])
{
	assert(pc);

	int i = 0;
	int pos = 0;
	for (i = 0; pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;

	}
	
	printf("请输入要删除的联系人的名字:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	int i = 0;
	if (-1 == ret)
	{
		printf("要删除的联系人不存在\n");
		return;
	}

	//删除
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");

}


void SearchContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}
	//打印信息

	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].tele);

}



void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的联系人不存在\n");
		return;
	}

	printf("请输入联系人的名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入联系人的年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入联系人的性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入联系人的地址:>");
	scanf("%s", pc->data[pos].addr);
	printf("请输入联系人的电话:>");
	scanf("%s", pc->data[pos].tele);

	printf("修改成功！");

}
//#include<stdlib.h>

int my_strcmp(const PeoInfo* str1, const PeoInfo* str2)
{
	assert(str1 && str2);
	while (str1->name == str2->name)
	{
		if (*str1->name == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1->name - *str2->name;

}

int cmp_data_by_name(const void* e1, const void* e2)
{
	return my_strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}


void Swap(char* bulf1, char* bulf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *bulf1;
		*bulf1 = *bulf2;
		*bulf2 = tmp;
		bulf1++;
		bulf2++;
	}
}

void my_qsort(void* base, size_t sz, size_t width, int (*cmp)(const void* e1,const void* e2))
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void SortContact(Contact* pc)
{
	my_qsort(pc->data, pc->sz, sizeof(pc->data[0]), cmp_data_by_name);
	printf("排序成功！\n");
}