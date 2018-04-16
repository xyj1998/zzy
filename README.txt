#---------------------------------------- SOUND RENSOR PROJECT -----------------------------------------

This project is meant to collect sound level at a proximity of a Respberry pi
device. The RPi is equipped with a USB sound card (C-Media Electronics,Inc.
Audio Adapter) and a microphone. The sound is recored at 16000Hz sample rate
and every second will produce 80 pleces of RMS value as a bar-diagram...

Table of Content
1. Configuration
	We need a computer,a Raspberry Pi3,a SD card,an USB cable,an internat cable,an USB sound card,
	a HDMI cable,a microphone.
	STEP 1 Connection:We should set the Raspberry Pi3.We use the HDMI cable connect the Pi and screen.
	and connect the keyboard and mouse on Pi.After that we could start to set the Pi.
	STEP 2 SETTING The Pi:1.Reboot "sudo reboot",after the reboot
						  2.run command "sudo nano /etc/rc.local"
						  3.Add following lines:
							#!/bin/sh -e
							#
							# rc.local
							#
							# This script is executed at the end of each multiuser runlevel.
							# Make sure that the script will "exit 0" on success or any other
							# value on error.
							#
							# In order to enable or disable this script just change the execution
							# bits.
							#
							# By default this script does nothing.
							
							# Print the IP address
							sleep 30
							
							_IP=$(hostname -I) || true
							if [ "$_IP" ]; then
							  printf "My IP address is %s\n" "$_IP"
							    curl --url http://www.cc.puv.fi/~your own name/php/sendMailRPi.php -d email=your own email=your own name
							      curl --url http://www.cc.puv.fi/~your name/php/rasp.php -d "ip=$_IP&name=gcPi3"
							        curl --url http://www.cc.puv.fi/~juma/raspi/rasp_ip.php -d "auth=mckdoe03&name=gcPi3&ip=$_IP"
							        fi
							        
							        exit 0
						  4.Set USB Sound Card as Default
						    1.	Boot up RPi, and apply the USB sound card.
						    2.	RPi onboard sound card doesn.t have microphone interface. We have to change the default audio device to be USB sound card.
						    3.	Use "lsusb" command to check if your USB sound card is mounted:
						    4.	Use "sudo nano /etc/asound.conf"command and put following content to the file:
																									pcm.!default {
																										  type plug
																									    slave {
																								        pcm "hw:1,0"
																									          }
																							          }
																							          ctl.!default {
																							              type hw
																											 card 1
																					                  }
						    5.	Go to your home directory. Use "nano asoundrc" command and put the same content to the file.
						    6.	Run "alsamixer" you should be able to see that USB sound card is the default audio device.
						  5. Fix the Bug of arecord
						    1.	The newest version of Raspbian (a.k.a. Jessie) comes with a new version of alsa-utils (1.0.28), which has a bug while 
						        recording: it doesn.t stop even a ..duration' switch is given, and generates lots of useless audio files. To fix this problem, 
						        we have to downgrade alsa-util to an earlier version (1.0.25).
			                2.	Use "sudo nano /etc/apt/sources.list" command and add the last line:
						    3.	Run "sudo apt-get update"
						    4.	Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-util is available:
						    5.	Run "sudo apt-get install alsa-utils=1.0.25-4. to downgrade"
						    6.	Reboot (if necessary)
						    7.	Run "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test that your microphone is working. You should see a .test.wav. file in the current folder.
						    8.	Put earphone on. Run "aplay test.wav" to check that your recording is okay.
						     
2. Installation
				-Put your SD card into your raspberry
				-Connect the raspberry to the internet by a internet cable
				-Connect the sound card to the raspberry
				-Connect the Microphone to the sound card
				-Connect the raspberry to the power souce by an USB cable
3. Operation
	When you have connect the respberry to computer you will get an email that is your address.And use this address to sign in to the putty.
	When you finish all the files you will use "make" comman and there will be a new file named "sound.a"
4. Manifest (list of files and short description of their roles)
    main.c 
    comm.c 
    comm.h
    makefile 
    README.txt 
    README.md 
    screen.c 
    screen.h 
    sound.c 
    sound.h 
    final.tar 
    testcurl.c
5. License
	 <one line to give the program's name and a brief idea of what it does.>
     Copyright (C) <year>  <name of author>
	 This program is free software: you can redistribute it and/or modify
	 it under the terms of the GNU General Public License as published by
	 the Free Software Foundation, either version 3 of the License, or
	 (at your option) any later version.
	 This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <https://www.gnu.org/licenses/>.
6. Contact information(xianxixinxi)
ZhangZeyu
Department of information technology
VASSA Univercity of Applied Sciences
Home:http://www.cc.puv.fi/~e1700707
Email:707657418@qq.com
