// File: ShellSort.swift
// Created on: 26th May 2018
// Updated on: 26th May 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Shell Sort")

func shellSort(array: [Int]) -> [Int] {

    var outputArray = array
    var gap = outputArray.count/2
    while gap > 0 {
        for i in gap..<outputArray.count {
            let key = outputArray[i]
            var j = i
            while j >= gap && outputArray[j-gap] > key {
                outputArray[j] = outputArray[j-gap]
                j -= gap
            }  
            outputArray[j] = key
        }
        gap /= 2
    }
    return outputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

let outputArray = shellSort(array: testArray)
print("\nOutput: ", separator:"", terminator:" ")
print(outputArray)
