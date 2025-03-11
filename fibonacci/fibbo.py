def fibbo(n):
    if (n==1):
        return 0
    elif (n==2):
        return 1
    else:
        return fibbo(n-1) + fibbo(n-2)
number=int(input("Enter the position of the fibbonaci number:"))

if (number<=0):
     print("Invalid number")
else:
     print(f"The fiboonaci  of {number}th  is: {fibbo(number)}\n")




        
