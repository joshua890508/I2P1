#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 600;
const int HEIGHT = 900;

ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;
bool* mouse_state;// Mouse position.
int next = 0;
