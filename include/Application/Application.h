#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <memory>
#include <type_traits>

using namespace std;

struct Application {
    virtual void initialize() = 0;
    virtual void execute() = 0;
};

#endif