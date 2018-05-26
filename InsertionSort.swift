// File: InsertionSort.swift
// Created on: 26th May 2018
// Updated on: 26th May 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Insertion Sort")

func insertionSort(array: [Int]) -> [Int] {
  
    var outputArray = array
   
    for (index, key) in outputArray.enumerated() {
        if index == 0 { continue }
        var j = index-1
        while j >= 0 && outputArray[j] > key {
            outputArray[j+1] = outputArray[j]
            j -= 1 
        }
        outputArray[j+1] = key
    }
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = insertionSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)

