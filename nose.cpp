#include "nose.h"

int score=0;

void nose_init(){
    // load character images
    nose.img_move = al_load_bitmap("./image/bullet.png");
    // initial the geometric information of character
    nose.w = al_get_bitmap_width(nose.img_move);
    nose.h = al_get_bitmap_height(nose.img_move);
    nose.x = LEFT-nose.w/2;
    nose.y = 100-nose.h/2;
    nose.v = 4;
    nose.dir = false;
    nose.hidden = false;
}

void nose_process(ALLEGRO_EVENT event){
    /*if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            nose.y+=nose.v;
        }
    }*/
}

void nose_update(){
    /*font=al_load_ttf_font("./font/pirulen.ttf",50,0);
    al_draw_text(font,al_map_rgb(0,0,0),width/2,height/2,"%d",word);*/
    nose.y+=nose.v;
    if (!nose.hidden &&
        nose.y>=chara.y+nose.h &&
        nose.y<=chara.y+(chara.h+nose.h)/4)//sensor
    {
        if(chara.x+chara.w/2==nose.x+nose.w/2)//same x position
        {
            nose.hidden = true;
            score+=5;
        }
    }
    /*for (int i = 0; i < 3; i++){
        for (int j = 0; j < MAX_BULLET-2; j++){
            if (nose[i][j].hidden)continue;
            nose[i][j].x += nose[i][j].vx;
            nose[i][j].y += nose[i][j].vy;
            if (nose[i][j].y >= HEIGHT)
                nose[i][j].hidden = true;
        }
    }*/
}

void nose_draw(){
    /*for (int i = 0; i < 3; i++)
        for(int j = 0;j < 100;j++)*/
            if (!nose.hidden)
                al_draw_bitmap(nose.img_move, nose.x, nose.y, 0);
}

void nose_destory(){
    al_destroy_bitmap(nose.img_move);
}
