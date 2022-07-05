#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
class X_constructor;
int x=10;
class x_object
{
int o;
static int s;
void x_private(void)
{
cout<<"It is a output from private member function";
}
public:
void x_callprivate(void)
{
x_private();
}
void x_overloading(int a)
{
cout<<"a="<<a<<" is a value taken from argument using function overloading";
}
void x_overloading(int a,float b)
{
cout<<"a="<<a<<endl<<"b="<<b<<" are also the value from argument using function overloading";
}
void x_scope();
void x_manipulators()
{
cout<<"By using manipulators"<<endl<<"setw()->"<<endl<<"set eg"<<setw(10)<<11111<<endl<<"setfill(type1)->"<<endl<<"set eg"<<setfill('0')<<11111<<endl<<"setfill(type2)->"<<endl<<"set eg"<<setfill('@')<<11111;
}
void x_inline();
void x_reference()
{
int p=15;
int &q=p;
cout<<"value of p="<<p<<" and q="<<q<<endl<<"address of &p="<<&p<<" and &q="<<&q<<endl<<"This are the value and address output using refrance variable";
}
void xobject(int o0)
{
o=o0;
}
void objectx(x_object o1,x_object o2)
{
cout<<"o1.o="<<o1.o<<" and o2.o="<<o2.o<<endl<<"This are the output using object as function argument";
}
static void x_static()
{
s++;
cout<<"static s="<<s<<" is output using static data member and member function";
}
friend void x_friend(x_object,X_constructor);
};

void x_object::x_scope()
{
int x=1;
cout<<"By using scope resolution operator"<<endl<<"x="<<x<<" is the value declared inside the function"<<endl<<"::x="<<::x<<" is the value declared outside outside the function";
}
inline void x_object::x_inline()
{
cout<<"It is a output from inline function";
}
void x_call(int &x)
{
cout<<"x="<<x;
x++;
cout<<"now x="<<x<<" is by using call by reference";
}

class X_constructor
{
int A,B;
int*g;
char X_string[20];
char*x_string[20];
public:
X_constructor()
{
cout<<"A=";
cin>>A;
cout<<endl<<"A is a value taken on run time using default constructor";
}
X_constructor(int x,int y)
{
A=x;B=y;
cout<<"Now A="<<A<<" is value taken from main function before run time using parameterised constructor";
}
X_constructor(const X_constructor&con)
{
A=con.A;
B=con.B;
cout<<"A="<<A<<" and B="<<B<<" are the output using copy constructor";
}
X_constructor(char*S)
{
strcpy(X_string,S);
cout<<"'"<<X_string<<"' is the output using string constructor";
}
X_constructor(int y,char*S)
{
g=new int;
*g=y;
x_string=new char[20];
x_string=S;
cout<<"B="<<B<<" and string '"<<X_string<<"' are the output allocate the memory of object at run time using new operator in dynamic constructor";
}
~X_constructor()
{
cout<<"destroy the object allocated using destructor";
}
friend void x_friend(x_object,X_constructor);
};
void x_friend(x_object O,x_constructor C)
{
cout<<"o="<<O.o<<" is value from class x_object and B="<<C.B<<" is value from class X_constructor";
}

class inharitance1
{
int N;
public:
inharitance1()
{
cout<<"inharitance1 constructor";
}
inharitance1(int n)
{
N=n;
}
void operator^()
{
N=N*N;
}
void put()
{
cout<<"N="<<N<<" is output using unary operator";
}
};
class inharitance2:public inharitance1
{
int r,i;
public:
inharitance2()
{
cout<<"inharitance2 constructor with public inharitance1";
}
inharitance2(int R,int I)
{
r=R;
i=I;
}
inharitance2 operator+(inharitance2 const&in1)
{
inharitance2 in;
in.r=r+in1.r;
in.i=i+in1.i;
cout<<in.r<<"+i"<<in.i<<" is output using binary operator overloading";
}
};
class inharitance3:public virtual inharitance2
{
int X_pointer;
public:
inharitance3()
{
cout<<"inharitance3 constructor with public virtual inharitance2"<<endl;
}
inharitance3(int p)
{
X_pointer=p;
cout<<"z="<<X_pointer<<" is output using pointer";
}
};
class inharitance4:public virtual inharitance2
{
int X_this;
public:
inharitance4()
{
cout<<"inharitance4 constructor with public virtual inharitance2";
}
inharitance4(int x_this)
{
this->X_this=x_this;
cout<<X_this<<" is the output using this pointer";
}
};
class inharitance5:public inharitance3,public inharitance4,public virtual inharitance2
{
public:
inharitance5()
{
cout<<"inharitance5 constructor with public inharitance3,public inharitance4 and public virtual inharitance2";
}
virtual void X_virtual()=0;
};
class inharitance6:public inharitance5
{
public:
inharitance6()
{
cout<<"inharitance6 constructor with public inharitance5";
}
void X_virtual()
{
cout<<"the virtual function is called using polymorphism";
}
};

int x_object::s;
void main()
{
int xcase,dummy;
char yes;
do
{
cout<<"scope resolution operator 1";
cout<<"manuplators 2";
cout<<"inline function 3";
cout<<"private member function 4";
cout<<"function overloading 5";
cout<<"reference variable 6";
cout<<"object as function argument 7";
cout<<"friend function 8";
cout<<"call by reference 9";
cout<<"static data members 10";
cout<<"default constructor 11";
cout<<"parameterised and copy constructor 12";
cout<<"string constructor 13";
cout<<"dynamic constructor 14";
cout<<"inharitance and virtual base class 15";
cout<<"unary operator 16";
cout<<"binary operator 17";
cout<<"pointers 18";
cout<<"this pointers 19";
cout<<"polymorphism 20";
cin>>xcase;
switch(xcase)
{
case 1:
x_object obj;
obj.x_scope();
break;
case 2:
x_object obj0;
obj0.x_manipulators();
break;
case 3:
x_object obj1;
obj1.x_inline();
break;
case 4:
x_object obj2;
obj2.x_callprivate();
break;
case 5:
x_object obj3;
obj3.x_overloading(5);
obj3.x_overloading(10,10.5);
break;
case 6:
x_object obj4;
obj4.x_reference();
break;
case 7:
x_object obj5,obj6,obj7;
obj6.xobject(15);
obj7.xobject(20);
obj5.objectx(obj6,obj7);
break;
case 8:
x_object obj8;
X_constructor con;
x_friend(obj8,con);
break;
case 9:
int v=25;
x_call(v);
break;
case 10:
x_object::x_static();
break;
case 11:
X_constructor con0;
con0();
break;
case 12:
X_constructor con1,con2;
con1(30,35);
con2=con1;
break;
case 13:
X_constructor con3("oop using c++");
break;
case 14:
X_constructor con4(40,"c++ project");
break;
case 15:
inharitance6 i6;
break;
case 16:
inharitance1 i1;
^i1;
i1.put();
break;
case 17:
inharitance2 i20(45,50),i21(55,60),i2=i20+i21;
break;
case 18:
inharitance3 i3(65);
break;
case 19:
inharitance4 i4(70);
break;
case 20:
inharitance6 i61;
i61.X_virtual();
break;
default:
cout<<"Enter number between 1 to 20";
break;
}
cout<<"do you want to learn more?, then type y";
cin>>dummy
cin>>yes;
}
while(yes=='y');
getch();
}





