#include <EntryPoint.h>
#include <frame/Application.h>


int main()
{
    ly::Application* application = GetApplication();
    application->Run();
    delete application;
}
