/*
1 Solve this.
Fresh business scenario to apply inheritance , polymorphism   to emp based organization scenario.

Create Emp based organization structure --- Emp , Mgr , Worker


1.1 Emp state--- id(int), name, deptId , basicSalary(double)
Accept all of above in constructor arguments.

Methods ---
1.2. compute net salary ---ret 0
(eg : public double computeNetSalary(){return 0;})

1.2 Mgr state  ---id,name,basic,deptId , perfBonus
Add suitable constructor
Methods ----
1. compute net salary (formula: basic+perfBonus) -- override computeNetSalary


1.3 Worker state  --id,name,basic,deptId,hoursWorked,hourlyRate
Methods : 
1.  compute net salary (formula:  = basic+(hoursWorked*hourlyRate) --override computeNetSalary
2. get hrlyRate of the worker  -- add a new method to return hourly rate of a worker.(getter)

Create suitable array to store organization details.
Provide following options
1. Hire Manager
I/P : all manager details

2. Hire Worker  
I/P : all worker details

3. Display information of all employees net salary (by invoking computeNetSal), 

4. Exit

*/

#include<iostream>
using namespace std;

class emp{
	protected:
	int id, deptId;
	string name;
	double basicSalary;
	public:
	emp(int id,int deptId,string name,double basicSalary){
		this->basicSalary=basicSalary;
		this->deptId=deptId;
		this->id=id;
		this->name=name;
	}
	emp(){
	}
	
	 double netSalary(){
		return 0;
	}
	
	void display(){
	cout<<"Basic Salary of Employee :"<<basicSalary<<endl;
	cout<<"id : "<<id<<endl;
	cout<<"deptId : "<<deptId<<endl;
	cout<<"Name : "<<name<<endl;
	}
	
};

class mrg : public  emp{
	protected:
	double perfBonus;
	
	public:
		mrg(int id,int deptId,string name,double basicSalary,double perfBonus):emp(id,deptId,name,basicSalary){
			this->perfBonus=perfBonus;
		}
		
	double netSalary(){
		return (basicSalary+this->perfBonus);
	}
	
		void display(){
	cout<<"Basic Salary of Manager :"<<basicSalary<<endl;
	cout<<"id : "<<id<<endl;
	cout<<"deptId : "<<deptId<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"PerfBounce : "<<perfBonus<<endl;
	}
	
};

class worker: public  emp{
	protected:
	double hoursWorked,hourlyRate;
	public:
	worker(int id, int deptId,string name,double basicSalary, double hoursWorked,double hourlyRate):emp(id,deptId,name,basicSalary){
		this->hourlyRate=hourlyRate;
		this->hoursWorked=hoursWorked;
	}
	
	double netSalary(){
		return basicSalary+(hoursWorked*hourlyRate);
	}
	
	double gethrlyRate(){		
		return hourlyRate;
	}
	
			void display(){
	cout<<"Basic Salary of Worker :"<<basicSalary<<endl;
	cout<<"id : "<<id<<endl;
	cout<<"deptId : "<<deptId<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"hoursWorked : "<<hoursWorked<<endl;
	cout<<"hourlyRate : "<<hourlyRate<<endl;
	}
	
};

int main(){
	
	cout<<"1. Hire Manager"<<endl;
	cout<<"2. Hire Worker "<<endl;
	cout<<"3. Display information of all employees net salary (by invoking computeNetSal)"<<endl;
	cout<<"4. Exit"<<endl<<endl;
	
	static int count=0;
	int num;

	emp *emp_detail[100];
	
	do{
	cout<<"Enter Choice :"<<endl;
	cin>>num;
	switch(num){
	
		case 1:
			int n;
			cout<<"Enter Total Number of Hire Manager :"<<endl;
			cin>>n;
			 
			 
//			mrg *mrg_detail[n];
			
			for(int i=0;i<n;i++){
				int id, deptId;
				string name;
				double basicSalary,perfBonus;
				cout<<"Hire Manager : "<<i+1<<endl;
				cout<<"Enter  id,deptId, name, basicSalary, perfBonus :"<<endl;
				cin>>id>>deptId>>name>>basicSalary>>perfBonus;
				emp_detail[count++]=new mrg(id,deptId,name,basicSalary,perfBonus);
				
			}
		  break;
	
		  case 2:
		  		int m;
			cout<<"Enter Total Number of Hire Worker :"<<endl;
			cin>>m;
			 
//			worker *worker_detail[m];
			
			for(int i=0;i<m;i++){
				int id, deptId;
				string name;
				double basicSalary,hoursWorked, hourlyRate;
				cout<<"Hire Worker : "<<i+1<<endl;
				cout<<"Enter  id ,deptId, name, basicSalary, hoursWorked, hourlyRate :"<<endl;
				cin>>id>>deptId>>name>>basicSalary>>hoursWorked>>hourlyRate;
				emp_detail[count++]=new worker(id,deptId,name,basicSalary,hoursWorked, hourlyRate);
				
			}
		  break;
		  
		  case 3:
		  	for(int j=0;j<count;j++){
		  		cout<<endl<<endl;
		  		emp_detail[j]->display();
			  }
			   count=0;
		  	break;
		  	
		 case 4:
		  cout<<"Thank You......"<<endl;
		  break;
		  
		  default:
		  	cout<<"Invalid Choise...... "<<endl;
		  	break;
					 	
	}
}while(num !=4);
	
	return 0;
}
