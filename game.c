// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: September 2019
// This program can display a sprite on the GameBoy


#include <stdio.h>
#include <gb/gb.h>

#include "smiler.c"

void main() {
    // This function displays a happy face that can move with the d-pad

    UINT8 currentspriteindex = 0;

    set_sprite_data(0, 2, smiler);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;

    while (1) {
        switch ( joypad() ) {
            case J_LEFT:
                scroll_sprite(0, -10, 0);
                break;
            case J_RIGHT:
                scroll_sprite(0, 10, 0);
                break;
            case J_UP:
                scroll_sprite(0, 0, -10);
                break;
            case J_DOWN:
                scroll_sprite(0, 0, 10);
                break;
        }

        delay(100);
    }
}
