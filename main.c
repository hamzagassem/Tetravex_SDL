#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <windows.h>
#include <SDL/SDL_mixer.h>



SDL_Surface* fenetre;
Mix_Music *musiquegame;
char nom[50];
char prn[50];
int id;
int sound=1;
char bestscore[20];
char scpapi[20];

struct jr
{
    int id;
    char nom[50];
    char prn[50];
    int nbr;
    char score[50];
    char best[50];
    char dte[300];
};
typedef struct jr jr;


struct rk
{
    char nom[100];
    char prenom[100];
    char best[100];
};
typedef struct rk rk;



void attendre(float temps);
void intialisation();
void cleanup();
void afficher_texte( int x, int y, int taille, char *ch, int R, int G,int B);
void cas1 ();
void cas2 ();
void cas3 ();
void cas4 ();
void cas5 ();
void cas6 ();
void game();
void datesys(char ch[]);
void menu();
void ranking();

void datesys(char ch[])
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(ch, asctime (timeinfo));
}



void ranking()
{
    SDL_Surface* bg = IMG_Load("Fichiers/Menu/rankingtable1.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    affich_rank();
    SDL_Event event;

    while(1)
    {
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        return;
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

}


void menu()
{
int sound=1;
    int x=0;
    SDL_Event event;
affich_rank();
    SDL_Surface* t [8];
    t[0]=IMG_Load("Fichiers/Menu/dmenu1.png");
    t[1]=IMG_Load("Fichiers/Menu/play1.png");
    t[2]=IMG_Load("Fichiers/Menu/ranking1.png");
    t[3]=IMG_Load("Fichiers/Menu/help1.png");
    t[4]=IMG_Load("Fichiers/Menu/about1.png");
    t[5]=IMG_Load("Fichiers/Menu/Settings1.png");
    t[6]=IMG_Load("Fichiers/Menu/Quit1.png");
    t[7]=IMG_Load("Fichiers/Menu/social.png");

    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);


    while(1)
    {
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 11.5) && (event.button.x <= 267))&&((event.button.y >= 630) && (event.button.y <= 658)))
                    {
                        system("START fb.html");
                    }
                    if (((event.button.x >= 278) && (event.button.x <= 499))&&((event.button.y >= 630) && (event.button.y <= 658)))
                    {
                        system("START www.twitter.com");
                    }
                    if (((event.button.x >= 510) && (event.button.x <= 755))&&((event.button.y >= 630) && (event.button.y <= 658)))
                    {
                        system("START www.youtube.com");
                    }
                }
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                    if((event.motion.x>78)&&(event.motion.x<156)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=1;
                    }
                    if((event.motion.x>254)&&(event.motion.x<327)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=2;
                    }
                    if((event.motion.x>418)&&(event.motion.x<490)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=3;
                    }
                    if((event.motion.x>566)&&(event.motion.x<638)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=4;
                    }
                    if((event.motion.x>734)&&(event.motion.x<806)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=5;
                    }
                    if((event.motion.x>886)&&(event.motion.x<960)&&(event.motion.y>296)&&(event.motion.y<375))
                    {
                    x=6;
                    }

            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    switch (x)
                    {
                    case 1:
                        saisir();
                        break;
                    case 2:
                        ranking();
                        break;
                    case 3:
                        help();
                        break;
                        case 4:
                        about();
                        break;
                    case 5:
                        settings();
                        break;
                    case 6:
                        exit(0);
                        break;
                    }
                }
            }
            if (event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    if(x<6)
                        x=x+1;
                }
                if(event.key.keysym.sym == SDLK_LEFT)
                {
                    if(x>1)
                        x=x-1;
                }
                else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                {
                    switch (x)
                    {
                    case 1:
                        saisir();
                        break;
                    case 2:
                        ranking();
                        break;
                    case 3:
                        help();
                        break;
                        case 4:
                        about();
                        break;
                    case 5:
                        settings();
                        break;
                    case 6:
                        exit(0);
                        break;

                    }
                }
            }
        }

        SDL_BlitSurface( t[x] ,NULL, fenetre, &imagebg);
        //SDL_BlitSurface( t[7] ,NULL, fenetre, &imagebg);
        SDL_Flip(fenetre);

    }

}


void slide()
{
    SDL_Event event;

SDL_Surface* tab[7];
tab[0]=IMG_Load("Fichiers/Menu/Hello/1.png");
tab[1]=IMG_Load("Fichiers/Menu/Hello/2.png");
tab[2]=IMG_Load("Fichiers/Menu/Hello/3.png");
tab[3]=IMG_Load("Fichiers/Menu/Hello/4.png");
tab[4]=IMG_Load("Fichiers/Menu/Hello/5.png");
tab[5]=IMG_Load("Fichiers/Menu/Hello/6.png");
tab[6]=IMG_Load("Fichiers/Menu/Hello/7.png");
//SDL_Surface* bg = IMG_Load("Fichiers/Menu/Hello/Hello.png");
    SDL_Rect img;
    img.x = 0;
    img.y = 0;


int x=0;
SDL_Surface* slide = IMG_Load("Fichiers/Menu/Hello/slide.png");
    SDL_Rect img1;
    img1.x = 286.4;
    img1.y = 560.1;
int t;
while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 286.4) && (event.button.x <= 330))&&((event.button.y >= 560.1) && (event.button.y <= 610)))
                    t=1;

                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                t=0;
                if(img1.x<646)
                img1.x=286.4;
                x=0;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( t==1 )
                {
                    img1.x = event.motion.x-(slide->w/2);
                    img1.y = 560.1;
                }
            }

            if(img1.x<280)
            img1.x=280;
            else if((img1.x>330)&&(img1.x<381.49))
                x=1;
            else if((img1.x>=381.49)&&(img1.x<430.49))
                x=2;
            else if((img1.x>=430.49)&&(img1.x<480.49))
                x=3;
                else if((img1.x>=480.49)&&(img1.x<535.49))
                x=4;
                else if((img1.x>=535.49)&&(img1.x<598.49))
                x=5;
                else if((img1.x>=598.49)&&(img1.x<646.49))
                x=6;
                else if((img1.x>=646.49))
                return(0);
        }
        //SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));
        switch(x)
        {
        case 0:SDL_BlitSurface( tab[0] ,NULL, fenetre, &img );break;
        case 1:SDL_BlitSurface( tab[1] ,NULL, fenetre, &img );break;
        case 2:SDL_BlitSurface( tab[2] ,NULL, fenetre, &img );break;
        case 3:SDL_BlitSurface( tab[3] ,NULL, fenetre, &img );break;
        case 4:SDL_BlitSurface( tab[4] ,NULL, fenetre, &img );break;
        case 5:SDL_BlitSurface( tab[5] ,NULL, fenetre, &img );break;
        case 6:SDL_BlitSurface( tab[6] ,NULL, fenetre, &img );break;
        }
                    SDL_BlitSurface( slide ,NULL, fenetre, &img1 );
                    SDL_Flip(fenetre);
    }
}


void afficher_texte_incliner( int x, int y, int taille, char *ch, int R, int G,int B,double zoom,double angle)
{
    TTF_Font* Font = TTF_OpenFont("Fichiers/Fonts/font.ttf",taille);
    SDL_Color color = {R, G, B};
    SDL_Surface* surface = TTF_RenderText_Solid(Font,ch,color);
    SDL_Rect texteDestination;
    texteDestination.x = x;
    texteDestination.y = y;
    SDL_Surface* rotation= rotozoomSurface(surface,angle,zoom,0);
    SDL_BlitSurface(rotation,NULL,fenetre,&texteDestination);
    SDL_FreeSurface(surface);
    TTF_CloseFont(Font);
}






void affich_rank()
{
    jr j1;
    rk t[100];
    FILE *fp=fopen("Fichiers/players/players.txt","r");
    char s1[200];
    int n=0;

    //while(!feof(fp))
    while(fgets(s1,200,fp)&&(strlen(s1)>20))
    {
//        fgets(s1,200,fp);
        sscanf(s1,"%d|%[^'|']|%[^'|']|%d|%[^'|']|%[^'|']|%[^'|']|",&j1.id,t[n].nom,t[n].prenom,&j1.nbr,j1.score,t[n].best,j1.dte);
        n++;
    }

    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(strcmp(t[j].best,t[j+1].best)>0)
            {
                rk tmp=t[j];
                t[j]=t[j+1];
                t[j+1]=tmp;
            }
        }
    }

    int prn=n;
    if(n>10)
        n=10;

    //afficher_texte_incliner(100,100,23, "aaaaaaa", 40,40,40,1,30);
    //afficher_texte_incliner(100,100,23, "bbbbbbb", 40,40,40,3,-90);


    char cht[300];
    int y=218;
    for(j=0; j<n; j++)
    {
        char ch[300];
        sprintf(ch,"%s %s %s",t[j].nom,t[j].prenom,t[j].best);
        if(strcmp(ch,cht)!=0)
        {
            afficher_texte(480,y,23, ch, 40,40,40);
            y+=25;
        }
        else
        {
            if(n<prn)
                n++;
        }
        if(j==2)
        {
            y+=110;
        }
        sprintf(cht,"%s %s %s",t[j].nom,t[j].prenom,t[j].best);
    }

    fclose(fp);
sprintf(bestscore,"%s",t[0].best);
fclose(fp);

}




void win()
{
    jr j;
    char s[200];
    char sc[20];

    datesys(j.dte);

    FILE * fp2=fopen("Fichiers/time/time.txt","r");
    fgets(sc,20,fp2);
    fclose(fp2);
    sprintf(scpapi,"%s",sc);
    sc[strlen(sc)-1]='\0';

    FILE * fp=fopen("Fichiers/players/players.txt","r");
    FILE * fp1=fopen("Fichiers/players/playerst.txt","w");
    while(fgets(s,200,fp)&&(strlen(s)>20))
    {
        sscanf(s,"%d|%[^'|']|%[^'|']|%d|%[^'|']|%[^'|']|%[^'|']|",&j.id,j.nom,j.prn,&j.nbr,j.score,j.best,j.dte);
        if(strcmp(j.nom,nom)!=0 || strcmp(j.prn,prn)!=0)
            fputs(s,fp1);

        else if(strcmp(j.best,sc)<0)
        {
            fprintf(fp1,"%d|%s|%s|%d|%s|%s|%s|\n",j.id,j.nom,j.prn,j.nbr+1,sc,j.best,j.dte);
            afficher_texte_incliner(220,190,50,sc,255,255,255,1,35);
            afficher_texte(657,465,50,j.best,255,255,255);
        }
        else
        {
            fprintf(fp1,"%d|%s|%s|%d|%s|%s|%s|\n",j.id,j.nom,j.prn,j.nbr+1,sc,sc,j.dte);
            afficher_texte_incliner(220,190,50,sc,255,255,255,1,35);
            afficher_texte(657,465,50,sc,255,255,255);
        }
    }
    fclose(fp);
    fclose(fp1);
    FILE * fp4=fopen("Fichiers/players/players.txt","w");
    FILE * fp3=fopen("Fichiers/players/playerst.txt","r");
    while(fgets(s,200,fp3))
    {
        if(strlen(s)>2)
            fputs(s,fp4);
    }
    fclose(fp4);
    fclose(fp3);
}


void saisir()
{

    jr j;
    SDL_Surface* bg = IMG_Load("Fichiers/cas2/nom.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);
    TTF_Font* pFont = TTF_OpenFont("Fichiers/Fonts/font.ttf",40);
    SDL_Event event;
    SDL_Rect tnom;
int  test=0;
    SDL_Surface* texte ;
    nom[0]='\0';
    int continuer=1;
    while (continuer)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                    strcat(nom," ");
                else if ( event.key.keysym.sym == SDLK_a)
                    strcat(nom,"q");
                else if ( event.key.keysym.sym == SDLK_b)
                    strcat(nom,"b");
                else if ( event.key.keysym.sym == SDLK_c)
                    strcat(nom,"c");
                else if ( event.key.keysym.sym == SDLK_d)
                    strcat(nom,"d");
                else if ( event.key.keysym.sym == SDLK_e)
                    strcat(nom,"e");
                else if ( event.key.keysym.sym == SDLK_f)
                    strcat(nom,"f");
                else if ( event.key.keysym.sym == SDLK_g)
                    strcat(nom,"g");
                else if ( event.key.keysym.sym == SDLK_h)
                    strcat(nom,"h");
                else if ( event.key.keysym.sym == SDLK_i)
                    strcat(nom,"i");
                else if ( event.key.keysym.sym == SDLK_j)
                    strcat(nom,"j");
                else if ( event.key.keysym.sym == SDLK_k)
                    strcat(nom,"k");
                else if ( event.key.keysym.sym == SDLK_l)
                    strcat(nom,"l");
                else if (event.key.keysym.sym == SDLK_SEMICOLON)
                    strcat(nom,"m");
                else if ( event.key.keysym.sym == SDLK_n)
                    strcat(nom,"n");
                else if ( event.key.keysym.sym == SDLK_o)
                    strcat(nom,"o");
                else if ( event.key.keysym.sym == SDLK_p)
                    strcat(nom,"p");
                else if ( event.key.keysym.sym == SDLK_q)
                    strcat(nom,"a");
                else if ( event.key.keysym.sym == SDLK_r)
                    strcat(nom,"r");
                else if ( event.key.keysym.sym == SDLK_s)
                    strcat(nom,"s");
                else if ( event.key.keysym.sym == SDLK_t)
                    strcat(nom,"t");
                else if ( event.key.keysym.sym == SDLK_u)
                    strcat(nom,"u");
                else if ( event.key.keysym.sym == SDLK_v)
                    strcat(nom,"v");
                else if ( event.key.keysym.sym == SDLK_w)
                    strcat(nom,"z");
                else if ( event.key.keysym.sym == SDLK_x)
                    strcat(nom,"x");
                else if ( event.key.keysym.sym == SDLK_y)
                    strcat(nom,"y");
                else if ( event.key.keysym.sym == SDLK_z)
                    strcat(nom,"w");
                else if ( event.key.keysym.sym == SDLK_BACKSPACE)
                    nom[strlen(nom)-1]='\0';
                else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                {
                    if((strlen(nom)>2)&&(strlen(nom)<14))
                        continuer=0;
                    else
                        MessageBox(0,"Votre Nom doit Entre 2 Et 14 caracteres","Information",MB_OK);
                }
                break;
            }
            }
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (((event.button.x >= 75) && (event.button.x <= 144))&&((event.button.y >= 46) && (event.button.y <= 133)))
                {
                    return(0);
                }
            }
        }
//        tnom.x = 20;
//        tnom.y = 20;
//        texte = TTF_RenderText_Solid(pFont,"Saisir votre nom :", {255, 14, 22});
        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        SDL_BlitSurface(texte, 0, fenetre, &tnom);
        tnom.x = 604;
        tnom.y = 258;

        SDL_Color fontColor = {27, 30, 35};
        texte = TTF_RenderText_Solid(pFont,nom,fontColor );
        SDL_BlitSurface(texte, 0, fenetre, &tnom);
        SDL_Flip(fenetre);
    }
    prn[0]='\0';
    int continuer2=1;
    while (continuer2)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                    strcat(prn," ");
                else if ( event.key.keysym.sym == SDLK_a)
                    strcat(prn,"q");
                else if ( event.key.keysym.sym == SDLK_b)
                    strcat(prn,"b");
                else if ( event.key.keysym.sym == SDLK_c)
                    strcat(prn,"c");
                else if ( event.key.keysym.sym == SDLK_d)
                    strcat(prn,"d");
                else if ( event.key.keysym.sym == SDLK_e)
                    strcat(prn,"e");
                else if ( event.key.keysym.sym == SDLK_f)
                    strcat(prn,"f");
                else if ( event.key.keysym.sym == SDLK_g)
                    strcat(prn,"g");
                else if ( event.key.keysym.sym == SDLK_h)
                    strcat(prn,"h");
                else if ( event.key.keysym.sym == SDLK_i)
                    strcat(prn,"i");
                else if ( event.key.keysym.sym == SDLK_j)
                    strcat(prn,"j");
                else if ( event.key.keysym.sym == SDLK_k)
                    strcat(prn,"k");
                else if ( event.key.keysym.sym == SDLK_l)
                    strcat(prn,"l");
                else if (event.key.keysym.sym == SDLK_SEMICOLON)
                    strcat(prn,"m");
                else if ( event.key.keysym.sym == SDLK_n)
                    strcat(prn,"n");
                else if ( event.key.keysym.sym == SDLK_o)
                    strcat(prn,"o");
                else if ( event.key.keysym.sym == SDLK_p)
                    strcat(prn,"p");
                else if ( event.key.keysym.sym == SDLK_q)
                    strcat(prn,"a");
                else if ( event.key.keysym.sym == SDLK_r)
                    strcat(prn,"r");
                else if ( event.key.keysym.sym == SDLK_s)
                    strcat(prn,"s");
                else if ( event.key.keysym.sym == SDLK_t)
                    strcat(prn,"t");
                else if ( event.key.keysym.sym == SDLK_u)
                    strcat(prn,"u");
                else if ( event.key.keysym.sym == SDLK_v)
                    strcat(prn,"v");
                else if ( event.key.keysym.sym == SDLK_w)
                    strcat(prn,"z");
                else if ( event.key.keysym.sym == SDLK_x)
                    strcat(prn,"x");
                else if ( event.key.keysym.sym == SDLK_y)
                    strcat(prn,"y");
                else if ( event.key.keysym.sym == SDLK_z)
                    strcat(prn,"w");
                else if ( event.key.keysym.sym == SDLK_BACKSPACE)
                    prn[strlen(prn)-1]='\0';
            }
            }
        }


        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if (((event.button.x >= 524) && (event.button.x <= 943))&&((event.button.y >= 460) && (event.button.y <= 550)))
                {
                    if((strlen(prn)>2)&&(strlen(prn)<14))
                        {test=1;
                        continuer2=0;
                        }
                    else
                        MessageBox(0,"Votre Prenom doit Entre 2 Et 14 caracteres","Information",MB_OK);
                }
                if (((event.button.x >= 75) && (event.button.x <= 144))&&((event.button.y >= 46) && (event.button.y <= 133)))
                {
                    return(0);
                }
            }
        }

        SDL_Surface* bg = IMG_Load("Fichiers/cas2/prenom.png");
        SDL_Rect imagebg;
        imagebg.x = 0;
        imagebg.y = 0;
        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        SDL_BlitSurface(texte, 0, fenetre, &tnom);
        tnom.x = 604;
        tnom.y = 258;
        SDL_Color fontColor = {27, 30, 35};
        texte = TTF_RenderText_Solid(pFont,nom, fontColor);
        SDL_BlitSurface(texte, 0, fenetre, &tnom);
        tnom.x = 604;
        tnom.y = 355;

        texte = TTF_RenderText_Solid(pFont,prn, fontColor);
        SDL_BlitSurface(texte, 0, fenetre, &tnom);
        SDL_Flip(fenetre);
    }
    char s[200];
    FILE *fp1=fopen("Fichiers/players/players.txt","r");
    int t=0;
    while(!feof(fp1))
    {
        fgets(s,200,fp1);
        sscanf(s,"%d|%[^'|']|%[^'|']|%d|%[^'|']|%s|",&j.id,j.nom,j.prn,&j.nbr,j.score,j.dte);
        if((strcmp(j.nom,nom)==0)&&(strcmp(j.prn,prn)==0))
        {
            test=1;
            t=1;
            break;
        }
    }
    fclose(fp1);

    fp1=fopen("Fichiers/players/players.txt","a+");
    if(t==0)
    {
        FILE * fid=fopen("Fichiers/players/idplayer.txt","r");
        fscanf(fid,"%d",&id);
        fclose(fid);
        FILE * fpnow=fopen("Fichiers/players/NowPlaying/pnow.txt","w");
        fprintf(fpnow,"%d",id);
        fclose(fpnow);
        j.nbr=0;
        sprintf(j.score,"00:99:99");
        sprintf(j.best,"00:99:99");
        datesys(j.dte);
        j.dte[strlen(j.dte)-1]='\0';
        fprintf(fp1,"%d|%s|%s|%d|%s|%s|%s|\n",id,nom,prn,j.nbr,j.score,j.best,j.dte);
        id++;
        fid=fopen("Fichiers/players/idplayer.txt","w");
        fprintf(fid,"%d",id);
        fclose(fid);
        fclose(fp1);
        game();
    }
    fclose(fp1);
if(test==1)
    game();
}




int main(int argc,char** argv)
{

    SDL_Init( SDL_INIT_VIDEO );
    fenetre = SDL_SetVideoMode(1024, 668, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Projet Jeu", NULL);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);
    TTF_Init();
    slide();
    menu();
    return 0;
}

void score(time_t t1)
{
    int seconde=0;
    int minute=0;
    int heure=0;
    int diff=0;
    char temps[10];
    time_t t2;

    t2 = time(NULL);
    diff=difftime(t2, t1);

    while(diff>=3600)
    {
        diff=diff-3600;
        heure++;
    }
    while(diff>=60)
    {
        diff=diff-60;
        minute++;
    }
    seconde=diff;

    if (heure<10)
        sprintf(temps,"0%d:",heure);
    else
        sprintf(temps,"%d:",heure);
    if (minute<10)
        sprintf(temps,"%s0%d:",temps,minute);
    else
        sprintf(temps,"%s%d:",temps,minute);
    if (seconde<10)
        sprintf(temps,"%s0%d",temps,seconde);
    else
        sprintf(temps,"%s%d",temps,seconde);
    printf("%s\n",temps);
    afficher_texte(165,39,45,temps,255,255,255);
    FILE *fp=fopen("Fichiers/time/time.txt","w");
    fprintf(fp,"%s\n",temps);
    fclose(fp);
}


void cleanup()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


void afficher_texte( int x, int y, int taille, char *ch, int R, int G,int B)
{
    TTF_Font* Font = TTF_OpenFont("Fichiers/Fonts/font.ttf",taille);
    SDL_Color color = {R, G, B};
    SDL_Surface* surface = TTF_RenderText_Solid(Font,ch,color);
    SDL_Rect texteDestination;
    texteDestination.x = x;
    texteDestination.y = y;
    SDL_BlitSurface(surface,NULL,fenetre,&texteDestination);
    SDL_FreeSurface(surface);
    TTF_CloseFont(Font);
}



void cas1()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
g++;
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas1/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas1/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas1/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas1/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas1/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas1/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas1/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas1/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas1/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
            Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}


void cas2()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
    g++;
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas3/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas3/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas3/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas3/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas3/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas3/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas3/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas3/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas3/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
           Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}




void cas3()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
    g++;
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas2/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas2/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas2/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas2/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas2/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas2/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas2/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas2/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas2/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
           Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}



void cas4()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
    g++;
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas4/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas4/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas4/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas4/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas4/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas4/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas4/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas4/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas4/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
           Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}



void cas5()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas5/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas5/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas5/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas5/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas5/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas5/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas5/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas5/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas5/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
           Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                       if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}




void cas6()
{
    time_t t1;
    t1 = time(NULL);
    int onclick = 0;
    SDL_Event event;
    int g = rand() % 3;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

Mix_Music *musiquegame;
if(sound==1)
{
g++;
switch(g)
{
case 0:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame.mp3");break;
case 1:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame1.mp3");break;
case 2:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame2.mp3");break;
case 3:musiquegame = Mix_LoadMUS("Fichiers/Sounds/ingame3.mp3");break;
}
Mix_PlayMusic(musiquegame, -1);
}

    /**Debut  Images btn btr est Grille **/

    SDL_Surface* bg = IMG_Load("Fichiers/cas1/bg.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);

    SDL_Surface* btnew = IMG_Load("Fichiers/cas1/buttonnew.png");
    SDL_Rect imagebnd1;
    imagebnd1.x = 111;
    imagebnd1.y = 610;
    SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
    SDL_Flip(fenetre);

    SDL_Surface* btr = IMG_Load("Fichiers/cas1/buttonr.png");
    SDL_Rect imagebrd1;
    imagebrd1.x = 291;
    imagebrd1.y = 610;
    SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille1 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd1;
    imagegd1.x = 96;
    imagegd1.y = 105;
    SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
    SDL_Flip(fenetre);


    SDL_Surface* grille2 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd2;
    imagegd2.x = 213.8;
    imagegd2.y = 105;
    SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
    SDL_Flip(fenetre);

    SDL_Surface* grille3 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd3;
    imagegd3.x = 330;
    imagegd3.y = 105;
    SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
    SDL_Flip(fenetre);


    SDL_Surface* grille4 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd4;
    imagegd4.x = 96;
    imagegd4.y = 269;
    SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
    SDL_Flip(fenetre);


    SDL_Surface* grille5 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd5;
    imagegd5.x = 213.8;
    imagegd5.y = 269;
    SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
    SDL_Flip(fenetre);

    SDL_Surface* grille6 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd6;
    imagegd6.x = 330;
    imagegd6.y = 269;
    SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
    SDL_Flip(fenetre);

    SDL_Surface* grille7 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd7;
    imagegd7.x = 96;
    imagegd7.y = 432;
    SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
    SDL_Flip(fenetre);

    SDL_Surface* grille8 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd8;
    imagegd8.x = 213.8;
    imagegd8.y = 432;
    SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
    SDL_Flip(fenetre);

    SDL_Surface* grille9 = IMG_Load("Fichiers/cas1/grille.png");
    SDL_Rect imagegd9;
    imagegd9.x = 330;
    imagegd9.y = 432;
    SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
    SDL_Flip(fenetre);

    /**Fin  Images btn btr est Grille **/

    /**Debut  Images 9 carre **/

    SDL_Surface* carre1 = IMG_Load("Fichiers/cas6/11.png");
    SDL_Rect imaged1;
    imaged1.x = 720;
    imaged1.y = 103.5;
    SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
    SDL_Flip(fenetre);


    SDL_Surface* carre2 = IMG_Load("Fichiers/cas6/22.png");
    SDL_Rect imaged2;
    imaged2.x = 600;
    imaged2.y = 103.5;
    SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
    SDL_Flip(fenetre);


    SDL_Surface* carre3 = IMG_Load("Fichiers/cas6/33.png");
    SDL_Rect imaged3;
    imaged3.x = 600;
    imaged3.y = 272;
    SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
    SDL_Flip(fenetre);



    SDL_Surface* carre4 = IMG_Load("Fichiers/cas6/44.png");
    SDL_Rect imaged4;
    imaged4.x = 840;
    imaged4.y = 103.5;
    SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
    SDL_Flip(fenetre);


    SDL_Surface* carre5 = IMG_Load("Fichiers/cas6/55.png");
    SDL_Rect imaged5;
    imaged5.x = 840;
    imaged5.y = 272;
    SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
    SDL_Flip(fenetre);

    SDL_Surface* carre6 = IMG_Load("Fichiers/cas6/66.png");
    SDL_Rect imaged6;
    imaged6.x = 720;
    imaged6.y = 272;
    SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
    SDL_Flip(fenetre);

    SDL_Surface* carre7 = IMG_Load("Fichiers/cas6/77.png");
    SDL_Rect imaged7;
    imaged7.x = 600;
    imaged7.y = 440;
    SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
    SDL_Flip(fenetre);

    SDL_Surface* carre8 = IMG_Load("Fichiers/cas6/88.png");
    SDL_Rect imaged8;
    imaged8.x = 840;
    imaged8.y = 440;
    SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
    SDL_Flip(fenetre);

    SDL_Surface* carre9 = IMG_Load("Fichiers/cas6/99.png");
    SDL_Rect imaged9;
    imaged9.x = 720;
    imaged9.y = 440;
    SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
    SDL_Flip(fenetre);

    SDL_Surface* aa = IMG_Load("Fichiers/cas2/fin.png");
    SDL_Rect aaa;
    aaa.x = 0;
    aaa.y = 0;


    /**Fin  Images 9 carre **/

    /**Debut While(1) **/

    while(!((((imaged1.x==imagegd1.x)&&(imaged1.x==imagegd1.x))&&((imaged1.y==imagegd1.y)&&(imaged1.y==imagegd1.y)))&&(((imaged2.x==imagegd2.x)&&(imaged2.x==imagegd2.x))&&((imaged2.y==imagegd2.y)&&(imaged2.y==imagegd2.y)))&&(((imaged3.x==imagegd3.x)&&(imaged3.x==imagegd3.x))&&((imaged3.y==imagegd3.y)&&(imaged3.y==imagegd3.y)))&&(((imaged4.x==imagegd4.x)&&(imaged4.x==imagegd4.x))&&((imaged4.y==imagegd4.y)&&(imaged4.y==imagegd4.y)))&&(((imaged5.x==imagegd5.x)&&(imaged5.x==imagegd5.x))&&((imaged5.y==imagegd5.y)&&(imaged5.y==imagegd5.y)))&&(((imaged6.x==imagegd6.x)&&(imaged6.x==imagegd6.x))&&((imaged6.y==imagegd6.y)&&(imaged6.y==imagegd6.y)))&&(((imaged7.x==imagegd7.x)&&(imaged7.x==imagegd7.x))&&((imaged7.y==imagegd7.y)&&(imaged7.y==imagegd7.y)))&&(((imaged8.x==imagegd8.x)&&(imaged8.x==imagegd8.x))&&((imaged8.y==imagegd8.y)&&(imaged8.y==imagegd8.y)))&&(((imaged9.x==imagegd9.x)&&(imaged9.x==imagegd9.x))&&((imaged9.y==imagegd9.y)&&(imaged9.y==imagegd9.y)))))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                Mix_FreeMusic(musiquegame);
                Mix_CloseAudio();
                menu();
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= imaged1.x) && (event.button.x <= imaged1.x +carre1->w))&&((event.button.y >= imaged1.y) && (event.button.y <= imaged1.y+carre1->h)))
                    {
                        onclick = 1;
                    }
                    if ((event.button.x >= imaged2.x) && (event.button.x <= imaged2.x +carre2->w))
                    {
                        if ((event.button.y >= imaged2.y) && (event.button.y <= imaged2.y+carre2->h ))
                        {
                            onclick = 2;
                        }
                    }
                    if ((event.button.x >= imaged3.x) && (event.button.x <= imaged3.x +carre3->w))
                    {
                        if ((event.button.y >= imaged3.y) && (event.button.y <= imaged3.y+carre3->h ))
                        {
                            onclick = 3;
                        }
                    }
                    if ((event.button.x >= imaged4.x) && (event.button.x <= imaged4.x +carre4->w))
                    {
                        if ((event.button.y >= imaged4.y) && (event.button.y <= imaged4.y+carre4->h ))
                        {
                            onclick = 4;
                        }
                    }
                    if ((event.button.x >= imaged5.x) && (event.button.x <= imaged5.x +carre5->w))
                    {
                        if ((event.button.y >= imaged5.y) && (event.button.y <= imaged5.y+carre5->h ))
                        {
                            onclick = 5;
                        }
                    }
                    if ((event.button.x >= imaged6.x) && (event.button.x <= imaged6.x +carre6->w))
                    {
                        if ((event.button.y >= imaged6.y) && (event.button.y <= imaged6.y+carre6->h ))
                        {
                            onclick = 6;
                        }
                    }
                    if ((event.button.x >= imaged7.x) && (event.button.x <= imaged7.x +carre7->w))
                    {
                        if ((event.button.y >= imaged7.y) && (event.button.y <= imaged7.y+carre7->h ))
                        {
                            onclick = 7;
                        }
                    }

                    if ((event.button.x >= imaged8.x) && (event.button.x <= imaged8.x +carre8->w))
                    {
                        if ((event.button.y >= imaged8.y) && (event.button.y <= imaged8.y+carre8->h ))
                        {
                            onclick = 8;
                        }
                    }
                    if ((event.button.x >= imaged9.x) && (event.button.x <= imaged9.x +carre9->w))
                    {
                        if ((event.button.y >= imaged9.y) && (event.button.y <= imaged9.y+carre9->h ))
                        {
                            onclick = 9;
                        }
                    }
                    if ((event.button.x >= imagebnd1.x) && (event.button.x <= imagebnd1.x +btnew->w))
                    {
                        if ((event.button.y >= imagebnd1.y) && (event.button.y <= imagebnd1.y+btnew->h ))
                        {
                            // return;
                            game();
                        }
                    }
                    if ((event.button.x >= imagebrd1.x) && (event.button.x <= imagebrd1.x +btr->w))
                    {
                        if ((event.button.y >= imagebrd1.y) && (event.button.y <= imagebrd1.y+btr->h ))
                        {
                            cas3();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if ((imaged1.x+80 >= imagegd1.x) && (imaged1.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged1.y+80 >= imagegd1.y) && (imaged1.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged1.x=imagegd1.x;
                    imaged1.y=imagegd1.y;
                }
                if ((imaged1.x+80 >= imagegd2.x) && (imaged1.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged1.y+80 >= imagegd2.y) && (imaged1.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged1.x=imagegd2.x;
                    imaged1.y=imagegd2.y;
                }
                if ((imaged1.x+80 >= imagegd3.x) && (imaged1.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged1.y+80 >= imagegd3.y) && (imaged1.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged1.x=imagegd3.x;
                    imaged1.y=imagegd3.y;
                }
                if (((imaged1.x+80 >= imagegd4.x) && (imaged1.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged1.y+80 >= imagegd4.y) && (imaged1.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged1.x=imagegd4.x;
                    imaged1.y=imagegd4.y;
                }
                if (((imaged1.x+80 >= imagegd5.x) && (imaged1.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged1.y+80 >= imagegd5.y) && (imaged1.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged1.x=imagegd5.x;
                    imaged1.y=imagegd5.y;
                }
                if (((imaged1.x+80 >= imagegd6.x) && (imaged1.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged1.y+80 >= imagegd6.y) && (imaged1.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged1.x=imagegd6.x;
                    imaged1.y=imagegd6.y;
                }
                if (((imaged1.x+80 >= imagegd7.x) && (imaged1.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged1.y+80 >= imagegd7.y) && (imaged1.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged1.x=imagegd7.x;
                    imaged1.y=imagegd7.y;
                }
                if (((imaged1.x+80 >= imagegd8.x) && (imaged1.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged1.y+80 >= imagegd8.y) && (imaged1.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged1.x=imagegd8.x;
                    imaged1.y=imagegd8.y;
                }
                if (((imaged1.x+imaged1.w >= imagegd9.x) && (imaged1.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged1.y+80 >= imagegd9.y) && (imaged1.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged1.x=imagegd9.x;
                    imaged1.y=imagegd9.y;
                }
                if ((imaged2.x+80 >= imagegd1.x) && (imaged2.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged2.y+80 >= imagegd1.y) && (imaged2.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged2.x=imagegd1.x;
                    imaged2.y=imagegd1.y;
                }
                if ((imaged2.x+80 >= imagegd2.x) && (imaged2.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged2.y+80 >= imagegd2.y) && (imaged2.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged2.x=imagegd2.x;
                    imaged2.y=imagegd2.y;
                }
                if ((imaged2.x+80 >= imagegd3.x) && (imaged2.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged2.y+80 >= imagegd3.y) && (imaged2.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged2.x=imagegd3.x;
                    imaged2.y=imagegd3.y;
                }
                if (((imaged2.x+80 >= imagegd4.x) && (imaged2.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged2.y+80 >= imagegd4.y) && (imaged2.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged2.x=imagegd4.x;
                    imaged2.y=imagegd4.y;
                }
                if (((imaged2.x+80 >= imagegd5.x) && (imaged2.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged2.y+80 >= imagegd5.y) && (imaged2.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged2.x=imagegd5.x;
                    imaged2.y=imagegd5.y;
                }
                if (((imaged2.x+80 >= imagegd6.x) && (imaged2.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged2.y+80 >= imagegd6.y) && (imaged2.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged2.x=imagegd6.x;
                    imaged2.y=imagegd6.y;
                }
                if (((imaged2.x+80 >= imagegd7.x) && (imaged2.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged2.y+80 >= imagegd7.y) && (imaged2.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged2.x=imagegd7.x;
                    imaged2.y=imagegd7.y;
                }
                if (((imaged2.x+80 >= imagegd8.x) && (imaged2.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged2.y+80 >= imagegd8.y) && (imaged2.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged2.x=imagegd8.x;
                    imaged2.y=imagegd8.y;
                }
                if (((imaged2.x+80 >= imagegd9.x) && (imaged2.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged2.y+80 >= imagegd9.y) && (imaged2.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged2.x=imagegd9.x;
                    imaged2.y=imagegd9.y;
                }
                if ((imaged3.x+80 >= imagegd1.x) && (imaged3.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged3.y+80 >= imagegd1.y) && (imaged3.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged3.x=imagegd1.x;
                    imaged3.y=imagegd1.y;
                }
                if ((imaged3.x+80 >= imagegd2.x) && (imaged3.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged3.y+80 >= imagegd2.y) && (imaged3.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged3.x=imagegd2.x;
                    imaged3.y=imagegd2.y;
                }
                if ((imaged3.x+80 >= imagegd3.x) && (imaged3.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged3.y+80 >= imagegd3.y) && (imaged3.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged3.x=imagegd3.x;
                    imaged3.y=imagegd3.y;
                }
                if (((imaged3.x+80 >= imagegd4.x) && (imaged3.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged3.y+80 >= imagegd4.y) && (imaged3.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged3.x=imagegd4.x;
                    imaged3.y=imagegd4.y;
                }
                if (((imaged3.x+80 >= imagegd5.x) && (imaged3.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged3.y+80 >= imagegd5.y) && (imaged3.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged3.x=imagegd5.x;
                    imaged3.y=imagegd5.y;
                }
                if (((imaged3.x+80 >= imagegd6.x) && (imaged3.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged3.y+80 >= imagegd6.y) && (imaged3.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged3.x=imagegd6.x;
                    imaged3.y=imagegd6.y;
                }
                if (((imaged3.x+80 >= imagegd7.x) && (imaged3.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged3.y+80 >= imagegd7.y) && (imaged3.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged3.x=imagegd7.x;
                    imaged3.y=imagegd7.y;
                }
                if (((imaged3.x+80 >= imagegd8.x) && (imaged3.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged3.y+80 >= imagegd8.y) && (imaged3.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged3.x=imagegd8.x;
                    imaged3.y=imagegd8.y;
                }
                if (((imaged3.x+80 >= imagegd9.x) && (imaged3.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged3.y+80 >= imagegd9.y) && (imaged3.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged3.x=imagegd9.x;
                    imaged3.y=imagegd9.y;
                }
                if ((imaged4.x+80 >= imagegd1.x) && (imaged4.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged4.y+80 >= imagegd1.y) && (imaged4.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged4.x=imagegd1.x;
                    imaged4.y=imagegd1.y;
                }
                if ((imaged4.x+80 >= imagegd2.x) && (imaged4.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged4.y+80 >= imagegd2.y) && (imaged4.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged4.x=imagegd2.x;
                    imaged4.y=imagegd2.y;
                }
                if ((imaged4.x+80 >= imagegd3.x) && (imaged4.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged4.y+80 >= imagegd3.y) && (imaged4.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged4.x=imagegd3.x;
                    imaged4.y=imagegd3.y;
                }
                if (((imaged4.x+80 >= imagegd4.x) && (imaged4.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged4.y+80 >= imagegd4.y) && (imaged4.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged4.x=imagegd4.x;
                    imaged4.y=imagegd4.y;
                }
                if (((imaged4.x+80 >= imagegd5.x) && (imaged4.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged4.y+80 >= imagegd5.y) && (imaged4.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged4.x=imagegd5.x;
                    imaged4.y=imagegd5.y;
                }
                if (((imaged4.x+80 >= imagegd6.x) && (imaged4.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged4.y+80 >= imagegd6.y) && (imaged4.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged4.x=imagegd6.x;
                    imaged4.y=imagegd6.y;
                }
                if (((imaged4.x+80 >= imagegd7.x) && (imaged4.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged4.y+80 >= imagegd7.y) && (imaged4.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged4.x=imagegd7.x;
                    imaged4.y=imagegd7.y;
                }
                if (((imaged4.x+80 >= imagegd8.x) && (imaged4.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged4.y+80 >= imagegd8.y) && (imaged4.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged4.x=imagegd8.x;
                    imaged4.y=imagegd8.y;
                }
                if (((imaged4.x+80 >= imagegd9.x) && (imaged4.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged4.y+80 >= imagegd9.y) && (imaged4.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged4.x=imagegd9.x;
                    imaged4.y=imagegd9.y;
                }
                if ((imaged5.x+80 >= imagegd1.x) && (imaged5.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged5.y+80 >= imagegd1.y) && (imaged5.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged5.x=imagegd1.x;
                    imaged5.y=imagegd1.y;
                }
                if ((imaged5.x+80 >= imagegd2.x) && (imaged5.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged5.y+80 >= imagegd2.y) && (imaged5.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged5.x=imagegd2.x;
                    imaged5.y=imagegd2.y;
                }
                if ((imaged5.x+80 >= imagegd3.x) && (imaged5.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged5.y+80 >= imagegd3.y) && (imaged5.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged5.x=imagegd3.x;
                    imaged5.y=imagegd3.y;
                }
                if (((imaged5.x+80 >= imagegd4.x) && (imaged5.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged5.y+80 >= imagegd4.y) && (imaged5.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged5.x=imagegd4.x;
                    imaged5.y=imagegd4.y;
                }
                if (((imaged5.x+80 >= imagegd5.x) && (imaged5.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged5.y+80 >= imagegd5.y) && (imaged5.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged5.x=imagegd5.x;
                    imaged5.y=imagegd5.y;
                }
                if (((imaged5.x+80 >= imagegd6.x) && (imaged5.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged5.y+80 >= imagegd6.y) && (imaged5.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged5.x=imagegd6.x;
                    imaged5.y=imagegd6.y;
                }
                if (((imaged5.x+80 >= imagegd7.x) && (imaged5.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged5.y+80 >= imagegd7.y) && (imaged5.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged5.x=imagegd7.x;
                    imaged5.y=imagegd7.y;
                }
                if (((imaged5.x+80 >= imagegd8.x) && (imaged5.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged5.y+80 >= imagegd8.y) && (imaged5.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged5.x=imagegd8.x;
                    imaged5.y=imagegd8.y;
                }
                if (((imaged5.x+80 >= imagegd9.x) && (imaged5.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged5.y+80 >= imagegd9.y) && (imaged5.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged5.x=imagegd9.x;
                    imaged5.y=imagegd9.y;
                }
                if ((imaged6.x+80 >= imagegd1.x) && (imaged6.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged6.y+80 >= imagegd1.y) && (imaged6.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged6.x=imagegd1.x;
                    imaged6.y=imagegd1.y;
                }
                if ((imaged6.x+80 >= imagegd2.x) && (imaged6.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged6.y+80 >= imagegd2.y) && (imaged6.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged6.x=imagegd2.x;
                    imaged6.y=imagegd2.y;
                }
                if ((imaged6.x+80 >= imagegd3.x) && (imaged6.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged6.y+80 >= imagegd3.y) && (imaged6.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged6.x=imagegd3.x;
                    imaged6.y=imagegd3.y;
                }
                if (((imaged6.x+80 >= imagegd4.x) && (imaged6.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged6.y+80 >= imagegd4.y) && (imaged6.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged6.x=imagegd4.x;
                    imaged6.y=imagegd4.y;
                }
                if (((imaged6.x+80 >= imagegd5.x) && (imaged6.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged6.y+80 >= imagegd5.y) && (imaged6.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged6.x=imagegd5.x;
                    imaged6.y=imagegd5.y;
                }
                if (((imaged6.x+80 >= imagegd6.x) && (imaged6.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged6.y+80 >= imagegd6.y) && (imaged6.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged6.x=imagegd6.x;
                    imaged6.y=imagegd6.y;
                }
                if (((imaged6.x+80 >= imagegd7.x) && (imaged6.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged6.y+80 >= imagegd7.y) && (imaged6.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged6.x=imagegd7.x;
                    imaged6.y=imagegd7.y;
                }
                if (((imaged6.x+80 >= imagegd8.x) && (imaged6.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged6.y+80 >= imagegd8.y) && (imaged6.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged6.x=imagegd8.x;
                    imaged6.y=imagegd8.y;
                }
                if (((imaged6.x+80 >= imagegd9.x) && (imaged6.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged6.y+80 >= imagegd9.y) && (imaged6.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged6.x=imagegd9.x;
                    imaged6.y=imagegd9.y;
                }
                if ((imaged7.x+80 >= imagegd1.x) && (imaged7.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged7.y+80 >= imagegd1.y) && (imaged7.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged7.x=imagegd1.x;
                    imaged7.y=imagegd1.y;
                }
                if ((imaged7.x+80 >= imagegd2.x) && (imaged7.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged7.y+80 >= imagegd2.y) && (imaged7.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged7.x=imagegd2.x;
                    imaged7.y=imagegd2.y;
                }
                if ((imaged7.x+80 >= imagegd3.x) && (imaged7.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged7.y+80 >= imagegd3.y) && (imaged7.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged7.x=imagegd3.x;
                    imaged7.y=imagegd3.y;
                }
                if (((imaged7.x+80 >= imagegd4.x) && (imaged7.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged7.y+80 >= imagegd4.y) && (imaged7.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged7.x=imagegd4.x;
                    imaged7.y=imagegd4.y;
                }
                if (((imaged7.x+80 >= imagegd5.x) && (imaged7.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged7.y+80 >= imagegd5.y) && (imaged7.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged7.x=imagegd5.x;
                    imaged7.y=imagegd5.y;
                }
                if (((imaged7.x+80 >= imagegd6.x) && (imaged7.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged7.y+80 >= imagegd6.y) && (imaged7.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged7.x=imagegd6.x;
                    imaged7.y=imagegd6.y;
                }
                if (((imaged7.x+80 >= imagegd7.x) && (imaged7.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged7.y+80 >= imagegd7.y) && (imaged7.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged7.x=imagegd7.x;
                    imaged7.y=imagegd7.y;
                }
                if (((imaged7.x+80 >= imagegd8.x) && (imaged7.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged7.y+80 >= imagegd8.y) && (imaged7.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged7.x=imagegd8.x;
                    imaged7.y=imagegd8.y;
                }
                if (((imaged7.x+80 >= imagegd9.x) && (imaged7.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged7.y+80 >= imagegd9.y) && (imaged7.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged7.x=imagegd9.x;
                    imaged7.y=imagegd9.y;
                }
                if ((imaged8.x+80 >= imagegd1.x) && (imaged8.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged8.y+80 >= imagegd1.y) && (imaged8.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged8.x=imagegd1.x;
                    imaged8.y=imagegd1.y;
                }
                if ((imaged8.x+80 >= imagegd2.x) && (imaged8.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged8.y+80 >= imagegd2.y) && (imaged8.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged8.x=imagegd2.x;
                    imaged8.y=imagegd2.y;
                }
                if ((imaged8.x+80 >= imagegd3.x) && (imaged8.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged8.y+80 >= imagegd3.y) && (imaged8.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged8.x=imagegd3.x;
                    imaged8.y=imagegd3.y;
                }
                if (((imaged8.x+80 >= imagegd4.x) && (imaged8.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged8.y+80 >= imagegd4.y) && (imaged8.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged8.x=imagegd4.x;
                    imaged8.y=imagegd4.y;
                }
                if (((imaged8.x+80 >= imagegd5.x) && (imaged8.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged8.y+80 >= imagegd5.y) && (imaged8.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged8.x=imagegd5.x;
                    imaged8.y=imagegd5.y;
                }
                if (((imaged8.x+80 >= imagegd6.x) && (imaged8.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged8.y+80 >= imagegd6.y) && (imaged8.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged8.x=imagegd6.x;
                    imaged8.y=imagegd6.y;
                }
                if (((imaged8.x+80 >= imagegd7.x) && (imaged8.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged8.y+80 >= imagegd7.y) && (imaged8.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged8.x=imagegd7.x;
                    imaged8.y=imagegd7.y;
                }
                if (((imaged8.x+80 >= imagegd8.x) && (imaged8.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged8.y+80 >= imagegd8.y) && (imaged8.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged8.x=imagegd8.x;
                    imaged8.y=imagegd8.y;
                }
                if (((imaged8.x+80 >= imagegd9.x) && (imaged8.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged8.y+80 >= imagegd9.y) && (imaged8.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged8.x=imagegd9.x;
                    imaged8.y=imagegd9.y;
                }
                if ((imaged9.x+80 >= imagegd1.x) && (imaged9.x +carre1->w - 80 <= imagegd1.x +grille1->w)&&(imaged9.y+80 >= imagegd1.y) && (imaged9.y +carre1->h - 80 <= imagegd1.y +grille1->h))
                {
                    imaged9.x=imagegd1.x;
                    imaged9.y=imagegd1.y;
                }
                if ((imaged9.x+80 >= imagegd2.x) && (imaged9.x +carre1->w - 80 <= imagegd2.x +grille1->w)&&(imaged9.y+80 >= imagegd2.y) && (imaged9.y +carre1->h - 80 <= imagegd2.y +grille1->h))
                {

                    imaged9.x=imagegd2.x;
                    imaged9.y=imagegd2.y;
                }
                if ((imaged9.x+80 >= imagegd3.x) && (imaged9.x +carre1->w - 80 <= imagegd3.x +grille1->w)&&(imaged9.y+80 >= imagegd3.y) && (imaged9.y +carre1->h - 80 <= imagegd3.y +grille1->h))
                {

                    imaged9.x=imagegd3.x;
                    imaged9.y=imagegd3.y;
                }
                if (((imaged9.x+80 >= imagegd4.x) && (imaged9.x +carre1->w - 80 <= imagegd4.x +grille1->w))&&((imaged9.y+80 >= imagegd4.y) && (imaged9.y +carre1->h - 80 <= imagegd4.y +grille1->h)))
                {
                    imaged9.x=imagegd4.x;
                    imaged9.y=imagegd4.y;
                }
                if (((imaged9.x+80 >= imagegd5.x) && (imaged9.x +carre1->w - 80 <= imagegd5.x +grille1->w))&&((imaged9.y+80 >= imagegd5.y) && (imaged9.y +carre1->h - 80 <= imagegd5.y +grille1->h)))
                {
                    imaged9.x=imagegd5.x;
                    imaged9.y=imagegd5.y;
                }
                if (((imaged9.x+80 >= imagegd6.x) && (imaged9.x +carre1->w - 80 <= imagegd6.x +grille1->w))&&((imaged9.y+80 >= imagegd6.y) && (imaged9.y +carre1->h - 80 <= imagegd6.y +grille1->h)))
                {
                    imaged9.x=imagegd6.x;
                    imaged9.y=imagegd6.y;
                }
                if (((imaged9.x+80 >= imagegd7.x) && (imaged9.x +carre1->w - 80 <= imagegd7.x +grille1->w))&&((imaged9.y+80 >= imagegd7.y) && (imaged9.y +carre1->h - 80 <= imagegd7.y +grille1->h)))
                {
                    imaged9.x=imagegd7.x;
                    imaged9.y=imagegd7.y;
                }
                if (((imaged9.x+80 >= imagegd8.x) && (imaged9.x +carre1->w - 80 <= imagegd8.x +grille1->w))&&((imaged9.y+80 >= imagegd8.y) && (imaged9.y +carre1->h - 80 <= imagegd8.y +grille1->h)))
                {
                    imaged9.x=imagegd8.x;
                    imaged9.y=imagegd8.y;
                }
                if (((imaged9.x+80 >= imagegd9.x) && (imaged9.x +carre1->w - 80 <= imagegd9.x +grille1->w))&&((imaged9.y+80 >= imagegd9.y) && (imaged9.y +carre1->h - 80 <= imagegd9.y +grille1->h)))
                {
                    imaged9.x=imagegd9.x;
                    imaged9.y=imagegd9.y;
                }
                onclick = 0;


                if((imaged1.x>imagegd3.x+imagegd3.w) || (imaged1.x<imagegd1.x) || (imaged1.y>imagegd9.y+imagegd9.h) || (imaged1.y<imagegd1.y) )
                {
                    imaged1.x = 720;
                    imaged1.y = 103.5;
                }
                if((imaged2.x>imagegd3.x+imagegd3.w) || (imaged2.x<imagegd1.x) || (imaged2.y>imagegd9.y+imagegd9.h) || (imaged2.y<imagegd1.y) )
                {
                    imaged2.x = 600;
                    imaged2.y = 103.5;
                }

                if((imaged3.x>imagegd3.x+imagegd3.w) || (imaged3.x<imagegd1.x) || (imaged3.y>imagegd9.y+imagegd9.h) || (imaged3.y<imagegd1.y) )
                {
                    imaged3.x = 600;
                    imaged3.y = 272;
                }
                if((imaged4.x>imagegd3.x+imagegd3.w) || (imaged4.x<imagegd1.x) || (imaged4.y>imagegd9.y+imagegd9.h) || (imaged4.y<imagegd1.y) )
                {
                    imaged4.x = 840;
                    imaged4.y = 103.5;
                }
                if((imaged5.x>imagegd3.x+imagegd3.w) || (imaged5.x<imagegd1.x) || (imaged5.y>imagegd9.y+imagegd9.h) || (imaged5.y<imagegd1.y) )
                {
                    imaged5.x = 840;
                    imaged5.y = 272;
                }
                if((imaged6.x>imagegd3.x+imagegd3.w) || (imaged6.x<imagegd1.x) || (imaged6.y>imagegd9.y+imagegd9.h) || (imaged6.y<imagegd1.y) )
                {
                    imaged6.x = 720;
                    imaged6.y = 272;
                }
                if((imaged7.x>imagegd3.x+imagegd3.w) || (imaged7.x<imagegd1.x) || (imaged7.y>imagegd9.y+imagegd9.h) || (imaged7.y<imagegd1.y) )
                {
                    imaged7.x = 600;
                    imaged7.y = 440;
                }
                if((imaged8.x>imagegd3.x+imagegd3.w) || (imaged8.x<imagegd1.x) || (imaged8.y>imagegd9.y+imagegd9.h) || (imaged8.y<imagegd1.y) )
                {
                    imaged8.x = 840;
                    imaged8.y = 440;
                }
                if((imaged9.x>imagegd3.x+imagegd3.w) || (imaged9.x<imagegd1.x) || (imaged9.y>imagegd9.y+imagegd9.h) || (imaged9.y<imagegd1.y) )
                {
                    imaged9.x = 720;
                    imaged9.y = 440;
                }



                break;
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if( onclick==1 )
                {
                    imaged1.x = event.motion.x-(carre1->w/2);
                    imaged1.y = event.motion.y-(carre1->h/2);
                }
                if( onclick==2 )
                {
                    imaged2.x = event.motion.x-(carre2->w/2);
                    imaged2.y = event.motion.y-(carre2->h/2);
                }
                if( onclick==3 )
                {
                    imaged3.x = event.motion.x-(carre3->w/2);
                    imaged3.y = event.motion.y-(carre3->h/2);
                }
                if( onclick==4 )
                {
                    imaged4.x = event.motion.x-(carre4->w/2);
                    imaged4.y = event.motion.y-(carre4->h/2);
                }
                if( onclick==5 )
                {
                    imaged5.x = event.motion.x-(carre5->w/2);
                    imaged5.y = event.motion.y-(carre5->h/2);
                }
                if( onclick==6 )
                {
                    imaged6.x = event.motion.x-(carre6->w/2);
                    imaged6.y = event.motion.y-(carre6->h/2);
                }
                if( onclick==7 )
                {
                    imaged7.x = event.motion.x-(carre7->w/2);
                    imaged7.y = event.motion.y-(carre7->h/2);
                }
                if( onclick==8 )
                {
                    imaged8.x = event.motion.x-(carre8->w/2);
                    imaged8.y = event.motion.y-(carre8->h/2);
                }
                if( onclick==9 )
                {
                    imaged9.x = event.motion.x-(carre9->w/2);
                    imaged9.y = event.motion.y-(carre9->h/2);
                }
            }
        }
        SDL_FillRect(fenetre, 0, SDL_MapRGB(fenetre->format, 2, 33, 0));

        SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
        score(t1);
        SDL_BlitSurface( grille1 ,NULL, fenetre, &imagegd1 );
        SDL_BlitSurface( grille2 ,NULL, fenetre, &imagegd2 );
        SDL_BlitSurface( grille3 ,NULL, fenetre, &imagegd3 );
        SDL_BlitSurface( grille4 ,NULL, fenetre, &imagegd4 );
        SDL_BlitSurface( grille5 ,NULL, fenetre, &imagegd5 );
        SDL_BlitSurface( grille6 ,NULL, fenetre, &imagegd6 );
        SDL_BlitSurface( grille7 ,NULL, fenetre, &imagegd7 );
        SDL_BlitSurface( grille8 ,NULL, fenetre, &imagegd8 );
        SDL_BlitSurface( grille9 ,NULL, fenetre, &imagegd9 );
        SDL_BlitSurface( btnew ,NULL, fenetre, &imagebnd1 );
        SDL_BlitSurface( btr ,NULL, fenetre, &imagebrd1 );
        SDL_BlitSurface( carre1 ,NULL, fenetre, &imaged1 );
        SDL_BlitSurface( carre2 ,NULL, fenetre, &imaged2 );
        SDL_BlitSurface( carre3 ,NULL, fenetre, &imaged3 );
        SDL_BlitSurface( carre4 ,NULL, fenetre, &imaged4 );
        SDL_BlitSurface( carre5 ,NULL, fenetre, &imaged5 );
        SDL_BlitSurface( carre6 ,NULL, fenetre, &imaged6 );
        SDL_BlitSurface( carre7 ,NULL, fenetre, &imaged7 );
        SDL_BlitSurface( carre8 ,NULL, fenetre, &imaged8 );
        SDL_BlitSurface( carre9 ,NULL, fenetre, &imaged9 );
        SDL_Flip(fenetre);
    }
Mix_FreeMusic(musiquegame);
    /**Fin  While **/
    SDL_BlitSurface( aa ,NULL, fenetre, &aaa );
    win();
    Mix_Music *musique;
    if(sound==1)
     {
         if(strcmp(scpapi,bestscore)<0)
         {
            musique = Mix_LoadMUS("Fichiers/Sounds/aaa.mp3");
            Mix_PlayMusic(musique, -1);
         }
        else
        {
        musique = Mix_LoadMUS("Fichiers/Sounds/a.mp3");
        Mix_PlayMusic(musique, -1);
        }
     }
    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        game();
                    }
                    else if (((event.button.x >= 856) && (event.button.x <= 966))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(sound==1)
                        {
                        Mix_FreeMusic(musique);
                        Mix_CloseAudio();
                        }
                        menu();
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

    Mix_CloseAudio();
    cleanup();

}




void about()
{

    SDL_Surface* bg = IMG_Load("Fichiers/Menu/About/1.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( bg ,NULL, fenetre, &imagebg );
    SDL_Event event;

    while(1)
    {
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        return(0);
                    }
                }
            }
        }
        SDL_Flip(fenetre);
    }

}



void settings()
{
SDL_Surface* t [7];
t[0]= IMG_Load("Fichiers/Menu/Settings/1.png");
t[1]= IMG_Load("Fichiers/Menu/Settings/9.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    if(sound==1)
    SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
    else
    SDL_BlitSurface( t[1] ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);
    SDL_Event event;
    while(1)
    {
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        return(0);
                    }
                    if(((event.button.x >= 409) && (event.button.x <= 619))&&((event.button.y >= 286) && (event.button.y <= 384))&&(sound==1))
                    {
                        SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        SDL_BlitSurface( t[1] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        sound=0;
                        }
                        else if (((event.button.x >= 409) && (event.button.x <= 619))&&((event.button.y >= 286) && (event.button.y <= 384))&&(sound==0))
                    {
                        SDL_BlitSurface( t[1] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
                                        SDL_Flip(fenetre);
                        sound=1;
                        }
                    }
                }
            }
        }
}


void help()
{
SDL_Surface* t [7];
int x=1;
t[0]= IMG_Load("Fichiers/Menu/Help/1.png");
t[1]= IMG_Load("Fichiers/Menu/Help/2.png");
t[2]= IMG_Load("Fichiers/Menu/Help/3.png");
    SDL_Rect imagebg;
    imagebg.x = 0;
    imagebg.y = 0;
    SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
    SDL_Flip(fenetre);
    SDL_Event event;

    while(1)
    {
        if(x>3)
            x=3;
        while (SDL_PollEvent(&event))

        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (((event.button.x >= 75) && (event.button.x <= 160))&&((event.button.y >= 39) && (event.button.y <= 142)))
                    {
                        if(x==1)
                            {
                                return(0);
                    }
                        else
                        x-=1;
                    }
                    if (((event.button.x >= 880) && (event.button.x <= 968))&&((event.button.y >= 536) && (event.button.y <= 626)))
                    {
                        x+=1;
                    }
                    }
                }
            }
            switch(x)
                        {
                        case 1:
                            {
                                SDL_BlitSurface( t[0] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        break;
                            }
                            case 2:
                            {
                                SDL_BlitSurface( t[1] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        break;

                            }
                                                        case 3:
                            {
                                SDL_BlitSurface( t[2] ,NULL, fenetre, &imagebg );
                        SDL_Flip(fenetre);
                        break;
                        }
                        }
        }
}




void game()
{
    while(1)
    {
        srand(time(NULL));
        int g = rand() % 5;
        g++;
        switch(g)
        {
        case 0:
            cas1();
            break;
        case 1:
            cas2();
            break;
        case 2:
            cas3();
            break;
        case 3:
            cas4();
            break;
        case 4:
            cas5();
            break;
        case 5:
            cas6();
            break;
        }
    }
        Mix_FreeMusic(musiquegame);
    Mix_CloseAudio();
}
