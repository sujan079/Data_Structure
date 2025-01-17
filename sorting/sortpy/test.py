import random
import time 
def BubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
def display(arr):
    for i in range(len(arr)):
        print(arr[i])
        print(" ")
    print("\n")

def main():
    array = []
    for i in range(10):
        array.append(random.randint(1,100))  #this assigns random values to the array from
    print("Unsorted array")
    display(array)
    start = time.time()
    BubbleSort(array)
    end = time.time()
    print("Sorted array")
    display(array)
if __name__ == "__main__":
    main()