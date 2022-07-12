#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//��ѡ����ɾ��ĵ���Ϊö�����ͣ���Ϊֱ�ۣ������Ķ�
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

//�ṹ������ϵ����Ϣ
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
	struct PeoInfo data[MAX]; //�����Ϣ
	int size; //��¼Ԫ�ظ���
};

//��������
//ͨѶ¼��ʼ��
void InitContact(struct Contact* ps);

//�����ϵ����Ϣ
void AddContact(struct Contact* ps);

//��ʾͨѶ¼��Ϣ
void ShowContact(const struct Contact* ps); 

//ɾ����ϵ��
void DelContact(struct Contact* ps);

//������ϵ��
void SearchContact(const struct Contact* ps);

//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* ps);

//����������ĸ����ϵ����Ϣ��������
void SortContact(struct Contact* ps);
