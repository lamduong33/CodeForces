#include <bits/stdc++.h>
using namespace std;
static double const& sqrt5 = sqrt(5); // for binets method

int recursiveFibonacci(int n)
{
    int result;
    if (n == 0 || n == 1)
        result = n;
    else
        result = recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    return result;
}

int iterativeFibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    auto first = 0, second = 1, result = 0;
    for (int i = 2; i <= n; i++)
    {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int binetsFormula(int n)
{
    return (1/sqrt5) * (pow((1+sqrt5)/2, n) - pow((1-sqrt5)/2, n));
}

int main()
{
    int n;
    cin >> n;
    auto startTimer = std::chrono::high_resolution_clock::now();

    recursiveFibonacci(n);

    auto stopTimer = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<chrono::microseconds>(stopTimer - startTimer);

    // cout << "Recursive Fibonacci execution time: " << duration.count() << "ms"
    //      << endl;

    startTimer = std::chrono::high_resolution_clock::now();

    binetsFormula(n);

    stopTimer = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<chrono::microseconds>(stopTimer - startTimer);

    cout << "Binets Formula execution time: " << duration.count() << "ms"
         << endl;

    startTimer = std::chrono::high_resolution_clock::now();

    iterativeFibonacci(n);

    stopTimer = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<chrono::microseconds>(stopTimer - startTimer);

    cout << "Iterative Fibonacci execution time: " << duration.count() << "ms"
         << endl;

    return 0;
}
