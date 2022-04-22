/*
 * music.h
 *
 *  Created on: Mar 23, 2022
 *      Author: tjfriedl
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#define RICK_ROLL           0 // length 11
#define IMPERIAL_MARCH1     1 // length 16
#define IMPERIAL_MARCH2     2 // length 3
#define BLUES_D             3 // length 14

#define MARIO_UNDERWORLD    3 //
#define MARIO_UNDERWATER    7


#warning "Make sure the open interface has been initialized before calling load_songs()." // you may delete this warning
/// Loads some songs over the open interface
void load_songs();





#endif /* MUSIC_H_ */
