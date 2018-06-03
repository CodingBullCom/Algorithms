// File: CountingSort.swift
// Created on: 4th June 2018
// Updated on: 4th June 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Counting Sort")

func countingSort(array: [Int]) -> [Int] {

    var countingArray = Array(repeating: 0, count: 101)
    var outputArray = Array(repeating: 0, count: array.count)

    array.forEach {
      countingArray[$0] += 1
    }

    for index in 1..<countingArray.count {
      countingArray[index] += countingArray[index-1]
    }

    var index = array.count-1
    while index >= 0 {
      outputArray[countingArray[array[index]]-1]  = array[index]
      countingArray[array[index]] -= 1
      index -= 1
    }

    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = countingSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)
