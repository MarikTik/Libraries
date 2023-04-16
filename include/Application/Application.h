#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <memory>
#include <type_traits>

using namespace std;

struct Application {

    virtual void initialize() = 0;
    virtual void execute() = 0;

    template<typename TApplication, typename... TArgs>
    class Runner final {
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
};

#endif