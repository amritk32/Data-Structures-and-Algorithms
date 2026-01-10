// Recursion 1
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Factorial
{
private:
    int n;

public:
    int factorial(int x)
    {
        n = x;

        if (x == 0)
        {
            return 1;
        }

        else
        {
            return x * factorial(x - 1);
        }
    }
};

class PowerOfTwo
{
public:
    int power(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 2 * power(n - 1);
        }
    }
};

class Counting
{
public:
    void printCount(int n)
    {
        if (n == 0)
        {
            return;
        }
        else
        {
            printCount(n - 1);
            cout << n << " ";
        }
    }
};

class ReachHome
{
public:
    void reachHome(int src, int dest)
    {
        cout << "Source " << src << "Destination " << dest << endl;

        if (src == dest)
        {
            cout << "Reached the destination " << endl;
            return;
        }
        src++;
        reachHome(src, dest);
    }
};

class Fibonaci
{
public:
    int fibonaci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }

       cout << n<<endl;

        return fibonaci(n - 1) + fibonaci(n - 2);
    }

    // Time Complexity O(2^n) Very slow
};

class fibonaci{
public:
    int validFibonaci(int n){
        int currentSum = 1;
        int preivousSum = 0;
        int nextSum;

        for(int i = 1; i < n; i++){
            nextSum = currentSum + preivousSum;
            preivousSum = currentSum;
            currentSum = nextSum;
    }
    return nextSum;
    }
    // Time Complexity O(n) Very Fast

};

class validPowerofTwo {
public:
    bool isPowerOfTwo(int n) {
        // Base Case
        if(n <= 0) return false;
        if(n == 1) return true;

        if(n%2 != 0) return false;
        // Recursive Case
        return isPowerOfTwo(n/2);
    }
};


int main()
{
    fibonaci f1;
    cout<<f1.validFibonaci(2);

    return 0;
}