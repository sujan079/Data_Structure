def gcd(a,b):
    if a==0:
        return b
    else :
        while (b!=0):
            r=a%b
            a=b
            b=r
        return a
print("Enter  greatest common divisor\n")
a=int(input('First Number'))
b=int(input("Second Number"))
ans = gcd(a,b)
print(f"The required answer is {ans} ")

