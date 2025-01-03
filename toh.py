def towerhanoi(n:int,  src:str, dest:str, temp:str):
    if n == 1:
        print(f"Move disk 1 from {src} to {dest}")
    else:
        towerhanoi(n-1, src, temp, dest)
        print(f"Move disk {n} from {src} to {dest}")
        towerhanoi(n-1, temp, dest, src)
n=int(input("Enter the number of disks: "))
towerhanoi(n, 'A', 'C', 'B') # A, B and C are the names of the rods(src, dest and temp resp)
