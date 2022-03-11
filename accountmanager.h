#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int n;
int idnumber=0;
typedef struct Fi
{
	int id;
	char name[20];//备注
	char time[20];
	char information[20];//钱
	struct Fi* fNext;
}Fi;
#define LEN sizeof(Fi)
 Fi* fhead = NULL;
 Fi* fpend = NULL;
 

 void FiAddNodeList();
 void FiScanList();
 Fi* FiSelectNode1(char xm[20]);
 Fi* FiSelectNode2(int id);
 void FiSelect();
 void FiDeleteListRand();
 void FiDeleteListHead();
 void FiDeleteListTail();
 void Fishowmenu();
 void Fichange();
 int accountmanager()
 {
	 SetConsoleOutputCP(65001);
	 fhead;
	 int choose;
	 while (1)
	 {
		 Fishowmenu();
		 printf("请输入选择的功能序号: ");
		 scanf("%d", &choose);
		 switch (choose)
		 {
		 case 1:
			 n++;
			 idnumber++;
			 FiAddNodeList();
			 break;
		 case 2:
			 FiSelect();
			 break;
		 case 3:
			 FiDeleteListRand();
			 break;
		 case 4:
			 Fichange();
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
 

 void print(Fi* fTemp) {
	 if (fTemp == NULL) {
		 printf("\n--------------------您要账户信息不存在!--------------------------------\n");
	 }
	 else {
		 printf("----------------------------------------------------------------------\n");
		 printf("编号：%d\n", fTemp->id);
		 printf("备注：%s\n", fTemp->name);
		 printf("金额：%s\n", fTemp->information);
		 printf("时间：%s\n", fTemp->time);
		 printf("----------------------------------------------------------------------\n");
	 }
 }
 
void FiAddNodeList()
{
	 Fi* fTemp = (Fi*)malloc(LEN);
	 printf("编号为%d\n", idnumber);
	fTemp->id = idnumber;
	printf("请输入备注：");
	scanf("%s", fTemp->name);
	printf("\n");
	printf("请输入时间：");
	scanf("%s",fTemp->time);
	printf("\n");
	printf("请输入金额：");
	scanf("%s", fTemp->information);
	printf("\n");
	fTemp->fNext = NULL;
	if (NULL == fhead)
	{
		fhead = fTemp;
		fpend = fTemp;
	}
	else
	{
		fpend->fNext = fTemp;
		fpend = fTemp;
	}
	system("pause");
	system("cls");
}
 
Fi* FiSelectNode1(char date[20])
{
	Fi* fTemp = fhead;
	while (fTemp != NULL)
	{
		if (strcmp(date,fTemp->time)==0)
		{
			return fTemp;
		}
		fTemp = fTemp->fNext;
	}
	return NULL;
}

Fi* FiSelectNode2(int id)
{
	Fi* fTemp = fhead;
	while (fTemp != NULL)
	{
		if ((fTemp->id)==id)
		{
			return fTemp;
		}
		fTemp = fTemp->fNext;
	}

	return NULL;
}

 

void FiSelect()
{
	printf("1.按时间查找\n");
	printf("2.按编号查询\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Fi* fTemp = fhead;
	switch (index) {
	case 1:
	{
		char time[20];
		printf("时间：");
		scanf("%s", time);
		fTemp =FiSelectNode1(time);
		print(fTemp);	
	}break;
	case 2:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		fTemp = FiSelectNode2(id);
		print(fTemp);
	}break;
	}
	system("pause");
	system("cls");
}
 

void FiDeleteListRand()
{
	
	if (fhead == NULL)
	{
		printf("链表为空！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("1.按时间查找\n");
	printf("2.按编号查询\n");
	int index, yn;
	scanf("%d", &index);
	Fi* fTemp = fhead;
	switch (index) {
	case 1: {
		char time[20];
		printf("请输入删除账户时间\n");
		scanf("%s", time);
		fTemp = FiSelectNode1(time);
		print(fTemp);
	}break;
	case 2: {
		int id = 0;
		printf("请输入删除的编号\n");
		scanf("%d", &id);
		fTemp = FiSelectNode2(id);
		print(fTemp);
	}break;
	}
	printf("确定删除以上账户信息吗？（输入 1 确认删除，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 0) {
		system("cls");
	}
	else {
		if (fhead == fpend)
		{
			free(fhead);
			fhead = NULL;
			fpend = NULL;
			printf("操作成功\n");
			n--;
			system("pause");
			system("cls");
			return;
		}
		else if (fhead->fNext == fpend)
		{
			if (fhead == fTemp)
			{
				FiDeleteListHead();
			}
			else
			{
				FiDeleteListTail();
			}
		}
		else
		{
			if (fhead == fTemp)
			{
				FiDeleteListHead();
			}
			else if (fpend == fTemp)
			{
				FiDeleteListTail();
			}
			else
			{
				Fi* pT = fhead;
				while (pT->fNext != fTemp)
				{
					pT = pT->fNext;
				}
				pT->fNext = fTemp->fNext;
				free(fTemp);
			}
 
		}
		printf("操作成功\n");
		n--;
		system("pause");
		system("cls");
	}
}
 

void FiDeleteListHead()
{
	if (fhead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
		Fi* fTemp = fhead;
		fhead = fhead->fNext;
		free(fTemp);
}
 

void FiDeleteListTail()
{
	if (NULL == fhead)
	{
		printf("链表为空！\n");
		return;
	}
	if (fhead == fpend)
	{
		free(fhead);
		fhead = NULL;
		fpend = NULL;
	}
	else
	{
		Fi* fTemp = fhead;
		while (fTemp->fNext != fpend)
		{
			fTemp = fTemp->fNext;
		}
		free(fpend);
		fpend = fTemp;
		fpend->fNext = NULL;
	}
}

void Fichange() {
	int yn, choose;
	printf("1.按编号查找\n");
	printf("2.按时间查找\n");
	int index;
	int b = 0;
	scanf("%d", &index);
	Fi* fTemp = fhead;
	switch (index) {
	case 1:
	{
		int id = 0;
		printf("编号：");
		scanf("%d", &id);
		fTemp = FiSelectNode2(id);
	}break;
	case 2:
	{
		char time[20];
		printf("时间：");
		scanf("%s", time);
		fTemp = FiSelectNode1(time);
	}break;
	default:return;
	}
	print(fTemp);
	printf("确定修改以上财务信息吗？\n（输入 1 进入修改，输入 0 退出该模块） ： ");
	scanf("%d", &yn);
	if (yn == 1)
	{
		printf("1.备注    2.时间   3.金额  ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: {
			printf("请输入新值：");
			scanf("%s", fTemp->name);
			printf("修改成功\n");
		}break;
		case 2: {
			printf("请输入新值：");
			scanf("%s", fTemp->time);
			printf("修改成功\n");
		}break;
		case 3: {
			printf("请输入新值：");
			scanf("%s", fTemp->information);
			printf("修改成功\n");
		}break;
		}
		system("pause");
	}
	system("cls");
}

void Fishowmenu()
{
	SetConsoleOutputCP(65001);
      printf("\t\t※※※※※※※※※※※※※※※※※※※ 铂金手册 ※※※※※※※※※※※※※※※※※※※\n");
      printf("\t\t————-----------————△财务管理界面△————-----------————\n");
      printf("            _____ | _____         ===============================================\n");
      printf("           ()____)+()____)");
      printf("\t 1.添加财务信息");
      printf("  2.查询财务信息");
	  printf("         ╭︽╮         ╭︽╮\n");
	  printf("           ()____)+()____)");
      printf("\t 3.删除财务信息");
      printf("  4.修改财务信息");
	  printf("        (“财”)╭︽╮(“管”)╭︽╮\n");
      printf("           ()____)+()____)");
	   printf("\t 5.返回主界面");
	  printf("    6.退出");   
	  printf("                  ╰︾╯  (“务”)╰︾╯(“理”)\n");
	  printf("                            ");
	  printf(" 　　                                                ╰︾╯        ╰︾╯\n");
	  printf("                / | |             ==============================================\n");
      printf("\t\t※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n\n");
}
