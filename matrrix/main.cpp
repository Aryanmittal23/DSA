
#include<iostream>
using namespace std;

class lowertri
{
private:
    int *A;
    int n;
public:
 lowertri( int n)
    {
        this->n=n;
        A=new int[2];
        
    }
    lowertri()
    {
        delete[]A;
    }
    void set( int i,int j,int x);
    int get(int i,int j);
    void display();
    int getdimennsion()
    {return n;}
   
    
};
void lowertri::set(int i,int j,int x)
{
    if(i>=j)
       A[i*(i-1)/2+j-1]=x;
}
int lowertri::get(int i,int j)
{
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    return 0;
}
void lowertri::display()
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i>=j)
            cout<<A[i*(i-1)/2+j-1]<<" ";
            else
            cout<<"0";
        }
        cout<<endl;
    } 
}
int main()
{
 int d;
 cout<<"dimension";
 cin>>d;

 lowertri lm(d);

 int x;
 cout<<"enter all elements";
 for(int i=1;i<=d;i++)
{
    for(int j=1;j<=d;j++)
    {
        cin>>x;
        lm.set(i,j,x);
    }
}

 lm.display();
    return 0;
}
