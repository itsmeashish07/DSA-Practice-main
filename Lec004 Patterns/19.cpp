#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int i = 1;
    
    while (i <= n)
    {
        int s=n-i;
        while(s){
           cout<< " ";
             s--;
        }
        int j = 1;
        while (j <=i)
        {
            cout << "*";
            j++;
            
        }
        i++;
        cout << endl;
    }
    
}