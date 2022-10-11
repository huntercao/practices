﻿using System.Linq.Expressions;

Func<int, int> square = x => x * x;
Console.WriteLine(square(5));

System.Linq.Expressions.Expression<Func<int, int>> e = x => x * x;
Console.WriteLine(e);

int[] numbers = { 2, 3, 4, 5 };
var squaredNumbers = numbers.Select(x => x * x);
Console.WriteLine(string.Join(" ", squaredNumbers));

// Expression Trees
// Creating a parameter expression.  
ParameterExpression value = Expression.Parameter(typeof(int), "value");

// Creating an expression to hold a local variable.
ParameterExpression result = Expression.Parameter(typeof(int), "result");

// Creating a label to jump to from a loop.  
LabelTarget label = Expression.Label(typeof(int));

// Creating a method body.  
BlockExpression block = Expression.Block(
    // Adding a local variable.  
    new[] { result },
    // Assigning a constant to a local variable: result = 1  
    Expression.Assign(result, Expression.Constant(1)),
        // Adding a loop.  
        Expression.Loop(
           // Adding a conditional block into the loop.  
           Expression.IfThenElse(
               // Condition: value > 1  
               Expression.GreaterThan(value, Expression.Constant(1)),
               // If true: result *= value --  
               Expression.MultiplyAssign(result,
                   Expression.PostDecrementAssign(value)),
               // If false, exit the loop and go to the label.  
               Expression.Break(label, result)
           ),
       // Label to jump to.  
       label
    )
);

// Compile and execute an expression tree.  
int factorial = Expression.Lambda<Func<int, int>>(block, value).Compile()(5);

Console.WriteLine(factorial);
// Prints 120.

Action<string> greet = name =>
{
   string greeting = $"Hello {name}!";
   Console.WriteLine(greeting);
};
greet("Hunter");

// Add the following using directive to your code file:  
// using System.Linq.Expressions;  

// Create an expression tree.  
Expression<Func<int, bool>> exprTree = num => num < 5;

// Decompose the expression tree.  
ParameterExpression param = (ParameterExpression)exprTree.Parameters[0];
BinaryExpression operation = (BinaryExpression)exprTree.Body;
ParameterExpression left = (ParameterExpression)operation.Left;
ConstantExpression right = (ConstantExpression)operation.Right;

Console.WriteLine("Decomposed expression: {0} => {1} {2} {3}",
                  param.Name, left.Name, operation.NodeType, right.Value);

// This code produces the following output:  

// Decomposed expression: num => num LessThan 5