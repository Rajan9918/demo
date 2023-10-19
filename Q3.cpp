/*3:Create a abstract class Shape with pure virtual method area;
Create Rectangle,Circle,Square class..inherit them from Shape class..Override area method.
Test these all classes by creating object of respective class.*/
#include<iostream>
using namespace std;
class Shape{
	public:
		virtual void area()=0;
};
class Rectangle:public Shape{
	public:
	void area(){
		cout<<"Area Of Rectangle"<<endl;
	}
};
class Circle:public Shape{
	public:
	void area(){
		cout<<"Area Of Circle"<<endl;
}
};
class Square:public Shape{
public:
void area(){
		cout<<"Area Of Square"<<endl;
}
};
int main()
{
	Shape*s1;
	Rectangle obj;
	s1=&obj;
	s1->area();
	// obj.area();
	// Square sq;
	// sq.area();
	return 0;
}
