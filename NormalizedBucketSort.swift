// File: NormalizedBucketSort.swift
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

func normalizedBucketSort(array: [Int]) -> [Int] {
    let max: Int! = array.max()
    var closer0sNumber: Float = 1.0
    while true {
        if max/Int(closer0sNumber) == 0 {
            break
        } else {
            closer0sNumber *= 10
        }
    }

    let mappedTestArray = array.map{ Float($0) / closer0sNumber }
    let outputArray = bucketSort(array: mappedTestArray)
    let mappedOutputArray = outputArray.map { Int($0*closer0sNumber) }
    return mappedOutputArray
}

let testArray = [92, 72, 10, 55, 20, 31, 99, 28, 87, 72, 47, 94, 62, 17, 23, 38]
print("Input: ", separator:"", terminator:"")
print(testArray, separator:" ", terminator:" ")

print("\nOutput: ", separator:"", terminator:" ")
print(normalizedBucketSort(array: testArray))
