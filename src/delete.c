#include"delete.h"

/**
  *@brief structure containing details required to keep a record of student
  */
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
/**
  *@brief structure  about define link list Structure for deleting or editing
  */
struct link_result 
{
   int lrm1,lrm2,lrm3,lrm4,lrtotal; // student members//
   char lrregn[10],lrgrade[2]; 
   struct link_result *next; 
};
/**
  *@declare typedef of structure
  */
typedef struct main m;
typedef struct result r;
typedef struct link_main lm;
typedef struct link_result lr;
long int size1=sizeof(m);
long int size2=sizeof(r);
FILE *f1,*f2; 


void delet()
{
 m a,b;
 r c,d;
 lm *s,*p,*n;
 lr *m,*t,*k;
 char reg[10],op;
 char newe[100];
 int flag,flag1;
 s=p=n=NULL;
 m=t=k=NULL;
 flag=flag1=0;
 clrscr();
 gotoxy(25,1);printf("-----------------------------------");
 gotoxy(24,2);printf("| Deleting Of A Student Profile |");
 gotoxy(25,3);printf("-----------------------------------");
 f1=fopen("c:\\student/main.dat","rb");
 if (f1==NULL){printf("Databse not exist");getch();exit(0);}
 gotoxy(5,6);printf("| Enter Reg No Of Student :-");fflush(stdin);scanf("%s",&reg);
 while(fread(&a,size1,1,f1)==1)
 {
 n=(lm*)malloc(sizeof(lm));
 strcpy(n->lmregn,a.regn);
 strcpy(n->lmname,a.name);
 strcpy(n->lmf_name,a.f_name);
 strcpy(n->lmaddress,a.address);
 strcpy(n->lmcourse,a.course);
 strcpy(n->lmdoa,a.doa);
 n->next=NULL;
 if (s==NULL)
 {
 s=n;
 }
 else
 {
 for(p=s;p->next!=NULL;p=p->next);p->next=n;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while(fread(&c,size2,1,f2)==1)
 {
 k=(lr*)malloc(sizeof(lr));
 strcpy(k->lrregn,c.regn);
 k->lrm1=c.m1;
 k->lrm2=c.m2;
 k->lrm3=c.m3;
 k->lrm4=c.m4;
 k->lrtotal=c.total;
 strcpy(k->lrgrade,c.grade);
 k->next=NULL;
 if (m==NULL)
 {
 m=k;
 }
 else
 {
 for(t=m;t->next!=NULL;t=t->next);t->next=k;
 }
 }
 fclose(f2);
 f1=fopen("c:\\student/main.dat","rb");
 while(fread(&a,size1,1,f1)==1)
 {
 if(strcmp(a.regn,reg)==0)
 { flag=0;
 gotoxy(5,5);printf("| |");
 gotoxy(5,7);printf("| |");
 gotoxy(5,8);printf("| |");
 gotoxy(5,9);printf("| |");
 gotoxy(5,10);printf("| |");
 gotoxy(5,11);printf("| |");
 gotoxy(5,4);printf("|-----------------------------Details-----------------------------|");
 gotoxy(5,7);printf("| Student Name :- %s",a.name);
 gotoxy(5,8);printf("| Student Father`s Name :- %s",a.f_name);
 gotoxy(5,9);printf("| Student Address :- %s",a.address);
 gotoxy(5,10);printf("| Course :- %s",a.course);
 gotoxy(5,11);printf("| Date of Addmission :- %s",a.doa);
 gotoxy(5,12);printf("|-----------------------------------------------------------------|");
 break;
 }
 else
 {
 flag=2;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while (fread(&c,size2,1,f2)==1)
 {
 if(strcmp(c.regn,reg)==0)
 {
 flag1=0;
 gotoxy(5,17);printf("|----------------------------------------------------------|");
 gotoxy(5,16);printf(" M1 Marks M2 Marks M3 Marks M4 Marks ");
 gotoxy(5,18);printf("| %d",c.m1);
 gotoxy(21,18);printf("| %d",c.m2);
 gotoxy(37,18);printf("| %d",c.m3);
 gotoxy(53,18);printf("| %d |",c.m4);
 gotoxy(5,19);printf("|----------------------------------------------------------|");
 gotoxy(5,21);printf("TOTAL MARKS:-%d",c.total);
 fflush(stdin);
 gotoxy(25,21);printf("GRADE:-%s",c.grade);
 fclose(f2);
 break;
 }
 else
 {
 flag1=2;
 }
 }
 fclose(f2);
 if (flag==2){gotoxy(10,30);printf("This Ren No Not Found Press Any Key To Continue");getch();goto end;}
 if (flag1==1){gotoxy(5,21);printf("The Marks Of This Student Not Exist");}
 gotoxy(5,23);printf("Are You Sure Delete This Record?(Y/N)");fflush(stdin);op=getch();
 if (op=='Y'||op=='y')
 {
 if(strcmp(s->lmregn,reg)==0)
 {
 flag=1;
 n=s->next;
 free(s);
 s=n;
 }
 else
 {
 for (p=s;p->next!=NULL;p=p->next)
 {
 if(strcmp(p->lmregn,reg)==0)
 {
 flag=1;
 n=p->next->next;
 free(p->next);
 p->next=n;
 }
 }
 }
 if(strcmp(m->lrregn,reg)==0)
 {
 flag1=1;
 k=m->next;
 free(m);
 m=k;
 }
 else
 {
 for (t=m;t->next!=NULL;t=t->next)
 {
 if(strcmp(t->lrregn,reg)==0)
 {
 flag1=1;
 k=t->next->next;
 free(t->next);
 t->next=k;
 }
 }
 }
 }
 else
 {
 gotoxy(10,30);printf("Record Was Not Deleted");getch();
 }
 if (flag==1)
 {
 f2=fopen("c:\\student/main.dat","wb");
 for(p=s;p!=NULL;p=p->next)
 {
 strcpy(b.regn,p->lmregn);
 strcpy(b.name,p->lmname);
 strcpy(b.f_name,p->lmf_name);
 strcpy(b.address,p->lmaddress);
 strcpy(b.course,p->lmcourse);
 strcpy(b.doa,p->lmdoa);
 fwrite(&b,size1,1,f2);
 free(p);
 }
 fclose(f2);
 }
 else
 {
 for(p=s;p!=NULL;p=p->next)
 {
 free(p);
 }
 }
 if (flag1==1)
 { fclose(f2);
 f2=fopen("c:\\student/result.dat","wb");
 for(t=m;t!=NULL;t=t->next)
 {
 strcpy(d.regn,t->lrregn);
 d.m1=t->lrm1;
 d.m2=t->lrm2;
 d.m3=t->lrm3;
 d.m4=t->lrm4;
 d.total=t->lrtotal;
 strcpy(d.grade,t->lrgrade);
 fwrite(&d,size2,1,f2);
 free(t);
 }
 fclose(f2);
 }
 else
 {
 for(t=m;t!=NULL;t=t->next)
 {
 free(t);
 }
 }
 end:
 form1();
}
