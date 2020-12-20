# Social Distancing & Health Detector
Fall 2020
ECE M202A Project:

Team Members: Xuanan Yue(UID: 405629055), Chuang Yu(UID: 305629107)
Link: 
## 1. Motivation:
Due to COVID-19 pandemic, most cities in the United States have made policies about social distancing(staying at least 6 feet away from others when possible). However, these policies are not strictly followed when people are not paying enough attention. For example, people tend not to remain at a safe distance with others when they are working on their cellphones, listening to music or concentrating on other things. Therefore, in order to practice this policy appropriately, our team came up with an idea of designing a device based on Arduino Nano 33 BLE Sense called Social Distancing & Health Detector. This detector has two basic features: Detecting the distance between the user and the person in front and measuring the temperature of that person. Another function of our device is that it can measure the humidity of the environment since high humidity can negatively affect the effectiveness of the masks. Furthermore, our device can connect to an APP on the user's smartphone to warn the user of close contact and transmit other useful information via Bluetooth. 

## 2. Abstract:
The main idea of this project is to design a device based on Arduino Nano 33 BLE Sense that can measure the distance between the user and the person in front. To keep safe social distancing, the Arduino board is going to be connected with IR and Ultrasonic sensors, which are used to measure the distance and body temperature of the person. To make the device user-friendly, the device will be connected to the app on cellphone via Bluetooth. By sending the warnings of high body temperature and insufficient social distance, the user is able to always keep social distance and know if others show symptoms of COVID-19. Additionally, the device can measure the user’s health conditions, such as heart rate, body temperature, etc.

## 3. Goals:
- Measuring the distance
- Measuring the body temperature of the person in front
- Measuring the humidity of the environment
- Measuring the user’s health conditions(body temperature, heart rate, etc) 

Other possible features when there are a group of users at a quarantine site:
- Cellphone APP that can warn the user based on the data from the detector
- GPS module to locate the users 
- Module to detect if the users takes the device off for a long time
- Alarms the medical personnel if the users are too close to others for a long time
- Conduct contact tracing if one of the users is tested positive 
	
	
## 4. Implementation:
- Arduino Nano 33 BLE Sense
- Bluetooth
- IR Sensor
- Ultrasonic Sensor 
- App Design
![whole](https://user-images.githubusercontent.com/72429957/102720457-53eed780-42a9-11eb-9bf3-b82ea8fe5888.jpg)

## 5. Functions:
- #### Project Diagram <img width="879" alt="diagram" src="https://user-images.githubusercontent.com/72429957/102720080-df1a9e00-42a6-11eb-8153-60af2243be5f.png">


- #### Distance Measuring [Demo Video](https://youtu.be/UINRYKL2Wlk)

The HC-SR04 Ultrasonic distance sensor connected to the Arduino Nano 33 BLE Sensor board can measure the distance between the device user and the person being measured. ![hr04](https://user-images.githubusercontent.com/72429957/102719415-daec8180-42a2-11eb-8fc9-74e256ade0a1.jpg)
In our design, we set the maximum distance to 6ft, which is the social distancing. If the distance between the measured person and the user is less than 6ft, the buzzer will be triggered with long beep warning. Additionally, we also applied the infrared thermometer sensor to the distance meauring function. The infraraed thermometer sensor will only measure the objects with a temperature greater than 36°C. In this case, we can guarantee that the device will only measure the human body temperature instead of the temperature of other objects. 

- #### Body Temperature Measuring [Demo Video](https://youtu.be/dmpkhwPQ704)
GY-MLX90614-DCI Long Distance Infrared Thermometer is used to measure the body temperature. ![thermal sensor](https://user-images.githubusercontent.com/72429957/102719703-5b5fb200-42a4-11eb-850a-c8e5e514f7a2.jpg)
```
float Adafruit_MLX90614::readTemp(uint8_t reg) {
  float temp;
  
  temp = read16(reg);
  temp *= .02;
  temp  -= 273.15;
  return temp;
}
```
Based on the datasheet, the sensor result has measurement resolution of 0.02°C and is aviailable in RAM, and is derived from RAM as: To(°K) = Toreg * 0.02. The result is calcaulated by following expressions: 1. Convert it to decimal value i.e. 0x3AF7 = 15095d. 2. Divide by 50 (or multiply by 0.02) i.e. 15095 / 50 = 301.9K (result is in Kelvin). 3. Convert K to °C i.e. 301.9 - 273.15 = 28.75°C. During testing, we found that the max safe body temperature cannot be set to 37.5°C due to environment temperature. After several testing cases, we set the temperature to 34.5°C. If the body temperature of the person being tested is greater than this value, the buzzer will be triggered and rush beep. At the same time, the red LED will be switched on to warn the user that person's body temperature is above the safe value and may be dangerous.  
In the demo video, becasue we live in different states and currently serious situation of COVID-19, we cannnot meet each other during week9-10. So we decided to use a candle to demo instead of human body temperature. 


## 6. Strengths, Weakness and Future Work:
#### Strength: 
- **Usefulness:** this device is very practical in light of the pandemic and people disregarding social distancing policy.
- **Size:** the size of our device is relatively small and thus make it easy to carry around.
- **Accuracy:** the readings were very accurate according to our experimental data.
- **Potential:** other meaningful features can be safely and easily added to our device and APP.

#### Weakness:
- **Package:** We did not package our device to make it a true wearable device to use.
- **Distance:** The measuring distance of the IR sensor is limited. 
- **APP:** The app is only at the early stage since we are still working on it.

#### Future Work: 
We will include more features of our device. Firstly, we might assign each device an identification number and distribute this device to many people in the city. When two devices are close enough, they will both record each other's ID and send this to the cloud, which is closely monitored by assigned medical personnel. The cloud will store this information of close contacts. If someone is unfortunately designated as positive of COVID19, the cloud can quickly do the contact tracing by sending an alert to each person's cellphone via the APP we have designed. Secondly, we will include another features for measuring the user's own health conditions like heart rate and temperature. If these readings are showing symptoms of COVID19, the device will send an alert to the user's APP and report this suspicious case to the cloud.


## 7. Contribution:
Xuanan Yue: Xuanan is responsible for the distance measuring and testing part. Physical connection of the board. App design. Humandity sensor testing. 

Chuang Yu: Chuang is responsible for comparing and selecting components we need in this project. Writing code for the IR sensor and testing. App design. 


## 8. Summary
In summary, we have successfully built a device composed of IR sensor, ultrasonic sensor and humidity sensor that could detect the distance between the user and the person in front, measure the temperature of that person, and measure the humidity of the environment. We have run multiple experiments and the results showed that the readings were stable and reliable in different settings. However, we are still working on the APP design right now for receiving multiple sets of data from our device. 

### 9. Reference
- https://www.digchip.com/datasheets/parts/datasheet/287/MLX90614ESF-DCI-000-SP-pdf.php
- https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
- https://www.arduino.cc/en/Guide/NANO33BLESense





 

