#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 600;
const int HEIGHT = 900;

const int MIDDLE = WIDTH/2;
const int LEFT = MIDDLE-180;
const int RIGHT = MIDDLE+180;

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

int nowchar = 1;
bool longneck = false;
bool penguin = false;
bool dog = false;

bool nowitem[4] = {0};
bool hat=false;
bool butterfly=false;
bool cry=false;
bool thunder=false;

MovableObject chara;
MovableObject nose[50];


