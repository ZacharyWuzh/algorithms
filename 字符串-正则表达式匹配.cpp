/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

#include <iostream>

using namespace std;

class Solution{
public:
  bool match(char* str, char* pattern){
    if(str[0]=='\0' && pattern[0] == '\0'){
      return true;
    }
    // if(str[0] == '\0' && pattern[0] != '\0'){
    //   return false;
    // }
    if(str[0] != '\0' && pattern[0] == '\0'){
      return false;
    }
    // if(str[0] == pattern[0] or pattern[0] == '.'){
    //   return match(str+1,pattern+1);
    // }
    // else{
    //   if(pattern[0] == '*'){
    //     if(str[0] == *(pattern-1)){
    //       return match(str+1,pattern);
    //     }
    //     else{
    //       return match(str,pattern+1);
    //     }
    //   }
    //   else{
    //     if(pattern[1] == '*'){
    //       return match(str,pattern+2);
    //     }
    //     else{
    //       return false;
    //     }
    //   }
    // }
    if(*(pattern + 1) != '*'){
      if(*str == *pattern || (*str !='\0' and *pattern == '.')){
        return match(str+1, pattern+1);
      }
      else{
        return false;
      }
    }
    else{
      if(*str == *pattern || (*str != '\0' and *pattern == '.')){
        return match(str+1,pattern) || match(str,pattern+2);
      }
      else{
        return match(str,pattern+2);
      }
    }

  }
};
int main(){
  char str[4] = "aaa";
  char pattern[8] = "ab*a";
  Solution s;
  cout<<s.match(str,pattern);
  return 0;
}
