#include "result.h"


struct result
{
   int m1,m2,m3,m4,total;
   char regn[10],grade[2];
};

long int size2=sizeof(r);

f2=fopen("C:\\student//result.dat","wb"); // Creating Result Database For This Application //
 fclose(f2);

 void result(void)
{
 r a;
 int i,j;
 i=4,j=0;
 clrscr();
 f1=fopen("c:\\student/result.dat","rb");
 gotoxy(1,1);printf("|---------------------------------------------------------------------------|");
 gotoxy(1,2);printf("| Reg No. Module 1 Module 2 Module 3 Module 4 Total Grade |");
 gotoxy(1,3);printf("|---------------------------------------------------------------------------|");
 while(fread(&a,size2,1,f1)==1)
 {
 if(j%2==0){textbackground(4);}else{textbackground(1);;}
 gotoxy(2,i);cprintf(" ");
 gotoxy(1,i);printf("| %s",a.regn);
 gotoxy(10,i);printf("| %d",a.m1);
 gotoxy(20,i);printf("| %d",a.m2);
 gotoxy(33,i);printf("| %d",a.m3);
 gotoxy(45,i);printf("| %d",a.m4);
 gotoxy(56,i);printf("| %d",a.total);
 gotoxy(65,i);printf("| %s",a.grade);
 gotoxy(77,i);printf("|");
 i++;
 j++;
 textbackground(0);
 gotoxy(1,i);printf("|--------|---------|------------|-----------|----------|--------|-----------|");
 i++;
 if(i==50)
 { i=4;
 gotoxy(10,52);printf("Press any Key To Continue Or Press 0 zero to Exit");
 if(getch()=='0')
 {
 break;
 }
 else
 {
 clrscr();
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 }
 }
 }
 fclose(f1);
 getch();
 form1();
}
