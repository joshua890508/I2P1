#include "global.h"

// variables for global usage
const float FPS = 60.0;
const float WIDTH = 600.0;
const float HEIGHT = 900.0;

const float LEFT = 120.0;
const float MIDDLE = 300.0;
const float RIGHT = 480.0;

ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
ALLEGRO_SAMPLE*song=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance;
ALLEGRO_SAMPLE*song2=NULL;
ALLEGRO_SAMPLE_INSTANCE*sample_instance2;
ALLEGRO_DISPLAY*display = NULL;
ALLEGRO_FONT *font = NULL;
bool judge_next_window = false;
bool* mouse_state;// Mouse position.
bool pause=false;

int next=0;
int score;
char s[20000];
int coin=0;
char c[20000];

bool longneck = false;
bool penguin = false;
bool dog = false;

MovableObject chara;
MovableObject nose[50];


