// File: MergeSort.swift
// Created on: 26th May 2018
// Updated on: 3rd June 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Merge Sort")

func merge(leftSortedArray: [Int], rightSortedArray: [Int]) -> [Int] {

  let outputArraySize = leftSortedArray.count + rightSortedArray.count
  var outputArray = Array(repeating: 0, count: outputArraySize)

  var i = 0, j = 0, k = 0
  while i < leftSortedArray.count && j < rightSortedArray.count {
    if leftSortedArray[i] < rightSortedArray[j] {
      outputArray[k] = leftSortedArray[i]
      i += 1
    } else {
      outputArray[k] = rightSortedArray[j]
      j += 1
    }
    k += 1
  }

  while i < leftSortedArray.count {
    outputArray[k] = leftSortedArray[i]
    i += 1
    k += 1
  }

  while j < rightSortedArray.count {
    outputArray[k] = rightSortedArray[j]
    j += 1
    k += 1
  }
  return outputArray
}

func mergeSort(array: [Int], low: Int, high: Int) -> [Int] {
  if low < high {
    let mid = low + (high - low)/2
    let leftArray = mergeSort(array: array, low: low, high: mid)
    let rightArray = mergeSort(array: array, low: mid+1, high: high)
    return merge(leftSortedArray: leftArray, rightSortedArray: rightArray)
  }
  return [array[high]]
}

func mergeSort(array: [Int]) -> [Int] {
  return mergeSort(array: array, low: 0, high: array.count-1)
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = mergeSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)
