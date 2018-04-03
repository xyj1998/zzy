#include "sound.h"
#include "screen.h"
#include <stdio.h>
#include <math.h>
//function definition of displayWAVheader()
void displayBar(char filename[]){
	FILE *fp;
	short int samples[SAMPLERATE];
	double sum_200,rms_80[80],dB;
	int i,j;
	WAVHeader myhdr;
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
		clearScreen();
	for(i=0; i<80; i++){
		for(j=0,sum_200=0.0;j<200;j++){
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] = sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);
#ifdef DEBUG
		printf("RMS[%d] = %10.4fdB\n", i,rms_80[i], dB);
#else
		bar(i, dB);
#endif
	}
}
void displayWAVheader(char filename[]){
	WAVHeader myhdr;
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL){
	printf("ERROR of opening file!\n");
	return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("subchunk 1 size: %d\n",myhdr.subchunk1Size);
	printf("audio format: %d\n",myhdr.audioFormat);
	printf("number of channels: %d\n",myhdr.numChannels);
	printf("sample rate: %d\n",myhdr.sampleRate);
	printf("byte rate: %d\n",myhdr.byteRate);
	printf("block align: %d\n",myhdr.blockAlign);
	printf("bits per sample: %d\n",myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("subchunk 2 size: %d\n",myhdr.subchunk2Size);
}
void printID(char id[]){
	int i;
	for(i=0;i<4;i++)
	printf("%c",id[i]);

	printf("\n");
}
