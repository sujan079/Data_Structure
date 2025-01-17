import random
import time


def selectionsort(arr):
    n = len(arr)
    pos = 1
    for i in range(n):
        least = arr[i]
        for j in range(i+1, n):
            if arr[j] < least:
                least = arr[j]
                pos = j
        if pos != i:
            temp = arr[i]
            arr[i] = arr[pos]
            arr[pos] = temp


def display(arr):
    for i in range(len(arr)):
        print(arr[i])
        print(" ")


def main():
    array = []
    for i in range(100000):
        array.append(random.randint(1, 100))
    # print("Unsorted array")
    # display(array)
    # print("\n")
    start = time.time()
    selectionsort(array)
    end = time.time()
    # print("Sorted array")
    # display(array)
    # print("\n")
    diffn = end - start
    print(f"Time taken: {end - start:.6f} seconds")


if __name__ == "__main__":
    main()
