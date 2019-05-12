#include<iostream>
using namespace std;

class B{
public:
    void display(){
    cout<<"Base class\n";}

    void d(){
    }
};
class S:public B{
public :
    void display(){
        cout<<"Sub class\n";}

};
int main(){
    S ob;
    ob.display();
    ob.B::display();
    ob.d();
}
