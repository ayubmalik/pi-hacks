extern const int digits[];

extern const int segments[];

#define NUM_SEGMENTS 8
extern const int char_map[][NUM_SEGMENTS];

int pi_init();

int pi_reset();

void pi_write_char(char c);

