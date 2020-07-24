#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
void modify_acc_details();
void create_account();
void display_acc_details();
double debit();
double credit();
void ministatement();
void close_acc();
void push(int,int);
void enter_pin();
void enter_epin();
struct net *start[10];
long stackc[5],stackd[5];
int topc=-1,topd=-1,flag;
int temp=0,z;
struct net
{
	struct net *start[10];
	int dd,mm,yyyy;
	char firstname[10],lastname[10];
	char country[10],state[10],city[10];
	char gender[10];
	long contactno;
	int accountno;
	long pincode;
	int pin,epin,bal;
};
int cr[5],j=0,d[5],i=0;



void main()
{
      /*	int choice1,choice2;
	 int gd=DETECT,gm;

       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
       setbkcolor(BROWN);
       */
       clrscr();

do
{
	printf("\n\n\n\n\nWELCOME TO TEAM BRAVO'S NET BANKING MANAGEMENT SYSTEM\n\n\n");
	printf("\n***** ****    *   *    *        **** ****   *  *     *    *    ");
	printf("\n  *   ****   ***  * ** *        **   ***   ***  *   *   *   *   ");
	printf("\n  *   ****  *   * *    *        **** *  * *   *   *       *     ");
	printf("\n1.SIGN UP\n2.LOG IN\n3.Exit Net Banking\nEnter the choice\n");
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 1:create_account();
		break;
		case 3:printf("\nExiting...");
		break;
		case 2:
		printf("\nEnter the unique id");
		scanf("%d",&z);
		temp=i;
		i=z;
	do
	{

		printf("\n1.Display Account details\n2.Modify account details\n3.Debit from account\n4.Credit to account\n5.Display Ministatement\n6.Close account\n7.Goto the main screen\n");
		scanf("%d",&choice2);
	       switch(choice2)
	       {
			case 1:display_acc_details();
			break;
			case 2:modify_acc_details();
			break;
			case 3:debit(start[i]->bal);
			break;
			case 4:credit(start[i]->bal);
			break;
			case 5:ministatement(start[i]->bal);
			break;
			case 6:close_acc();
			break;
			case 7:printf("Diverting to main screen...");
			break;
			default:printf("\nInvalid Choice!!!");
	       }

	}while(choice2!=7);
	default:printf("\nInvalid Choice!!!");
	}
}while(choice1!=3);
getch();
}




struct net *create_node()
{
	struct net *p;
	p=(struct net*)malloc(sizeof(struct net));
	return p;
}



void push(int num,int flag)
{
	if(flag==0)
	{
		if(topc==-1)
		printf("\nno transaction in credit");
		else
		{
			stackc[++topc]= num;
		}
	}
	else
	{
		if(topd==-1)
		printf("\nno transaction in debit");
	       {
		stackd[++topd]= num;
	       }
	}
}



void create_account()
{
	int n;
	clrscr();
	if(temp!=0)
	{
		i=temp;
	}
	i++;
		start[i]=create_node();
	printf("\nthe unique id is \t%d",i);
	//scanf("%d",&start[i]->accountno);
	printf("\nenter your first name:");
	scanf("%s",&start[i]->firstname);
	printf("\nenter your last name:");
	scanf("%s",&start[i]->lastname);
	printf("\nenter the date of birth(dd):");
	scanf("%d",&start[i]->dd);
	printf("\nenter the month of birth(mm):");
	scanf("%d",&start[i]->mm);
	printf("\nenter the year of birth(yyyy):");
	scanf("%d",&start[i]->yyyy);
	printf("\nenter your country:");
	scanf("%s",&start[i]->country);
	printf("\nenter your state:");
	scanf("%s",&start[i]->state);
	printf("\nenter your city:");
	scanf("%s",&start[i]->city);
	printf("\nenter your pin code:");
	scanf("%l",&start[i]->pincode);
	printf("\nenter your gender(male/female):");
	scanf("%s",&start[i]->gender);
	printf("\nenter your 10 digits contact no:");
	scanf("%d",&start[i]->contactno);
	printf("\nenter a secured pin for your account\n(To build a Strong Password it must have atleast one number\natleast one alphabet in uppercase\natleast one  alphabet in lower case\nit should contain atleast 8 charaters):");
      //	scanf("%d",&start[i]->pin);
       enter_pin();


	printf("\nDo you want to create one more account press 1(yes)\t0(no)");
	scanf("%d",&n);
	if (n==1)
	create_account();
}



void display_acc_details()
{
	clrscr();
	printf("\n\nYour unique id is\t%d",i);
	//scanf("%d",&start[i]->accountno);
	printf("\n\nEnter Your Correct Account Pin");
       //	scanf("%d",&start[i]->epin);
       enter_epin();
	if(start[i]->pin==start[i]->epin)
	{
		printf("\nThe Account No is:\t%d",start[i]->accountno);
		printf("\nAccount Holder's Name:\t%s %s",start[i]->firstname,start[i]->lastname);
		printf("\nAccount Holder's Date Of Birth is:\t%d %d %d",start[i]->dd,start[i]->mm,start[i]->yyyy);
		printf("\nThe Account Balance is:\t%d",start[i]->bal);
		printf("\nThe Country :%s\nThe State :%s \nThe City : %s",start[i]->country,start[i]->state,start[i]->city);
		printf("\nThe pincode :%d\nGender :%s \nContact : %lu",start[i]->pin,start[i]->gender,start[i]->contactno);
	}
	else
	{
		printf("\n The entered pin is ***INVALID***");
	}
}



void modify_acc_details()
{
int ch;
	display_acc_details();
	printf("\n\nEnter Your Correct Account Pin");
	scanf("%d",&start[i]->epin);
	do
	{
		if(start[i]->pin==start[i]->epin)
		{
			printf("\n\nChoose Appropriate Entity To Be Modified");
			printf("\n1.Account Holder's Name\n2.Account Holder's Date Of Birth\n3.Pin\n4.Cancel\n Enter choice");
			scanf("%dd",&ch);
			switch(ch)
			{
				case 1:printf("\n Enter the firstname and lastname separated with enter key");
					scanf("%s%s",&start[i]->firstname,&start[i]->lastname);
				break;
				case 2:printf("\n Enter the date month and year separated with enter key");
					scanf("%d%d%d",&start[i]->dd,&start[i]->mm,&start[i]->yyyy);
				break;
				case 3:printf("\n Enter the new");
					scanf("%d",&start[i]->pin);
					printf("\n re-enter the new pin");
					scanf("%d",&start[i]->epin);
					if(start[i]->pin!=start[i]->epin)
					continue;
					break;
				//break;
				case 4:printf("\n Canceling...");
				break;
				default:printf("\nInvalid choice");
			}
		}
		else
		{
		printf("\n The entered pin is ***INVALID***");
		}
	}while(ch!=4);
}



double debit()
{
	int flag=1,val;
	printf("enter the amount to debit\n");
	scanf("%d",&val);

	if(val<=start[i]->bal)
	{
		start[i]->bal= start[i]->bal-val;
		printf("\nYour account balance is: %d",start[i]->bal);
	}
	else
	{
		printf("YOUR BALANCE IS LOW!");
	}
	push(val,flag);
	return start[i]->bal;
}



double credit()
{
	int flag=0,val;
	printf("enter the amount to credit\n");
	scanf("%d",&val);

	start[i]->bal=start[i]->bal+val;
	printf("\nYour account balance is: %d",start[i]->bal);
	push(val,flag);
	return start[i]->bal;
}



void ministatement()
{
	int k;
	for(k=topd;k>=0;k--)
	{
		printf("\nDEBITED AMOUNT::%d",stackd[k]);
	}
	for(k=topc;k>=0;k--)
	{
		printf("\nCREDITED AMOUNT::%d",stackc[k]);
	}
		printf("\nCURRENT BALANCE::%d",start[i]->bal);

}



void close_acc()
{
	printf("\n Your account is succesfully deactivated");
}



void enter_pin()
{
int str[10],m=0,f,j,sum=0;
printf("\n Enter the password [ max length 4 ] : ");
while (m<=3)
{
	 str[m]=getch();
	 printf("*");
	 m++;
}
 for(f=3,j=0;f>=0&&j<=3;f--,j++)
    {
	sum+=str[f]*pow(10,j);
    }
     start[i]->pin=sum;
}



void enter_epin()
{
int str[10],m=0;
int sum=0,f,j;
printf("\n Enter the password [ max length 4 ] : ");
while (m<=3)
    {
	 str[m]=getch();
	 printf("*");
	  m++;
     }
    for(f=3,j=0;f>=0&&j<=3;f--,j++)
    {
	sum+=str[f]*pow(10,j);
    }
    start[i]->epin=sum;
}