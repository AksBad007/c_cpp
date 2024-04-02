#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapSack(int weight[], int profit[], float cap, int n)
{
    int i, j, w;
    int x[20];
    int k[20][20];
    float u;

    weight[0] = 0;
    profit[0] = 0;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= cap; w++)
        {
            if ((i == 0) || (w == 0))
            {
                k[i][w] = 0;
            }
            else if (weight[i] <= w)
            {
                k[i][w] = max(profit[i] + k[i - 1][w - weight[i]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    i = cap;
    j = cap;

    while ((i >= 0) && (j >= 0))
    {
        if (k[i][j] == k[i - 1][j])
        {
            x[i] = 0;
            i = i - 1;
        }
        else
        {
            x[i] = 1;
            j - j - weight[i];
            i = i - 1;
        }
    }

    cout << "Matrix:" << endl;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Resultant Vector is ";
    for (i = 0; i <= n; i++)
    {
        cout << x[i] << "--x[" << i << "]";
        cout << endl;
    }
}

int main()
{
    int weight[20], profit[20];
    int cap;
    int n, i, j;

    cout << "Enter capacity of knapSack: ";
    cin >> cap;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items: ";
    for (i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter profit of items: ";
    for (i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }

    knapSack(weight, profit, cap, n);
    return 0;
}