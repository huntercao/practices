#include <iostream>
#include <regex>
#include <string>

int main()
{
   std::regex re("a(a)*b");
   std::string target("aaaaab");
   std::smatch sm;

   std::cout << "target string: " << target << '\n';

   std::regex_match(target, sm, re);
   std::cout << sm.size() << '\n';
   std::cout << "entire match: " << sm.str(0) << '\n';
   std::cout << "submatch: " << sm.str(1) << '\n';

   std::regex re1("a(a*)b");
   std::regex_match(target, sm, re1);
   std::cout << sm.size() << '\n';
   std::cout << "entire match: " << sm.str(0) << '\n';
   std::cout << "submatch: " << sm.str(1) << '\n';

   std::string target2("aaaaab (123 abc)");
   //std::string target2("(123 abc)");
   std::cout << "target2 string: " << target2 << '\n';
   //std::regex re2("aaaaab \\(*$");
   //std::regex re2("a(.+)");
   std::string pattern("aaaaab \\((.+)\\)");
   //std::string pattern("(.*)");
   std::regex re2(pattern);
   std::regex_match(target2, sm, re2);
   std::cout << sm.size() << '\n';
   std::cout << "entire match: " << sm.str(0) << '\n';
   std::cout << "submatch: " << sm.str(1) << '\n';
}
