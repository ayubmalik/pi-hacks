#define SCREEN_SIZE 4

char* init_screen(int size);

void update_screen(char *screen, int screen_size, char *msg, int current_pos);

void write_screen(char *screen);
