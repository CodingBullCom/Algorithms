// File: BubbleSort.swift
// Created on: 26th May 2018
// Updated on: 26th May 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print(" ** Hello Bubble Sort **")

func bubbleSort(array: [Int]) -> [Int] {
  
    var outputArray = array
   
    for i in 0..<outputArray.count {
        
        for j in 0 ..< outputArray.count-i-1 {
            if outputArray[j] > outputArray[j+1] {
                let temp = outputArray[j+1]
                outputArray[j+1] = outputArray[j]
                outputArray[j] = temp
            }
        }
    }
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = bubbleSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)

