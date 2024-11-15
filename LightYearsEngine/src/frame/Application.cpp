#include <frame/Application.h>
#include <frame/Core.h>

namespace ly
{
    Application::Application()
        : mWindow(sf::VideoMode(800, 1000), "Light Year"),
            mTargetFrameRate(60.f),
            mTickClock()
    {

    }

    void Application::Run()
    {
        mTickClock.restart();
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / mTargetFrameRate;
        while (mWindow.isOpen())
        {
            sf::Event windowEvent;
            while (mWindow.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    mWindow.close();
                }
            }
            float frameDeltaTime = mTickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
            LOG("ticking at framerate: %f", 1.f / frameDeltaTime);
        }
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    void Application::RenderInternal()
    {
        mWindow.clear();

        Render();

        mWindow.display();
    }

    void Application::Render()
    {
        sf::RectangleShape rect(sf::Vector2f(100, 100));
        rect.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
        rect.setFillColor(sf::Color::Green);
        rect.setOrigin(50,50);

        mWindow.draw(rect);
    }

    void Application::Tick(float deltaTime)
    {

    }
}