#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size >= MAX)
	{
		printf("ͨѶ¼������");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ���\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	int i;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//������������ϵ�ˣ����ҳɹ�������ϵ��λ�ã�ʧ�ܷ���-1
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//ɾ������ϵ�˺󣬽��������ϵ�˾���ǰ�ƶ�
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &ps->data[pos].age);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		printf("�޸���ɡ�\n");
	}
}

//ʹ��qsort�������Լ���д�ȽϺ���
//void qsort (void* base, size_t num, size_t size,
//int(*compar)(const void*, const void*));
//qsort�����ܹ������������飬�������͡������͡��ṹ��ȡ�
//
//��һ������base : �������������Ԫ�ص�ַ
//�ڶ�������num�������Ԫ�ظ���
//����������size������ÿ��Ԫ�ش�С���ֽڣ�
//���ĸ�����compar������ָ�룬�ȽϺ����ĵ�ַ������ȽϺ���ʹ�����ֽڱ�д�����������Ǵ��Ƚ�����Ԫ�ص�ַ
//��1��Ԫ�� > ��2��Ԫ�أ����� > 0 ����
//��1��Ԫ�� = ��2��Ԫ�أ����� 0
//��1��Ԫ�� < ��2��Ԫ�أ����� < 0 ����
static int CompareByName(const void* p1, const void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name, ((struct PeoInfo*)p2)->name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), CompareByName);
	printf("������ɡ�\n");
}