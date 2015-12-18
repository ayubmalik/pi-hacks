#define NUM_LEDS 4
#define NUM_SEGMENTS 8

//extern const int pi_leds[];

//extern const int segments[];

extern const int char_map[][NUM_SEGMENTS];

int pi_init();

int pi_reset();

void pi_write_char(int pos, char c);

