//
//  main.swift
//  SwiftTest
//
//  Created by 朱猛 on 2020/11/2.
//

import Foundation

enum Beverage: CaseIterable {
    case coffee, tea, juice
}
let numberOfChoices = Beverage.allCases.count
print("\(numberOfChoices) beverages available")


for tmpcase in Beverage.allCases {
    print(tmpcase)
}





