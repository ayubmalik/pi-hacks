typedef char* screen_t;

screen_t screen_init();

void screen_update(screen_t, int screen_size, char *msg, int current_pos);

void screen_scroll(char *msg, int delay_in_ms);

void sleepms(int millis);

