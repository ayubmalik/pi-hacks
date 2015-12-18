typedef char* led_screen_t;

led_screen_t init_screen();

void update_screen(led_screen_t, int screen_size, char *msg, int current_pos);

void write_screen(led_screen_t, int delay_in_ms);

void scroll(char *msg, int delay_in_ms);

void sleepms(int millis);
