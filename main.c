/**
 * @file main.c
 * @author Mandeep 
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<string.h>
/*#include"marks.h"
#include"add.h"
#include"edit.h"
#include"find.h"
#include"delet.h"
#include"marks.h"
#include"help.h"
#include"list.h"
#include"result.h"*/

struct main
{
 char regn[10],name[50],f_name[50],address[100],course[10],doa[10];
};
struct result
{
 int m1,m2,m3,m4,total;
 char regn[10],grade[2];
};
struct link_main
{
 char lmregn[10],lmname[50],lmf_name[50],lmaddress[100],lmcourse[10],lmdoa[10];
 struct link_main *next;
};
struct link_result // Define link list Structure for deleting or editing//
{
 int lrm1,lrm2,lrm3,lrm4,lrtotal; // members//
 char lrregn[10],lrgrade[2]; // ,, //
 struct link_result *next; //linking address for next node//
};
typedef struct main m; //Declear typedef of structure//
typedef struct result r;
typedef struct link_main lm;
typedef struct link_result lr;
long int size1=sizeof(m); //declear size of structure//
long int size2=sizeof(r);
FILE *f1,*f2;
int main()
{
    int iterate,option;
    int user,password;
    char c;
     f1=fopen("main.dat","r"); // Open Main File In Read Mode //
    if (f1==NULL) // Checking database if avalible of not//
    {
        printf("Your data base not exit are you must create it prese any key to continue");
        getch();
        clrscr();
        //mkdir("c:\\student");
        f2=fopen("main.dat","wb"); // Creating Main database for application//
        fclose(f2);
        f2=fopen("result.dat","wb"); // Creating Result Database For This Application //
        fclose(f2);
        fclose(f1);
        f1=fopen("help","wb");
        f2=fopen("help","rb");
        while(feof(f2)==0) //=== Writeing Help File==//
        {
            c=getc(f2);
            putc(c,f1);
        }
         printf("You must restart your application press any key to continue.....");
         getch();
         exit(0);
    }
    printf("please enter your credentials");
    scanf("%d",&user);
    scanf("%d",&password);
    if(user=="admin"&&password=="admin")
    {
        printf("Welcome admin to student management system please select the below options\n");
        for(iterate=0;;iterate++)
        {
            printf("1.add a new record\n");
            printf("2.edit an existing record\n");
            printf("3.find a record\n");
            printf("4.delete a record\n");
            printf("5.add results\n");
            printf("6.help page\n");
            printf("7.list students\n");
            printf("8.display results\n");
            printf("9.exit\n");
            scanf("%d",&option);
            switch(option)
            {
                case 1: add();
                break;
                case 2: edit();
                break;
                case 3:find();
                break;
                case 4: delet();
                break;
                case 5: marks();
                break;
                case 6: help();
                break;
                case 7:list();
                break;
                case 8: result();
                break;
                case 9: exit(0);
                break;
                default: printf("you have chosen the wrong option");
                break;
            }
        }

    }
    else
    {
        printf("Welcome user to student management system please select the below options\n");
        for(iterate=0;;iterate++)
        {
            printf("1.add a new record\n");
            printf("2.edit an existing record\n");
            printf("3.find a record\n");
            printf("4.delete a record\n");
            printf("5.add results\n");
            printf("6.help page\n");
            printf("7.display results\n");
            printf("8.exit\n");
            scanf("%d",&option);
            switch(option)
            {
                case 1: add();
                break;
                case 2: edit();
                break;
                case 3:find();
                break;
                case 4: delet();
                break;
                case 5: marks();
                break;
                case 6: help();
                break;
                case 7: result();
                break;
                case 8: exit(0);
                break;
                default: printf("you have chosen the wrong option");
                break;
            }
        }
    }
    return 0;
}
