NMEA library

Introduction
We present library in 'C' programming language for work with NMEA protocol. Small and easy to use. The library build on different compilers under different platforms (see below). The code was tested in real projects. Just download and try...

Usage
* This is a GPS simulator application, as you can provide dynamic GPS NMEA string at 1Hz Frequency.
* Here, we have used Linux IPC mechanism FIFO. By running this application, /tmp/.myfifo node will be created. 
* This producer application will broadcast NMEA string at a second interval. Based on the requirement, you can have consumder application which can read NMEA string from /tmp/.myfifo and 
  parse it based on the requirement. 
* Use build.sh library to create GPS simulator application for. It will create gps_v2.0 binary.
* To give dynamic spped and latitude longitude, provide command line argument's as per following.

1 ./gps_v2.0 <kmphspeed>		// Speed should be in multiple of 30 and maximum 180, else default 180 will be taken.

	#./gps_v2.0 60
	
2. ./gps_v2.0 <lat> <long>		// Provide lat long first four digits without decimals to give dynamic start location.

	#./gps_v2.0 2342 7200
	
3. ./gps_v2.0 <lat> <long> <kmphspeed>	// To give speed and dynamic start location.

	#./gps_v2.0 2342 7200 90

Features
- Analysis NMEA sentences and granting GPS data in C structures
- Generate NMEA sentences
- Supported sentences: GPGGA, GPGSA, GPGSV, GPRMC, GPVTG
- Multilevel architecture of algorithms
- Additional functions of geographical mathematics and work with navigation data

Supported (tested) platforms
- Microsoft Windows (MS Visual Studio 8.0, GCC)
- Windows Mobile, Windows CE (MS Visual Studio 8.0)
- UNIX (GCC)

Licence: LGPL

Disclaimer
The National Marine Electronics Association (NMEA) has developed a specification that defines the interface between various pieces of marine electronic equipment. The standard permits marine electronics to send information to computers and to other marine equipment. Most computer programs that provide real time position information understand and expect data to be in NMEA format. This data includes the complete PVT (position, velocity, time) solution computed by the GPS receiver. The idea of NMEA is to send a line of data called a sentence that is totally self contained and independent from other sentences. All NMEA sentences is sequences of ACSII symbols begins with a '$' and ends with a carriage return/line feed sequence and can be no longer than 80 characters of visible text (plus the line terminators).
