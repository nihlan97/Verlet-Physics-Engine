#include "dot.h"

Dot::Dot()
{
    //Load image
    _radius = 5;
    _diameter = _radius * 2;

    _imagePos.w = _radius * 2;
    _imagePos.h = _radius * 2;

    //Initialize motion variables
    //Slow down velocity with each collision
    _bounce = 0.9;
    _gravity = 0.0025;
    _friction = 0.999;
}

//Manually set position of Dot
void Dot::SetPosition(const int x, const int y)
{
    _imageX = x + _radius;
    _imageY = y + _radius;

    _oldX = _imageX + 0.25;
    _oldY = _imageY + 0.25;

    _imagePos.x = _imageX;
    _imagePos.y = _imageY;
}

//Resize Dot width and height

//Initialize dot texture
bool Dot::LoadTexture(const char* path)
{

    bool success = true;

    //Initialize image loaders
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initiatedFlags = IMG_Init(flags);

    if((initiatedFlags & flags) != flags)
    {
        std::cerr << "Failed to properly initialize image loaders. Error: " << SDL_GetError() << std::endl;
        return !success;
    }

    //Load image at path
    SDL_Surface* imageSurface = IMG_Load(path);
    if (imageSurface == nullptr)
    {
        std::cerr << "Failed to load dot.bmp surface. Error: " << SDL_GetError() << std::endl;
        return !success;
    }

    //Create texture from surface pixels
    _texture = SDL_CreateTextureFromSurface(_renderer, imageSurface);
    if (_texture == nullptr)
    {
        std::cerr << "Failed to load dot.bmp texture. Error: " << SDL_GetError() << std::endl;
        return !success;
    }
    return success;
}

//When dot is at edge of window
void Dot::ApplyConstraints()
{
    double windowWidth = SDL_GetWindowSurface(_window)->w;
    double windowHeight = SDL_GetWindowSurface(_window)->h;

    //X on left side 
    if(_imageX < 0) 
    {
        _imageX = 0;
        //If going left, go right
        if (_velX < 0)
        {
            _velX = _velX * -1 * _bounce;
        }
    }

    //X on right side
    if(_imageX + _diameter > windowWidth)
    {
        _imageX = windowWidth - _radius*2;
        
        //If going right, go left
        if (_velX > 0)
        {
            _velX = _velX * -1 * _bounce;
        }
    }

    //Y at top
    if(_imageY < 0)
    {
        _imageY = 0;
        //If going up, go down
        if(_velY < 0)
        {
            _velY = _velY *- 1 * _bounce;
        }
    }

    //Y at bottom
     if(_imageY + _diameter > windowHeight)
    {
        _imageY = windowHeight - _radius * 2;
        //If going down, go up
        if(_velY > 0)
        {
            _velY = (_velY *- 1) * _bounce;
        }
    }
}

//Handle motion logic and states
void Dot::Update(double deltaTime)
{
    if(!_pinned)
    {
        //Setup velocity + timesteps
        _velX = (_imageX - _oldX) * _friction;
        _velY = (_imageY - _oldY) * _friction;  

        ApplyConstraints();

        _oldX = _imageX;
        _oldY = _imageY;

        //Move dot
        _imageX = _imageX + _velX;  
        _imageY = _imageY + _velY;
        _imageY += _gravity;
        
        //Update window coordinates
        _imagePos.x = _imageX;
        _imagePos.y = _imageY;
    }
}


//Render texture to screen
void Dot::Draw()
{   
     if (!LoadTexture("../img/dot.png"))
    {
        std::cerr << "Failed to render dot.bmp in constructor. Error: " << SDL_GetError() << std::endl;
        return;
    }
    
    SDL_RenderCopy(_renderer, _texture, NULL, &_imagePos);
}

void Dot::HandleEvents(SDL_Event const &e)
{
    switch(e.type)
    {
        //Get dragged when held down by left mouse click
    }
}
