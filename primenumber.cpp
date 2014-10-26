/*
 * get the number of prime number <= input 
*/

#include <iostream>
using namespace std;

int main(){
    int primenumber(int n);
    int n;
    int numberofprime;
    cout<<"input"<<endl;
    cin>>n;
    numberofprime =  primenumber(n);
    cout<<"number of prime number is:"<<numberofprime<<endl;
    return 0;
}

int primenumber(int n){
    int number = 0;
    for(int i=2; i<=n; i++){
        bool prime = true;
        for (int j=2; j*j<=i; j++){
            if(i%j==0){
                prime = false;
                break;
            }
        }        
        if(prime)
        {
            cout<<i<<endl;
            number++;
        }
    }
    return number;
}
