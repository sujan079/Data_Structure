n=int(input("Enter the postion for factorial\n"))
# a is the accumulator 
def fact(n,a):
    if (n==0 or  n==1):
        return a;

    else: 
        return fact(n-1,n*a)

print(f"The factorial of {n} is: {fact(n,1)}")


