// radians
#define angle_between_strips (PI/12)
#define num_strips (24)
// in inches
#define distance_between_LEDs (2.45)
#define LEDs_per_strip (150)
#define strips_per_bus (3)
#define LEDs_per_bus (LEDs_per_strip * strips_per_bus)
#define brightness_scalar (64)
#define LED_max_volts (5)
#define LED_max_amps (2500)
#define PIN_List \
    X(16) \
    X(17) \
    X(18) \
    X(19)
#define num_busses (4)