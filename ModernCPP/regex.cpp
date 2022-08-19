#include <iostream>
#include <regex>


/*
+:前面的字符出现[1,n]
*：前面的字符出现[0,n]
?:前面的字符出现[0,1]
^:匹配字符串的开始 或用于取反
$:匹配字符串的结束
():子表达式
[]:最基本的表达式单元

[^ ]* 匹配所有字符
*/

int main() {
  std::regex pattern("^([^ ]*) ([^ ]*) HTTP/([^ ]*)$");
  std::string requestLine("GET /cat.jpg HTTP/1.1");

  std::smatch subMatch;
  std::regex_match(requestLine, subMatch, pattern);

  /*subMatch[0] 保存整体匹配结果
  之后的index保存子表达式匹配结果
  子表达式的数量由 ()决定*/

  std::string method = subMatch[1];
  std::string path = subMatch[2];
  std::string version = subMatch[3];

  std::cout << method << std::endl;
  std::cout << path << std::endl;
  std::cout << version << std::endl;
  return 0; 
}
