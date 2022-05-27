#include <bits/stdc++.h>

using namespace std;

struct Bigint
{
    vector<int> a;
    bool isNegative;
    int size;
    int sign()
    {
        if (isNegative)
            return -1;
        else
            return 1;
    }

    Bigint()
    {
        isNegative = false;
        size = 0;
    }

    Bigint(string s)
    {
        isNegative = false;
        size = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            a.push_back(s[i] - '0');
            size++;
        }
    }
    Bigint(int n)
    {
        isNegative = false;
        size = 0;
        if (n == 0)
        {
            a.push_back(0);
            size++;
        }
        else
        {
            while (n > 0)
            {
                a.push_back(n % 10);
                size++;
                n /= 10;
            }
        }
    }
    Bigint operator+(Bigint b)
    {
        Bigint c;
        int carry = 0;
        int i = 0;
        while (i < max(size, b.size))
        {
            int sum = a[i] + b.a[i] + carry;
            c.a.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }
        if (carry > 0)
            c.a.push_back(carry);
        c.size = max(size, b.size);
        return c;
    }

    Bigint operator-(Bigint b)
    {
        Bigint c;
        int carry = 0;
        int i = 0;
        while (i < max(size, b.size))
        {
            int sum = a[i] - b.a[i] + carry;
            if (sum < 0)
            {
                sum += 10;
                carry = -1;
            }
            else
                carry = 0;
            c.a.push_back(sum);
            i++;
        }
        c.size = max(size, b.size);
        return c;
    }

    Bigint operator*(Bigint b)
    {
        Bigint c;
        int carry = 0;
        int i = 0;
        while (i < size)
        {
            int j = 0;
            Bigint d;
            while (j < b.size)
            {
                int prod = a[i] * b.a[j] + carry;
                d.a.push_back(prod % 10);
                carry = prod / 10;
                j++;
            }
            if (carry > 0)
                d.a.push_back(carry);
            c = c + d;
            carry = 0;
            i++;
        }
        c.size = size + b.size;
        return c;
    }

    Bigint operator/(Bigint b)
    {
        Bigint c;
        Bigint d;
        int i = 0;
        while (i < size)
        {
            d.a.push_back(a[i]);
            i++;
        }
        d.size = size;
        while (d >= b)
        {
            c.a.push_back(0);
            d = d - b;
        }
        i = 0;
        while (d < b)
        {
            d = d + b;
            c.a[i]++;
            i++;
        }
        c.size = size;
        return c;
    }

    Bigint operator%(Bigint b)
    {
        Bigint c;
        Bigint d;
        int i = 0;
        while (i < size)
        {
            d.a.push_back(a[i]);
            i++;
        }
        d.size = size;
        while (d >= b)
        {
            d = d - b;
        }
        i = 0;
        while (d < b)
        {
            d = d + b;
            i++;
        }
        i = 0;
        while (i < size)
        {
            c.a.push_back(d.a[i]);
            i++;
        }
        c.size = size;
        return c;
    }

    Bigint operator^(Bigint b)
    {
        Bigint c;
        Bigint d;
        int i = 0;
        while (i < size)
        {
            d.a.push_back(a[i]);
            i++;
        }
        d.size = size;
        while (d >= b)
        {
            d = d - b;
        }
        i = 0;
        while (d < b)
        {
            d = d + b;
            i++;
        }
        i = 0;
        while (i < size)
        {
            c.a.push_back(d.a[i]);
            i++;
        }
        c.size = size;
        return c;
    }

    bool operator<(Bigint b)
    {
        if (size < b.size)
            return true;
        else if (size > b.size)
            return false;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] < b.a[i])
                    return true;
                else if (a[i] > b.a[i])
                    return false;
                i--;
            }
        }
        return false;
    }

    bool operator>(Bigint b)
    {
        if (size > b.size)
            return true;
        else if (size < b.size)
            return false;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] > b.a[i])
                    return true;
                else if (a[i] < b.a[i])
                    return false;
                i--;
            }
        }
        return false;
    }

    bool operator==(Bigint b)
    {
        if (size != b.size)
            return false;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] != b.a[i])
                    return false;
                i--;
            }
        }
        return true;
    }

    bool operator!=(Bigint b)
    {
        if (size != b.size)
            return true;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] != b.a[i])
                    return true;
                i--;
            }
        }
        return false;
    }

    bool operator<=(Bigint b)
    {
        if (size < b.size)
            return true;
        else if (size > b.size)
            return false;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] < b.a[i])
                    return true;
                else if (a[i] > b.a[i])
                    return false;
                i--;
            }
        }
        return true;
    }

    bool operator>=(Bigint b)
    {
        if (size > b.size)
            return true;
        else if (size < b.size)
            return false;
        else
        {
            int i = size - 1;
            while (i >= 0)
            {
                if (a[i] > b.a[i])
                    return true;
                else if (a[i] < b.a[i])
                    return false;
                i--;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &out, Bigint b)
    {
        int i = b.size - 1;
        while (i >= 0)
        {
            out << b.a[i];
            i--;
        }
        return out;
    }
};
