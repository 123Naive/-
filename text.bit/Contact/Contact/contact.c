#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(Contact* pc)
{
	pc-> sz = 0;
	memset(pc->data, 0, sizeof(pc->data));

}


void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	//增加一个人的信息
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);

	pc->sz++;
}


void ShowContact(Contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%s\t%d\t%s\t%s\t%s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}