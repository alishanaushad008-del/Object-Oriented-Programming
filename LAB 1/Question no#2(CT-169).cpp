//Question no#2
#include<iostream>
using namespace std;
void swapnumbers(int* a,int* b,int* c);
int main(){
int a,b,c;
cout<<"Enter first no:";
cin>>a;
cout<<"Enter second no:";
cin>>b;
cout<<"Enter third no:";
cin>>c;
cout<<"The numbers you entered are:"<<endl;
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
cout<<"c="<<c<<endl;
swapnumbers(&a,&b,&c);
cout<<"The swapped numbers are:"<<endl;
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
cout<<"c="<<c<<endl;
}
void swapnumbers(int* a,int* b,int* c){
int temp;
temp=*a;
*a=*b;
*b=*c;
*c=temp;
}