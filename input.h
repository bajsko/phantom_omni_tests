#include <SFML/Graphics.hpp>

#ifndef INPUT_H
#define INPUT_H
#pragma once

using namespace sf;

extern bool keys[1337];
extern bool lastkeys[1337];

extern float mouseX;
extern float mouseY;
extern float lastMouseX;
extern float lastMouseY;

extern bool KEY_W;
extern bool KEY_A;
extern bool KEY_S;
extern bool KEY_D;
extern bool KEY_L;
extern bool KEY_R;

#endif