#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int n;
int idnumber_i=0;
typedef struct Member
{
	int id;
	char name[20];
	char password[20];
	char answer[20];
	char question[20];
	struct Member* pNext;
}Member;
#define LEN_i sizeof(Member)
 Member* phead = NULL;
 Member* pend = NULL;
 

 void AddNodeList_i();
 void ScanList_i();
 Member* SelectNode1_i(char xm[20]);
 Member* SelectNode2_i(int id);
 Member* SelectNode3_i(char question[20]);
 void Select_i();
 void DeleteListRand_i();
 void DeleteListHead_i();
 void DeleteListTail_i();
 void showmenu_i();
 void change_i();


 int infomanager()//总
 {
	 SetConsoleOutputCP(65001);
	 phead;
	 int choose;
	 while (1)
	 {
		 showmenu_i();
		 printf("请输入选择的功能序号: ");
		 scanf("%d", &choose);
		 switch (choose)
		 {
		 case 1:
			 n++;
			 idnumber_i++;
			 AddNodeList_i();
			 break;
		 case 2:
			 Select_i();
			 break;
		 case 3:
			 DeleteListRand_i();
			 break;
		 case 4:
		     change_i();
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
 

 void print_i(Member* pTemp) {
	 if (pTemp == NULL) {
		 printf("\n--------------------您要查找的用户不存在!--------------------------------\n");
	 }
	 else {
		 printf("----------------------------------------------------------------------\n");
		 printf("编号：%d\n", pTemp->id);
		 printf("姓名：%s\n", pTemp->name);
		 printf("密码：%s\n", pTemp->password);
		 printf("密保问题：%s\n", pTemp->question);
		 printf("密保答案：%s\n", pTemp->answer);
		 printf("----------------------------------------------------------------------\n");
	 }
 }
 
void AddNodeList_i()
{
	 Member* pTemp = (Member*)malloc(LEN_i);
	 printf("编号为%d\n", idnumber_i);
	pTemp->id = idnumber_i;
	printf("请输入姓名：");
	scanf("%s", pTemp->name);
	printf("\n");
	printf("请输入密码：");
	scanf("%s", pTemp->password);
	printf("\n");
	printf("请输入密保问题：");
	scanf("%s", pTemp->question);
	printf("\n");
	printf("请输入密保答案：");
	scanf("%s", pTemp->answer);
	printf("\n");
	pTemp->pNext = NULL;
	if (NULL == phead)
	{
		phead = pTemp;
		pend = pTemp;
	}
	else
	{
		pend->pNext = pTemp;
		pend = pTemp;
	}
	system("pause");
	system("cls");
}
 
Member* SelectNode1_i(char xm[20])
{
	Member* pTemp = phead;
	while (pTemp != NULL)
	{
		if (strcmp(xm,pTemp->name)==0)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}

Member* SelectNode2_i(int id)
{
	Member* pTemp = phead;
	while (pTemp != NULL)
	{
		if ((pTemp->id)==id)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}

	return NULL;
}
 
Member* SelectNode3_i(char question[20])
{
	Member* pTemp = phead;
	while (pTemp != NULL)
	{
		if (strcmp(question, pTemp->question) == 0)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}
 

void Select_i()
{
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	printf("3.按密保问题查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Member* pTemp = phead;
	switch (index) {
	case 1:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		pTemp = SelectNode1_i(name);
		print_i(pTemp);	
	}break;
	case 2:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		pTemp = SelectNode2_i(id);
		print_i(pTemp);
	}break;
	case 3:
	{
		char question[20];
		printf("密保问题：");
		scanf("%s", question);
		pTemp = SelectNode3_i(question);
		print_i(pTemp);
	}break;
	}
	system("pause");
	system("cls");
}
 
 void change_i() {
	int yn, choose;
	printf("1.按编号查找\n");
	printf("2.按姓名查找\n");
	printf("3.按密保问题查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Member* pTemp = phead;
	switch (index) {
	case 1:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		pTemp = SelectNode2_i(id);
	}break;
	case 2:
	{
		char name[20];
		printf("姓名：");
		scanf("%s", name);
		pTemp = SelectNode1_i(name);
	}break;
	case 3:
	{
 
		char phone[20];
		printf("密保问题：");
		scanf("%s", phone);
		pTemp = SelectNode3_i(phone);
	}break;
	default:return;
	}
	print_i(pTemp);
	printf("确定修改以上用户吗？\n（输入 1 进入修改，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 1)
	{
		printf("1.姓名    2.密码    3.密保问题    4.密保答案   \n请输入序号：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: {
			printf("请输入新值：");
			scanf("%s", pTemp->name);
			printf("修改成功\n");
		}break;
		case 2: {
			printf("请输入新值：");
			scanf("%s", pTemp->password);
			printf("修改成功\n");
		}break;
		case 3: {
			printf("请输入新值：");
			scanf("%s", pTemp->question);
			printf("修改成功\n");
		}break;
		case 4: {
			printf("请输入新值：");
			scanf("%s", pTemp->answer );
			printf("修改成功\n");
		}break;
		}
		system("pause");
		system("cls");
	}
	system("cls");
}



void DeleteListRand_i()
{
	
	if (phead == NULL)
	{
		printf("链表为空！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("1.按姓名查找\n");
	printf("2.按编号查询\n");
	printf("3.按密保问题查找\n");
	int index, yn;
	scanf("%d", &index);
	Member* pTemp = phead;
	switch (index) {
	case 1: {
		char name[20];
		printf("请输入删除的用户姓名\n");
		scanf("%s", name);
		pTemp = SelectNode1_i(name);
		print_i(pTemp);
	}break;
	case 2: {
		int id = 0;
		printf("请输入删除的用户编号\n");
		scanf("%d", &id);
		pTemp = SelectNode2_i(id);
		print_i(pTemp);
	}break;
	case 3: {
		char question[20];
		printf("请输入删除的用户密保问题\n");
		scanf("%s", question);
		pTemp = SelectNode3_i(question);
		print_i(pTemp);
	}break;
	}
	printf("确定删除以上用户吗？（输入 1 确认删除，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 0) {
		system("cls");
	}
	else {
		if (phead == pend)
		{
			free(phead);
			phead = NULL;
			pend = NULL;
			printf("操作成功\n");
			n--;
			system("pause");
			system("cls");
			return;
		}
		else if (phead->pNext == pend)
		{
			if (phead == pTemp)
			{
				DeleteListHead_i();
			}
			else
			{
				DeleteListTail_i();
			}
		}
		else
		{
			if (phead == pTemp)
			{
				DeleteListHead_i();
			}
			else if (pend == pTemp)
			{
				DeleteListTail_i();
			}
			else
			{
				Member* pT = phead;
				while (pT->pNext != pTemp)
				{
					pT = pT->pNext;
				}
				pT->pNext = pTemp->pNext;
				free(pTemp);
			}
 
		}
		printf("操作成功\n");
		n--;
		system("pause");
		system("cls");
	}
}
 

void DeleteListHead_i()
{
	if (phead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
		Member* pTemp = phead;
		phead = phead->pNext;
		free(pTemp);
}
 

void DeleteListTail_i()
{
	if (NULL == phead)
	{
		printf("链表为空！\n");
		return;
	}
	if (phead == pend)
	{
		free(phead);
		phead = NULL;
		pend = NULL;
	}
	else
	{
		Member* pTemp = phead;
		while (pTemp->pNext != pend)
		{
			pTemp = pTemp->pNext;
		}
		free(pend);
		pend = pTemp;
		pend->pNext = NULL;
	}
}


void showmenu_i()
{
	printf("※※※※※※※※※※※※※※※※※※※ 欢迎来到铂金手册 ※※※※※※※※※※※\n");
    printf("    --------------------△个人信息管理系统△--------------------    \n");
    printf("  (＼  ＼)_                                                        ,_\n");
    printf("  .--' ')             1.注册用户            2.用户信息查询         >' )\n");
    printf(" o(  )_-＼                  ／＼ ／＼                              ( (    \n ");
    printf("   .....   3.删除指定用户  ＼      /      4.修改指定用户          /|  \n");
    printf("                             ＼    ／      \n");
    printf("                   5.返回主界面           6.退出  \n");
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※ \n");
}
 