#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"accountmanager.h"
#include"infomanager.h"
#include"diarymanager.h"
#include"maillistmanager.h"
int main(){
    SetConsoleOutputCP(65001);
    int n;
    printf("※※※※※※※※※※※※※※※※※※※ 欢迎来到铂金手册 ※※※※※※※※※※※※※※※※※※※\n");
	printf(" \n");
	printf("                                           ");
	printf("1.个人信息管理系统\n");
	printf("                                           ");
    printf("2.财务管理系统");
	printf("                  ◢◣ \n");
	printf(",'''╭⌒╮⌒╮.',''',,',.'',,','',.");
	printf("          ");
    printf(" 3.通讯录管理系统");
	printf("               ◢★◣ \n");
	printf(" ╱◥██◣''o',''',,',.''.'',,',. ");
	printf("           ");
    printf("4.日志管理系统");
	printf("                ◢■■◣ \n");
	printf("｜田｜田田│ '',,',.',''',,',.''");
	printf("            ");
    printf("5.退出");
	printf("                       ◢■■■◣\n");
	printf("╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬                                                      ︸︸||︸︸ \n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
    printf("请输入您想要进入的模块\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    system("cls;");
    infomanager();break;//个人信息管理系统
    case 2:
    system("cls;");
    accountmanager();//财务管理系统
    break;
    case 3:
    system("cls;");
    maillistmanager();//通讯录管理系统
    break;
    case 4:
    system("cls;");
    diarymanager();//日志管理系统
    break;
    case 5:
    system("cls;");
    exit(0);
    break;
    }
    return 0;

}