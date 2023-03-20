#include "Infinite_cal.h"
#include "Stack.h"
#include "Dll.h"
#include "Plus.h"

int main(int argc, char* argv[]){
  FILE* ifp;
  ifp = fopen(argv[1], "r+");
  char* input = argv[1];
  postfix(input);
  return;
}