// Copyright 2022 Mustafaev Dmitry

#include "include/ceacer_cifir_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/alimov_mike_ceacer_cifir.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    CaesarCipher z;
    string a = argv[2];
    // EXPECT_EQ(z.encrypt(a, 3), "TZHUWBXLRDVGIJKMNOCAFYEQP");
    os << z.encrypt(a, 3);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    CaesarCipher z;
    string a = argv[2];
    // EXPECT_EQ(z.decrypt(a, 3), "QWERTYUIOASDFGHJKLZXCVBNM");
    os << z.decrypt(a, 3);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    CaesarCipher z;
    string a = argv[2];
    // EXPECT_EQ(z.encrypt(a, 3), "WHVW");
    os << z.encrypt(a, 3);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test4" || std::string(argv[i]) == "-t4") {
    CaesarCipher z;
    string a = argv[2];
    a += ' ';
    a += argv[3];
    // EXPECT_EQ(z.encrypt(a, 3), "KHOOR ZRUOG");
    os << z.encrypt(a, 3);
    std::cout << os.str() << std::endl;
    return "success";
  }
  return "success";
}

std::string CLPApplication::help() {
  std::string help = "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}