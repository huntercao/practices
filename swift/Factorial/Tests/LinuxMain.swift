import XCTest

import FactorialTests

var tests = [XCTestCaseEntry]()
tests += FactorialTests.allTests()
XCTMain(tests)
