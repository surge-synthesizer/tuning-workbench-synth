#pragma once
#include "Tunings.h"

class TuningUpdatedListener {
public:
    virtual ~TuningUpdatedListener() { }
    virtual void tuningUpdated(const Tunings::Tuning &newTuning) = 0;
};
