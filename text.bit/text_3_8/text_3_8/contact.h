#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12


typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;


//��ʼ��ͨѶ¼��������
void InitContact(Contact* pc);

//������ϵ�˺�������
void AddContact(Contact* pc);

//ɾ����ϵ����Ϣ��������
void DelContact(Contact* pc);

//��ʾͨѶ¼����Ϣ
void ShowContact(const Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ�˵���Ϣ
void ModifyContact(Contact* pc);

//������ϵ����Ϣ
void SortContact(Contact* pc);