#define NUM_LEDS 4
#define NUM_SEGMENTS 8

extern const int char_map[][NUM_SEGMENTS];

int pi_init();

int pi_reset();

void pi_write_char(int pos, char c);

void pi_all_leds_off();

