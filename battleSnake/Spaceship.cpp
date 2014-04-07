//
//  Spaceship.cpp
//  GiocoLabInf
//
//  Created by Enrico Migliorini on 12/03/14.
//  Copyright (c) 2014 Enrico Migliorini. All rights reserved.

#include "Spaceship.h"

Spaceship::Spaceship(int ba, int bd, int bh, location pos, string crname) {
    atk = ba;
    def = bd;
    hp = bh;
    
    // CAREFUL!!! Here we are using SDL coordinate system, which is flipped around the x axis.
    position = pos;
    name = crname;
}

// I'll need to check in the game loop if the enemy is still alive.
void Spaceship::takeDamage(int damage) {
    // ANIMATE DAMAGE
    double percentage = 100/((double)def + 100);    // LoL calculation
    damage *= percentage;
    hp -= damage;
    cout << name << " subisce " << damage << " danni; HP rimanenti = " << hp << endl;
}

void Spaceship::attack(Spaceship enemy, power strength) {
    // ATTACK ANIMATION
    enemy.takeDamage(atk*0.5*strength);
}

// WARNING WARNING CODE BLUE
// Drawing functions destroy rendered characters unless they are refreshed.
// This one looks like it's working, and it could even apply to battle scenes.
void Spaceship::drawOnScene(Graphics graph) {
    int rotation = 0;
    switch (position.orient) {
        case NORTH:
            rotation = 0;
            break;
        case EAST:
            rotation = 90;
            break;
        case SOUTH:
            rotation = 180;
            break;
        case WEST:
            rotation = 270;
            break;
        default:
            break;
    }
    SDL_Rect renderZone = {(position.x-1) * SPRITE_WIDTH, (position.y-1) * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT};
    SDL_RenderCopyEx(graph.getRenderer(), graph.getSprite(sprite), 0, &renderZone, rotation, 0, SDL_FLIP_NONE);
}
// x-1 and y-1 because we are working on an array

string Spaceship::getName() {
    return name;
}

int Spaceship::getAtk() {
    return atk;
}

int Spaceship::getDef() {
    return def;
}

int Spaceship::getHP() {
    return hp;
}

int Spaceship::getX() {
    return position.x;
}

int Spaceship::getY() {
    return position.y;
}

Direction Spaceship::getDirection() {
    return position.orient;
}

void Spaceship::setX(int value) {
    position.x = value;
}

void Spaceship::setY(int value) {
    position.y = value;
}

void Spaceship::setDirection(Direction facing) {
    position.orient = facing;
}

Characters Spaceship::getSprite() {
    return sprite;
}
