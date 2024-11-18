#include "frame/World.h"
#include "frame/Core.h"
#include "frame/Actor.h"

namespace ly
{
    World::World(ly::Application *owningApp)
          : mOwningApp(owningApp),
            mBeganPlay(false),
            mActors(),
            mPendingActors()
    {

    }

    void World::BeginPlayInternal()
    {
        if (!mBeganPlay)
        {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime)
    {
        for (shared<Actor> actor : mPendingActors)
        {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }
        mPendingActors.clear();

        for (shared<Actor> actor : mActors)
        {
            actor->Tick(deltaTime);
        }



        Tick(deltaTime);
    }

    void World::Tick(float deltaTime)
    {
        LOG("ticking at framerate: %f", 1.f / deltaTime);
    }

    void World::BeginPlay()
    {
        LOG("Begin play");

    }

    World::~World()
    {

    }
}