# Draw-Circle-Example
This is an example of how you can use SDL to draw a circle on a screen.


Do  :)
``` make ``` 
It will generate the sdl2.out file, which will open the window, and will render a circle.

First, of all, we include some SDL2 Libraries, *SOME OF THEM ARE NOT BEING USED*, like _log.h, _timer.h, _image.h and complex.h. 'Cause this file was being used for some other things until i turned out into an example.

Second, we define some variables, h(height), w(width), and then define some properties of the window.

Then, we initalize SDL2 Stuff, so we can properly use it.

We create a function called drawCircle, which will check if it has a completed circle, if not, it will start the circle creation process, it will increment the angle by 1 every time and print it on the console(if you're using it), it will make some calculations, the circle formula, and it will use SDL_RenderDrawPoint() to render a point.

If angle ultrapasses 360(total angles of a circle) it turns `CompletedCircle` into 1, and finish the function();

=======================================
          The main function
=======================================

The main function have some crucial things, it will set some variables, and some checks, so if it detects something wrong, the program will crash.

It will set a new value to the variable window and basic renderer, using SDL_CreateWindow and SDL_CreateRenderer, both are necessary to render a circle. Also it clears the renderer and set the Background Color to 0, the order is very important!

We have the main loop, this is where everything happens, inside the first while loop, it has a second while loop, it will check if the event variable that we made, had received a QUIT_EVENT, if no, it will normally;
Then we really start the fun, it will initialize the drawCircle function with the arguments we put it and will set the Color to White; after this, it will render with SDL_RenderPresent() and set a Delay, so the CPU don't go to 100% usage and explode.

The main function have the ABORT PART, which will quit and destroy both renderer and window, after that it will return 0;

That's it :)
