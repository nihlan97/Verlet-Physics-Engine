#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include "simulator.h"

void Simulator::Run(Renderer& renderer, Controller& controller)
{
    if (!renderer.Init())
    {
        std::cerr << "SDL failed to initialize." << std::endl;
    }
    else
    {
        
        SDL_Event e;        
        SDL_Surface* keyPressDefaultSurface = controller.keyPressSurfaces[controller.KEY_PRESS_SURFACE_DEFAULT];
        // renderer.SetCurrentSurface(renderer.LoadSurface("../img/background1.jpeg"));

        while (!controller.hasQuit())
        {
            //Handle events
            controller.HandleEvents(e, renderer);

            //Handle media
            if(!renderer.LoadMedia(controller))
            {
                std::cerr << "Failed to load media." << std::endl;
            }
            else
            {
                // SDL_BlitSurface(renderer.getCurrentSurface(), NULL, renderer.getScreenSurface(), NULL);
                // SDL_UpdateWindowSurface(renderer.getWindow());
                SDL_RenderClear(renderer.getRenderer());
                SDL_RenderCopy(renderer.getRenderer(), renderer.getTexture(), NULL, NULL);

                //Update screen
                SDL_RenderPresent(renderer.getRenderer());            
            }
            //Insert activity
        }   
    }
    renderer.Close();
}
    
