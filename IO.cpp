#include "IO.h"


IO::IO() {
    SDL_Init(SDL_INIT_EVERYTHING);
    m_keystates = SDL_GetKeyboardState(NULL);
}

IO::~IO() {
    SDL_Quit();
}

bool IO::PollEvent() {
    return SDL_PollEvent(&m_event) != 0;
}

bool IO::WasKeyDown(SDL_Scancode key) {
    return m_event.type == SDL_KEYDOWN && m_event.key.keysym.scancode == key;
}

bool IO::IsKeyDown(SDL_Scancode key) {
    return m_keystates[key];
}
