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

def main():
    array = []
    for i in range(100000):
        array.append(random.randint(1,100000))
    # print("Unsorted array")
    # display(array)
    # print("\n")
    start = time.time()
    BubbleSort(array)
    end = time.time()
    # print("Sorted array")
    diffn = end - start 
    # display(array)
    # print("\n") 
    print(f"Time taken: {end - start:.6f} seconds")
if __name__ == "__main__":
    main()