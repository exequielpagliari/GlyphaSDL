//
// Created by exepa on 9/29/25.
//

#ifndef NEWCODE_SDL_SOUND_H
#define NEWCODE_SDL_SOUND_H

#pragma once
#include <CoreSDL/SDL_Utilities.h>

#define pascal

typedef void* SndChannelPtr;

typedef void* SndCallBackUPP;

typedef enum {
    soundCmd  = 80,
    bufferCmd = 81,
    freqCmd   = 82,
    volumeCmd = 83,
    quietCmd  = 84,
    callBackCmd = 85,
    flushCmd    = 86

} SndCommandType;

typedef struct sndCommand {
    SndCommandType cmd;
    int param1;
    long param2;
} SndCommand;


typedef struct soundHeader {
    short format;
    short numChannels;
    long sampleRate;
    long numFrames;
    long dataOffset;
    short loopStart;
    short loopEnd;
    short loopCount;
} soundHeader, *SoundHeader;

OSErr SndDoImmediate(SndChannelPtr snd_channel_ptr, SndCommand *snd_command);
OSErr SndDoCommand(SndChannelPtr snd_channel_ptr, SndCommand *snd_command, Boolean bool);
long SetCurrentA5(void);
long SetA5(long A5);

typedef struct routineDescriptor {

} RoutineDescriptor;
long uppSndCallBackProcInfo;

RoutineDescriptor BUILD_ROUTINE_DESCRIPTOR(long uppSndCall, void* ExternalCallBack);

#endif //NEWCODE_SDL_SOUND_H