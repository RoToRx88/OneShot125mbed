#ifndef MOTOR_H_
# define MOTOR_H_

# include "mbed.h"

class OneShot125
{
public:
    OneShot125(PinName const _pin, bool const isDual); /*isDual = false: stdRotation; isDual = true: DualRotation*/
    ~OneShot125();
    void stdSetPercent(float const _percent); /*from 0% to 100%*/
    void dualSetPercent(float const _percent, bool _direction); /*_percent: from 0% to 100%; _direction: true to forward, false to backward*/
    float getPercent();

private:
    float stdOneShotCalculatePercent(float const _percent);
    float dualOneShotCalculatePercent(float const _percent, bool _direction);

private:
    PwmOut *motor;
    float min;
    float middle;
    float max;
    float percent;
    bool direction;
};

#endif /*!MOTOR_H_*/