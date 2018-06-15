#ifndef GLOBALPARAMETER_H
#define GLOBALPARAMETER_H

#include "captureimagethread.h"
#include "stm32controlthread.h"
#include "mainthread.h"

extern STM32ControlThread STM32Thread;
extern captureImageThread ImageThread;
extern mainThread ecoliThread;

#endif // GLOBALPARAMETER_H
