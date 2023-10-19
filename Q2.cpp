/*2:Create cpp application for bank account handling.
2.1. Create a class BankAccount -- acct no(int),customer name(string),balance(double)
Add  constr. (2 constrs : first to accept all details )

2.2 Add Business logic methods
Methods
public void withdraw(double amt) 
public void deposit(double amt)

2.3: Create object of account class and test withdraw and deposit methods.
---------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;
class BankAccount{
	private:
		int acctno;
		string name;
		double balance;
	public:
		BankAccount(){
			acctno=1000;
			name="Yamraj";
			balance=200000;
		}
		BankAccount(int acctno,string name,double balance)
		{
			this->acctno=acctno;
			this->name=name;
			this->balance=balance;
		}
		void withdraw(double amt)
		{
			balance=balance-amt;
			cout<<"Withdraw : "<<balance<<endl;
		}
		void deposit(double amt)
		{
			balance=balance+amt;
			cout<<"Deposite : "<<balance<<endl;
		}
		void display()
		{
			cout<<"Account No. : "<<acctno<<endl<<"Name : "<<name<<endl<<"Balance : "<<balance<<endl;
		}
};
int main(){
	BankAccount obj;
	obj.display();
	obj.deposit(2000);
	obj.withdraw(10055);
}
