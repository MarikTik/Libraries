#ifndef APPLICATION_RUNNER_H_
#define APPLICATION_RUNNER_H_

#include <memory>
#include <type_traits>
#include "Application.h"

template<typename TApplication, typename... TArgs>
class ApplicationRunner {
   static_assert(is_base_of_v<Application, TApplication>, "TApplication is not derived from Application class");
public:
    Runner(TArgs&&... args) : _app(make_unique<TApplication>(args...))
    {
    }
    virtual void start() {
        _app->initialize();
    }
    virtual void run() {
        _app->execute();
    }
private:
    unique_ptr<Application> _app;

};
#endif