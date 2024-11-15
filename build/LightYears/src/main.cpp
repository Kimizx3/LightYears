#include <iostream>
#include <memory>
#include <frame/Application.h>
#include <SFML/Graphics.hpp>

int main()
{
    //ly::Application* application = new ly::Application();
    std::unique_ptr<ly::Application> application = std::make_unique<ly::Application>();
    application->Run();
}
