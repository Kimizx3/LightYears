#pragma once
#include <SFML/Graphics.hpp>
#include "frame/Core.h"

namespace ly
{
    class World;
    class Application
    {
    public:
        Application();
        void Run();

        template<typename WorldType>
        weak<WorldType> LoadWorld();

    private:
        sf::RenderWindow mWindow;
        sf::Clock mTickClock;

        float mTargetFrameRate;

        void RenderInternal();
        void TickInternal(float deltaTime);

        virtual void Render();
        virtual void Tick(float deltaTime);

        shared<World> currentWorld;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld()
    {
        shared<WorldType> newWorld {new WorldType{this}};
        currentWorld = newWorld;
        return newWorld;
    }
}
