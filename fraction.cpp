#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

struct fraction
{
    ll num, den;
    fraction() {}
    fraction(ll n, ll d) : num(n), den(d) {}

    fraction operator+(const fraction &f) const
    {
        ll lcm_den = lcm(den, f.den);
        ll lcm_num = lcm_den / den * num + lcm_den / f.den * f.num;
        return fraction(lcm_num, lcm_den);
    }

    fraction operator-(const fraction &f) const
    {
        return *this + fraction(-f.num, f.den);
    }

    fraction operator*(const fraction &f) const
    {
        return fraction(num * f.num, den * f.den);
    }

    fraction operator/(const fraction &f) const
    {
        return fraction(num * f.den, den * f.num);
    }

    void minimize()
    {
        if(num == 0){
            den = 1;
            return;
        }
        if(den < 0){
            num = -num;
            den = -den;
        }
        ll g = gcd(abs(num), den);
        num /= g;
        den /= g;
    }

    friend ostream &operator<<(ostream &os, const fraction &f)
    {
        os << f.num << "/" << f.den;
        return os;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> q;
    fraction f(0,1);
    // next q lines are queries, first is the operation, second is the fraction
    while (q--)
    {
        string op;
        cin >> op;
        fraction f2;
        string fr;
        cin >> fr;
        // fr is in the form "n/d"
        int i = fr.find('/');
        f2.num = stoi(fr.substr(0, i));
        f2.den = stoi(fr.substr(i + 1));
        if (op == "+")
            f = f + f2;
        else if (op == "-")
            f = f - f2;
        else if (op == "*")
            f = f * f2;
        else if (op == "/")
            f = f / f2;
        f.minimize();
    }
    cout << f << endl;
    return 0;
}
