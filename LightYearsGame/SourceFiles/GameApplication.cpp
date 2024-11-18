#include <GameApplication.h>
#include <frame/World.h>
#include "frame/Actor.h"

ly::Application* GetApplication()
{
    return new ly::GameApplication{};
}

namespace ly
{
    GameApplication::GameApplication()
    {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
    }
}