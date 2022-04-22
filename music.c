/*
 * music.c
 *
 *  Created on: Mar 23, 2022
 *      Author: tjfriedl
 */

#include "open_interface.h"
#include "music.h"
//
///// Load three songs onto the iRobot
///**
// * Before calling this method, be sure to initialize the open interface by calling:
// *
// *   oi_t* sensor = oi_alloc();
// *   oi_init(sensor);
// *
// */
void load_songs() {
//
//  // Notes: oi_load_song takes four arguments
//  // arg1 - an integer from 0 to 16 identifying this song
//  // arg2 - an integer that indicates the number of notes in the song (if greater than 16, it will consume the next song index's storage space)
//  // arg3 - an array of integers representing the midi note values (example: 60 = C, 61 = C sharp)
//  // arg4 - an array of integers representing the duration of each note (in 1/64ths of a second)
//  //
//  // For a note sheet, see page 12 of the iRobot Creat Open Interface datasheet
//
    //0
    unsigned char rickrollNumNotes = 11;
    unsigned char rickrollNotes[11]    = {53, 55, 48, 55, 57, 60, 58, 57, 53, 55, 48};
    unsigned char rickrollDuration[11] = {48, 64, 16, 48, 48, 8,  8,  8,  48, 64, 64};
    oi_loadSong(RICK_ROLL, rickrollNumNotes, rickrollNotes, rickrollDuration);
//
//  //1
    unsigned char ImperialMarchNumNotes1 = 16;
    unsigned char ImperialMarchNotes1[16]     = {55, 55, 55, 51, 58, 55, 51, 58, 55, 0,  62, 62, 62, 63, 58, 54};
    unsigned char ImperialMarchDurations1[16] = {32, 32, 32, 20, 12, 32, 20, 12, 32, 32, 32, 32, 32, 20, 12, 32};
    oi_loadSong(IMPERIAL_MARCH1, ImperialMarchNumNotes1, ImperialMarchNotes1, ImperialMarchDurations1);
//
//2
    unsigned char ImperialMarchNumNotes2 = 3;
    unsigned char ImperialMarchNotes2[3]     = {63, 58, 54};
    unsigned char ImperialMarchDurations2[3] = {20, 12, 32};
    oi_loadSong(IMPERIAL_MARCH2, ImperialMarchNumNotes2, ImperialMarchNotes2, ImperialMarchDurations2);
//
//  unsigned char BluesNumNotesA = 16;
//  unsigned char BluesNotesA[16]     = {};
//  unsigned char BluesDurationA[16]  = {};
//  oi_load_song(BLUES_A, BluesNotesA, BluesNumNotesA, BluesDurationA);
//
//  unsigned char BluesNumNotesB = 16;
//  unsigned char BluesNotesB[16]     = {};
//  unsigned char BluesDurationB[16]  = {};
//  oi_load_song(BLUES_B, BluesNotesB, BluesNumNotesB, BluesDurationB);
//
//  unsigned char BluesNumNotesC = 16;
//  unsigned char BluesNotesC[16]     = {};
//  unsigned char BluesDurationC[16]  = {};
//  oi_load_song(BLUES_C, BluesNotesC, BluesNumNotesC, BluesDurationC);
//
//    unsigned char BluesNumNotesD = 14;
//    unsigned char BluesNotesD[14]     = {74, 73, 70, 67, 61, 60, 58, 55, 50, 55, 58, 60, 58, 62};
//    unsigned char BluesDurationD[14]  = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
//    oi_loadSong(BLUES_D, BluesNotesD, BluesNumNotesD, BluesDurationD);
//
    unsigned char mario1NumNotes = 49;
    unsigned char mario1Notes[49]    = {48, 60, 45, 57, 46, 58,  0, 48, 60, 45, 57, 46, 58,  0, 41, 53, 38, 50, 39, 51,  0, 41, 53, 38, 50, 39, 51,  0, 51, 50, 49, 48, 51, 50, 44, 43, 49, 48, 54, 53, 52, 58, 57, 56, 51, 47, 46, 45, 44 };
    unsigned char mario1Duration[49] = {12, 12, 12, 12, 12, 12, 62, 12, 12, 12, 12, 12, 12, 62, 12, 12, 12, 12, 12, 12, 62, 12, 12, 12, 12, 12, 12, 48,  8,  8,  8, 24, 24, 24, 24, 24, 24,  8,  8,  8,  8,  8,  8, 16, 16, 16, 16, 16, 16 };
    oi_loadSong(MARIO_UNDERWORLD, mario1NumNotes, mario1Notes, mario1Duration);
//
//  unsigned char mario2NumNotes = 65;
//  unsigned char mario2Notes[65]    = {50, 52, 54, 55, 57, 58, 59, 59, 59, 59, 59, 55, 64, 63, 64, 0, 55, 57, 59, 60, 62, 64, 63, 65, 64,  0, 55, 62, 61, 62,  0, 55, 57, 59, 60, 61, 62, 55, 65, 64,  0, 55, 67, 67, 67, 67, 69,  0, 67, 65, 65, 65, 65, 67,  0, 65, 64, 57, 59, 65, 64, 64, 64, 59, 60 };
//  unsigned char mario2Duration[65] = {18, 18, 18, 18, 18, 18,  9,  9, 18, 18, 45,  9, 54, 54, 54, 9,  9,  9,  9,  9,  9, 54, 36, 18, 54, 45,  9, 54, 54, 54,  9,  9,  9,  9,  9,  9, 54, 36, 18, 54, 45,  9, 54, 54, 54, 18, 18,  9,  9, 54, 54, 54, 18, 18,  9,  9, 54, 18, 18, 18,  9,  9, 27,  9, 54 };
//  oi_load_song(MARIO_UNDERWATER, mario2NumNotes, mario2Notes, mario2Duration);
//
//
//
}
//
////oi_play_song(int index) -- this is how we play the songs

