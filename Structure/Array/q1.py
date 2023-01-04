from sys import stdin
from typing import Iterable, Optional

def reverse(arr: list[int], start: int, end: int):
    for i in range(int((end - start + 1) / 2)):
        arr[start + i], arr[end - i] = arr[end - i], arr[start + i]

def printArray(arr: list[int]):
    print(" ".join(arr))


N: int = int(stdin.readline().strip())
arr: list[int] = list(map(int, stdin.readline().strip().split()))
cnt: int = int(stdin.readline().strip())

def accumulator(i: Iterable[int]) -> Iterable[tuple[int, Optional[int]]]:
    while True:
        try:
            # a = next(i)
            # b = next(i, None)
            # e = (a, b)
            # print(f"accumulated -> {e}")
            # yield e
            yield (next(i), next(i, None))
        except StopIteration:
            return

# reverses: Iterable[tuple[int, Optional[int]]] = accumulator(map(
#     lambda e: (
#         print(s, " -> ",  e),
#         int(e)
#     )[1],
#     (s := stdin.readline().strip().split(" "))
# ))
reverses: Iterable[tuple[int, Optional[int]]] = accumulator(map(int, stdin.readline().strip().split(" ")))

for start, end in reverses:
    reverse(arr, start, end)

print(arr)
