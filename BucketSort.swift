// File: BucketSort.swift
// Created on: 4th June 2018
// Updated on: 4th June 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import Foundation

print("Hello Bucket Sort")

func insertionSort(array: [Float]) -> [Float] {

    var outputArray = array
    for (index, item) in outputArray.enumerated() {
        if index == 0 { continue }
        var i = index - 1
        while i >= 0 && outputArray[i] > item {
            outputArray[i+1] = outputArray[i]
            i -= 1
        }
        outputArray[i+1] = item
    }
    return outputArray
}

func bucketSort(array: [Float]) -> [Float] {

    var outputArray = array
    var bucket = [[Float]?](repeating: nil, count: 10)

    for item in outputArray {
        let index = Int(item * 10)
        if bucket[index] == nil {
            bucket[index] = [Float]()
        }
        bucket[index]?.append(item)
    }

    var index = 0
    for bucketItem in bucket {
        if bucketItem == nil { continue }
        for item in insertionSort(array: bucketItem!) {
            outputArray[index] = item
            index += 1
        }
    }

    return outputArray
}

func print(_ arr: [Float]) {
    arr.forEach {
        print(String(format:"%.3f", $0), separator: "", terminator: " ")
    }
}

let testArray: [Float] = [0.46, 0.19, 0.92, 0.37, 0.7, 0.34, 0.610, 0.7, 0.204, 0.184, 0.1, 0.48, 0.92, 0.22]
print("Input: ", separator:"", terminator:"")
print(testArray)

let outputArray = bucketSort(array: testArray)
print("\nOutput: ", separator:"", terminator:"")
print(outputArray)
print()
