#include<iostream>
#include<stdio.h>       //for gets()
#include<stdlib.h>      //for system("cls")
using namespace std;
class Account
{
private:
	int AcctNo;
	char AcctName[20];
	char AcctType;
	int Amount;
	char DateCreated[10];
	int PinNo;
public:
	long Deposit;
	void CreateAcct();
	void ShowAcct();
	void DepositAmt();
	void WithdrawAmt();
	int Search(int);
	int Verify(int);
};
void Account::CreateAcct()
{
	cout<<"\n\n\n\n\n\t\t\t\t\t"<<"Enter your account details here :"<<"\n\n";
	cout<<"\n\t\t\t\t"<<"Enter your account no. :: ";
	cin>>AcctNo;
	cout<<"\n\t\t\t\t"<<"Enter your account name :: ";
	cin.ignore();
	cin.getline(AcctName,15);
	cout<<"\n\t\t\t\t"<<"Enter your account type (C/S) :: ";
	cin>>AcctType;
	cout<<"\n\t\t\t\t"<<"Enter the amount to be deposited :: ";
	cin>>Deposit;
	cout<<"\n\t\t\t\t"<<"Enter the date created :: ";
	cin>>DateCreated;
	cout<<"\n\t\t\t\t"<<"Set your user pin : ";
	cin>>PinNo;
}
void Account::ShowAcct()
{
	cout<<"\n\n\n\n\n\t\t\t\t\t\t"<<":: ACCOUNT DETAILS ::"<<"\n\n";
	cout<<"\n\t\t\t\t\t"<<"Account No. : "<<AcctNo<<"\n";
    cout<<"\n\t\t\t\t\t"<<"Account Holder Name : "<<AcctName<<"\n";
	cout<<"\n\t\t\t\t\t"<<"Type Of Account : "<<AcctType<<"\n";
	cout<<"\n\t\t\t\t\t"<<"Balance Amount : "<<Deposit<<"\n";
	cout<<"\n\t\t\t\t\t"<<"Account Created : "<<DateCreated<<"\n\n";
}
void Account::DepositAmt()
{
	cout<<"\n\n\t\t\t\t\t"<<"TO DEPOSIT AMOUNT :"<<"\n";
	cout<<"\n\t\t\t\t\t"<<"Enter the amount you want to deposit : ";
	cin>>Amount;
	Deposit = Deposit + Amount;
	cout<<"\n\n\t\t\t\t\t"<<"Record Updated!"<<"\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
}
void Account::WithdrawAmt()
{
	cout<<"\n\n\t\t\t\t\t"<<"TO WITHDRAW AMOUNT :"<<"\n";
	cout<<"\n\t\t\t\t\t"<<"Enter the amount you want to withdraw : ";
	cin>>Amount;
	{
	    if (Amount<=Deposit)
	        Deposit =  Deposit - Amount;
	    else
	        cout<<"\n\t\t\t\t\t"<<"Less balance in your account...";
	}
	cout<<"\n\n\t\t\t\t\t"<<"Record Updated!"<<"\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";	
}
int Account::Search(int a)
{
	if (AcctNo==a)
	{
	    ShowAcct();
		return(1);
	}
	return 0;
}
int Account::Verify(int b)
{
	if(PinNo==b)
	{
		return(1);
	}
	return 0;
}
int main()
{
	Account K;
	int ch,a,p,found,match;
	
	do
	{
	     system("cls");
		 cout<<"\n\n\n\n\n\n\t\t\t\t\t"<<" ~~ "<<"  BANK MANAGEMENT SYSTEM  "<<" ~~ "<<"\n";
	     cout<<"\n\t\t\t\t\t\t"<<" :: MAIN MENU :: "<<"\n";
	     cout<<"\n\n\t\t\t\t\t"<<"1. NEW ACCOUNT. "<<"\n";
	     cout<<"\t\t\t\t\t"<<"2. ACCOUNT INFO. "<<"\n";
	     cout<<"\t\t\t\t\t"<<"3. DEPOSIT AMOUNT. "<<"\n";
	     cout<<"\t\t\t\t\t"<<"4. WITHDRAW AMOUNT. "<<"\n";
	     cout<<"\t\t\t\t\t"<<"5. BALANCE ENQUIRY.  "<<"\n";
	     cout<<"\t\t\t\t\t"<<"6. ABOUT THIS PROJECT. "<<"\n";
	     cout<<"\t\t\t\t\t"<<"7. EXIT. "<<"\n";
         cout<<"\n\n\t\t\t\t\t"<<"Select your option (1-6): ";	
	     cin>>ch;
	   
	     switch(ch)
	     {
	   	    case 1://creating an user account
	   	        system("cls");
	   	        K.CreateAcct();
	   	        cout<<"\n\n\n\t\t\t\t\t"<<"Account info saved successfully!"<<"\n";
	   	        cout<<"\t\t\t\t\t"<<"THANK YOU for choosing us :)"<<"\n\n";
	   	        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        break;
	   	    
	   	    case 2://displaying an user account
	   	    	system("cls");
	   	    	cout<<"\n\n\n\n\n\t\t\t\t"<<"Enter the account no. whose details is reqd. : ";
	   	    	cin>>a;
	   	    	cout<<"\n\n\t\t\t\t"<<"Please verify your password : ";
	   	    	cin>>p;
	   	    	match=K.Verify(p);
	   	    	if(match==1)
	   	    	{
	   	    	    system("cls");
	   	    	    found=K.Search(a);
				   	    if(found==0)
	   	    		        cout<<"\n\n\n\t\t\t\t\t\t"<<"RECORD  NOT  FOUND!"<<"\n\n";
	   	    		        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        }
	   	        else
	   	        {
	   	            cout<<"\n\n\n\n\t\t\t\t\t\t"<<"Wrong pin no. entered!"<<"\n\n";
	   	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to retry...";
	   	        }
	   	        break;
	   	    	
	   	    case 3://deposition of money
	   	    	system("cls");
	   	    	cout<<"\n\n\n\n\n\t\t\t\t"<<"Enter the account no. to deposit money : ";
	   	    	cin>>a;
	   	    	cout<<""<<"Please verify your password : ";
	   	    	cin>>p;
	   	    	match=K.Verify(p);
	   	    	if(match==1)
	   	    	{
	   	    	    system("cls");
	   	    	    found=K.Search(a);
	   	    	        if (found==1)
	   	    		    {
	   	    		    	K.DepositAmt();
	   	    		    	break;
	   	    		    }
	   	    	    	if (found==0)
	   	    		        cout<<"\n\n\n\t\t\t\t\t\t"<<"RECORD  NOT  FOUND!"<<"\n\n";
	   	    		        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        }
	   	        else
	   	        {
	   	            cout<<"\n\n\n\n\t\t\t\t\t\t"<<"Wrong pin no. entered!"<<"\n\n";
	   	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to retry...";
	   	        }
	   	    	break;
	   	    	
	   	    case 4://withdrawal of money
	   	    	system("cls");
	   	    	cout<<"\n\n\n\n\n\t\t\t\t"<<"Enter the account no. to withdraw money from : ";
	   	    	cin>>a;
	   	    	cout<<""<<"Please verify your password : ";
	   	    	cin>>p;
	   	    	match=K.Verify(p);
	   	    	if(match==1)
	   	    	{
	   	            system("cls");
	   	    	    found=K.Search(a);
	   	    	        if (found==1)
	   	    	        {
	   	    	        	K.WithdrawAmt();
	   	    	        	break;
	   	    	        }
	   	    	        if (found==0)
	   	    	            cout<<"\n\n\n\t\t\t\t\t\t"<<"RECORD  NOT  FOUND!"<<"\n\n";
	   	    	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        }
	   	        else
	   	        {
	   	            cout<<"\n\n\n\n\t\t\t\t\t\t"<<"Wrong pin no. entered!"<<"\n\n";
	   	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to retry...";
	   	        }
	   	    	break;
	   	    	
	   	    case 5://enquiry of current balance
	   	    	system("cls");
	   	    	cout<<"\n\n\n\n\n\t\t\t"<<"Enter the account number whose current balance is required : ";
	   	    	cin>>a;
	   	    	cout<<""<<"Please verify your password : ";
	   	    	cin>>p;
	   	    	match=K.Verify(p);
	   	    	if(match==1)
	   	    	{
	   	            system("cls");
	   	    	    found=K.Search(a);
	   	    	        if (found==1)
	   	    	        {
	   	    	    	    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	    	    	    break;
	   	    	        }
	   	    	        else if (found==0)
	   	    	            cout<<"\n\n\n\t\t\t\t\t\t\t"<<"RECORD  NOT  FOUND!"<<"\n\n";
	   	    	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	    	}
	   	    	else
	   	        {
	   	            cout<<"\n\n\n\n\t\t\t\t\t\t"<<"Wrong pin no. entered!"<<"\n\n";
	   	            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to retry...";
	   	        }        
	   	    	break;
	   	    	
	   	    case 6://concept idea of the project
	   	        system("cls");
	   	        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t"<<": ABOUT THIS PROJECT :";
	   	        cout<<"\n\n\n\n\t\t\t"<<"This program has been coded on the ideology of the Banking Management System.";
	   	        cout<<"\n\n\t\t\t"<<"It basically highlights the computing methods used by the Managing Director.";
	   	        break;
	   	    	
	   	    case 7://exiting the program
	   	        system("cls");
	   	        cout<<"\n\n\n\n\n\t\t\t\t\t\t"<<"HAVE  A  NICE  DAY  :)"<<"\n\n";
	   	        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        break;
			
	   	    default://wrong choice
	   	        system("cls");
	   	        cout<<"\n\n\n\t\t\t\t\t\t"<<" WRONG  INPUT! "<<"\n\n";
	   	        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"<<"Press enter to continue...";
	   	        break;
	     }
	   cin.ignore();
	   cin.get();
    }
    while ((ch>=1 && ch<7)||(ch!=7));
return 0;	
}
