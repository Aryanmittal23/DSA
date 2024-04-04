#include<iostream>
using namespace std;

void prime(int n){
    int count =0;
    for(int i=0;i<n;i++){
    if(n%i==0){
    count++;}
    }
if(count==2)
    cout<<"prime number"<<endl;
    else
    cout<<"not a prime number"<<endl;
}
int main(){
     int n;
cout<<"enter the number"<<endl;
cin>>n;
prime(n);
return 0;
}

