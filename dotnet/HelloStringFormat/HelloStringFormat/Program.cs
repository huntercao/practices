// https://learn.microsoft.com/en-us/dotnet/api/system.string.format?view=net-7.0
Decimal pricePerOunce = 17.36m;
String s = String.Format("The current price is {0} per ounce.",
                         pricePerOunce);
Console.WriteLine(s);

// "C" Currency
String s2 = String.Format("The current price is {0:C2} per ounce.",
                         pricePerOunce);
Console.WriteLine(s2);

string s3 = String.Format("At {0}, the temperature is {1}°C.",
                         DateTime.Now, 20.4);
Console.WriteLine(s3);

string s4 = String.Format("It is now {0:d} at {0:t}", DateTime.Now);
Console.WriteLine(s4);

string name = "Mark";
var date = DateTime.Now;

// Composite formatting:
Console.WriteLine("Hello, {0}! Today is {1}, it's {2:HH:mm} now.", name, date.DayOfWeek, date);
// String interpolation:
Console.WriteLine($"Hello, {name}! Today is {date.DayOfWeek}, it's {date:HH:mm} now.");

Console.WriteLine($"|{"Left",-7}|{"Right",7}|");
const int FieldWidthRightAligned = 20;
Console.WriteLine($"{Math.PI,FieldWidthRightAligned} - default formatting of the pi number");
// "F" Fixed-point
Console.WriteLine($"{Math.PI,FieldWidthRightAligned:F3} - display only three decimal digits of the pi number");