#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
char username[10]="ash";
char pass[10]="con1";
int l=3;
void acont();
void scont();
void dcont();
void vcont();
void main()
{
    system("cls");
    char ch;
    char old[10];
    char newp[10];
    //int i=3;
    int option;
    char u[10],p[10];
    textcolor(9);
    //printf("\n\n\t\t\t");
    do
    {
    printf("Enter username and password : ");
    scanf("%s%s",&u,&p);
    if(strcmp(u,username)==0 && strcmp(p,pass)==0)
    {
    system("cls");
    printf("\n\n\t\t\t");
    cprintf("*****PHONE BOOK*****");
    textcolor(10);
    printf("\n\t\t\t");
    cprintf("~~~~~DIVISION C~~~~~");
    do
    {
    textcolor(13);
    printf("\n\t");
    cprintf("1. Add Contact");
    printf("\n\t");
    cprintf("2. Search Contact");
    printf("\n\t");
    cprintf("3. Delete Contact");
    printf("\n\t");
    cprintf("4. View All Contact");
    printf("\n\t");
    cprintf("5. Exit");
    printf("\n\t");
    printf("Enter Your Choice:-");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
	acont();
	break;
    case 2:
	scont();
	break;
    case 3:
	dcont();
	break;
    case 4:
	vcont();
	break;
    case 5:
	exit(0);
    default:
	textcolor(6);
	cprintf("PLEASE ENTER VALID INPUT");
    }
    }
    while(option>5);
    }
    else
    {
    l--;
    printf("\n\tYou have %d more tries\n\n",l);
    }
    }
    while(l>0);
    if(l<=0)
    {
    printf("\nChange old password ???");
    printf("\nEnter y or n");
    scanf("%c",&ch);
    if(ch=='y')
    {
	printf("Enter old password : ");
	scanf("%s",&old);
	if(strcmp(old,pass)==0)
	{
	printf("Enter new password : ");
	scanf("%s",&newp);
	strcpy(pass,newp);
	}
    }
    }
    getch();
}
void acont()
{
    FILE *fp;
    //struct password p[100];
    fp=fopen("contact.txt","a+");
    system("cls");
    textcolor(11);
    printf("\t\t");
    cprintf("*****ADD CONTACT*****\n");
    textcolor(14);
    printf("\n\t");
    cprintf("Name    :- ");
    char name[20];
    scanf("%s",name);
    printf("\n\t");
    cprintf("Mob No. :- ");
    char mob[20];
    scanf("%s",mob);
    /*printf("Enter password : ");
    scanf("%s",&p[l].pass);
    l++;*/
    fprintf(fp,"%s %s\n",name,mob);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    //main();
}
void scont()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    textcolor(11);
    printf("\t\t");
    cprintf("\t*****SEARCH CONTACT*****");
    textcolor(14);
    printf("\n\t");
    cprintf("Enter Name :-");
    char name1[20];
    scanf("%s",name1);
    char name[20],mob[20];
    int flag=0;
    char pas[15];
    printf("Enter password : ");
    scanf("%s",&pas);
    if(strcmp(pas,pass)==0)
    {
    while(fscanf(fp,"%s %s",name,mob)!=EOF)
    {
	if(strcmp(name,name1)==0)
	{
	    textcolor(12);
	    printf("\n\t");
	    cprintf("NAME     :- %s\n",name);
	    textcolor(6);
	    printf("\n\t");
	    cprintf("MOB NO.  :- %s\n",mob);
	    flag=1;
	}
    }
    if(flag==0)
    {
	    textcolor(4);
	    printf("\n\t\t");
	    cprintf("NO CONTACTS FOUND !!!");
    }
    }
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    //main();
}
void dcont()
{
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    textcolor(11);
    printf("\t\t");
    cprintf("*****DELETE CONTACT*****");
    textcolor(14);
    printf("\n\t");
    cprintf("Enter Name :-");
    char name1[20];
    scanf("%s",name1);
    char name[20],mob[20];
    int flag=0;
    while(fscanf(fp,"%s %s",name,mob)!=EOF)
    {
	if(strcmp(name1,name)==0)
	{
	    flag=1;
	    continue;
	}
	fprintf(fp1,"%s %s\n",name,mob);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s",name,mob)!=EOF)
    {

	fprintf(fp,"%s %s\n",name,mob);
    }
    if(flag==0)
    {
	    textcolor(4);
	    printf("\n\t\t");
	    cprintf("NO CONTACTS FOUND !!!");
    }
    fclose(fp);
    fclose(fp1);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    //main();
}
void vcont()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t*****ALL CONTACTS*****");
    char name[20],mob[20];
    while(fscanf(fp,"%s %s",name,mob)!=EOF)
    {
	textcolor(12);
	printf("\n\t");
	cprintf("NAME    :-  %s",name);
	textcolor(6);
	printf("\n\t");
	cprintf("MOB NO. :-  %s",mob);
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    //main();
}











