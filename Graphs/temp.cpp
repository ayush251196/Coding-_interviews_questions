#include <iostream>
using namespace std;
void funct(){
    //cout<<a;//
}
class A{
 private: int a,b;
 public:
     int funcA(){cout<<"Value of a="<<this->a<<endl;}
     void setv(){this->a=11;}
    A(){cout<<"Constructor from A\n";}
};
class B: private A{
    int b;
public:
    B(){cout<<"I am from B";}
    void access(){this->setv();}
    void print(){this->funcA();}
   // int funct(){return this->a;}
}st2;
 int main()
{   //St ob;
    st2.access();
    st2.print();
}
