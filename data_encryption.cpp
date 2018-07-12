#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<fstream.h>
#include<process.h>


void savedata(char str3[]);

void DECRYPT(char str2[])
{
	char str3[100];
	int i,c=1,x;
	char resp2;
	for(i=0;str2[i]!='\0';i++)
	{	if(str2[i]==' ')
		{	str3[i]=' ';
		}
		else
		{	str3[i]=str2[i]-c;
		}
		c++;
	}
	str3[i]='\0';
	textcolor(0);
	for(i=0;i<=15;i++)
	{	textcolor(x);
		cprintf("\nYour Data is being Decrypted -.");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Decrypted /..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Decrypted -...");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Decrypted \..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Decrypted |.");
		delay(50);
		clrscr();
		x++;

	}
	textcolor(BLACK);
	for(i=0;	;i++)
	{
		clrscr();
		gotoxy(15,5);
		cprintf("DECRYPTED DATA:");
		cout<<str3;
		getch();
		gotoxy(15,7);
		cprintf("Do you want to save the data?(Y/N): ");
		cin>>resp2;
		if(resp2=='y'|| resp2=='n'|| resp2=='Y'|| resp2=='N')
		break;

	}
	if(resp2=='y' || resp2=='Y')
	{	savedata(str3);
	}
	else
	getch();

}

void dis_savedata(char str3[])
{
	int i;
	char name[30],lock[20],p_file[20]={"P_"};
	gotoxy(15,9);
	cprintf("Enter new file name :");
	gets(name);
	ofstream out;
	out.open(name);
	for(i=0;str3[i]!='\0';i++)
	{	out<<str3[i];
	}
	out.close();
	strcat(p_file,name);
	gotoxy(15,12);
	cprintf("\Enter a Lock Key:");
	gets(lock);
	out.open(p_file);
	for(i=0;lock[i]!='\0';i++)
	{	out<<lock[i];
	}
	out.close();
	for(i=0;i<5;i++)
	{     	gotoxy(15,10);
		cprintf("SAVING.");
		delay(100);
		clrscr();
		gotoxy(15,10);
		cprintf("SAVING..");
		delay(100);
		clrscr();
		gotoxy(15,10);
		cprintf("SAVING...");
		delay(100);
		clrscr();
	}
	gotoxy(15,10);
	cprintf("SAVED...");
	delay(1000);
	gotoxy(15,11);
	textcolor(0+BLINK);
	cprintf("Press any key ...");
	textcolor(0);

}

void savedata(char str3[])
{
	int i;
	char name[30];
	gotoxy(15,9);
	cprintf("Enter new file name :");
	gets(name);
	ofstream out;
	out.open(name);
	for(i=0;str3[i]!='\0';i++)
	{	out<<str3[i];
	}
	out.close();
	for(i=0;i<10;i++)
	{     	gotoxy(15,10);
		cprintf("SAVING.");
		delay(100);
		clrscr();
		gotoxy(15,10);
		cprintf("SAVING..");
		delay(100);
		clrscr();
		gotoxy(15,10);
		cprintf("SAVING...");
		delay(100);
		clrscr();
	}
	gotoxy(15,10);
	cprintf("SAVED...");
	delay(1000);
	textcolor(0+BLINK);
	cprintf("\n\n Press Any Key to continue...");
	getch();


}
void dis_getdata(char str1[])
{       clrscr();
	ifstream in;
	int i=0,flag=1;
	char name[30],lock[20],give[20],p_file[20]={"P_"};
	gotoxy(5,5);
	cprintf("\n Enter the file name :");
	gets(name);
	in.open(name);
	while(! in.eof())
	{       in>>str1[i];
		i++;
	}
	in.close();
	str1[i]='\0';
	cout<<endl;
	i=0;
	strcat(p_file,name);
	in.open(p_file);
	while(! in.eof())
	{       in>>lock[i];
		i++;
	}
	lock[i-1]='\0';
	in.close();
	gotoxy(5,7);
	cprintf("Enter the unlock Key :");
	gets(give);
       /*	cout<<endl<<name;
	cout<<endl<<p_file;
	cout<<endl<<give;
	cout<<endl<<lock;
	cout<<endl<<str1;
	getch();     */
	if(strcmp(lock,give)==0)
	{	DECRYPT(str1);
		flag=0;
	}
	if(flag==1)
	{	clrscr();
		gotoxy(5,5);
		cprintf(" File doesnot exist.");
	}
	getch();
	clrscr();
}


void getdata(char str1[])
{
	ifstream in;
	int i=0;
	char name[30];
	cprintf("\n Enter the file name :");
	gets(name);
	in.open(name);
	while(! in.eof())
	{       in>>str1[i];
		i++;
	}
	str1[i]='\0';


}

void pubpassword(char pass[])
{
	clrscr();
	int i,n;
	do
	{       clrscr();
		gotoxy(15,5);
		cprintf("\n Enter the password to retrieve the secured data:");
		gotoxy(15,6);
		cprintf("\n{ The length should not exceed 10. }");
		gotoxy(15,9);
		cprintf("\n Enter the length of password:");
		cin>>n;
	}while(n<1 || n>10);
	gotoxy(15,10);
	cprintf("\n Enter the password:");
	for(i=n-1;i>=0;i--)
	{	pass[i]=getch();
		cprintf("*");
	}
	pass[n]='\0';

}

void password(char pass[])
{
	clrscr();
	int i,n;
	do
	{       clrscr();
		gotoxy(15,5);
		cprintf("\n Enter the password to retrieve the secured data:");
		gotoxy(15,6);
		cprintf("\n{ The length should not exceed 10. }");
		gotoxy(15,9);
		cprintf("\n Enter the length of password:");
		cin>>n;
	}while(n<1 || n>10);
	gotoxy(15,10);
	cprintf("\n Enter the password:");
	for(i=0;i<n;i++)
	{	pass[i]=getch();
		cprintf("*");
	}
	pass[n]='\0';

}

int dis_ENCRYPT(char str1[])
{
	int i,c=1,x=0,count,ch;
	char str2[100];
	for(i=0;i<=10;i++)
	{	textcolor(x);
		cprintf("\nYour Data is being Encrypted -.");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted /..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted -...");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted \..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted |.");
		delay(50);
		clrscr();
		x++;

	}
	textcolor(0);
	cprintf("\nYour Data has been successfully Encrypted:\n\n");
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]==' ')
		{	str2[i]=' ';
		}
		else
		{	str2[i]=str1[i]+c;
			c++;
		}
	}
	str2[i]='\0';
	gotoxy(3,5);
	textcolor(0);
	cprintf("\nEncrypted Data :");
	cout<<str2;
	gotoxy(10,9);
	cprintf(" Press Any key to go to SAVING option...");
	getch();
	clrscr();
	dis_savedata(str2);
	getch();
	return(0);

}


int ENCRYPT(char str1[],char pass[])
{
	int i,c=1,x=0,count,flag=0,ch;
	char str2[100],resp;
	char gipass[20];
	for(i=0;i<=15;i++)
	{	textcolor(x);
		cprintf("\nYour Data is being Encrypted -.");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted /..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted -...");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted \..");
		delay(50);
		clrscr();
		cprintf("\nYour Data is being Encrypted |.");
		delay(50);
		clrscr();
		x++;

	}
	textcolor(0);
	cprintf("\nYour Data has been successfully Encrypted:\n\n");
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]==' ')
		{	str2[i]=' ';
		}
		else
		{	str2[i]=str1[i]+c;
		}
		c++;
	}
	str2[i]='\0';
	gotoxy(3,5);
	textcolor(0);
	cprintf("\nEncrypted Data :");
	cout<<str2;
	do
	{
		textcolor(0);
		gotoxy(3,7);
		cprintf("\nDo you want to Decrypt the Data??(Y/N):");
		cin>>resp;
		if(resp=='Y'|| resp=='y')
		{	for(count=0;count<=2;count++)
			{       clrscr();
				pubpassword(gipass);
				ch=strcmp(gipass,pass);
				if(ch==0)
				{
					DECRYPT(str2);
					flag=1;
					break;
				}
				else
				{  	cprintf("\n IT's WRONG");
				}
				getch();
			}
			clrscr();
			if(flag==0)
			{	textcolor(0);
				gotoxy(15,10);
				cprintf("\n Sorry the data couldn't be decrypted.");
				delay(5000);
			}
			return(0);

		}
		else if(resp=='N'||resp=='n')
		{       return(0);
		}
	}while(resp!='Y' || resp!='N'||resp!='y'|| resp!='n');
	return(0);

}

void main()
{
	textbackground(7);
	clrscr();
	char pass[20];
	char str1[100],ans;
	int i,c=15,m=0;  //design purpose.
	gotoxy(15,15);
	textcolor(0);
	cprintf("Created and developed by:-");
	gotoxy(15,16);
	cprintf("Tanmoy Ghosh");
	gotoxy(15,17);
	cprintf("Siddhant Mohanty");
	gotoxy(15,18);
	cprintf("Subhasish Mukherjee");
	gotoxy(15,19);
	cprintf("Zaid Hossain");
	gotoxy(15,10);
	textcolor(0);
	cprintf("#### Welcome To Data Encryption Centre ####");
	delay(3000);
	textcolor(0+BLINK);
	cprintf("\n\n Press Any Key...");
	getch();
	clrscr();
	for(i=1;i<10;i++)
	{	textcolor(0);
		gotoxy(15,10);
		cprintf("Loading,Please Wait....");
		gotoxy(c,11);
		m++;
		textcolor(m);
		cprintf("#");
		delay(100);
		clrscr();
		c++;
		if(c>27)
		c=15;
	}
     run:gotoxy(15,9);
	cprintf(" Use it for...");
	gotoxy(15,10);
	cprintf(" 1.Distribution Purpose.");
	gotoxy(15,11);
	cprintf(" 2.Personal Purpose.");
	gotoxy(15,12);
	cprintf(" 3.Exit.");
	gotoxy(15,13);
	cprintf("         Response:");
	int decide;
	cin>>decide;
	clrscr();
	switch(decide)
	{   int enc_dec;
	    encdec:	case 1:gotoxy(15,9);
		   cprintf("1. ENCRYPT.");
		   gotoxy(15,11);
		   cprintf("2. DECRYPT.");
		   gotoxy(15,13);
		   cprintf("3. EXIT.");
		   gotoxy(15,14);
		   cprintf("          Response:");
		   cin>>enc_dec;
		   switch(enc_dec)
		   {	case 1:clrscr();
				textcolor(0);
				gotoxy(15,10);
				cprintf("Enter Data for Encryption:");
				gets(str1);
				dis_ENCRYPT(str1);
				goto run;
			      break;
			case 2: dis_getdata(str1);
				goto run;
				break;
			case 3: exit(0);
				break;
			default:cprintf("\n Please give a valid response.");
		   delay(1000);
		   clrscr();
		   goto encdec;
		   }

		case 2:gotoxy(15,9);
			cprintf("Press...");
			gotoxy(15,10);
			cprintf("   1.Work on saved data.");
			gotoxy(15,11);
			cprintf("   2.Enter data now.");
			gotoxy(15,12);
			cprintf("   3.Exit.");
			gotoxy(15,14);
			cprintf("      Response:");
			int res;
			cin>>res;
			clrscr();
			switch(res)
			{   case 1:getdata(str1);
			    break;
			    case 2:
				textcolor(0);
				gotoxy(15,10);
				cprintf("Enter Data for Encryption:");
				gets(str1);
			   break;
			   case 3: exit(0);
				break;
			   default:cprintf("\n Please respond in either 1 or 2.");
				   delay(1000);
				   clrscr();
				   goto run;
			}
			clrscr();
			gotoxy(15,10);
			cprintf("Enter a password to keep it secured");
			gotoxy(15,11);
			password(pass);
			textcolor(WHITE);
			clrscr();
			ENCRYPT(str1,pass);
			 break;
			 case 3: exit(0);
				break;
	   default:cprintf("\n Please give a valid response.");
		   delay(1000);
		   clrscr();
		   goto run;
	}
	while(1)
	{	clrscr();
		textcolor(0);
		cprintf("\n Do you want to encrypt data again (Y/N):");
		cin>>ans;
		if(ans=='Y'|| ans=='N'|| ans=='y'|| ans=='n')
		break;
	}
	if(ans=='Y'||ans=='y')
	{       goto run;
	}
	else
  thanks:{ 	clrscr();
		c=10;
		while(! kbhit())
		{	textcolor(m);
			gotoxy(15,c);
			cprintf("***THANKS FOR USING DATA ENCRYPTOR***");
			c++;
			if(c>15)
			c=10;
			delay(500);
			clrscr();
			m++;
		}
	}
	getch();
}
