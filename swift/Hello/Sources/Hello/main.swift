if CommandLine.arguments.count != 2 {
   print("Usage: Hello NAME")
} else {
   let name = CommandLine.arguments[1]
   sayHello(name: name)
}

