# Inspirobot-X

## Team Members

* Ishika Banga(2401010216)
* Piyush Mishra(2401010293)
* Ankit Kumar(2401010246)
* Muskan(2401010239)

## Project Description

Inspirobot-X is an autonomous ground-based robotic system designed for real-time infrastructure inspection and maintenance. It enhances safety, accuracy, and cost-efficiency in hazardous and hard-to-reach environments, minimizing human intervention and improving operational efficiency.

## Link to Video Explanation



## Technologies Used

* Python
* C++
* OpenCV
* ROS (Robot Operating System)
* Arduino
* Sensor Integrations
* **Air Quality Sensor (e.g., MQ-135):** Monitors pollutants like CO2 and other harmful gases.
* **Chassis & Wheels:** Durable and terrain-friendly mobility.
* **Temperature Sensor (e.g., DHT22):** Detects heat levels.
* **Smoke Sensor (e.g., MQ-2):** Detects smoke and carbon dioxide levels.
* **Microcontroller (e.g., Arduino or Raspberry Pi):** Central control unit for all sensors.

## Steps to Run/Execute the Project

1. **Clone the repository**

   ```bash
   git clone https://github.com/IshikaBanga26/Inspirobot-X.git
   cd Inspirobot-X
   ```

2. **Install the required dependencies**

   ```bash
   pip install -r requirements.txt
   ```

3. **Upload the Arduino Code** (if applicable)

   * Navigate to the Arduino folder
   * Open the .ino file in the Arduino IDE
   * Select the correct port and upload to the Arduino

4. **Run the ROS Nodes**

   ```bash
   roslaunch inspirobot_x main.launch
   ```

5. **Start the Inspection Process**

   * Use the controller interface or the autonomous mode to start inspection.

6. **View the Live Stream and Logs**

   * Open the visual interface to monitor real-time progress and logs.

7. **Shutdown Process**

   * Press `Ctrl+C` to terminate the program gracefully.




