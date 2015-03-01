#define motionSensor 2//Use pin 2 to receive the signal from the motion
#define lightSensor A0// Use analog pin 0 to recive signal from light sensor
#define LED	13// LED light output 

void setup()
{
	pinsInit();
}

void loop() 
{
	if(isMotionDetected() && !isLightDetected())//if the sensor detects movement and light is poor, turn on LED.
		turnOnLED();
	else//if the sensor does not detect movement or light is high , do not turn on LED.
		turnOffLED();
}
void pinsInit()
{
	pinMode(motionSensor, INPUT);
	pinMode(LED,OUTPUT);

}
void turnOnLED()
{
	digitalWrite(LED,HIGH);
        delay(5000);
}
void turnOffLED()
{
	digitalWrite(LED,LOW);
}

boolean isMotionDetected()
{
	int sensorValue = digitalRead(motionSensor);
	if(sensorValue == HIGH)//if motion is detected
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean isLightDetected ()
{
       int sensorValue = analogRead(lightSensor); 
       if (sensorValue > 80)// if resistance ammount on light sensor is more than number. Higher Value == More Light
       {
         return true;
       }
       
       else
       {
         return false;
       }
}
         
