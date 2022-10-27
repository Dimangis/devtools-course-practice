// Copyright 2022 Mustafaev Dmitry

#include <iostream>
#include <string>

#include "include/ceacer_cifir_app.h"

int main(int argc, const char** argv) {
  CLPApplication app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
