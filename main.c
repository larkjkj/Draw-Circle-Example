#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#include <SDL2/SDL_image.h>

#include <SDL2/SDL_video.h>
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int h, w;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 448 
#define WINDOW_XPOS 0
#define WINDOW_YPOS 0

int completedCircle = 0, radAngle, angle, xc, yc;
SDL_Event event;
SDL_Texture* texture = NULL;
SDL_Window* window = NULL;
SDL_Renderer* basic_renderer = NULL;
void drawCircle(int x, int y, int radius) {
        for(int i = 0; i < 360; i ++) {
        	xc = WINDOW_WIDTH / 2;
        	yc = WINDOW_HEIGHT / 2;
                                                   
        	x = xc + radius * cos(i);
        	y = yc + radius * sin(i);
        	SDL_RenderDrawPoint(basic_renderer, x, y); 
	}
	SDL_RenderPresent(basic_renderer);
}

int main() {
    int open = 1;
    (SDL_GetWindowSize(window, &w, &h));
    printf("A largura é : %i", w);
    printf("A altura é: %i", h);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("irmao, tem alguma coisa errado com o sdl ae pae");
    }

    if (!window) {
        //Se algo falhar, morre
        SDL_DestroyRenderer(basic_renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    window = SDL_CreateWindow("WINDOW_NAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    basic_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(basic_renderer);
    SDL_SetRenderDrawColor(basic_renderer, 50, 50, 50, 255);

    //Loop Principal
    while (open) {
        //Loop pra garantir que a janela feche e nao feche
        SDL_Delay(16);
        
	while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                open = 0;
            }
        }
        //Renderizar circulo
	drawCircle(320, 240, 100);
        SDL_SetRenderDrawColor(basic_renderer, 255, 255, 255, 255);

        //Dar um delay para que a cpu nn va fritar um ovo
    }
    SDL_DestroyRenderer(basic_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
