// File: SelectionSort.swift
// Created on: 26th May 2018
// Updated on: 26th May 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Selection Sort")

func selectionSort(array: [Int]) -> [Int] {
  
    var outputArray = array
   
    for index in 0..<outputArray.count {
        var minIndex = index  
        for j in index+1..<outputArray.count {
            if outputArray[minIndex] > outputArray[j] {
                minIndex = j 
	    }
        }
        let temp = outputArray[index] 
        outputArray[index] = outputArray[minIndex]
        outputArray[minIndex] = temp
    }
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = selectionSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)

