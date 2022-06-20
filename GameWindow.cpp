#include "GameWindow.h"

bool draw = false;
int window = SCENE_MENU;

const char *title = "LONG LONG FRIENDS";

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
    al_set_window_position(display, 600, 30);
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
    fps  = al_create_timer( 2.5 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;
    // mouse
    const unsigned m_buttons = al_get_mouse_num_buttons();
	mouse_state = (bool*)malloc((m_buttons + 1) * sizeof(bool));
	memset(mouse_state, false, (m_buttons + 1) * sizeof(bool));
    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.png");
    al_set_display_icon(display, icon);
    // preload animation for scene8&9
    win_gif = (GIF*)malloc(sizeof(GIF));
    win_gif->anim = algif_load_animation("./image/win_anim.gif");
    lose_gif = (GIF*)malloc(sizeof(GIF));
    lose_gif->anim = algif_load_animation("./image/lose_anim.gif");
}

void game_begin() {
    //Load font
    font=al_load_ttf_font("./font/abg.ttf",35,0);
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

    // Load sound1-1
    song11 = al_load_sample("./sound/1-1.wav");
    al_reserve_samples(20);
    sample_instance11 = al_create_sample_instance(song11);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance11, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance11, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance11, 2) ;

    // Load sound1-2
    song12 = al_load_sample("./sound/1-2.wav");
    al_reserve_samples(20);
    sample_instance12 = al_create_sample_instance(song12);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance12, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance12, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance12, 2) ;

    // Load sound1-3
    song13 = al_load_sample("./sound/1-3.wav");
    al_reserve_samples(20);
    sample_instance13 = al_create_sample_instance(song13);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance13, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance13, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance13, 1) ;

    // Load sound1-4
    song14 = al_load_sample("./sound/1-4.mp3");
    al_reserve_samples(20);
    sample_instance14 = al_create_sample_instance(song14);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance14, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(sample_instance14, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance14, 1) ;

    click = al_load_sample("./sound/click.wav");
    sample_instanceclick  = al_create_sample_instance(click);
    al_set_sample_instance_playmode(sample_instanceclick, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(sample_instanceclick, al_get_default_mixer());

    al_start_timer(fps);
    // initialize the menu before entering the loop
    menu_init();
}

void game_update(){
    if( judge_next_window ){
        if( window == SCENE_MENU ){
            if(next==SCENE_TARGET)
            {
                game_scene11_init();
                judge_next_window = false;
                window = 11;
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
        else if( window == SCENE_ABOUT){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
        }
        else if( window == SCENE_HOWTOPLAY){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
            else if(next==SCENE_HOWTOPLAY2)
            {
                game_scene12_init();
                judge_next_window = false;
                window = SCENE_HOWTOPLAY2;
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
        else if( window == SCENE_ITEM){
            if(next==SCENE_STORE)
            {
                game_scene5_init();
                judge_next_window = false;
                window = SCENE_STORE;
            }else if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
        }
        else if( window == SCENE_GAME){
            if(next==SCENE_PAUSE)
            {
                game_scene7_init();
                judge_next_window = false;
                window = SCENE_PAUSE;
            }
            else if(next==SCENE_WIN)
            {
                game_scene8_init();
                judge_next_window = false;
                window = SCENE_WIN;
            }
            else if(next==SCENE_LOSE)
            {
                game_scene9_init();
                judge_next_window = false;
                window = SCENE_LOSE;
            }
            else if(next==SCENE_LEVELUP)
            {
                game_scene10_init();
                judge_next_window = false;
                window = SCENE_LEVELUP;
            }
        }
        else if( window == SCENE_PAUSE){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }else if(next==SCENE_STORE)
            {
                game_scene5_init();
                judge_next_window = false;
                window = SCENE_STORE;
            }else if(next==SCENE_HOWTOPLAY)
            {
                game_scene4_init();
                judge_next_window = false;
                window = SCENE_HOWTOPLAY;
            }else if(next==SCENE_GAME)
            {
                level = 1;
                game_scene2_init();
                judge_next_window = false;
                window = 2;
            }
        }
        else if( window == SCENE_WIN || window == SCENE_LOSE){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
        }
        else if( window == SCENE_LEVELUP){
            if(next==SCENE_TARGET)
            {
                game_scene11_init();
                judge_next_window = false;
                window = 11;
            }
        }
        else if( window == SCENE_TARGET){
            if(next==SCENE_GAME)
            {
                game_scene2_init();
                judge_next_window = false;
                window = 2;
            }
        }
        else if( window == SCENE_HOWTOPLAY2){
            if(next==SCENE_MENU)
            {
                menu_init();
                judge_next_window = false;
                window = SCENE_MENU;
            }
            else if(next==SCENE_HOWTOPLAY)
            {
                game_scene4_init();
                judge_next_window = false;
                window = SCENE_HOWTOPLAY;
            }
        }
    }
    else if( window == SCENE_GAME ){
        charater_update();
        nose_update();
    }
}
int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( window == SCENE_GAME )
        charater_process(event);
    else
        menu_process(event);

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
    }else if( window == 7 ){
        game_scene7_draw();
    }else if( window == 8 ){
        game_scene8_draw();
    }else if( window == 9 ){
        game_scene9_draw();
    }else if( window == 10 ){
        game_scene10_draw();
    }else if( window == 11 ){
        game_scene11_draw();
    }else if( window == 12 ){
        game_scene12_draw();
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
    al_destroy_sample_instance(sample_instance);
    al_destroy_sample_instance(sample_instance11);
    al_destroy_sample_instance(sample_instance12);
    al_destroy_sample_instance(sample_instance13);
    al_destroy_sample_instance(sample_instance14);
    menu_destroy();
    game_scene2_destroy();
    game_scene3_destroy();
    game_scene4_destroy();
    game_scene5_destroy();
    game_scene6_destroy();
    game_scene7_destroy();
    game_scene8_destroy();
    game_scene9_destroy();
    game_scene10_destroy();
    game_scene11_destroy();
    game_scene12_destroy();
    free(mouse_state);
}
