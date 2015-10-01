/**
 * @file L9110_motor_driver.h
 * @brief Motor device driver for the l9110 h bridge motor shield.
 * @author Luke Edwards
 */
#include "motor_driver.h"

namespace Michelino
{
    class Motor : public MotorDriver
    {
    public:
        /*
         * @brief Class constructor.
         * @param IApin 
         * @param IBpin 
         */
        Motor(int IApin, int IBpin) 
            : MotorDriver(), motorIAPin(IApin), motorIBPin(IBpin), currentSpeed(0)
        {
        }

        void setSpeed(int speed)
        {
            currentSpeed = speed;
            if (speed > 0) {  //check the direction
                analogWrite(motorIAPin, currentSpeed); //set forward pin to PWM speed
	        digitalWrite(motorIBPin, LOW); //disengage brake
            }
            else if (speed < 0) { //check the direction
                digitalWrite(motorIAPin, LOW);// disengage brake
                analogWrite(motorIBPin, -currentSpeed); //set reverse pin to PWM speed
            }
	    else { //check the direction
                digitalWrite(motorIAPin, LOW); //engage brake
                digitalWrite(motorIBPin, LOW); //set speed pin to 0
            }
        }
        
        int getSpeed() const
        {
            return currentSpeed;
        }
        
    private:
       	int motorIAPin;
	int motorIBPin;
        int currentSpeed;
    };
};
