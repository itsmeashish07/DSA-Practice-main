#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <=n)
        {
            char ch='A'+j-1;
            cout << ch<< " " ;
            j++;
            
        }
        i++;
        cout << endl;
    }
}