//ActivityBot code here

#include "simpletools.h"                      // Include libraries
#include "fdserial.h"
#include "abdrive.h"

fdserial *xbee;

int main()                                    // Main function
{
  xbee = fdserial_open( 9, 8, 0, 9600 ); //Begin the serial connection ( this is why we needed the jumper cables connected to pins 8 and 9 )

  char data; //Create the variable that will be used to hold the incoming data

  while ( 1 ) //repeat this forever or until loss of power
  {
    if ( ( data = fdserial_rxChar( xbee ) ) ) //set data to the data received from the XBee board
    {
      if ( data == 'f' ) //If the data incoming is telling the robot to move forward
      {
        drive_speed( 128, 128 ); //move forward at 1/2 speed
      } else if ( data == 'b' ) //If the data incoming is telling the robot to move backward
      {
        drive_speed( -128, -128 ); //move backward at 1/2 speed
      } else if ( data == 'l' ) //If the data incoming is telling the root to turn left
      {
        drive_speed( 0, 128 ); //turn left in a spin turn at 1/2 speed
      } else if ( data == 'r' ) //If the data incoming is telling the robot to turn right
      {
        drive_speed( 128, 0 ); //turn right in a spin turn at 1/2 speed
      } else if ( data == 's' ) //If the data incoming is telling the robot to stop
      {
        drive_speed( 0, 0 ); //stop
      }
    }
  }
}
