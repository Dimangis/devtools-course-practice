// Copyright 2022 Mustafaev Dmitry

#ifndef MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_CEACER_CIFIR_APP_H_
#define MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_CEACER_CIFIR_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_ALIMOV_MIKE_CEACER_CIFIR_INCLUDE_CEACER_CIFIR_APP_H_
