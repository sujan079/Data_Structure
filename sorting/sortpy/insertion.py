import random
import time


def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j = j-1
        arr[j+1] = key


def display(arr):
    for i in range(len(arr)):
        print(arr[i])
        print(" ")


def main():
    array = []
    for i in range(100):
        array.append(random.randint(1, 100))
    print("Unsorted array")
    display(array)
    print("\n")
    start = time.time()
    insertionSort(array)
    end = time.time()
    print("Sorted array")

    display(array)
    print("\n")
    diffn = end - start
    print(f"Time taken: {end - start:.6f} seconds")


if __name__ == "__main__":
    main()
