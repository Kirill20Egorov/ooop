#include "Car.h"

Car::Car()
{
}

Car::~Car()
{
}


bool Car::TurnOnEngine()
{

	if (m_isOnEngine == false)
	{
		m_isOnEngine = true;
		return true;
	}
	return false;

}

bool Car::TurnOffEngine()
{
	if ((m_isOnEngine == true) && (m_gear == 0) && (m_speed == 0) && (m_direction == Direction::OnPlace))
	{
		m_isOnEngine = false;	
		return true;
	}
	return false;
}

bool Car::SetGear(int gear)
{
	switch (gear)
	{
	case -1:
	{
		if (((m_speed == 0) && (m_direction == Direction::OnPlace)) && (m_isOnEngine == true))
		{
			m_gear = -1;
			return true;
		}
		return false;
	}
	case 0:
	{
		m_gear = 0;
		return true;
	}
	case 1:
	{
		if (((((m_speed >= 0) && (m_speed <= 30)) && (m_gear >= 0) || (m_speed == 0)) && (m_isOnEngine == true)) && (m_direction != Direction::Back))
		{
			m_gear = 1;
			return true;
		}
	}
	case 2:
	{
		if (((m_speed >= 20) && (m_speed <= 50)) && (m_isOnEngine == true) && (m_direction != Direction::Back))
		{
			m_gear = 2;
			return true;
		}
	}
	case 3:
	{
		if (((m_speed >= 30) && (m_speed <= 60)) && (m_isOnEngine == true) && (m_direction != Direction::Back))
		{
			m_gear = 3;
			return true;
		}
	}
	case 4:
	{
		if (((m_speed >= 40) && (m_speed <= 90)) && (m_isOnEngine == true) && (m_direction != Direction::Back))
		{
			m_gear = 4;
			return true;
		}
	}
	case 5:
	{
		if ((m_speed >= 50) && (m_isOnEngine == true) && (m_direction != Direction::Back))
		{
			m_gear = 5;
			return true;
		}
	}
	}
	return false;
}

bool Car::SetSpeed(int speed)
{
	if ((m_gear == -1) && (speed <= 20) && (speed >= 0))
	{
		m_speed = speed;
		m_direction = Direction::Back;
		return true;
	}
	if ((m_gear == 0) && (speed <= m_speed) && (speed >= 0))
	{
		m_speed = speed;
		if (speed == 0)
		{
			m_direction = Direction::OnPlace;
		}
		return true;
	}
	if ((m_gear == 1) && (speed >= 0) && (speed <= 30) && (speed >= 0))
	{
		m_speed = speed;
		m_direction = Direction::Straight;
		return true;
	}
	if ((m_gear == 2) && (speed >= 20) && (speed <= 50) && (speed >= 0))
	{
		m_speed = speed;
		return true;
	}
	if ((m_gear == 3) && (speed >= 30) && (speed <= 60) && (speed >= 0))
	{
		m_speed = speed;
		return true;
	}
	if ((m_gear == 4) && (speed >= 40) && (speed <= 90) && (speed >= 0))
	{
		m_speed = speed;
		return true;
	}
	if ((m_gear == 5) && (speed >= 50) && (speed <= 150) && (speed >= 0))
	{
		m_speed = speed;
		return true;
	}
	return false;
}

int Car::GetSpeed() const
{
	return m_speed;
}

int Car::GetGear() const
{
	return m_gear;
}


Direction Car::GetDirection() const
{
	return m_direction;
}

bool Car::GetEngineState() const
{
	return m_isOnEngine;
}