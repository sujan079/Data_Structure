def isOperator(ch):
    return (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '%' or ch == '^')
    
def getPrecedence(op):
    if op == '^':
        return 3
    elif op == '*' or op == '/' or op == '%':
        return 2
    elif op == '+' or op == '-':
        return 1
    else: 
        return -1

infix = input()  # Input infix expression
postfix = ''  # Resultant postfix expression
stack = []  # Stack to hold operators and parentheses

for i in infix:
    if i.isalnum():  # If the character is alphanumeric (operand), add to postfix
        postfix += i
    elif i == '(':  # If the character is '(', push to stack
        stack.append(i)
    elif i == ')':  # If the character is ')', pop and add to postfix until '(' is found
        while len(stack) != 0 and stack[-1] != '(':
            postfix += stack.pop()
        stack.pop()  # Remove '(' from stack
    elif isOperator(i):  # If the character is an operator
        while (len(stack) != 0 and getPrecedence(stack[-1]) >= getPrecedence(i)):
            postfix += stack.pop()
        stack.append(i)  # Push the current operator onto the stack

# Pop all remaining operators in the stack and add to postfix
while len(stack) != 0:
    postfix += stack.pop()

print(postfix)
