#pragma once

#include<string.h>
#include<stdio.h>

#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12





typedef struct PeoInfor
{
	char name[NAME_MAX];
	int age;
	char sex;
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfor;


typedef struct Contact
{
	PeoInfor data[MAX];
	int sz;
}Contact;


void InitContact(Contact* pc);
//��ʼ��ͨѶ¼��������

void AddContact(Contact* pc);
//����һ����ϵ�˵ĺ�������

void ShowContact(Contact* pc);
//��ʾͨѶ¼����Ϣ