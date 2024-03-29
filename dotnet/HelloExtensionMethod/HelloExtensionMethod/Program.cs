﻿// https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/how-to-implement-and-call-a-custom-extension-method
// https://www.c-sharpcorner.com/UploadFile/3d39b4/extension-method-in-C-Sharp/

using System.Linq;
using System.Text;
using System;

namespace CustomExtensions
{
   // Extension methods must be defined in a static class.
   public static class StringExtension
   {
      // This is the extension method.
      // The first parameter takes the "this" modifier
      // and specifies the type for which the method is defined.
      public static int WordCount(this string str)
      {
         return str.Split(new char[] { ' ', '.', '?' }, StringSplitOptions.RemoveEmptyEntries).Length;
      }
      public static int TotalCharWithoutSpace(this string str)
      {
         int totalCharWithoutSpace = 0;
         string[] userString = str.Split(' ');
           foreach (string stringValue in userString)
           {
               totalCharWithoutSpace += stringValue.Length;
           }
           return totalCharWithoutSpace;
       }
   }
}
namespace Extension_Methods_Simple
{
   // Import the extension method namespace.
   using CustomExtensions;
   class Program
   {
      static void Main(string[] args)
      {
         string s = "The quick brown fox jumped over the lazy dog.";
         // Call the method as if it were an
         // instance method on the type. Note that the first
         // parameter is not specified by the calling code.
         int i = s.WordCount();
         System.Console.WriteLine("Word count of s is {0}", i);

         int totalCharWithoutSpace = s.TotalCharWithoutSpace();
         Console.WriteLine("Total number of character is :" + totalCharWithoutSpace);
      }
   }
}