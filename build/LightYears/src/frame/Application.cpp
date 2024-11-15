#include <frame/Application.h>

namespace ly {
    ly::Application::Application() : renderWindow(sf::VideoMode(400, 400), "Render Window")
    {

    }

    void ly::Application::Run()
    {
        while (renderWindow.isOpen())
        {
            sf::Event windowEvent;
            while (renderWindow.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    renderWindow.close();
                }
            }
        }
    }
}