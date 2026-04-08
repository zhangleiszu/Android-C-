#!/usr/bin/env python3

from __future__ import annotations

from typing import List


def quick_sort(values: List[int]) -> List[int]:
    """Return a new list sorted with quicksort."""
    if len(values) <= 1:
        return values

    pivot = values[len(values) // 2]
    left = [x for x in values if x < pivot]
    middle = [x for x in values if x == pivot]
    right = [x for x in values if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)


if __name__ == "__main__":
    sample = [9, 3, 7, 1, 5, 8, 2, 6, 4]
    print("Before:", sample)
    print("After: ", quick_sort(sample))
