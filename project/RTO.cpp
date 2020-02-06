#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
#include<string.h>
#include<process.h>
#include<ctype.h>

class person

{
 protected:
 int appno;
 int age;
 int lictype;
 int issued;

 char name[25];
 char add[25];

public:

 void getdata();
 void showdata();
 void returnissued()  //assigns license
 {issued=1;}
 };

 void person::getdata()
 {
 clrscr();
 cout<<"\n\n\n\t\tLicense Application";
 cout<<"\n\n\t\tApp.No.       :\t";cin>>appno;cout<<endl;
 cout<<"\t\tName          :\t";gets(name);cout<<endl;
 cout<<"\t\tAddress       :\t";gets(add);cout<<endl;
 do {
 cout<<"\t\tAge           :\t";cin>>age;cout<<endl;
 }while(age<18);
 cout<<"\t1. Two Wheeler  2.Four Wheeler   3. Heavy Vehicle"<<endl;
 cout<<"\n\t\tLicense Type  :\t";cin>>lictype;cout<<endl;
 issued=0;
 }

 void person::showdata()
 {
 clrscr();
 cout<<"\n\n\n\t\tLicence Verification"<<endl;
 cout<<"\n\n\t\tNo  :"<<appno<<endl;
 cout<<"\t\tName    :";puts(name);cout<<endl;
 cout<<"\t\tAddress :";puts(add);cout<<endl;
 cout<<"\t\tAge     :"<<age<<endl;
 cout<<"\t\tType    :"<<lictype<<endl;
 issued=0;
 cout<<flush;
}


class vehicle
{
protected:
char oname[20];                                          //owner name
char vname[20];                                         //vehicle name
char type[10];
char regno[15];
char engno[15];
char chassisno[15];
char cost[8];
public:


void getvehicle();
void showvehicle();
};

void vehicle::getvehicle()
{
clrscr();
cout<<"\n\n\n\t\tVehicle Registration Application"<<endl;
cout<<"\n\n\t\t\tOwner Name  :\t";gets(oname);cout<<endl;
cout<<"\t\t\tVehicle Make:\t";gets(vname);cout<<endl;
cout<<"\t\t\tVehicle Type:\t";gets(type);cout<<endl;
cout<<"\t\t\tVehicle Cost:\t";gets(cost);cout<<endl;
cout<<"\t\t\tEngine No.  :\t";gets(engno);cout<<endl;
cout<<"\t\t\tChasis No.  :\t";gets(chassisno);cout<<endl;
cout<<flush;
}

void vehicle::showvehicle()
{
clrscr();
cout<<"\n\n\n\t\t\tVehicle Registration"<<endl;
cout<<"\n\n\t\t\tOwner Name  :";puts(oname);cout<<endl;
cout<<"\t\t\tVehicle Make:";puts(vname);cout<<endl;
cout<<"\t\t\tVehicle Type:";puts(type);cout<<endl;
cout<<"\t\t\tVehicle Cost:";puts(cost);cout<<endl;
cout<<"\t\t\tEngine No.  :";puts(engno);cout<<endl;
cout<<"\t\t\tChasis No.  :";puts(chassisno);cout<<endl;
cout<<flush;
}

class license:public person
{ public:
  char licenseno[10];
  void displicense()
 {
  person::showdata();
  cout<<"\n\t\tlicense no  :";puts(licenseno);cout<<endl;
 }
 };
 class reg:public vehicle
 {
  public:
  char regno[15];
  void dispreg()
  {
  vehicle::showvehicle();
  cout<<"\n\t\t\tregistration no:"<<regno<<endl;
 }
 };

///////////////////////////////////////////////////////////////////////
void main()
{
int choice,choice1,choice2,flag=1;
char tans='n',tans1='n';
fstream file,file1,vfile,vfile1;
license lob;
reg rob;
char pwd[3];
char ch1='y',ch2='y';
do{
clrscr();
cout<<"\n\n\n\n\n\t\t welcome to the RT Office Management system"<<endl;
cout<<"\n\t\t\t 1.Applications"<<endl;
cout<<"\t\t\t 2.RTO login"<<endl;
cout<<"\t\t\t 3.Exit\t\t" ;cin>>choice1;
if(choice1==1)
{
  		do
      {
      	clrscr();
   		cout<<"\t\t\tApplications"<<endl;
   		cout<<"\t\t\tselect your choice(1-2)"<<endl;
   		cout<<"\n\t\t\t 1.Driving License"<<endl;
   		cout<<"\t\t\t 2.Vehicle Registration"<<endl;
   		cout<<"\t\t\t 3.Exit\t";cin>>choice;

   		if(choice==1)
   		{
            do
            {
         		file.open("license.txt",ios::app);
            	lob.getdata();
            	file.write((char*)&lob,sizeof(lob));
            	file.close();
            	cout<<"\n\n\n\t\tdo you want to continue(y/n)?\t";
            	cin>>ch1;
            }while(ch1=='y');
         }

			if(choice==2)
      	{
            do
            {
      			vfile.open("reg.txt",ios::app);
     	 			rob.getvehicle();
					vfile.write((char*)&rob,sizeof(rob));
      			vfile.close();
      			cout<<"\n\n\n\t\tdo you want to continue(y/n)?\t";
      			cin>>ch1;
            }while(ch1=='y');
  			}

             if(choice==3)break;

  		}while((ch1=='n'));	// choice3

 }


 if(choice1==2)
 {clrscr();
 cout<<"\n\n\t\tRTO LOGIN"<<endl;
 cout<<"\n\n\t\Password:";gets(pwd);
 if(strcmp(pwd,"rto")==0)
 {
  do
    {
   clrscr();
   cout<<"\n\n\n\t\t\tRTO Login"<<endl;
	cout<<"\n\n\t\t\t 1.Issue License"<<endl;
	cout<<"\t\t\t 2.Registration"<<endl;
   cout<<"\t\t\t 3.Show all  licenses"<<endl;
   cout<<"\t\t\t 4.Show all registrations"<<endl;
   cout<<"\t\t\t 5.Exit\t\t";
	cin>>choice2;
   if(choice2==1)
   	{

          file.open("license.txt",ios::in);
          //file.seekg(0);

          while(!file.eof())
          {
               tans='n';
               file.read((char*)&lob,sizeof(lob));
               if(file.eof()){cout<<"\n\t\tno more applications today";cout<<flush;break;}
               lob.showdata();
          		cout<<"\n\n\t\tApproved [y/n]";cin>>tans;
            	if(tans=='y')
               {
          			// write new file with info
          			file1.open("licenseissued.txt",ios::app);
           			cout<<"\n\n\t\tLicense No :\t";gets(lob.licenseno);cout<<endl;
          			file1.write((char*)&lob,sizeof(lob));
          			file1.close();
               }

            }
          	file.close();
            remove("license.txt");
           cout<<"\n\n\n\t\tpress n to go back to menu ";cin>>ch2;cout<<endl;
           cout<<flush;
      }

   	else if (choice2==2)
      	{
         	vfile.open("reg.txt",ios::in);
           //	vfile.seekg(0);



         while(!vfile.eof())
            { 	tans1='n';
         	vfile.read((char*)&rob,sizeof(rob));
            if(vfile.eof()){cout<<"\n\t\tno more applications today";cout<<flush;break;}
            rob.showvehicle();
         	cout<<"\t\t\tApproved [y/n]";cin>>tans1;

         	if(tans1=='y')
            {
         		// write new file with info
          		vfile1.open("regissued.txt",ios::app);
          		cout<<"\t\tEnter Registration No.:\t";gets(rob.regno);cout<<endl;
          		vfile1.write((char*)&rob,sizeof(rob));
          		vfile1.close();

          	}
            if(tans=='n')continue;
          	}
            vfile.close();
            remove("reg.txt");
            cout<<"\n\n\n\t\tpress n to go back to main menu";cin>>ch2;cout<<endl;
      	}

     		else if(choice2==3)
     		{  cout<<"\t\t\t Display all licenses"<<endl;
        		file1.open("licenseissued.txt",ios::in);

        		while(!file1.eof())
        		{
          		file1.read((char*)&lob,sizeof(lob));
               if(file1.eof()){cout<<"\n\t\tno more applications today";cout<<flush;break;}
          		lob.displicense();
          		getch();
        		}
        		file1.close();
             cout<<"\n\n\n\t\tpress n to go back to main menu";cin>>ch2;cout<<endl;
         }

        else if(choice2==4)
        {
          cout<<"\t\t\t Display all registrations"<<endl;
        		vfile1.open("regissued.txt",ios::in);
            while(!vfile1.eof())
        		{
          		vfile1.read((char*)&rob,sizeof(rob));
               if(vfile1.eof()){cout<<"\n\t\tno more applications today";cout<<flush;break;}
          		rob.dispreg();
          		getch();
        		}
        		vfile1.close();
            cout<<"\n\n\n\t\t press n to go back to main menu";cin>>ch2;cout<<endl;
         }
         if(choice2==5)break;
     }while(ch2=='n');
     }
  else
  { flag=0;
   cout<<"\n\n\t\twrong password"<<endl;
   getch();
  }
  }
 if(choice1==3)
 {
 	clrscr();
   cout<<"\n\n\n\n\n\t\t\t Thank You For Visiting us ";
   getch();
   exit(0);
 }
 }while((choice==3||choice2==5||flag==0));
 } //end of  main



