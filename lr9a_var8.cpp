#include <iostream>
using namespace std;

int** init_m(int** m, int n) //Initialization of the matrix
{
    int i, j;
    m = new int* [n];
    for (i = 0; i < n; i++) m[i] = new int[n]; //Allocating memory for a dynamic array
    cout << "Enter the matrix elements: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "m[" << i+1 << "][" << j+1 << "] = ";
            cin >> m[i][j];
        }
    }
    return m;
}

void out_m(int** m, int n) //Displaying the matrix on the screen
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_CTYPE, "");
    int n, ** m;
    m = NULL;
    do {
        cout << "Enter the dimension of the matrix : ";
        cin >> n;
    } while (n <= 0);
    m = init_m(m, n);
    cout << "Initialized matrix: \n";
    out_m(m, n);
    delete[]m; //Freeing up memory used by the dynamic array
}