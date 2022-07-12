#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//将选项增删查改等设为枚举类型，更为直观，便于阅读
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//结构体存放联系人信息
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX]; //存放信息
	int size; //记录元素个数
};

//函数声明
//通讯录初始化
void InitContact(struct Contact* ps);

//添加联系人信息
void AddContact(struct Contact* ps);

//显示通讯录信息
void ShowContact(const struct Contact* ps); 

//删除联系人
void DelContact(struct Contact* ps);

//查找联系人
void SearchContact(const struct Contact* ps);

//修改联系人信息
void ModifyContact(struct Contact* ps);

//按姓名首字母对联系人信息进行排序
void SortContact(struct Contact* ps);
