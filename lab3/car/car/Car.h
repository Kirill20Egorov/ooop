#pragma once

// todo: scoped enum
enum class Direction
{
    Straight,
    OnPlace,
    Back
};

class Car
{
public:
    Car();
    ~Car();
    bool TurnOnEngine();
    bool TurnOffEngine();
    bool SetGear(int gear);
    bool SetSpeed(int speed);
    int GetSpeed() const;
    int GetGear() const;
    Direction GetDirection()const;
    bool GetEngineState() const;
private:
    Direction m_direction = Direction::OnPlace;
    int m_gear = 0;
    int m_speed = 0;
    bool m_isOnEngine = false;
};

