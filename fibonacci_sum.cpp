#include <iostream>
using namespace std;

const int Q = 1e9+7;

const long long M = 101;
long long **A;
long long **B;
long long **W;
long long **K;

void mnozenie(int d, long long ** pA, long long ** pB, long long ** pC)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                K[i][j] += (pB[i][k]*pC[k][j])%Q;
                K[i][j]%=Q;
            }
        }
    }
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            pA[i][j] =K[i][j];
            K[i][j]=0;
        }
    }
}
void pot(long long n, int d)
{

    while(n>0)
    {
        if(n%2==1) mnozenie(d, W, W, A);

        mnozenie(d, A, A, A);
        n/=2;
    }
}

int main()
{
    long long n, b;
    cin >> n>>b;
    A = new long long * [M];
    B = new long long * [M];
    W = new long long * [M];
    K = new long long * [M];
    for(int i = 0; i < 2; i++)
    {
        A[i] = new long long [2];
        B[i] = new long long [2];
        W[i] = new long long [2];
        K[i] = new long long [2];
        for(int j = 0; j < 2; j++)
        {
            K[i][j]=0;
            B[i][j] = 0;
            if(i==j)
            {
                W[i][j] = 1;
            }else{
                W[i][j] = 0;
            }
        }
    }
    A[0][0] = 1;
    A[1][0] = 1;
    A[0][1] = 1;
    A[1][1] = 0;
    int pom1, pom2;
    pot(n+2, 2);
    pom2 = W[1][0]%Q;
    int sum1 = pom2-2;
    A[0][0] = 1;
    A[1][0] = 1;
    A[0][1] = 1;
    A[1][1] = 0;
    W[0][0] = 1;
    W[1][0] = 0;
    W[0][1] = 0;
    W[1][1] = 1;
    pot(b+2+1, 2);
    pom1 = W[1][0]%Q;
    int sum2 = pom1-2;
    if(sum2-sum1<0)
    { 
        cout << sum2 - sum1 + Q;
        return 0;
    }
    cout << sum2- sum1;
    return 0;
}