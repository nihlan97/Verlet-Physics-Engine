# Verlet-Physics-Engine 

## Description


A simple cloth simulation using verlet physics. Gravity, friction, and bounce are all accounted for.


## Dependencies for running locally

- git (latest version) : All Oses([click here for instructions](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git))
- cmake >= 3.7 : All OSes ([click here for instructions](https://cmake.org/install/))
- make >= 4.1 (Linux, Mac), 3.81 (Windows)
    - Linux: make is installed by default on most Linux distros.
    - Mac: install Xcode command line tools to get make ([click here for instructions](https://developer.apple.com/xcode/features/))
    - Windows ([click here for instructions](https://developer.apple.com/xcode/features/))
- SDL >= 2.0: All OSes ([click here for instructions](https://wiki.libsdl.org/Installation))
- SDL_image >= 2.0.5: All OSes([click here for instructions](https://www.libsdl.org/projects/SDL_image/))
    - On Linux command line, enter ``sudo apt-get install -y libsdl2-dev``
- gcc/g++ >= 5.4
    - Linux: gcc/g++ is installed by default on most Linux distros.
    - Mac: already received with make (install Xcode command line tools to get make)
    - Windows: MinGW highly recommended ([click here for instructions](http://www.mingw.org/))


## Build Instructions


1. Clone this repository

2. Move to the top-level directory and clone this external repository: `git clone https://github.com/aminosbh/sdl2-cmake-modules.git`

3. Create and move to a build directory in the top-level directory: `mkdir build && cd build`

4. Compile: `cmake .. ` followed by `make`

5. Run: `./verlet_simulator`


### Known Bugs

- Segmentation fault when dot radius and number of squares per row/column are changed.

### Rubric requirements met:

- The project demonstrates an understanding of C++ functions and control structures.

- The project uses Object Oriented Programming techniques

- Classes use appropriate access specifiers for class members.

- Class constructors utilize member initialization lists.
    - cloth.h, dot.h, and cloth.h use initializer lists.

- Classes abstract implementation details from their interfaces
    - All non-setter/non-getter functions are abstracted.
    - Cloth is an abstraction of Structure class.

- Classes encapsulate behavior 

- Classes follow an appropriate inheritance hierarchy (ahild class of class Structure, Cloth, inherits it publicly, and uses its member variables to store and retrieve appropriate data).

- The project uses destructors appropriately. (all structures where a Dot or Stick was initialized with the **new** keyword properly deallocates them in its destructor).

