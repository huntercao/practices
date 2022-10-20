using System;
using System.Reflection;
using System.Security.Permissions;

//[assembly: AssemblyVersionAttribute("1.0.2000.0")]

public class HelloAssembly
{
   private int factor;
   public HelloAssembly(int f)
   {
      factor = f;
   }

   public int SampleMethod(int x)
   {
      Console.WriteLine("\nHelloAssembly.SampleMethod({0}) executes.", x);
      return x * factor;
   }

   public static void Main()
   {
      Assembly assem = typeof(HelloAssembly).Assembly;

      Console.WriteLine("Assembly Full Name:");
      Console.WriteLine(assem.FullName);

      // The AssemblyName type can be used to parse the full name.
      AssemblyName assemName = assem.GetName();
      Console.WriteLine("\nName: {0}", assemName.Name);
      Console.WriteLine("Version: {0}.{1}",
          assemName.Version?.Major, assemName.Version?.Minor);

      Console.WriteLine("\nAssembly CodeBase:");
      Console.WriteLine(assem.Location);

      // Create an object from the assembly, passing in the correct number
      // and type of arguments for the constructor.
#pragma warning disable CS8600 // Converting null literal or possible null value to non-nullable type.
      Object objectAssem = assem.CreateInstance("HelloAssembly", false,
          BindingFlags.ExactBinding,
          null, new Object[] { 2 }, null, null);
#pragma warning restore CS8600 // Converting null literal or possible null value to non-nullable type.

      // Make a late-bound call to an instance method of the object.
      MethodInfo? m = assem!.GetType("HelloAssembly")!.GetMethod("SampleMethod");
      Object? ret = m!.Invoke(objectAssem, new Object[] { 42 });
      Console.WriteLine("SampleMethod returned {0}.", ret);

      Console.WriteLine("\nAssembly entry point:");
      Console.WriteLine(assem.EntryPoint);
   }
}
