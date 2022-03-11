#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int n;
int midnumber=0;
typedef struct Maillist
{
	int id;
	char name[20];
	char age[20];
	char sex[20];
	char phone[20];
	struct Maillist* mNext;
}Maillist;
#define mLen sizeof(Maillist)
 Maillist* mhead = NULL;
 Maillist* mpend = NULL;
 

 void AddNodeList();
 void ScanList();
 Maillist* SelectNode1(char xm[20]);
 Maillist* SelectNode2(int id);
 Maillist* SelectNode3(char phone[20]);
 void Select();
 void DeleteListRand();
 void DeleteListHead();
 void DeleteListTail();
 void showmenu();
 void change();


 int maillistmanager()
 {
	 SetConsoleOutputCP(65001);
	 mhead;
	 int choose;
	 while (1)
	 {
		 showmenu();
		 printf("请输入选择的功能序号: ");
		 scanf("%d", &choose);
		 switch (choose)
		 {
		 case 1:
			 n++;
			 midnumber++;
			 AddNodeList();
			 break;
		 case 2:
			 Select();
			 break;
		 case 3:
			 DeleteListRand();
			 break;
		 case 4:
			 change();
			 break;
		 case 5:
		 	 system("cls;");
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
 

 void mprint(Maillist* mTemp) {
	 if (mTemp == NULL) {
		 printf("\n--------------------您要查找的联系人不存在!--------------------------------\n");
	 }
	 else {
		 printf("----------------------------------------------------------------------\n");
		 printf("编号：%d\n", mTemp->id);
		 printf("姓名：%s\n", mTemp->name);
		 printf("年龄：%s\n", mTemp->age);
		 printf("性别：%s\n", mTemp->sex);
		 printf("手机号：%s\n", mTemp->phone);
		 printf("----------------------------------------------------------------------\n");
	 }
 }
 
void AddNodeList()
{
	 Maillist* mTemp = (Maillist*)malloc(mLen);
	 printf("编号为%d\n", midnumber);
	mTemp->id = midnumber;
	printf("请输入姓名：");
	scanf("%s", mTemp->name);
	printf("\n");
	printf("请输入年龄：");
	scanf("%s", mTemp->age);
	printf("\n");
	printf("请输入性别：");
	scanf("%s", mTemp->sex);
	printf("\n");
	printf("请输入手机号：");
	scanf("%s", mTemp->phone);
	printf("\n");
	mTemp->mNext = NULL;
	if (NULL == mhead)
	{
		mhead = mTemp;
		mpend = mTemp;
	}
	else
	{
		mpend->mNext = mTemp;
		mpend = mTemp;
	}
	system("pause");
	system("cls");
}
 
Maillist* SelectNode1(char xm[20])
{
	Maillist* mTemp = mhead;
	while (mTemp != NULL)
	{
		if (strcmp(xm,mTemp->name)==0)
		{
			return mTemp;
		}
		mTemp = mTemp->mNext;
	}
	return NULL;
}

Maillist* SelectNode2(int id)
{
	Maillist* mTemp = mhead;
	while (mTemp != NULL)
	{
		if ((mTemp->id)==id)
		{
			return mTemp;
		}
		mTemp = mTemp->mNext;
	}

	return NULL;
}
 
Maillist* SelectNode3(char phone[20])
{
	Maillist* mTemp = mhead;
	while (mTemp != NULL)
	{
		if (strcmp(phone, mTemp->phone) == 0)
		{
			return mTemp;
		}
		mTemp = mTemp->mNext;
	}
	return NULL;
}
 

void Select()
{
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	printf("3.按手机号查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Maillist* mTemp = mhead;
	switch (index) {
	case 1:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		mTemp = SelectNode1(name);
		mprint(mTemp);	
	}break;
	case 2:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		mTemp = SelectNode2(id);
		mprint(mTemp);
	}break;
	case 3:
	{
		char phone[20];
		printf("手机号：");
		scanf("%s", phone);
		mTemp = SelectNode3(phone);
		mprint(mTemp);
	}break;
	}
	system("pause");
	system("cls");
}
 

void DeleteListRand()
{
	
	if (mhead == NULL)
	{
		printf("链表为空！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	printf("3.按手机号查找\n");
	int index, yn;
	scanf("%d", &index);
	Maillist* mTemp = mhead;
	switch (index) {
	case 1: {
		char name[20];
		printf("请输入删除的联系人姓名\n");
		scanf("%s", name);
		mTemp = SelectNode1(name);
		mprint(mTemp);
	}break;
	case 2: {
		int id = 0;
		printf("请输入删除的联系人编号\n");
		scanf("%d", &id);
		mTemp = SelectNode2(id);
		mprint(mTemp);
	}break;
	case 3: {
		char phone[20];
		printf("请输入删除的联系人手机号\n");
		scanf("%s", phone);
		mTemp = SelectNode3(phone);
		mprint(mTemp);
	}break;
	}
	printf("确定删除以上联系人吗？（输入 1 确认删除，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 0) {
		system("cls");
	}
	else {
		if (mhead == mpend)
		{
			free(mhead);
			mhead = NULL;
			mpend = NULL;
			printf("操作成功\n");
			n--;
			system("pause");
			system("cls");
			return;
		}
		else if (mhead->mNext == mpend)
		{
			if (mhead == mTemp)
			{
				DeleteListHead();
			}
			else
			{
				DeleteListTail();
			}
		}
		else
		{
			if (mhead == mTemp)
			{
				DeleteListHead();
			}
			else if (mpend == mTemp)
			{
				DeleteListTail();
			}
			else
			{
				Maillist* pT = mhead;
				while (pT->mNext != mTemp)
				{
					pT = pT->mNext;
				}
				pT->mNext = mTemp->mNext;
				free(mTemp);
			}
 
		}
		printf("操作成功\n");
		n--;
		system("pause");
		system("cls");
	}
}
 

void DeleteListHead()
{
	if (mhead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
		Maillist* mTemp = mhead;
		mhead = mhead->mNext;
		free(mTemp);
}
 

void DeleteListTail()
{
	if (NULL == mhead)
	{
		printf("链表为空！\n");
		return;
	}
	if (mhead == mpend)
	{
		free(mhead);
		mhead = NULL;
		mpend = NULL;
	}
	else
	{
		Maillist* mTemp = mhead;
		while (mTemp->mNext != mpend)
		{
			mTemp = mTemp->mNext;
		}
		free(mpend);
		mpend = mTemp;
		mpend->mNext = NULL;
	}
}

//修改联系人信息
void change() {
	int yn, choose;
	printf("1.按编号查找\n");
	printf("2.按姓名查找\n");
	printf("3.按手机号查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Maillist* mTemp = mhead;
	switch (index) {
	case 1:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		mTemp = SelectNode2(id);
	}break;
	case 2:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		mTemp = SelectNode1(name);
	}break;
	case 3:
	{
 
		char phone[20];
		printf("手机号：");
		scanf("%s", phone);
		mTemp = SelectNode3(phone);
	}break;
	default:return;
	}
	mprint(mTemp);
	printf("确定修改以上联系人吗？\n（输入 1 进入修改，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 1)
	{
		printf("1.姓名    2.年龄    3.性别    4.手机号   ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: {
			printf("请输入新值：");
			scanf("%s", mTemp->name);
			printf("修改成功\n");
		}break;
		case 2: {
			printf("请输入新值：");
			scanf("%s", mTemp->age);
			printf("修改成功\n");
		}break;
		case 3: {
			printf("请输入新值：");
			scanf("%s", mTemp->sex);
			printf("修改成功\n");
		}break;
		case 4: {
			printf("请输入新值：");
			scanf("%s", mTemp->phone);
			printf("修改成功\n");
		}break;
		}
		system("pause");
		system("cls");
	}
	system("cls");
}

void showmenu()
{
	    printf("※※※※※※※※※※※※※※※※※※※ 铂金手册 ※※※※※※※※※※※※※※※※※※※\n");
	printf("              ");
	printf("--------------------△通讯录管理系统△--------------------\n");
	printf("                                        1.新建联系人\n");
	printf("﹎ ┈ ┈ .o┈ ﹎  ﹎.. ○");
	printf("                  ");
	printf("2.查询指定联系人");
	printf("    ╭⌒╮              　╭⌒╮ ╭⌒╮\n");
	printf(" ﹎┈﹎● ○ .﹎ ﹎o▂▃▅▆");
	printf("                 ");
	printf("3.删除指定联系人");
	printf("    ╭⌒╭⌒╮╭⌒╮～╭⌒╮   ︶︶　︶︶ \n");
	printf(" ┈ ┈ /█/▓ ﹎ ┈ ﹎﹎ ┈ ﹎");
	printf("                ");
	printf("4.修改指定联系人");
	printf("     ︶︶︶ ︶ ︶︶ ︶   \n");
	printf("▅▆▇█████▇▆▅▃▂┈﹎");
	printf("                        ");
	printf("5.返回主界面\n");
	printf("                                        6.退出\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
}