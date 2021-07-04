/*This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. 
To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/deed.en */

#define C3 523
#define S_C3 523
#define D3 1
#define E3  1
#define F3 1
#define G3 1
#define A3 1
#define B3 1

#include "chimes.h"
using namespace Chimes;
//Sum of ADSR values must not exceed 100%
uint8_t envelope[] = {
	0,  //attack[%]
	50, //decay[%]
	80,  //sustain[%]
	0, //release[%]
	16  //Sustain Level 1..32
};

void setup()
{
	init(
		SINE, //TRI: Triangle, RECT: Rectangle
		50,  //duty cycle 0..100%, only matters for Triangle and Rectangle
		envelope);
}

uint16_t melody[][2] = {{330, 1000}, {415, 1000}, {370, 1000}, {247, 1000}, {0, 1000}, {330, 1000}, {370, 1000}, {415, 1000}, {330, 1000}, {0, 1000}, {415, 1000}, {330, 1000}, {370, 1000}, {247, 1000}, {0, 1000}, {247, 1000}, {370, 1000}, {415, 1000}, {330, 1000}};

void loop()
{
	static int i = 0;
	if (i < 19 && !isPlaying())
	{
		play(melody[i][0], melody[i][1]);
		i++;
	}

  if (i >= 19 && !isPlaying())
  {
    
    init(
    TRI, //TRI: Triangle, RECT: Rectangle
    50,  //duty cycle 0..100%, only matters for Triangle and Rectangle
    envelope);
    play(melody[1][0], melody[1][1]);
    
  }


    
}
