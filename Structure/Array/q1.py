from sys import stdin
from typing import Iterable

def reverse(arr: list[int], start: int, end: int):
    for i in range(int((end - start + 1) / 2)):
        arr[start + i], arr[end - i] = arr[end - i], arr[start + i]

def printArray(arr: list[int]):
    print(" ".join(arr))


N: int = int(stdin.readline().strip())
arr: list[int] = list(map(int, stdin.readline.strip().split()))

cnt: int = int(stdin.readline().strip())

def accumulator(iter: Iterable[int]) -> Iterable[tuple[int, int]]:
    yield (next(iter), next(iter))
    
reverses: list[tuple[int, int]] = list(accumulator(map(int, stdin.readline().strip().split())))
for start, end in reverse:
    print(start, end)
