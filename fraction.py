import math

class Fraction:
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

    def __str__(self):
        return str(self.numerator) + "/" + str(self.denominator)

    def __add__(self, other):
        if self.denominator == other.denominator:
            return Fraction(self.numerator + other.numerator, self.denominator)
        else:
            return Fraction(self.numerator * other.denominator + other.numerator * self.denominator, self.denominator * other.denominator)

    def __sub__(self, other):
        if self.denominator == other.denominator:
            return Fraction(self.numerator - other.numerator, self.denominator)
        else:
            return Fraction(self.numerator * other.denominator - other.numerator * self.denominator, self.denominator * other.denominator)

    def __mul__(self, other):
        return Fraction(self.numerator * other.numerator, self.denominator * other.denominator)

    def __truediv__(self, other):
        return Fraction(self.numerator * other.denominator, self.denominator * other.numerator)

    def minimize(self):
        if(self.numerator == 0):
            return Fraction(0, 1)
        if(self.denominator < 0):
            self.numerator *= -1
            self.denominator *= -1
        gcd = math.gcd(abs(self.numerator), self.denominator)
        return Fraction(self.numerator // gcd, self.denominator // gcd)

def main():
    q = int(input())
    f1 = Fraction(0, 1)
    for i in range(q):
        s = input().split(" ")
        f = s[1].split("/")
        f2 = Fraction(int(f[0]), int(f[1]))
        if(s[0] == "+"):
            f1 = f1 + f2
        elif(s[0] == "-"):
            f1 = f1 - f2
        elif(s[0] == "*"):
            f1 = f1 * f2
        elif(s[0] == "/"):
            f1 = f1 / f2
        f1 = f1.minimize()

    print(f1)


if(__name__ == "__main__"):
    main()
