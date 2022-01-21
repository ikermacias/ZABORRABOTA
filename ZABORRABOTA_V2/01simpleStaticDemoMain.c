#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define SOINU_KOP 4
char* soundFiles[] = { ".\\sound\\Musika_Jokoa.wav", ".\\sound\\Musika_Mapa.wav", ".\\sound\\Musika_Laguntza.wav", ".\\sound\\Mii_Music.wav" };

typedef struct S_GURE_GAUZAK
{
    int idSounds[SOINU_KOP];
    int idIrudi;
    int idIrudi1;
    int idIrudi2;
    int idIrudi3;
    int idIrudi4;
    int idIrudi5;
    int idIrudi6;
    int idIrudi7;
    int idIrudi8;
    int idIrudi9;
    int idIrudi10;
    int idIrudi11;
    int idIrudi12;
    int idIrudi13;
    int idIrudi14;
    int idIrudi15;
    int idIrudi16;
    int idIrudi17;
    int idIrudi18;
    int idIrudi19;
    int idIrudi20;
    int idIrudi21;
    int idIrudi22;
    int idIrudi23;
    int idIrudi24;
    int idIrudi25;
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int hasieratu(void);
void margotu(int pantaila, int score, int mapa);
void zaborraPlastikoa(int x, int y, int zaborra);
void zaborraPapera(int x, int y, int zaborra);
void zaborraBeira(int x, int y, int zaborra);
void pelotaMugitu(int xp, int yp, int time);
void irudiak_kargatu(void);
void mapa_aukeratu(void);
void mapa_play(int mapa, int score);
void zaborra(int x, int y, int color);

int main(int argc, char* str[])
{
    srand(time(NULL));
    int ebentu = 0, irten = 0, intervalo = 0, mapa = 1, pantaila = 1, click = 0, score = 0, x = 0, y = 0, time = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, botoi = 0, xp = 325, yp = 275, zaborra1 = 1, zaborra3 = 1, zaborra2 = 1, time1 = 3;
    char str1[100];
    POSIZIOA pos;
    x = rand() % 400 + 40;
    y = rand() % 400 + 10;
    x1 = rand() % 400 + 40;
    y1 = rand() % 400 + 10;
    x2 = rand() % 400 + 40;
    y2 = rand() % 400 + 10;
    hasieratu();
    if (pantaila == 1)
    {
        playSound(3);
    }
    while (!irten)
    {
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            printf("\n\nX: %d Y: %d", pos.x, pos.y);
        }
        intervalo += 1;
        if (intervalo == 4)
        {
            intervalo = 0;
        }
        margotu(pantaila, score, mapa);

        if (pantaila == 8)
        {
            zaborra(x, y, 1);//berdea
            zaborra(x1, y1, 2);//urdina
            zaborra(x2, y2, 3);//horia
        }

        ebentu = ebentuaJasoGertatuBada();
        if ((time + 30) == (clock() / CLOCKS_PER_SEC) && pantaila == 3)
        {//30s
            pantaila = 1;
        }

        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA && pantaila == 8 && click == 0)
        {// Hartu berdea
            if ((pos.x > x - 10) && (pos.x < x + 10) && (pos.y > y - 10) && (pos.y < y + 10))
            {
                click = 1;
                ebentu = 0;
                botoi = 1;
            }
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA && pantaila == 8 && click == 0)
        {// Hartu urdina
            if ((pos.x > x1 - 10) && (pos.x < x1 + 10) && (pos.y > y1 - 10) && (pos.y < y1 + 10))
            {
                click = 1;
                ebentu = 0;
                botoi = 2;
            }
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA && pantaila == 8 && click == 0)
        {// Hartu oria
            if ((pos.x > x2 - 10) && (pos.x < x2 + 10) && (pos.y > y2 - 10) && (pos.y < y2 + 10))
            {
                click = 1;
                ebentu = 0;
                botoi = 3;
            }
        }
        if (click == 1 && botoi == 1)
        {// Mugitu berdea
            x = pos.x;
            y = pos.y;
        }
        if (click == 1 && botoi == 2)
        {// Mugitu urdina
            x1 = pos.x;
            y1 = pos.y;
        }
        if (click == 1 && botoi == 3)
        {// Mugitu horia
            x2 = pos.x;
            y2 = pos.y;
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA && click == 1)
        {// Utzi hartutakoa
            click = 0;
            botoi = 0;
        }
        if (mapa == 2 && intervalo == 3)
        {
            if (y < 250 && botoi != 1)
            {
                y += 1;
            }
            if (y1 < 250 && botoi != 2)
            {
                y1 += 1;
            }
            if (y2 < 250 && botoi != 3)
            {
                y2 += 1;
            }
            if (y >= 250 && y < 500 && x <= 300 && botoi != 1)
            {
                y += 1;
                x -= 1;
            }
            else if (y >= 250 && y < 500 && x >= 300 && botoi != 1)
            {
                y += 1;
                x += 1;
            }
            if (y1 >= 250 && y1 < 500 && x1 <= 300 && botoi != 2)
            {
                y1 += 1;
                x1 -= 1;
            }
            else if (y1 >= 250 && y1 < 500 && x1 >= 300 && botoi != 2)
            {
                y1 += 1;
                x1 += 1;
            }
            if (y2 >= 250 && y2 < 500 && x2 <= 300 && botoi != 3)
            {
                y2 += 1;
                x2 -= 1;
            }
            else if (y2 >= 250 && y2 < 500 && x2 >= 300 && botoi != 3)
            {
                y2 += 1;
                x2 += 1;
            }
            if (y > 480 || x > 600 || x < 0)
            {
                x = rand() % 400 + 40;
                y = 160;
            }
            if (y1 > 480 || x1 > 600 || x1 < 0)
            {
                x1 = rand() % 400 + 40;
                y1 = 160;
            }
            if (y2 > 480 || x2 > 600 || x2 < 0)
            {
                x2 = rand() % 400 + 40;
                y2 = 160;
            }
        }
        if ((x > 130) && (x < 170) && (y > 130) && (y < 170) && pantaila == 8 && click != 1)
        {// Berdea ondo re-ubikatu
            x = rand() % 400 + 40;
            y = rand() % 400 + 10;
            botoi = 0;
        }
        if ((x1 > 130) && (x1 < 170) && (y1 > 180) && (y1 < 220) && pantaila == 8 && click != 1)
        {// Urdina ondo re-ubikatu
            x1 = rand() % 400 + 40;
            y1 = rand() % 400 + 10;
            botoi = 0;
        }
        if ((x2 > 130) && (x2 < 770) && (y2 > 230) && (y2 < 270) && pantaila == 8 && click != 1)
        {// Horia ondo re-ubikatu
            x2 = rand() % 400 + 40;
            y2 = rand() % 400 + 10;
            botoi = 0;
        }
        if (((x > 130) && (x < 170) && (y > 230) && (y < 270) || (x1 > 130) && (x < 170) && (y > 180) && (y < 220)) && pantaila == 8 && click != 1)
        {// Berdea gaixki re-ubikatu
            click = 0;
            x = rand() % 400 + 40;
            y = rand() % 400 + 10;
            botoi = 0;
        }
        if (((x1 > 130) && (x1 < 170) && (y1 > 130) && (y1 < 170) || (x1 > 130) && (x1 < 170) && (y1 > 230) && (y1 < 270)) && pantaila == 8 && click != 1)
        {// Urdina gaixki re-ubikatu
            click = 0;
            x1 = rand() % 400 + 40;
            y1 = rand() % 400 + 10;
            botoi = 0;
        }
        if (((x2 > 130) && (x2 < 170) && (y2 > 130) && (y2 < 170) || (x2 > 130) && (x2 < 170) && (y2 > 180) && (y2 < 220)) && pantaila == 8 && click != 1)
        {// Horia gaixki re-ubikatu
            click = 0;
            x2 = rand() % 400 + 40;
            y2 = rand() % 400 + 10;
            botoi = 0;
        }
        pos = saguarenPosizioa();
        if (pantaila == 3)
        {// Pantaila 3 hasi
            if (ebentu == SAGU_BOTOIA_EZKERRA && click == 0)
            {// Hartu beira
                if ((pos.x > x) && (pos.x < x + 50) && (pos.y > y) && (pos.y < y + 50))
                {
                    click = 1;
                    ebentu = 0;
                    botoi = 1;
                }
            }
            if (ebentu == SAGU_BOTOIA_EZKERRA && click == 0)
            {// Hartu plastikoa
                if ((pos.x > x1) && (pos.x < x1 + 50) && (pos.y > y1) && (pos.y < y1 + 50))
                {
                    click = 1;
                    ebentu = 0;
                    botoi = 2;
                }
            }
            if (ebentu == SAGU_BOTOIA_EZKERRA && click == 0)
            {// Hartu papera
                if ((pos.x > x2) && (pos.x < x2 + 50) && (pos.y > y2) && (pos.y < y2 + 50))
                {
                    click = 1;
                    ebentu = 0;
                    botoi = 3;
                }
            }

            if (click == 1 && botoi == 1)
            {// Mugitu beira
                x = pos.x - 25;
                y = pos.y - 25;
            }
            if (click == 1 && botoi == 2)
            {// Mugitu plastikoa
                x1 = pos.x - 25;
                y1 = pos.y - 25;
            }
            if (click == 1 && botoi == 3)
            {// Mugitu papera
                x2 = pos.x - 25;
                y2 = pos.y - 25;
            }
            if (ebentu == SAGU_BOTOIA_EZKERRA && click == 1)
            {// Utzi hartutakoa
                click = 0;
            }
            if ((x + 25 > 25) && (x + 25 < 125) && (y + 25 > 19) && (y + 25 < 158) && click != 1)
            {// Beira ondo +1
                x = rand() % 400 + 40;
                y = rand() % 400 + 160;
                score += 1;
                botoi = 0;
                zaborra3 = rand() % 3 + 1;
            }
            if ((x1 + 25 > 245) && (x1 + 25 < 362) && (y1 + 25 > 30) && (y1 + 25 < 158) && click != 1)
            {// Plastikoa ondo +1
                x1 = rand() % 400 + 40;
                y1 = rand() % 300 + 160;
                score += 1;
                botoi = 0;
                zaborra2 = rand() % 3 + 1;
            }
            if ((x2 + 25 > 444) && (x2 + 25 < 570) && (y2 + 25 > 15) && (y2 + 25 < 158) && click != 1)
            {// Papera ondo +1
                x2 = rand() % 400 + 40;
                y2 = rand() % 300 + 160;
                score += 1;
                botoi = 0;
                zaborra1 = rand() % 3 + 1;
            }
            mapa_play(mapa, score);
            zaborraPapera(x2, y2, zaborra1);
            zaborraPlastikoa(x1, y1, zaborra2);
            zaborraBeira(x, y, zaborra3);
        }
        if (pantaila == 4)
        {//pantaila 4 mapa
            mapa_aukeratu();
            if (ebentu == TECLA_LEFT)
            {//mugitu berdea ezkerreruntz
                xp = xp - 4;
                time1 = 1;
            }
            if (ebentu == TECLA_RIGHT)
            {//mugitu berdea eskubiruntz
                xp = xp + 4;
                time1 = 2;
            }
            if (ebentu == TECLA_DOWN)
            {//mugitu berdea beheruntz
                yp = yp + 4;
                time1 = 3;
            }
            if (ebentu == TECLA_UP)
            {//mugitu berdea goruntz
                yp = yp - 4;
                time1 = 4;
            }
            pelotaMugitu(xp, yp, time1);
            if (ebentu == TECLA_SPACE && pantaila == 4)
            {
                if ((xp > 40) && (xp < 190) && (yp > 100) && (yp < 224) && (pantaila == 4))
                {// Lehenengo mapara joan
                    pantaila = 3;
                    mapa = 1;
                    x = rand() % 400 + 40;
                    y = rand() % 300 + 160;
                    x1 = rand() % 400 + 40;
                    y1 = rand() % 300 + 160;
                    x2 = rand() % 400 + 40;
                    y2 = rand() % 300 + 160;
                    playSound(0);
                }
                else if ((xp > 250) && (xp < 400) && (yp > 100) && (yp < 224) && (pantaila == 4))
                {// Bigarren mapara joan
                    pantaila = 3;
                    mapa = 2;
                    x = rand() % 400 + 40;
                    y = rand() % 300 + 160;
                    x1 = rand() % 400 + 40;
                    y1 = rand() % 300 + 160;
                    x2 = rand() % 400 + 40;
                    y2 = rand() % 300 + 160;
                    playSound(0);
                }
                else if ((xp > 460) && (xp < 610) && (yp > 100) && (yp < 224) && (pantaila == 4))
                {// Hirugarren mapara joan
                    pantaila = 3;
                    mapa = 3;
                    x = rand() % 400 + 40;
                    y = rand() % 300 + 160;
                    x1 = rand() % 400 + 40;
                    y1 = rand() % 300 + 160;
                    x2 = rand() % 400 + 40;
                    y2 = rand() % 300 + 160;
                    playSound(0);
                }
            }
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA && pantaila != 3)//menua
        {
            pos = saguarenPosizioa();
            if ((pos.x > 245) && (pos.x < 400) && (pos.y > 130) && (pos.y < 350) && pantaila == 1)
            {//Hasi pantailara joan
                pantaila = 3;
                time = (clock() / CLOCKS_PER_SEC);
                score = 0;
                playSound(0);
                mapa = rand() % 3 + 1;
                x = rand() % 400 + 40;
                y = rand() % 300 + 160;
                x1 = rand() % 400 + 40;
                y1 = rand() % 300 + 160;
                x2 = rand() % 400 + 40;
                y2 = rand() % 300 + 160;
            }
            if ((pos.x > 110) && (pos.x < 225) && (pos.y > 160) && (pos.y < 320) && pantaila == 1) // Mapak pantailara joan
            {
                pantaila = 4;
                playSound(1);
            }
            if ((pos.x > 415) && (pos.x < 530) && (pos.y > 160) && (pos.y < 320) && pantaila == 1) // Nola jolastu pantailara joan
            {
                pantaila = 5;
                playSound(2);
            }
            if ((pos.x > 15) && (pos.x < 90) && (pos.y > 195) && (pos.y < 305) && pantaila == 1)
            {// Puntuaketa pantailara joan 
                pantaila = 2;
            }
            if ((pos.x > 545) && (pos.x < 620) && (pos.y > 195) && (pos.y < 305) && pantaila == 1)
            {// Irten botoia 
                irten = 1;
            }
            else if ((pos.x > 290) && (pos.x < 365) && (pos.y > 350) && (pos.y < 405) && (pantaila == 2)) // Return botoia 2-1
            {
                pantaila = 1;
                playSound(3);
            }
            else if ((pos.x > 275) && (pos.x < 360) && (pos.y > 390) && (pos.y < 445) && (pantaila == 4)) // Return botoia 4-1
            {
                pantaila = 1;
                playSound(3);
            }
            if ((pos.x > 290) && (pos.x < 365) && (pos.y > 350) && (pos.y < 400) && pantaila == 5) // Return botoia 5-1
            {
                pantaila = 1;
                playSound(3);
            }
            if ((pos.x > 290) && (pos.x < 365) && (pos.y > 415) && (pos.y < 465) && pantaila == 5)
            {// Irten botoia 5
                irten = 1;
            }
            if ((pos.x > 489) && (pos.x < 564) && (pos.y > 362) && (pos.y < 413) && pantaila == 5)
            {// Kontrolak botoia
                pantaila = 6;
            }
            if ((pos.x > 290) && (pos.x < 365) && (pos.y > 415) && (pos.y < 465) && pantaila == 6)
            {// Irten botoia 6
                irten = 1;
            }
            if ((pos.x > 290) && (pos.x < 365) && (pos.y > 350) && (pos.y < 400) && pantaila == 6)
            {// Return botoia 6-1
                pantaila = 1;
                playSound(3);
            }
            if ((pos.x > 70) && (pos.x < 145) && (pos.y > 410) && (pos.y < 460) && pantaila == 6)
            {// Nola Jolastu botoia
                pantaila = 5;
            }
            if ((pos.x > 500) && (pos.x < 575) && (pos.y > 405) && (pos.y < 455) && pantaila == 6)
            {// Demoa botoia
                pantaila = 8;
            }
            if ((pos.x > 286) && (pos.x < 352) && (pos.y > 354) && (pos.y < 401) && pantaila == 8)
            {// Return botoia 7-1
                pantaila = 1;
            }
            if ((pos.x > 286) && (pos.x < 351) && (pos.y > 416) && (pos.y < 462) && pantaila == 8)
            {// Irten botoia 7
                irten = 1;
            }
            if ((pos.x > 74) && (pos.x < 141) && (pos.y > 412) && (pos.y < 464) && pantaila == 8)
            {// Kontrolak botoia
                pantaila = 6;
            }
        }
        if (ebentu == TECLA_RETURN) pantaila = 1;// Return tekla sakatu menura joateko
        if (ebentu == TECLA_ESCAPE) irten = 1;// Escape tekla sakatu irteteko
    }//while bukatu
    sgItxi();
    return 0;
}

int hasieratu(void)
{
    int i;
    char str[128];
    double d = 7.3;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    for (i = 0; i < SOINU_KOP; i++)
    {
        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
    }
    irudiak_kargatu();
    textuaGaitu();
    pantailaGarbitu();
    return 0;
}
void zaborraPapera(int x, int y, int zaborra)
{// Papera zaborren mugimendua
    int z1, img;
    if (y > 400 && y < 158)
    {
        y = 300;
    }
    if (zaborra == 1)
    {
        z1 = gureGauzak.idIrudi4;
        img = 4;
    }
    else if (zaborra == 2)
    {
        z1 = gureGauzak.idIrudi5;
        img = 5;
    }
    else
    {
        z1 = gureGauzak.idIrudi6;
        img = 6;
    }
    irudiaMugitu(z1, x, y);
    irudiakMarraztu(img);
}
void zaborraBeira(int x, int y, int zaborra)
{// Beira zaborren mugimendua
    int z1, img;
    if (zaborra == 1)
    {
        z1 = gureGauzak.idIrudi7;
        img = 7;
    }
    else if (zaborra == 2)
    {
        z1 = gureGauzak.idIrudi8;
        img = 8;
    }
    else
    {
        z1 = gureGauzak.idIrudi9;
        img = 9;
    }
    irudiaMugitu(z1, x, y);
    irudiakMarraztu(z1);
}
void zaborraPlastikoa(int x, int y, int zaborra)
{// Plastikoa zaborren mugimendua
    int z1, img;
    if (zaborra == 1)
    {
        z1 = gureGauzak.idIrudi1;
        img = 1;
    }
    else if (zaborra == 2)
    {
        z1 = gureGauzak.idIrudi2;
        img = 2;
    }
    else
    {
        z1 = gureGauzak.idIrudi3;
        img = 3;
    }
    irudiaMugitu(z1, x, y);
    irudiakMarraztu(z1);
}
void zaborra(int x, int y, int color)
{// Pelotak marraztu
    zirkuluaMarraztu(x, y, 10, color);
}

void margotu(int pantaila, int score, int mapa)
{
    char str1[100];
    int mapa1, mapa2, mapa3;
    sprintf(str1, "%d", score);

    if (pantaila == 1)
    {// Menua
        irudiaMugitu(gureGauzak.idIrudi17, 0, 20);
        irudiakMarraztu(17);
    }
    else if (pantaila == 2)
    {// Puntuaketa
        irudiaMugitu(gureGauzak.idIrudi18, 0, 50);
        irudiakMarraztu(18);
        textuaIdatzi(316, 222, str1);
    }
    else if (pantaila == 5)
    {// Nola Jolastu     
        irudiaMugitu(gureGauzak.idIrudi, 7, 0);
        irudiakMarraztu(0);
    }
    else if (pantaila == 6)
    {// Kontrolak
        irudiaMugitu(gureGauzak.idIrudi20, -20, 0);
        irudiakMarraztu(20);
    }
    else if (pantaila == 8)
    {// Demoa
        irudiaMugitu(gureGauzak.idIrudi25, 0, 340);
        irudiakMarraztu(25);
        zirkuluaMarraztu(170, 50, 20, 1);
        zirkuluaMarraztu(320, 50, 20, 2);
        zirkuluaMarraztu(470, 50, 20, 3);
    }
    pantailaBerriztu();
    pantailaGarbitu();
}
void pelotaMugitu(int xp, int yp, int time)
{
    int img1, img2;
    if (time == 2)
    {
        img1 = gureGauzak.idIrudi21;
        img2 = 21;
    }
    if (time == 1)
    {
        img1 = gureGauzak.idIrudi22;
        img2 = 22;
    }
    if (time == 4)
    {
        img1 = gureGauzak.idIrudi23;
        img2 = 23;
    }
    if (time == 3)
    {
        img1 = gureGauzak.idIrudi24;
        img2 = 24;
    }
    irudiaMugitu(img1, xp, yp);
    irudiakMarraztu(img2);
}
void mapa_aukeratu(void)
{// Mapak 
    irudiaMugitu(gureGauzak.idIrudi19, 175, 10);
    irudiakMarraztu(19);
    irudiaMugitu(gureGauzak.idIrudi13, 40, 100);
    irudiakMarraztu(13);
    irudiaMugitu(gureGauzak.idIrudi14, 250, 100);
    irudiakMarraztu(14);
    irudiaMugitu(gureGauzak.idIrudi15, 460, 100);
    irudiakMarraztu(15);
    irudiaMugitu(gureGauzak.idIrudi16, 0, 300);
    irudiakMarraztu(16);
}
void mapa_play(int mapa, int score)
{// Hasi 
    int mapa1, mapa2;
    char str1[100];
    sprintf(str1, "%d", score);
    if (mapa == 1)
    {
        mapa2 = 10;
    }
    else if (mapa == 2)
    {
        mapa2 = 11;
    }
    else
    {
        mapa2 = 12;
    }
    irudiakMarraztu(mapa2);
    textuaIdatzi(275, 4, "Score:");
    textuaIdatzi(325, 4, str1);
}
void irudiak_kargatu(void)
{// Irudiak 
    gureGauzak.idIrudi = irudiaKargatu(".\\img\\Nola_jolastu.bmp");
    gureGauzak.idIrudi1 = irudiaKargatu(".\\img\\Botella_plastico.bmp");
    gureGauzak.idIrudi2 = irudiaKargatu(".\\img\\Lata_aplastada.bmp");
    gureGauzak.idIrudi3 = irudiaKargatu(".\\img\\Envase_carton.bmp");
    gureGauzak.idIrudi4 = irudiaKargatu(".\\img\\Carton.bmp");
    gureGauzak.idIrudi5 = irudiaKargatu(".\\img\\Caja_huevos.bmp");
    gureGauzak.idIrudi6 = irudiaKargatu(".\\img\\Bola_papel.bmp");
    gureGauzak.idIrudi7 = irudiaKargatu(".\\img\\Botella_vino.bmp");
    gureGauzak.idIrudi8 = irudiaKargatu(".\\img\\Tarro_vidrio.bmp");
    gureGauzak.idIrudi9 = irudiaKargatu(".\\img\\Vidrio_roto.bmp");
    gureGauzak.idIrudi10 = irudiaKargatu(".\\img\\a.bmp");
    gureGauzak.idIrudi11 = irudiaKargatu(".\\img\\b.bmp");
    gureGauzak.idIrudi12 = irudiaKargatu(".\\img\\c.bmp");
    gureGauzak.idIrudi13 = irudiaKargatu(".\\img\\kalea.bmp");
    gureGauzak.idIrudi14 = irudiaKargatu(".\\img\\ibaia.bmp");
    gureGauzak.idIrudi15 = irudiaKargatu(".\\img\\hondartza.bmp");
    gureGauzak.idIrudi16 = irudiaKargatu(".\\img\\kontrolak.bmp");
    gureGauzak.idIrudi17 = irudiaKargatu(".\\img\\MENU.bmp");
    gureGauzak.idIrudi18 = irudiaKargatu(".\\img\\PUNTUAZIOA.bmp");
    gureGauzak.idIrudi19 = irudiaKargatu(".\\img\\IZENBURUA.bmp");
    gureGauzak.idIrudi20 = irudiaKargatu(".\\img\\KONTROLA.bmp");
    gureGauzak.idIrudi21 = irudiaKargatu(".\\img\\ibili1.bmp");
    gureGauzak.idIrudi22 = irudiaKargatu(".\\img\\ibili2.bmp");
    gureGauzak.idIrudi23 = irudiaKargatu(".\\img\\ibili3.bmp");
    gureGauzak.idIrudi24 = irudiaKargatu(".\\img\\ibili4.bmp");
    gureGauzak.idIrudi25 = irudiaKargatu(".\\img\\Demoa.bmp");
}
