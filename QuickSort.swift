// File: ShellSort.swift
// Created on: 26th May 2018
// Updated on: 4th June 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Quick Sort")

func partition(array: inout [Int], low: Int, high: Int) -> Int {
  let pivotItem = array[high];
  var i = (low-1)
  for j in low..<high {
    if array[j] <= pivotItem {
      i += 1
      array.swapAt(i, j)
    }
  }
  array.swapAt(i+1, high)
  return i+1
}

func quickSort(array: inout [Int], low: Int, high: Int) {
  if low < high {
    let pivotIndex = partition(array: &array, low: low, high: high)
    quickSort(array: &array, low: low, high: pivotIndex-1)
    quickSort(array: &array, low: pivotIndex+1, high: high)
  }
}

func quickSort(array: [Int]) -> [Int] {
    var outputArray = array
    quickSort(array: &outputArray, low: 0, high: array.count-1)
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = quickSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)
