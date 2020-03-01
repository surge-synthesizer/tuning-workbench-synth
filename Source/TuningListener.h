#pragma once
#include "Tunings.h"

class TuningUpdatedListener {
public:
    virtual ~TuningUpdatedListener() { }
    virtual void tuningUpdated(const Tunings::Tuning &newTuning) = 0;
};

class NotesOnChangedListener {
public:
    virtual ~NotesOnChangedListener() { }
    virtual void noteOn( int noteNum ) = 0;
    virtual void noteOff( int noteNum ) = 0;
};
