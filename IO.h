#ifndef IO_H
#define IO_H

#include <SDL.h>

class IO {
public:
    IO();
    ~IO();

    bool PollEvent();
    bool WasKeyDown(SDL_Scancode key);
    bool IsKeyDown(SDL_Scancode key);

private:
    const Uint8* m_keystates;
    SDL_Event m_event;
};

#endif
