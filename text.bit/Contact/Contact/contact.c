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
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	//����һ���˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰:>");
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