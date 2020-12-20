# Social Distancing & Health Detector
Fall 2020
ECE M202A Project:

Team Members: Xuanan Yue(UID: 405629055), Chuang Yu(UID: 305629107)

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

## 5. Functions:
#### Distance Measuring
The HC-SR04 Ultrasonic distance sensor connected to the Arduino Nano 33 BLE Sensor board can measure the distance between the device user and the person being measured. In our design, we set the maximum distance to 6ft, which is the social distancing. If the distance between the measured person and the user is less than 6ft, the buzzer will be triggered with long beep warning. Additionally, we also applied the infrared thermometer sensor to the distance meauring function. The infraraed thermometer sensor will only measure the objects with a temperature greater than 36°C. In this case, we can guarantee that the device will only measure the human body temperature instead of the temperature of other objects. 


## 6. Timeline:
- Week4: Project introduction and research. Order components
- Week5: Sensors value collection and circuits setup
- Week6: Mock test on PC
- Week7: Cell Phone App design
- Week 8-9: Bluetooth wireless communication and device tests
- Week10: Final test and demo


## 7. Strengths, Weakness and Future Work:
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



## 8. Summary
In summary, we have successfully built a device composed of IR sensor, ultrasonic sensor and humidity sensor that could detect the distance between the user and the person in front, measure the temperature of that person, and measure the humidity of the environment. We have run multiple experiments and the results showed that the readings were stable and reliable in different settings. However, we are still working on the APP design right now for receiving multiple sets of data from our device. 






 

