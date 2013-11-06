#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <conio.h>
//#include <dos.h>
#include <stdlib.h>
#include "../dis/dis.h"
#include "graphics.h"
#include "glenz.h"
#include "vec.h"

extern int sin1024[];

void zoomer1(char *pic);

char bgpic[65535];

//extern char fc[];
char *fcrow[100];
char *fcrow2[16];

//char far *vram=(char far *)0xa0000000L;

extern int lightshift;

//extern int _ndebug1;

//extern char asmtestmode;


extern void (*demomode[])(int, int*);

#if 0
int    cubepoints[]={8,
-999,-999,-999,
999,-999,-999,
999,999,-999,
-999,999,-999,
-999,-999,999,
999,-999,999,
999,999,999,
-999,999,999
};
int cubeepolys[]={
4,0x4002,0,1,2,3,
4,0x4004,4,5,6,7,
4,0x4008,0,1,5,4,
4,0x4006,1,2,6,5,
4,0x400c,2,3,7,6,
4,0x400a,3,0,4,7,
0};
#endif

#define ZZZ 50
#define QQQ 99

int    points[64]={14,
-100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,100*ZZZ,100*ZZZ,
-100*ZZZ,100*ZZZ,100*ZZZ,
0*ZZZ,0*ZZZ,-170*ZZZ,
0*ZZZ,0*ZZZ,170*ZZZ,
170*ZZZ,0*ZZZ,0*ZZZ,
-170*ZZZ,0*ZZZ,0*ZZZ,
0*ZZZ,170*ZZZ,0*ZZZ,
0*ZZZ,-170*ZZZ,0*ZZZ};
#if 0
int    points1[64]={14,
-100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,100*ZZZ,100*ZZZ,
-100*ZZZ,100*ZZZ,100*ZZZ,
0*ZZZ,0*ZZZ,-170*ZZZ,
0*ZZZ,0*ZZZ,170*ZZZ,
170*ZZZ,0*ZZZ,0*ZZZ,
-170*ZZZ,0*ZZZ,0*ZZZ,
0*ZZZ,170*ZZZ,0*ZZZ,
0*ZZZ,-170*ZZZ,0*ZZZ};
int    points9[64]={14,
-111*ZZZ,-111*ZZZ,-111*ZZZ,
111*ZZZ,-111*ZZZ,-111*ZZZ,
111*ZZZ,111*ZZZ,-111*ZZZ,
-111*ZZZ,111*ZZZ,-111*ZZZ,
-111*ZZZ,-111*ZZZ,111*ZZZ,
111*ZZZ,-111*ZZZ,111*ZZZ,
111*ZZZ,111*ZZZ,111*ZZZ,
-111*ZZZ,111*ZZZ,111*ZZZ,
0*ZZZ,0*ZZZ,-122*ZZZ,
0*ZZZ,0*ZZZ,144*ZZZ,
122*ZZZ,0*ZZZ,0*ZZZ,
-144*ZZZ,0*ZZZ,0*ZZZ,
0*ZZZ,122*ZZZ,0*ZZZ,
0*ZZZ,-144*ZZZ,0*ZZZ};
int    points8[64]={14,
-140*ZZZ,-140*ZZZ,-140*ZZZ,
140*ZZZ,-140*ZZZ,-140*ZZZ,
140*ZZZ,140*ZZZ,-140*ZZZ,
-140*ZZZ,140*ZZZ,-140*ZZZ,
-140*ZZZ,-140*ZZZ,140*ZZZ,
140*ZZZ,-140*ZZZ,140*ZZZ,
140*ZZZ,140*ZZZ,140*ZZZ,
-140*ZZZ,140*ZZZ,140*ZZZ,
0*ZZZ,0*ZZZ,-140*ZZZ,
0*ZZZ,0*ZZZ,140*ZZZ,
190*ZZZ,0*ZZZ,0*ZZZ,
-190*ZZZ,0*ZZZ,0*ZZZ,
0*ZZZ,140*ZZZ,0*ZZZ,
0*ZZZ,-140*ZZZ,0*ZZZ};
int    points7[64]={14,
-100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,-100*ZZZ,-100*ZZZ,
100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,100*ZZZ,-100*ZZZ,
-100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,-100*ZZZ,100*ZZZ,
100*ZZZ,100*ZZZ,100*ZZZ,
-100*ZZZ,100*ZZZ,100*ZZZ,
0*ZZZ,0*ZZZ,-170*ZZZ,
0*ZZZ,0*ZZZ,170*ZZZ,
170*ZZZ,0*ZZZ,0*ZZZ,
-170*ZZZ,0*ZZZ,0*ZZZ,
0*ZZZ,170*ZZZ,0*ZZZ,
0*ZZZ,-170*ZZZ,0*ZZZ};
#endif
int    pointsb[64]={14,
-60*QQQ,-60*QQQ,-60*QQQ,
60*QQQ,-60*QQQ,-60*QQQ,
60*QQQ,60*QQQ,-60*QQQ,
-60*QQQ,60*QQQ,-60*QQQ,
-60*QQQ,-60*QQQ,60*QQQ,
60*QQQ,-60*QQQ,60*QQQ,
60*QQQ,60*QQQ,60*QQQ,
-60*QQQ,60*QQQ,60*QQQ,
0,0,-105*QQQ,
0,0,105*QQQ,
105*QQQ,0,0,
-105*QQQ,0,0,
0,105*QQQ,0,
0,-105*QQQ,0};
int    points2[256];
int    points2b[256];
int points3[256*2];
#if 0
int edges[64]={12,0,
0,1,0,0,
1,2,0,0,
2,3,0,0,
3,0,0,0,
4,5,0,0, // 4
5,6,0,0,
6,7,0,0,
7,4,0,0,
0,4,0,0, // 8
1,5,0,0,
2,6,0,0,
3,7,0,0};
int edges2[64];
int polys[64]={
4,0x4010,0,1,2,3,
4,0x4008,0,8,4,9,
4,0x4010,1,9,5,10,
4,0x4020,2,10,6,11,
4,0x4040,3,11,7,12,
4,0x4080,4,5,6,7,
0};
#endif

int epolys[]={
3,0x4002,0,1,8,
3,0x4004,1,2,8,
3,0x4006,2,3,8,
3,0x4008,3,0,8,

3,0x400a,2,1,10,
3,0x400c,1,5,10,
3,0x400e,5,6,10,
3,0x4010,6,2,10,

3,0x4012,2,6,12,
3,0x4014,6,7,12,
3,0x4016,7,3,12,
3,0x4018,3,2,12,

3,0x401a,0,3,11,
3,0x401c,3,7,11,
3,0x401e,7,4,11,
3,0x4020,4,0,11,

3,0x4022,5,1,13,
3,0x4024,1,0,13,
3,0x4026,0,4,13,
3,0x4028,4,5,13,

3,0x402a,5,4,9,
3,0x402c,4,7,9,
3,0x402e,7,6,9,
3,0x4030,6,5,9,

0};

int epolysb[]={
3,0x4004,0,1,8,
3,0x4002,1,2,8,
3,0x4004,2,3,8,
3,0x4002,3,0,8,

3,0x4004,2,1,10,
3,0x4002,1,5,10,
3,0x4004,5,6,10,
3,0x4002,6,2,10,

3,0x4004,2,6,12,
3,0x4002,6,7,12,
3,0x4004,7,3,12,
3,0x4002,3,2,12,

3,0x4004,0,3,11,
3,0x4002,3,7,11,
3,0x4004,7,4,11,
3,0x4002,4,0,11,

3,0x4004,5,1,13,
3,0x4002,1,0,13,
3,0x4004,0,4,13,
3,0x4002,4,5,13,

3,0x4004,5,4,9,
3,0x4002,4,7,9,
3,0x4004,7,6,9,
3,0x4002,6,5,9,

0};
int polylist[256];
int matrix[9];

extern  char    backpal[16*3];
char    pal[768];

static char fc[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00,
0x0d, 0x09, 0x0d,
0x10, 0x0b, 0x10,
0x12, 0x0d, 0x12,
0x14, 0x0f, 0x14,
0x16, 0x10, 0x16,
0x18, 0x12, 0x18,
0x1a, 0x14, 0x1b,
0x18, 0x12, 0x1b,
0x16, 0x10, 0x19,
0x14, 0x0f, 0x17,
0x12, 0x0e, 0x15,
0x10, 0x0d, 0x13,
0x0e, 0x0b, 0x11,
0x0c, 0x0a, 0x0f,
//0x0b, 0x09, 0x0d
0x20, 0x20, 0x20	// CM: Workaround for chessboard fadeout
};

#if 0
int testlist[]={
3,16, 190,100, 90,50, 110,150,
3,20, 10,100, 90,50, 99,150,
0};
#endif

void    waitb(void)
{
#if 0
    while(!(inp(0x3da)&8));
    while((inp(0x3da)&8));
#endif
}

char tmppal[768];

int repeat=0;
int frame=0;

//#pragma check_stack(off)
void /*_loadds*/ copper(void)
{
	int	a;
	repeat++;
        for(a=0;a<16;a++) setrgb(a, pal[a*3], pal[a*3+1], pal[a*3+2]);
}
//#pragma check_stack(on)
    
int main()
{
    int a,b,c,/*x,*/y,rx,ry,rz,/*n=8,p1,p2,*/r,g,zpos=7500,y1,y2,/*rya,*/ypos,yposa;
    int ya,yy,boingm=6,boingd=7;
    int jello=0,jelloa=0/*,bigjello=0,bigjelloa=0*/;
    int xscale=120,yscale=120,zscale=120,bscale=0;
    int oxp=0,oyp=0,ozp=0;
    int oxb=0,oyb=0,ozb=0;
    //int bscaleflag=0;
    //int	repec;
    //int pdy;
    //int lasta=-1;
    char    *ps,*pd,*pp;
    //unsigned int u;

    dis_partstart();

    while(!dis_exit() && dis_musplus()<-19) ;
    dis_setmframe(0);

    zoomer2();

    if (init_graphics("Glenz", window_width, window_height) < 0) {
        fprintf(stderr, "Can't init graphics\n");
        return -1;
    };

    init_opengl(window_width, window_height);

    projection();

#if 0
    _asm mov dx,3c4h
    _asm mov ax,0f02h
    _asm out dx,ax
    memset(vram,0,65535);
    _asm
    {
        mov ax,13h
        int 010h
    }
    testasm();
#endif

    for(a=0;a<100;a++)
    {
        fcrow[a]=fc+768+16+a*320;
    }
    for(a=0;a<16;a++)
    {
        fcrow2[a]=fc+768+16+a*320+100*320;
    }
    
#if 0
    outp(0x3c8,0);
    for(a=0;a<768;a++) outp(0x3c9,0);
    outp(0x3c8,0);
    for(a=0;a<16*3;a++) outp(0x3c9,fc[a+16]);
#endif

    for(a=0;a<16;a++) setrgb(a,fc[(a+16)*3],fc[(a+16)*3+1],fc[(a+16)*3+2]);

    yy=0; ya=0;
    while(!dis_exit())
    {
        ya++; yy+=ya;
        if(yy>48*16)
        {
            yy-=ya;
            ya=-ya*2/3;
            if(ya>-4 && ya<4) break;
        }
        y=yy/16;
        y1=130+y/2;
        y2=130+y*3/2;
        if(y2!=y1) b=25600/(y2-y1);
        //pd=vram+(y1-4)*320; pdy=y1;
        for(ry=y1-4;ry<y1;ry++,pd+=320)
        {
            if(ry>199) continue;
            //memset(pd,0,320);
        }
        for(c=0,ry=y1;ry<y2;ry++,pd+=320,c+=b)
        {
            if(ry>199) continue;
            //memcpy(pd,fcrow[c/256],320);
        }
        for(c=0;c<16;c++,pd+=320,ry++)
        {
            if(ry>199) continue;
            //if(c>7) memset(pd,0,320);
            //else memcpy(pd,fcrow2[c],320);
        }
        waitb();
    }
    
    //while(!dis_exit() && dis_getmframe()<300);
    dis_waitb();

    //initnewgroup();
    for(a=0;a<16;a++)
    {
        ps=fc+0x10+a*3;
        pd=backpal+a*3;
        pd[0]=ps[0];
        pd[1]=ps[1];
        pd[2]=ps[2];
    }
    pp=tmppal;
    for(a=0;a<256;a++)
    {
        if(a<16) b=a;
        else
        {
            b=a&7;
        }
        r=backpal[b*3+0];
        g=backpal[b*3+1];
        b=backpal[b*3+2];
        if((a&8) && a>15)
        {
            r+=16;
            g+=16;
            b+=16;
        }
        if(r>63) r=63;
        if(g>63) g=63;
        if(b>63) b=63;
	*pp++=r;
	*pp++=g;
	*pp++=b;
    }
    for(a=0;a<768/3;a++)
    {
	setrgb(a, tmppal[a*3], tmppal[a*3+1], tmppal[a*3+2]);
    }
    lightshift=9;
    rx=ry=rz=0;
    ypos=-9000; yposa=0;
    dis_waitb();
    //memcpy(bgpic,vram,64000);
    
    //while(!dis_exit() && dis_getmframe()<333);

    memcpy(pal,backpal,16*3);
    dis_partstart();
    dis_waitb();

    for(a=0;a<16;a++) getrgb(a,&pal[a*3]);
    //dis_setcopper(0,copper);
    while(frame<7000 && !dis_exit())
    {
	poll_event();
	clear_screen();
	copper();

        a=dis_musplus(); if(a<0 && a>-16) break;
        
	repeat=dis_waitb();
        //outp(0x3c8,0);
        //for(a=0;a<16*3;a++) outp(0x3c9,pal[a]);
        for(a=0;a<16;a++) setrgb(a, pal[a*3], pal[a*3+1], pal[a*3+2]);
	//setrgb(0, 8, 8, 8);	// XXX
	//setrgb(4, 12, 12, 12);
	
	while(repeat--)
        {
            frame++;
            rx+=32; ry+=7;
	    rx%=3*3600; ry%=3*3600; rz%=3*3600;
            
            if(frame>900)
            {
                b=frame-900;
		/*
		if(b<=256)
		{
			c=256-b;
			for(a=1;a<14*3+1;a++)
			{
				points[a]=(points1[a]*c+points9[a]*b)/256L;
			}
		}
		else if(b<=512)
		{
			b-=256;
			c=256-b;
			for(a=1;a<14*3+1;a++)
			{
				points[a]=(points9[a]*c+points8[a]*b)/256L;
			}
		}
		else if(b<=768)
		{
			b-=512;
			c=256-b;
			for(a=1;a<14*3+1;a++)
			{
				points[a]=(points8[a]*c+points7[a]*b)/256L;
			}
		}
		*/
                a=frame-900;
		b=frame-900; if(b>50) b=50;
                oxp=sin1024[(a*3)&1023]*b/10;
                oyp=sin1024[(a*5)&1023]*b/10;
                ozp=(sin1024[(a*4)&1023]/2+128)*b/16;
		if(frame>1800)
		{
			a=frame-1800+64;
			if(a>1024) a=1024;
	                oxb=(int)(-sin1024[(a*6)&1023])*(int)a/40L;
	                oyb=(int)(-sin1024[(a*7)&1023])*(int)a/40L;
	                ozb=(int)(sin1024[(a*8)&1023]+128)*(int)a/40L;
		}
		else
		{
	                oxb=-sin1024[(a*6)&1023];
	                oyb=-sin1024[(a*7)&1023];
	                ozb=sin1024[(a*8)&1023]+128;
		}
		b=1800-frame;
		if(b<0) 
		{
			if(b<-99) b=-99;
			oyp-=b*b/2;
		}
            }
            
            if(frame>800)
            {
                if(frame>1220+789)
                {
                    if(xscale>0) xscale-=1;
                    if(yscale>0) yscale-=1;
                    if(zscale>0) zscale-=1;
		    if(bscale>0) bscale-=1;
                }
                else if(frame>1400+789)
                {
                    if(bscale>0) bscale-=8;
                    if(bscale<0) bscale=0;
                }
                else
                {
                    if(bscale<180) bscale+=2;
		    else bscale=180;
                }
                if(bscale>xscale) lightshift=10;
            }
            else
            {
                if(frame<640+70)
                {
                    yposa+=31;
                    ypos+=yposa/40; 
                    if(ypos>-300)
                    {
                        ypos-=yposa/40;
                        yposa=-yposa*boingm/boingd;
                        boingm+=2; boingd++;
                        //jelloa=500;
                    }
                    if(ypos>-900 && yposa>0)
                    {
                        jello=(ypos+900)*5/3;
                        jelloa=0;
                    }
                }
                else
                {
                    if(ypos>-2800) ypos-=16;
                    else if(ypos<-2800) ypos+=16;
                }
                yscale=xscale=120+jello/30;
                zscale=120-jello/30;
                a=jello;
                jello+=jelloa;
                if((a<0 && jello>0) || (a>0 && jello<0))
                {
                    jelloa=jelloa*5/6;
                }
                a=jello/20;
                jelloa-=a;
            }

            if(frame>1280+789)
            {
	            b=1280+789+64-frame;
	            if(b<0) b=0;
	            for(a=0;a<16*3;a++) pal[a]=backpal[a]*b/64;
            }
            else if(frame>700)
            {
	            if(frame<765)
	            {
	                b=764-frame;
	                if(b<0) b=0;
	                for(a=0;a<16*3;a++) pal[a]=backpal[a]*b/64;
	            }
	            else if(frame<790)
	            {
	                y=150+(frame-765)*2;
	                memset(bgpic+y*320,0,640);
	                //memset(vram+y*320,0,640);
	                if(frame>785) for(a=0;a<16;a++)
	                {
	                    r=g=b=0;
	                    if(a&1)
	                    {
	                        r+=10;
	                    }
	                    if(a&2)
	                    {
	                        r+=30;
	                    }
	                    if(a&4)
	                    {
	                        r+=20;
	                    }
	                    if(a&8)
	                    {
	                        r+=16;
	                        g+=16;
	                        b+=16;
	                    }
	                    if(r>63) r=63;
	                    if(g>63) g=63;
	                    if(b>63) b=63;
	                    backpal[a*3+0]=r;
	                    backpal[a*3+1]=g;
	                    backpal[a*3+2]=b;
	                }
	            }
	            else if(frame<795)
	            {
		    	memcpy(pal,backpal,16*3);
		    }
   	    }
	}

        cglenzinit();

        if(frame>800 && bscale>4)
        {       
            demomode[0]=demomode[2];
            cmatrix_yxz(3600-rx/3,3600-ry/3,3600-rz/3,matrix);
            csetmatrix(matrix,0,0,0);
            points2b[0]=0; crotlist(points2b,pointsb);
            matrix[0]=bscale*64;
            matrix[1]=0;
            matrix[2]=0;
            matrix[3]=0;
            matrix[4]=bscale*64;
            matrix[5]=0;
            matrix[6]=0;
            matrix[7]=0;
            matrix[8]=bscale*64;
            csetmatrix(matrix,0+oxb,ypos+1500+oyb,zpos+ozb);
            points2[0]=0; crotlist(points2,points2b);
            points3[0]=0; cprojlist((int *)points3,points2);
            ceasypolylist(polylist,epolysb,points3);
            //cglenzpolylist(polylist);

	    blend_alpha();
            draw_poly(polylist);
        }

        if(xscale>4)
        {
            demomode[0]=demomode[1];
            cmatrix_yxz(rx,ry,rz,matrix);
            csetmatrix(matrix,0,0,0);
            points2b[0]=0; crotlist(points2b,points);
            matrix[0]=xscale*64;
            matrix[1]=0;
            matrix[2]=0;
            matrix[3]=0;
            matrix[4]=yscale*64;
            matrix[5]=0;
            matrix[6]=0;
            matrix[7]=0;
            matrix[8]=zscale*64;
            csetmatrix(matrix,0+oxp,ypos+1500+oyp,zpos+ozp);
            points2[0]=0; crotlist(points2,points2b);
            if(frame<800) ccliplist(points2);
            points3[0]=0; cprojlist((int *)points3,points2);
            ceasypolylist(polylist,epolys,points3);
            //cglenzpolylist(polylist);

	    blend_color();

	    if (frame < 780) {
            	draw_fc();
	    }

            draw_poly(polylist);
        }
        
        cglenzdone();

	swap_buffers();
    }
    dis_setcopper(0,NULL);
#if 0
    if(!dis_indemo())
    {
        _asm mov ax,3
        _asm int 10h
    }
#endif

    return 0;
}
