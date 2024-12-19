def memofibo(n,memo={}):
    if (n==1):
        return 0;
    elif (n==2):
        return 1;
    elif (n not in memo):
        memo[n]=memofibo(n-1,memo) + memofibo(n-2,memo)
    return memo[n]

n=int(input("Enter the number to calculate the fibbonacci:"))
if (n<=0):
    print("Invalid number")
else:
    print(f"number is  {memofibo(n)}\n")



