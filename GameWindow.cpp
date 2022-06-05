#include "GameWindow.h"

enum {
	SCENE_MENU = 1,
	SCENE_GAME = 2,
	SCENE_ABOUT = 3,
    SCENE_HOWTOPLAY = 4,
    SCENE_STORE = 5,
    SCENE_ITEM = 6,
    SCENE_WIN = 7,
    SCENE_PAUSE = 8,
    SCENE_GAMEOVER = 9,
};

bool draw = false;
int window = SCENE_MENU;

const char *title = "Final Project 10xxxxxxx";

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;

int Game_establish() {
    int msg = 0;

    game_init();
    game_begin();

    while ( msg != GAME_TERMINATE ) {
        msg = game_run();
        if ( msg == GAME_TERMINATE )
            printf( "Game Over\n" );
    }
    game_destroy();
    return 0;
}

void game_init() {
    printf( "Game Initializing...\n" );
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps  = al_create_timer( 1.0 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;

    const unsigned m_buttons = al_get_mouse_num_buttons();
	mouse_state = (bool*)malloc((m_buttons + 1) * sizeof(bool));
	memset(mouse_state, false, (m_buttons + 1) * sizeof(bool));
    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.jpg");
    al_set_display_icon(display, icon);
}

void game_begin() {
    // Load sound
    song = al_load_sample("./sound/BGM.wav");
    al_reserve_samples(20);
    sample_instance = al_create_sample_instance(song);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1) ;
    al_play_sample_instance(sample_instance);
    al_start_timer(fps);
    // initialize the menu before entering the loop
    menu_init();
}
void game_update(){
    if( judge_next_window ){
        if( window == SCENE_MENU ){
            if(next==SCENE_GAME)
            {
                game_scene2_init();
                judge_next_window = false;
                window = 2;
            }else if(next==SCENE_ABOUT)
            {
                game_scene3_init();
                judge_next_window = false;
                window = 3;
            }else if(next==SCENE_HOWTOPLAY)
            {
                game_scene4_init();
                judge_next_window = false;
                window = 4;
            }else if(next==SCENE_STORE)
            {
                game_scene5_init();
                judge_next_window = false;
                window = 5;
            }
        }
        else if( window == SCENE_ABOUT || window == SCENE_HOWTOPLAY){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
        }
        else if( window == SCENE_STORE){
            if(next==SCENE_ITEM)
            {
                game_scene6_init();
                judge_next_window = false;
                window = SCENE_ITEM;
            }else if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
        }
    }
    if( window == SCENE_GAME ){
        charater_update();
    }
}
int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( window == SCENE_MENU ){
        menu_process(event);
    }else if( window == SCENE_GAME ){
        charater_process(event);
    }else if( window == SCENE_ABOUT || window == SCENE_HOWTOPLAY){
        about_process(event);
    }else if( window == SCENE_STORE){
        store_process(event);
    }

    // Shutdown our program
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    if(draw) game_update();
    return 0;
}
void game_draw(){
    if( window == 1 ){
        menu_draw();
    }else if( window == 2 ){
        game_scene2_draw();
    }else if( window == 3 ){
        game_scene3_draw();
    }else if( window == 4 ){
        game_scene4_draw();
    }else if( window == 5 ){
        game_scene5_draw();
    }else if( window == 6 ){
        game_scene6_draw();
    }
    al_flip_display();
}
int game_run() {
    int error = 0;
    if( draw ){
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    game_scene2_destroy();
    free(mouse_state);
}
