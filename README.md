# ChickenCoopAutoDoor
uses esp32 to open and close a door based on contents of Google sheets cell

This project uses and esp32 development board to communicate with Google sheets.  The motor state is dependent on the contents of the sheets command cell (a2) in my case.  
THe cell can be changed 3 ways.  
  - using Google SHeets
  - using a trigger that calls the CloseDoor.gs/OpenDoor.gs  (i used a time based trigger but there are many options)
  - by creating and using APP Sheets to create an app that is connected to your Sheets

equipment:  
  - esp32 or other wifi enabled development board
  - 2 reed switches
  - 12 volt geared DC motor
  - l298 motor relay
  - 
optional equipment:
  - solar panel
  - solar control charger
  - 12 battery

Created by Justin Pursley

Feel free to use and modify to fit your needs. 
If you see any security issues let me know at jpurs007@gmail.com
Use at your own risk.
