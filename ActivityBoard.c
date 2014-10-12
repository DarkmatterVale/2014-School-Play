//ActivityBoard code here

#include "simpletools.h"                      // Include simple tools
#include "fdserial.h"
#include "adcDCpropab.h"

fdserial *xbee; //Initialize the full-duplex serial connection over XBee

int main()
{
  xbee = fdserial_open( 9, 8, 0, 9600 ); //open the serial connection
  adc_init( 21, 20, 19, 18 ); //initialize the analogue connections for the joystick

  float lrV, udV; //create 2 float values for incoming joystick values

  while ( 1 )
  {
    udV = adc_volts( 2 ); //get values from the joystick
    lrV = adc_volts( 3 );

    if ( udV < 1.00 ) //if joystick going backward, send backward value
    {
      dprint( xbee, "b" );
    } else if ( udV > 4.00 ) //if joystick going forward, send forward value
    {
      dprint( xbee, "f" );
    } else if ( udV < 4.00 && udV > 1.00 && lrV < 4.00 && lrV > 1.00 ) //if joystick is in center, send stop value
    {
      dprint( xbee, "s" );
    } else if ( lrV < 1.00 ) //if joystick is going left, send left value
    {
      dprint( xbee, "l" );
    } else if ( lrV > 4.00 ) //if joysitck is going right, send right value
    {
      dprint( xbee, "r" );
    }

    pause( 50 ); //only need to check joystick values 20 times a second
  }
}
