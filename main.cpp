#include "core/DecafLexer.h"
#include "core/DecafParser.h"
#include <antlr4-runtime/antlr4-common.h>
#include <iostream>

using namespace antlr4;
using namespace std;
using namespace decafcore;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "File not provided!" << endl;
    return -1;
  }

  ifstream stream;
  stream.open(argv[1]);

  ANTLRInputStream input(stream);
  DecafLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  DecafParser parser(&tokens);
  parser.program();

  return 0;
}
