#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        char ch = 'A' + n - i;
        while (j <= i)
        {
            cout << ch << " ";
            j++;
            ch++;
        }
        i++;
        cout << endl;
    }
}