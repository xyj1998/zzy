#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

int main(void){
	while(1){
	//record 1sec of sound into test.wav
	system("arecord -q -r16000 -c1 -f s16_LE -d1 test.wav");
	//open the wav file and read samples
	 displayWAVheader("test.wav");
	//display necessary information (duration, wav header etc)
	//calculate fast dBs
	dispalyBar("test.wav");
	//send fast dBs to web (ph program on www.cc.puv.fi)
	break;//for tasting,just run the loop once
	}
}
