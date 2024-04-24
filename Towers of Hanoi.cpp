#include<iostream>
#include"Stackt.h"

using namespace std;

// A function to display the stack content

void display(Stackt<int> V)
    {
    Stackt<int>temp= V;  // making a temp stack to store the value of the stack then stacktop()and pop it
     while (!temp.stackIsEmpty())
     {
        int x;   //in this example I do not need to store the value I pop;hence, I made any variable to only put the value in it
        int y;
        temp.stackTop(y);
        cout<<y;
        temp.pop(x);   // in this example I do not need to store the value I pop 
     }
     }

     int TowersOfHanoi(int N, Stackt<int>& pegA, Stackt<int>& pegB, Stackt<int>& pegC, int & count) {
        int x;   // in this example I do not need to store the value I pop hence I made any variable to only put the value in it
    if (N == 1) 
    {
        int disk;
        pegA.stackTop( disk);
         cout << "-----------------" <<endl;
         cout << "The result" << endl;
        pegA.pop(x);

        cout<< "the peg A is" <<endl; 
        display(pegA); 
        cout<<endl;

        pegC.push(disk);

        cout<< "the peg B is" <<endl;
        display(pegB);
        cout<<endl;

        cout<< "the peg C is" <<endl;
        display(pegC);
        cout<<endl;

         count++;
    } 
    else 
    {    
        TowersOfHanoi(N - 1 ,pegA, pegC, pegB, count);
        
        int disk;
         pegA.stackTop( disk);
         pegA.pop(x);
         pegC.push(disk);

        TowersOfHanoi(N - 1, pegB, pegA, pegC, count);
        count++;
    }
    return count;
}
int main()
{
    int N=3;
    int count=0;
    Stackt<int> pegA, pegB ,pegC;
    
    for (int i = 1; i <= N; i++) 
    {
        pegA.push(i);
    }

    cout << " The start of the game" << std::endl;
    cout << "The pegA is (source): "<<endl;
    display(pegA);
    cout<<endl;

    cout << "The pegB is (Aux): "<<endl;
    display(pegB); 
    cout<<endl;

    cout << " the pegC is (Target): "<<endl;
    display(pegC); 
    cout<<endl;

    TowersOfHanoi(N,pegA, pegB, pegC, count);

    cout << "-----------------" <<endl;
    cout<<"the count is: "<<endl;
    cout<<count;

 
    return 0;
}