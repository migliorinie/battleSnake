//
//  Cruiser.cpp
//  GiocoLabInf
//
//  Created by Enrico Migliorini on 25/03/14.
//  Copyright (c) 2014 Enrico Migliorini. All rights reserved.
//

#include "Cruiser.h"

EnCruiser::EnCruiser(string plname) : Enemy(150, 50, 50, plname) {
    sprite = EN_CRUISER;
}