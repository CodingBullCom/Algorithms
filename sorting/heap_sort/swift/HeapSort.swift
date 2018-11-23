// File: HeapSort.swift
// Created on: 4th June 2018
// Updated on: 5th June 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Heap Sort")

func parentIndex(of index: Int) -> Int {
    return index/2
}

func leftChildIndex(of index: Int) -> Int {
    return 2*index + 1
}

func rightChildIndex(of index: Int) -> Int {
    return 2*index + 2
}

func heapify(array: inout [Int], at index: Int, count: Int) {
    var largestItemIndex = index
    let leftChildIdx = leftChildIndex(of: index)
    let rightChildIdx = rightChildIndex(of: index)

    if leftChildIdx < count && array[leftChildIdx] > array[largestItemIndex] {
        largestItemIndex = leftChildIdx
    }

    if rightChildIdx < count && array[rightChildIdx] > array[largestItemIndex] {
        largestItemIndex = rightChildIdx
    }

    if largestItemIndex != index {
        array.swapAt(index, largestItemIndex)
        heapify(array: &array, at: largestItemIndex, count: count)
    }
}

func heapSort(array: [Int]) -> [Int] {

    var outputArray = array
    var index = array.count/2 - 1
    while index >= 0 {
        heapify(array: &outputArray, at: index, count: array.count)
        index -= 1
    }
    index = array.count - 1
    while index >= 0 {
        outputArray.swapAt(0, index)
        heapify(array: &outputArray, at: 0, count: index)
        index -= 1
    }
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

print("\nOutput: ", separator:"", terminator:" ")
print(heapSort(array: testArray))
