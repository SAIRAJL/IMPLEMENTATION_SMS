//C Language
//
// Project: Student Management System
//
// Program: Finding a record from file
// Author: Srusht Lingawar
//
//Update Time Spread:
//1 - 21 August 2021

void find()
{
 int flag=0;
 char rn[10];
 m b;
 r c;
 clrscr();
 gotoxy(5,6);printf("Enter Registration No ");fflush(stdin);scanf("%s",&rn);fflush(stdin);
 f1=fopen("c:\\student/main.dat","rb");
 while(fread(&b,size1,1,f1)==1)
 {
 if(strcmp(b.regn,rn)==0)
 {
 flag=0;
 clrscr();
 gotoxy(30,2);printf("|-------------------|");
 gotoxy(30,3);printf("| Student Details |");
 gotoxy(30,4);printf("|-------------------|") ;
 gotoxy(5,6); printf("Student Registration no :-%s",b.regn);
 gotoxy(5,8); printf("Student Name :-%s",b.name);
 gotoxy(5,10);printf("Student Fathers Name :-%s",b.f_name);
 gotoxy(5,12);printf("Student Address :-%s",b.address);
 gotoxy(5,14);printf("Course name :-%s",b.course);
 gotoxy(5,16);printf("Date Of Admission :-%s",b.doa);
 break;
 }
 else
 {
 flag=1;
 }
 }
 fclose(f1);
 f2=fopen("c:\\student/result.dat","rb");
 while (fread(&c,size2,1,f2)==1)
 {
 if(strcmp(c.regn,rn)==0)
 { gotoxy(1,17);printf("|----------------------------------------------------------|");
 gotoxy(1,16);printf(" M1 Marks M2 Marks M3 Marks M4 Marks ");
 gotoxy(1,18);printf("| %d",c.m1);
 gotoxy(16,18);printf("| %d",c.m2);
 gotoxy(32,18);printf("| %d",c.m3);
 gotoxy(48,18);printf("| %d",c.m4);
 gotoxy(1,19);printf("|----------------------------------------------------------|");
 gotoxy(5,21);printf("TOTAL MARKS:-%d",c.total);
 fflush(stdin);
 gotoxy(25,21);printf("GRADE:-%s",c.grade);
 fclose(f2);
 getch();
 break;
 }
 else
 {
 flag=2;
 }
 }
 fclose(f1);
 if(flag==1)
 {
 gotoxy(5,16);printf("This Record Is Not Fond Press Any Key To Continue..");
 getch();
 }
 else if(flag==2)
 {
 gotoxy(5,16);printf("Marks Of This Student Not Found Any Key To Continue..");
 getch();
 }
}
