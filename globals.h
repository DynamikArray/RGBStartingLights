//Lights Setup
#define PIN_LED        4
#define NUM_LEDS       60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);
uint32_t RED = strip.Color(255, 0, 0);
uint32_t YELLOW = strip.Color(255, 255, 0);   //255,255,0
uint32_t  GREEN = strip.Color(0, 55, 0);
uint32_t  BLACK = strip.Color(0, 0, 0);

//Blink Interval
#define BLINK_INTERVAL 100

//Sensors Setup
#define MAX_DISTANCE 200  // Maximum distance we want to measure (in centimeters)
#define STAGING_HEIGHT_TRIGGER 45
#define STAGING_DETECTION_TIME .5

//Sensor Setup Lane 1
#define TRIGGER_PIN_1 17
#define ECHO_PIN_1 18

//Race control statges
enum RACING_STATES { WAITING,
                    PRESTAGE,
                    STAGED,
                    COUNTDOWN };

//initilize raceState in waiting mode
RACING_STATES raceState = WAITING;

//define staging stages
enum STAGING_STATES { EMPTY,
                     READY };    

STAGING_STATES stagingState[1];  

unsigned long timerForSensor;



