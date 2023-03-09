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


//初始化通讯录函数声明
void InitContact(Contact* pc);

//增加联系人函数声明
void AddContact(Contact* pc);

//删除联系人信息函数声明
void DelContact(Contact* pc);

//显示通讯录的信息
void ShowContact(const Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人的信息
void ModifyContact(Contact* pc);

//排序联系人信息
void SortContact(Contact* pc);