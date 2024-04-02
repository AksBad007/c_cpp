#include <iostream>
using namespace std;

void printArray(float q[],int size )
{
    for(int i = 0; i < size; i++)
    {
        cout << q[i] << endl;
    }
}

void knapSack( float p[],float w[],float x[], int m ,int n)
{
    int l;
    for(l = 0; l < n; l++)
    {
        x[l] = 0;
    }

    int u = m;
    for(l = 0; l < n; l++)
    {
        if(w[l] > u) {
            break;
        }
        else {
            x[l] = 1;
            u = u - w[l];
        }
    }

    if(l<=n)
    {
        x[l]=u/w[l];
    }
}

int main()
{

    int n;
    cout << "Enter number of objects: ";
    cin >> n;

    float p[n];
    float w[n];
    float x[n];
    float profit = 0;

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = p[i] / w[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] < x[j])
            {
                float temp = x[j];
                x[j] = x[i];
                x[i] = temp;

                int temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
            }
        }
    }
    knapSack(p, w, x, 15, n);
    cout << endl;
    printArray(x, n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        profit = profit + x[i] * p[i];
    }
    cout << "Profit is " << profit << endl;
}