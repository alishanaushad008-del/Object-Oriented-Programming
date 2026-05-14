//Question no#5
#include<iostream>
using namespace std;
float area_of_sphere(float radius);
float volume_of_sphere(float radius);
int main(){
    float radius;
    cout<<"Enter the radius of sphere:";
    cin>>radius;
cout<<"The area of sphere is:"<<area_of_sphere(radius)<<endl;
cout<<"The volume of sphere is:"<<volume_of_sphere(radius)<<endl;
}
float area_of_sphere(float radius){
    float area;
    area=4*3.142*radius*radius;
    return area;
}
float volume_of_sphere(float radius){
    float volume;
    volume=(4.0/3.0)*3.142*radius*radius*radius;
    return volume;
}