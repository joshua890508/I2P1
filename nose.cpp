#include "nose.h"

void nose_init(){
    srand( time(NULL) );
    // load character images
    for(int i=0;i<50;i++)
    {
        int min=0,max=3;
        nose[i].type=rand() % (max - min + 1) + min;
        if(nose[i].type)nose[i].img_move = al_load_bitmap("./image/bullet.png");
        else nose[i].img_move = al_load_bitmap("./image/weapon_3.png");
        // initial the geometric information of character
        nose[i].w = al_get_bitmap_width(nose[i].img_move);
        nose[i].h = al_get_bitmap_height(nose[i].img_move);
        min=0,max=2;
        nose[i].x = LEFT + 180*( rand() % (max - min + 1) + min) - nose[i].w/2;
        nose[i].y = 100 - nose[i].h/2;
        nose[i].v = 3.0;
        nose[i].hidden = true;
    }
    nose[0].hidden = false;//first nose
}

void nose_update(){
    for(int i=0;i<50;i++)
    {
        if (!nose[i].hidden)
        {
            nose[i].y+=nose[i].v;
            if (nose[i].y>=WIDTH/2 && nose[i].y<=WIDTH/2+(chara.h+nose[i].h)/4)
                nose[i+1].hidden=false;
            else if (nose[i].y>=chara.y+nose[i].h &&
                nose[i].y<=chara.y+(chara.h+nose[i].h)/4)//same y position
            {
                if(chara.x+chara.w/2==nose[i].x + nose[i].w/2)//same x position
                {
                    nose[i].hidden = true;
                    score+=5;
                    if(nose[i].type==0)coin+=3;
                }
            }
        }
    }
    sprintf(s, "%d", score);
    sprintf(c, "%d", coin);
}

void nose_draw(){
    for(int i=0;i<50;i++)
        if (!nose[i].hidden)
            al_draw_bitmap(nose[i].img_move, nose[i].x, nose[i].y, 0);

    al_draw_text(font,al_map_rgb(0,0,0),350,47,0,s);
    al_draw_text(font,al_map_rgb(0,0,0),520,47,0,c);
}

void nose_destory(){
    for(int i=0;i<50;i++)al_destroy_bitmap(nose[i].img_move);
}
