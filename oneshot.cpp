#include "oneshot.h"

OneShot125::OneShot125(PinName const _pin, bool const isDual)
{
    this->min = 0.000125;
    this->middle = 0.0001875;
    this->max = 0.000250;
    this->direction = false;
    this->motor = new PwmOut(_pin);
    this->motor->period_ms(1);
    if (isDual) {
        this->dualSetPercent(0, true);
    } else
        this->stdSetPercent(0);
}

void OneShot125::stdSetPercent(float const _percent)
{
    this->percent = _percent;
    this->motor->pulsewidth(this->stdOneShotCalculatePercent(_percent));
}

void OneShot125::dualSetPercent( float const _percent, bool _direction)
{
    this->percent = _percent;
    this->direction = _direction;
    this->motor->pulsewidth(this->dualOneShotCalculatePercent(_percent, _direction));
}

float OneShot125::stdOneShotCalculatePercent(float const _percent)
{
    return (((_percent - 0) * (this->max - this->min)) / (100 - 0)) + this->min;
}

float OneShot125::dualOneShotCalculatePercent(float const _percent, bool _direction)
{
    if (_direction)
        return (((_percent - 0) * (this->max - this->middle)) / (100 - 0)) + this->middle;
    else
        return (((_percent - 0) * (this->min - this->middle)) / (100 - 0)) + this->middle;
}



float OneShot125::getPercent()
{
    return this->percent;
}

OneShot125::~OneShot125()
{
}