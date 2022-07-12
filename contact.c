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
		printf("通讯录已满。");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功。\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	int i;
	if (ps->size == 0)
	{
		printf("通讯录为空。\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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

//按姓名查找联系人，查找成功返回联系人位置，失败返回-1
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

//删除该联系人后，将后面的联系人均向前移动
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入联系人姓名：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("没有该联系人信息。\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功。\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入联系人姓名：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("没有该联系人信息。\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入联系人姓名：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("没有该联系人信息。\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &ps->data[pos].age);
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成。\n");
	}
}

//使用qsort函数需自己编写比较函数
//void qsort (void* base, size_t num, size_t size,
//int(*compar)(const void*, const void*));
//qsort函数能够排序任意数组，无论整型、浮点型、结构体等。
//
//第一个参数base : 待排序数组的首元素地址
//第二个参数num：数组的元素个数
//第三个参数size：数组每个元素大小（字节）
//第四个参数compar：函数指针，比较函数的地址，这个比较函数使用者字节编写，函数参数是待比较两个元素地址
//第1个元素 > 第2个元素，返回 > 0 的数
//第1个元素 = 第2个元素，返回 0
//第1个元素 < 第2个元素，返回 < 0 的数
static int CompareByName(const void* p1, const void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name, ((struct PeoInfo*)p2)->name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), CompareByName);
	printf("排序完成。\n");
}