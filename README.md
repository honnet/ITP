# Wireless and Tangible Interactive Media _at the era of the "Internet of Shit"_

<img align="right" width="200" src="https://itp.nyu.edu/camp2018/images/session_photos/large/session_134.png">

This repo contains Arduino and Processing code to control a visualization using:

- an MPU-6050 motion sensor (with accel + gyro)

- a Wemos, an Arduino compatible board with WiFi (using ESP8266)

- the OSC protocol to communicate with a computer


## INSTALLATIONS

### ARDUINO

0) If you don't have Arduino, download it:
[arduino.cc/en/main/software](https://www.arduino.cc/en/main/software)

1) If you use Mac or Windows, you need drivers:
[wiki.wemos.cc/downloads](https://wiki.wemos.cc/downloads)

2) If you never used ESP8266 with your Arduino IDE you need to follow this procedure:

[github.com/esp8266/Arduino#installing-with-boards-manager](https://github.com/esp8266/Arduino#installing-with-boards-manager) (but you can stop before the "Using git version", unless you want to contribute to their work).

3) If you never used the MPU-6050 or OSC in Arduino, use the following keywords in the Library Manager:

 - *MPU6050_tockn*

 - *OSC (Open Sound Control)* by Adrian Freed and Yotam Mann

It will allow you to install these libraries, here is the procedure:

[arduino.cc/en/Guide/Libraries#toc3](https://www.arduino.cc/en/Guide/Libraries#toc3)


### PROCESSING

0) If you don't have it, download Processing: [processing.org/download](https://processing.org/download)

1) As in the Arduino section, go to `Sketch -> Import Library... -> Add Library...` to install the following libraries:

 - *oscP5* by Andreas Schlegel

 - *controlP5* by Andreas Schlegel


## USAGE

### HELLO WORLD?

0) Close the Arduino IDE, unplug and replug your Wemos board, then re-open the Arduino IDE (it can help for many problems)

1) Select the port *at the bottom of the list* of `Tools -> Port` (or the latest that appeared at least), it looks like:

 - OS X: /dev/cu...

 - Linux: /dev/tty...

 - Win: COM...

2) Select your board: `Tools -> Board -> LOLIN (WEMOS) D1 R2 & mini`

3) In the Arduino IDE, open the ESP8266 blink example from
`File -> Examples -> ESP8266 -> Blink`

4) Upload the code (command-U / ctrl-U)

5) Change the delay times (ex: remove a zero), the blue LED should blink at a different speed.


### TESTS

#### Sensing

0) Upload the Arduino file in the `1_tests/a_sensor` folder

1) Open `Tools -> Serial Monitor`, you should observe values

2) Open `Tools -> Serial Plotter`  you should observe a graph of these values (shake the accelerometer!)

3) Challenge: modify the Serial.print(...) section to trace these values in ASCII
(hint: amplify the measured value in a "for loop")


#### Communicating

0) Create an access point in your phone:

 - iOS: [support.apple.com/en-us/HT204023](https://support.apple.com/en-us/HT204023)

 - Android: [https://www.wikihow.tech/Turn-Your-Android-Phone-Into-a-Wi‐Fi-Hotspot](https://www.wikihow.tech/Turn-Your-Android-Phone-Into-a-Wi‐Fi-Hotspot)

1) Get your computer's local IP with ifconfig (Mac/Linux) or ipconfig (Windows)

2) Open the Arduin file in the `1_tests/b_communication/arduino/` folder, put your WiFi
login/password, your IP address (look for `IPAddress outIp(192.168...)`), and upload...

3) Open the Processing sketch in `1_tests/b_communication` and run it
(command-R / ctrl-R)

4) If both your computer and the Wemos are connected to the same network, some values should appear in the console part of Processing (black background), they actually came by WiFi!

5) Optional challenge: send a String message from the Wemos over OSC and print it in the console (see documentation section below)


### VISUALIZATION
<img align="right" width="300" src="https://farm2.staticflickr.com/1784/42817121852_6db390bffd_z_d.jpg">

Now that we can sense and communicate, let's use the data!

0) As earlier, open the *Arduino* file in the `2_play` folder, put your WiFi
login/password, your IP address, and upload...

1) Open the *Processing* sketch in the `2_play` folder and run it, now you know...

2) Challenge: make it your own, change the color, the speed, or the entire visualization!

Credit: the visualization is derived from the work by Andreas Schlegel, more info here:

[github.com/sojamo/Movement-of-Things](https://github.com/sojamo/Movement-of-Things)


### MORE CHALLENGES!

#### Make noise

- With Processing:

[github.com/processing/processing-sound/blob/master/examples/Oscillators/SawWave/](https://github.com/processing/processing-sound/blob/master/examples/Oscillators/SawWave/)

[github.com/processing/processing-sound/blob/master/examples/Demos/SineCluster/](https://github.com/processing/processing-sound/blob/master/examples/Demos/SineCluster)

[github.com/processing/processing-sound/blob/master/examples/Effects/Filter/BPF](https://github.com/processing/processing-sound/blob/master/examples/Effects/Filter/BPF)

- With Sonic Pi: [sonic-pi.net/tutorial.html#section-12-1](https://sonic-pi.net/tutorial.html#section-12-1)


#### Play with javascript

- [github.com/adzialocha/osc-js](https://github.com/adzialocha/osc-js#example-osc-between-maxmsppdsc-etc-and-your-browser)

- [github.com/genekogan/p5js-osc/tree/master/p5-basic](https://github.com/genekogan/p5js-osc/tree/master/p5-basic)


#### Motion recognition

- [wekinator.org](http://www.wekinator.org)

- [nickgillian.com/wiki/pmwiki.php/GRT/GestureRecognitionToolkit](http://www.nickgillian.com/wiki/pmwiki.php/GRT/GestureRecognitionToolkit)

- [Example-based Sensor Predictions](https://github.com/damellis/ESP)

#### Play with the ESP8266 examples!

Try them all but this board can even host a webserver for instance:

`File -> Examples -> ESP8266WebServer`


## DOCUMENTATION

[arduino.cc/reference](https://arduino.cc/reference)

[arduino-esp8266.readthedocs.io/en/latest](https://arduino-esp8266.readthedocs.io/en/latest)

[wiki.wemos.cc/products:d1:d1_mini](https://wiki.wemos.cc/products:d1:d1_mini)

[processing.org/reference](https://processing.org/reference)

[sojamo.de/libraries/oscP5/reference/oscP5/OscMessage.html](http://www.sojamo.de/libraries/oscP5/reference/oscP5/OscMessage.html)


## POTENTIAL PROBLEMS

### OSX DRIVER

If the board doesn't appear in Arduino for OSX, the follwoing links should help:

[mblock.cc/docs/run-makeblock-ch340-ch341-on-mac-os-sierra](http://www.mblock.cc/docs/run-makeblock-ch340-ch341-on-mac-os-sierra)

[github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver#ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver#ch340g-ch34g-ch34x-mac-os-x-driver)

[https://sparks.gogo.co.nz/ch340.html](https://sparks.gogo.co.nz/ch340.html)



### UPLOAD ERROR

If you get `espcomm_open failed`, try again, restart Arduino, check the connection and the cable, use another USB plug...

...and if it persists, use a slower upload speed in `Tools -> Upload Speed`


### LINUX ERROR

`cannot access [serial port]`

This might help:

    sudo usermod -a -G dialout $USER  # needs logout  (it might be plugdev too)

Or make a udev file:

    RULES='SUBSYSTEMS=="usb", ATTRS{idProduct}=="7523", ATTRS{idVendor}=="1a86", MODE:="0666", GROUP="plugdev"'
    echo $RULES | sudo tee /etc/udev/rules.d/30-HL-340.rules
    sudo restart udev

