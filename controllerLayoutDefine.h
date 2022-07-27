// Define circuit type used for switch
#define circuit_C1 INPUT         // switch circuit requires an external pull down 10k ohm resistor
#define circuit_C2 INPUT_PULLUP  // switch type reqires no other components beyond the button switch

// define characterisitcs of switches
#define debounce 100  // number of millisecs to wait for a switch to settle once activated
#define switched true  // signifies switch has been pressed/switch cycle complete
#define on true        // used for toggle switch staus
#define not_used true  // helps self document code

//define switch type
#define button_switch 1  
#define toggle_switch 2

//define button switches
#define apertureP 22
#define apertureN 23
#define isoP 24
#define isoN 25
#define shutterSpeedP 26
#define shutterSpeedN 27
#define menu 28
#define up 29
#define down 30
#define left 31
#define right 32
#define select 33
#define playBack 34
#define triggerAF 35
#define shutter 36
#define recVideo 37
#define customOne 38
#define customTwo 39
#define customThree 40
#define customFour 41

//define toggle switch
#define cameraAPwr 42
#define cameraBPwr 43
#define cameraSelect 44
#define lightAPwr 45
#define lightBPwr 46
#define micRecord 47
#define videoTransmitPwr 48
#define drivePwr 49
#define shutterSelect 50

// define number of switches used
#define num_switches 29  // number of button switches connected


