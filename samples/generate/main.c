/*
********************************************************************************	
*	Title: NMEA string for FIFO
*	Author: Nayan Patel
*	Decription: This application generate the NMEA string as per below details
********************************************************************************
*	Speed		Latitude step		Longitude Step
*	180kmph     0000.026973			0000.000000
*	150kmph		0000.022480			0000.000000
*	120kmph		0000.017984			0000.000000
*   90kmph		0000.013488			0000.000000
*	72kmph		0000.010789			0000.000000			
*	60kmph		0000.008992			0000.000000
*	36kmph		0000.005394			0000.000000
*	30kmph 		0000.004496			0000.000000
*
********************************************************************************
*	usage: ./GPS_sim <speed-180|150|120|90|60|30> <KMDistance> <Lat-2342> <long-7200> 
*		 	./GPS_sim 90 5 2342 7200 \n
*
*/

#include <nmea/nmea.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef NMEA_WIN
#   include <windows.h>
#else
#   include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    nmeaINFO info;
    char buff[65536];
    int gen_sz,it;
    int fd,i = 0;
    float latstep,longstep;
    
    
    char *myfifo = "/tmp/.myfifo";
    
    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);
    
    /* write GPS string to the FIFO */
    fd = open(myfifo, O_WRONLY);
		
    nmea_zero_INFO(&info);
	info.sig = 1;
    info.fix = 1;
    info.speed = 2.14 * NMEA_TUS_MS;
    info.elv = 10.86;
    info.satinfo.inuse = 7;
    info.satinfo.inview = 12;
        
   	info.lat = 5183.919000;
	info.lon = 0569.061000;
	latstep= 0000.026973;
	longstep = 0000.000000;  

    if(argc == 2)
    {  	
    	switch (atoi(argv[1])) 
    	{
        	case 180:
        		latstep= 0000.026973;
	            break;
        	case 150:          
				latstep= 0000.022480;
            	break;
	        case 120:         
				latstep= 0000.017984;				
            	break;
	        case 90:        
				latstep= 0000.013488;
	            break;
			case 60:        
				latstep= 0000.008992;
	            break;
			case 30:        
				latstep= 0000.004496;
	            break;
	        default:            
	            break;
    	}
    }
	else if(argc==3)
	{
	    info.lat = atoi(argv[1]);
		info.lon = atoi(argv[2]);
	}
	else if(argc==4)
	{
		info.lat = atoi(argv[1]);
		info.lon = atoi(argv[2]);
		
		switch (atoi(argv[3])) 
    	{
        	case 180:
        		latstep= 0000.026973;
	            break;
        	case 150:          
				latstep= 0000.022480;
            	break;
	        case 120:         
				latstep= 0000.017984;				
            	break;
	        case 90:        
				latstep= 0000.013488;
	            break;
			case 60:        
				latstep= 0000.008992;
	            break;
			case 30:        
				latstep= 0000.004496;
	            break;
	        default:            
	            break;
    	}
	}

   	while(1)
    {
		//  to get any string among GPGGA | GPGSA | GPGSV | GPRMC | GPVTG -- add in the function call	
		gen_sz = nmea_generate( &buff[0], 2048, &info, GPGGA | GPRMC);
		buff[gen_sz] = 0;
		
		//write the generated NMEA string to the FIFO
		write(fd, buff, strlen(buff));
		sleep(1);
		
		info.speed += .1;
		info.lat+=latstep; // increment the latitude value
		info.lon+=longstep; // increment the longitude value
    }
	unlink(myfifo);
	return 0;
}
