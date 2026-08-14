#include <bits/stdc++.h>
using namespace std;

double B_S(int n, int p)
{
    int s = 0, e = n, mid;
    double ans = 0;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    double inc = 0.1;

    for (int i = 0; i < p; i++)
    {
        while ((ans + inc) * (ans + inc) <= n)
        {
            ans += inc;
        }

        inc /= 10;
    }

    return ans;
}

int main()
{
    double p = B_S(50, 3);

    cout << p;

    return 0;
}