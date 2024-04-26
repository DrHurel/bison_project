#include <iostream>
#include <stdio.h>

extern FILE *yyin;

int yylex();

void yyparse();

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <entry>\n";
    return 1;
  }
  if (!(yyin = fopen(argv[1], "r"))) {
    std::cerr << "Could not open file '" << argv[1] << "'\n";
    return 1;
  }

  yyparse();
  return 0;
}
