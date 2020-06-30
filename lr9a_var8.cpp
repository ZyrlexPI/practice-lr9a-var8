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

void mod_m(int** m, int n)
{
    int i, j, max, min, inmax, inmin, temp, *k;
    k = new int [n];
    for (j = 0; j < n; j++) {//Search for the number of positive elements in columns
        k[j] = 0;
        for (i = 0; i < n; i++) {
            if (m[i][j] > 0) {
                k[j] = k[j] + 1;
            }
        }
    }
    max = k[0];
    inmax = 0;
    for (i = 1;i < n;i++) {//Search for the largest number of positive elements in a column
        if (k[i] > max) {
            max = k[i];
            inmax = i;
        }
    }
    min = k[0];
    inmin = 0;
    for (i = 1;i < n;i++) {//Search for the smallest number of positive elements in a column
        if (k[i] < max) {
            min = k[i];
            inmin = i;
        }
    }
    for (i = 0;i < n;i++) { //Permutation of columns
        temp = m[i][inmax];
        m[i][inmax] = m[i][inmin];
        m[i][inmin] = temp;
    }
    delete[]k;
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
    mod_m(m, n);
    cout << "The modified matrix: \n";
    out_m(m, n);
    delete[]m; //Freeing up memory used by the dynamic array
}