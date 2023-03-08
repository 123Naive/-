#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��ʼ��ͨѶ¼����ʵ��

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//������ϵ�˺�����ʵ��
void AddContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}

	//����һ����ϵ�˵���Ϣ
	printf("��������ϵ�˵�����:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("��������ϵ�˵�����:>");
	scanf("%d",&(pc->data[pc->sz].age));
	printf("��������ϵ�˵��Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��������ϵ�˵ĵ�ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("��������ϵ�˵ĵ绰:>");
	scanf("%s", pc->data[pc->sz].tele);

	pc->sz++;
}

//��ʾ��ϵ�˵ĺ���ʵ��
void ShowContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;

	}
	
	printf("������Ҫɾ������ϵ�˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	int i = 0;
	if (-1 == ret)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}

	//ɾ��
	for (i = ret; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");

}


void SearchContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
		return;
	}
	//��ӡ��Ϣ

	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}

	printf("��������ϵ�˵�����:>");
	scanf("%s", pc->data[pos].name);
	printf("��������ϵ�˵�����:>");
	scanf("%d", &(pc->data[pos].age));
	printf("��������ϵ�˵��Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("��������ϵ�˵ĵ�ַ:>");
	scanf("%s", pc->data[pos].addr);
	printf("��������ϵ�˵ĵ绰:>");
	scanf("%s", pc->data[pos].tele);

	printf("�޸ĳɹ���");

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
	printf("����ɹ���\n");
}