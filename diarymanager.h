#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int n;
int idnumber_d=0;
typedef struct Diary
{
	int id;
	char name[20];
	char time[20];
	char information[20];
	struct Diary* dNext;
}Diary;
#define dLen sizeof(Diary)
 Diary* dhead = NULL;
 Diary* dpend = NULL;
 

 void REAddNodeList();
 void ScanList();
 Diary* RESelectNode1(char xm[20]);
 Diary* RESelectNode2(int id);
 void RESelect();
 void REDeleteListRand();
 void REDeleteListHead();
 void REDeleteListTail();
 void showmenu1();
 void REchange();


 int diarymanager()
 {
	 dhead;
	 int choose;
	 while (1)
	 {
		 showmenu1();
		 printf("请输入选择的功能序号: ");
		 scanf("%d", &choose);
		 switch (choose)
		 {
		 case 1:
			 n++;
			 idnumber_d++;
			 REAddNodeList();
			 break;
		 case 2:
			 RESelect();
			 break;
		 case 3:
			 REDeleteListRand();
			 break;
		 case 4:
			 REchange();
			 break;
		 case 5:
		 	 system("cls");
			 main();
			 break;
		 case 6:
		 	 system("cls;");
			 exit(0);
			 break;
		 default:
			 break;
		 }
	 }
	 system("pause");
	 return 0;
 }
 

 void dprint(Diary* dTemp) {
	 if (dTemp == NULL) {
		 printf("\n--------------------您要查找的日记不存在!--------------------------------\n");
	 }
	 else {
		 printf("----------------------------------------------------------------------\n");
		 printf("编号：%d\n", dTemp->id);
		 printf("姓名：%s\n", dTemp->name);
		 printf("内容：%s\n", dTemp->information);
		 printf("时间：%s\n", dTemp->time);
		 printf("----------------------------------------------------------------------\n");
	 }
 }
 
void REAddNodeList()
{
	 Diary* dTemp = (Diary*)malloc(dLen);
	 printf("编号为%d\n", idnumber_d);
	dTemp->id = idnumber_d;
	printf("请输入姓名：");
	scanf("%s", dTemp->name);
	printf("\n");
	printf("请输入日记时间：");
	scanf("%s",dTemp->time);
	printf("\n");
	printf("请输入内容：");
	scanf("%s", dTemp->information);
	printf("\n");
	dTemp->dNext = NULL;
	if (NULL == dhead)
	{
		dhead = dTemp;
		dpend = dTemp;
	}
	else
	{
		dpend->dNext = dTemp;
		dpend = dTemp;
	}
	system("pause");
	system("cls");
}
 
Diary* RESelectNode1(char xm[20])
{
	Diary* dTemp = dhead;
	while (dTemp != NULL)
	{
		if (strcmp(xm,dTemp->name)==0)
		{
			return dTemp;
		}
		dTemp = dTemp->dNext;
	}
	return NULL;
}

Diary* RESelectNode2(int id)
{
	Diary* dTemp = dhead;
	while (dTemp != NULL)
	{
		if ((dTemp->id)==id)
		{
			return dTemp;
		}
		dTemp = dTemp->dNext;
	}

	return NULL;
}

 

void RESelect()
{
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Diary* dTemp = dhead;
	switch (index) {
	case 1:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		dTemp = RESelectNode1(name);
		dprint(dTemp);	
	}break;
	case 2:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		dTemp = RESelectNode2(id);
		dprint(dTemp);
	}break;
	}
	system("pause");
	system("cls");
}
 

void REDeleteListRand()
{
	
	if (dhead == NULL)
	{
		printf("链表为空！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	int index, yn;
	scanf("%d", &index);
	Diary* dTemp = dhead;
	switch (index) {
	case 1: {
		char name[20];
		printf("请输入删除的日记姓名\n");
		scanf("%s", name);
		dTemp = RESelectNode1(name);
		dprint(dTemp);
	}break;
	case 2: {
		int id = 0;
		printf("请输入删除的日记编号\n");
		scanf("%d", &id);
		dTemp = RESelectNode2(id);
		dprint(dTemp);
	}break;
	}
	printf("确定删除以上日记吗？（输入 1 确认删除，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 0) {
		system("cls");
	}
	else {
		if (dhead == dpend)
		{
			free(dhead);
			dhead = NULL;
			dpend = NULL;
			printf("操作成功\n");
			n--;
			system("pause");
			system("cls");
			return;
		}
		else if (dhead->dNext == dpend)
		{
			if (dhead == dTemp)
			{
				REDeleteListHead();
			}
			else
			{
				REDeleteListTail();
			}
		}
		else
		{
			if (dhead == dTemp)
			{
				REDeleteListHead();
			}
			else if (dpend == dTemp)
			{
				REDeleteListTail();
			}
			else
			{
				Diary* pT = dhead;
				while (pT->dNext != dTemp)
				{
					pT = pT->dNext;
				}
				pT->dNext = dTemp->dNext;
				free(dTemp);
			}
 
		}
		printf("操作成功\n");
		n--;
		system("pause");
		system("cls");
	}
}
 

void REDeleteListHead()
{
	if (dhead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
		Diary* dTemp = dhead;
		dhead = dhead->dNext;
		free(dTemp);
}
 

void REDeleteListTail()
{
	if (NULL == dhead)
	{
		printf("链表为空！\n");
		return;
	}
	if (dhead == dpend)
	{
		free(dhead);
		dhead = NULL;
		dpend = NULL;
	}
	else
	{
		Diary* dTemp = dhead;
		while (dTemp->dNext != dpend)
		{
			dTemp = dTemp->dNext;
		}
		free(dpend);
		dpend = dTemp;
		dpend->dNext = NULL;
	}
}

void REchange() {
	int yn, choose;
	printf("1.按编号查找\n");
	printf("2.按姓名查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Diary* dTemp = dhead;
	switch (index) {
	case 1:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		dTemp = RESelectNode2(id);
	}break;
	case 2:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		dTemp= RESelectNode1(name);
	}break;
	default:return;
	}
	dprint(dTemp);
	printf("确定修改以上日记吗？\n（输入 1 进入修改，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 1)
	{
		printf("1.姓名    2.时间   3.内容  ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: {
			printf("请输入新值：");
			scanf("%s", dTemp->name);
			printf("修改成功\n");
		}break;
		case 2: {
			printf("请输入新值：");
			scanf("%s", dTemp->time);
			printf("修改成功\n");
		}break;
		case 3: {
			printf("请输入新值：");
			scanf("%s", dTemp->information);
			printf("修改成功\n");
		}break;
		}
		system("pause");
	}
	system("cls");
}

void showmenu1()
{
	printf("※※※※※※※※※※※※※※※※※※※ 铂金手册 ※※※※※※※※※※※※※※※※※※※\n");
	printf("      ");
	printf("--------------------△日记管理系统△--------------------\n");
	printf("   ┏┳━━━━━━━━━━━━┓                                  \n");
	printf("   ┃┃██████┃");
	printf("                 ");
	printf("1.新建日记\n");
	printf("   ┃┃███┏━━┓  ┃");
	printf("              ");
	printf("2.查询指定日记");
	printf("                ╭%╮   ╭ '''╮\n");
	printf("   ┣┫███┃日┃  ┃");
	printf("              ");
	printf("3.删除指定日记");
	printf("               (@^o^@) (⌒:⌒)\n");
	printf("   ┃┃███┃记┃  ┃");
	printf("              ");
	printf("4.修改指定日记");
	printf("               (~):(~) (~)v(~) \n");
	printf("   ┣┫███┗━━┛  ┃");
	printf("              ");
	printf("5.返回主界面\n");
	printf("   ┃┃██████┃");
	printf("                 ");
	printf("6.退出\n");
	printf("   ┗┻━━━━━━━━━━━━┛     \n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
}
 
