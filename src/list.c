#include "list.h"

struct main
{
   char regn[10],name[50],f_name[50],address[100],course[10],doa[10];
};
typedef struct main m;
long int size1=sizeof(m);
FILE *f1,*f2; 

void list(void)
{
 m a;
 int i,j;
 int mx, my, mouse_button,mouse_button2, maxx, maxy ;
 i=4,j=0;
 clrscr();
 f1=fopen("c:\\student/main.dat","rb");
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 while(fread(&a,size1,1,f1)==1)
 {
 if(j%2==0){textbackground(4);}else{textbackground(1);;}
 gotoxy(2,i);cprintf(" ");
 gotoxy(1,i);cprintf("| %s",a.regn);
 gotoxy(10,i);cprintf("| %s",a.name);
 gotoxy(30,i);cprintf("| %s",a.f_name);
 gotoxy(53,i);cprintf("| %s",a.course);
 gotoxy(67,i);cprintf("| %s",a.doa);
 gotoxy(80,i);cprintf("|");
 fflush(stdin);
 j++;
 i++;
 textbackground(0);
 gotoxy(1,i);cprintf("|--------|-------------------|----------------------|-------------|------------|");
 i++;
 if(i==50)
 { i=4;
 gotoxy(10,52);printf("Press any Key To Continue Or Press 0 zero to Exit");
 while (!kbhit())
 {
 get_position();
 if (mouse_button==1)
 {
 clrscr();
 gotoxy(1,2);printf(" Reg No. Student Name F_name Courese Date Of Add");
 gotoxy(1,3);printf("|------------------------------------------------------------------------------|");
 }
 else if(mouse_button2==2)
 {
 break;
 }
 }
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
 getch();
 fclose(f1);
 form1();
}

