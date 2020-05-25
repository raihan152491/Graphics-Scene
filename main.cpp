#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <windows.h>
#include <glut.h>
#include <gl.h>
#include <time.h>
#include<cstring>
#include<mmsystem.h>


float r,g,b;
float r1,g1,b1;
float r2,g2,b2;
int p1=325;
int p2=325+350;
int drawaxes;

#define pi (2*acos(0.0))
#define HIGHT 1000
#define WIDTH 1000

struct point2d
{
    double x, y;
};
struct manKind
{
    double x,y;
    int type;
    double size_;
    double r,g,b;

};
struct manKind mankind[200];
int man_count;

struct point2d cp[200];
int cpidx;
double red=1,green,blue;

void drawSquare()
{
    glBegin(GL_QUADS);
    {
        glVertex3d( 3,  3, 0);
        glVertex3d( 3, -3, 0);
        glVertex3d(-3, -3, 0);
        glVertex3d(-3,  3, 0);
    }
    glEnd();
}

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex2f( 0,500);
			glVertex2f(1000,500);

			glVertex2f( p1,0);
			glVertex2f(p1,1000);

            glVertex2f(p2,0);
			glVertex2f(p2 ,1000);


		}glEnd();
	}
}




void s_quad()
{
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2d(-4.0,-4.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(4.0,-4.0);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(4.0,4.0);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2d(-4.0,4.0);
    glEnd();

}
void myline(double p1x,double p1y, double p2x,double p2y)
{

    glBegin(GL_LINES);
    {
        glVertex3f(p1x,p1y,0);
        glVertex3f(p2x,p2y,0);

        //glVertex3f(0,0, 100);
        //glVertex3f(0,0,-100);
    }
    glEnd();


}
void mytriangle(double height,double width)
{
    glBegin(GL_LINES);
    {
        glVertex3f( 0, height,2);
        glVertex3f( -width,-height/2,2);
        glVertex3f( -width,-height/2,2);
        glVertex3f(width,-height/2,2);
        glVertex3f(width,-height/2,2);
        glVertex3f( 0, height,2);
    }
    glEnd();

}
void mytrianglefill(float cx,float cy,float width,float height)
{
    glBegin(GL_POLYGON);
    {


        glVertex2f(cx,cy);
        glVertex2f(cx+width,cy);
        glVertex2f(cx+width/2,cy+height);


        //glVertex3f(a, -b,2);
    }
    glEnd();

}
void mySquare(double a,double b)
{
    //glColor3f(1.0,0.0,0.0);



    glBegin(GL_LINES);
    {
        glVertex2f( a, b);
        glVertex2f( -a,b);
        glVertex2f( -a,b);
        glVertex2f(-a,-b);
        glVertex2f(-a,-b);
        glVertex2f(a, -b);
        glVertex2f(a, -b);
        glVertex2f(a, b);

    }
    glEnd();
}
void mySquarefill(float cx,float cy ,float a,float b) // start cx,cy && a=width ,b= height
{
    //glColor3f(1.0,0.0,0.0);



    glBegin(GL_POLYGON);
    {
        glVertex2f( cx, cy);
        glVertex2f( cx+a, cy);
        glVertex2f( cx+a, cy+b);
        glVertex2f( cx, cy+b);

    }
    glEnd();
}
void myCircle(float cx,float cy,float rx,float ry,int num_segments)
{
    int i = 0;
    float angle = 0.0;


    glBegin(GL_LINES);
    {

        for(i = 0; i < 100000; i++)
        {

            angle = 3.1416 *i/num_segments;
            glVertex3f (cx+(cos(angle) * rx), cy+(sin(angle) * ry), 0);
            angle = 3.1416 *(i+1)/num_segments;
            glVertex3f (cx+(cos(angle) * rx), cy+(sin(angle) * ry), 0);


        }

    }
    glEnd();


}


void myCirclefill(float cx,float cy,float rx,float ry,int num_segments){

    glBegin(GL_POLYGON);
    int i;
    for(i=0;i<num_segments;i++)
    {
        float theta=2.0f*3.1415926f*float(i)/float(num_segments);
        float x=rx*cosf(theta);
        float y=ry*sinf(theta);

        glVertex2f(x+cx,y+cy);

    }
    glEnd();


}
void myCirclefillUpper(float cx,float cy,float rx,float ry,int num_segments){

    glBegin(GL_POLYGON);
    int i;
    for(i=0;i<num_segments;i++)
    {
        float theta=2.0f*3.1415926f*float(i)/float(num_segments);
        float x=rx*cosf(theta);
        float y=ry*sqrt(sinf(theta)*sinf(theta));

        glVertex2f(x+cx,y+cy);

    }
    glEnd();


}
void myCirclefillLower(float cx,float cy,float rx,float ry,int num_segments){

    glBegin(GL_POLYGON);
    int i;
    for(i=0;i<num_segments;i++)
    {
        float theta=2.0f*3.1415926f*float(i)/float(num_segments);
        float x=rx*cosf(theta);
        float y=-1*ry*sqrt(sinf(theta)*sinf(theta));

        glVertex2f(x+cx,y+cy);

    }
    glEnd();


}
void keyboardListener(unsigned char key, int x,int y){
	switch(key){

        case '1':
			break;
        case 'r':
            red=1;
            green=0;
            blue = 0;
            break;
        case 'b':
            red=0;
            green=0;
            blue = 1;
            break;
        case 'g':
            red=0;
            green=1;
            blue = 0;
            break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			break;
		case GLUT_KEY_UP:		// up arrow key
			break;

		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP

                std::cout << x << " " << WIDTH-y << std::endl;

                //cp[cpidx].x = (double)x;
                //cp[cpidx].y = (double)(600 - y);
               // std::cout << cp[cpidx].x << " " << cp[cpidx].y << std::endl;
               // cpidx++;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}

void door(float cx,float cy,float wd,float hg,int seg){



    /// lock
    glColor3f(.1,.1,.1);
    myCirclefill(cx+(wd-10),cy+wd/2+wd/1.5,10,10,100);


    int x1=10; //  stripe width
    int y1=hg; // stripe height



    int j,q=0;
    for(j=0;j<seg;j++) // stripe  column
    {
            glColor3f(r1,g1,b1);
            mySquarefill(cx+2+q,0,x1,y1);
            q=q+x1+5;




    }
    //door background
    glColor3f(r,g,b);
    mySquarefill(cx,cy,wd,hg);

}
void setDoor(){

    r=0.4;g=0.0;b=0.0;//  color back
    r1=0.40;g1=0.20;b1=0.00; //
    door(415,0,175,380,12);
}
void window(float cx,float cy,float wd,float hg,int gp){

    mySquarefill(cx,cy,wd,hg);
    mySquarefill(cx+gp+wd,cy,wd,hg);
    mySquarefill(cx+gp+wd,cy+gp+hg,wd,hg);
    mySquarefill(cx,cy+gp+hg,wd,hg);



}
void window2(float cx,float cy,float wd,float hg,int gp){




    glColor3f(r,g,b);
   // glColor3f(1.0,0.0,0.0);
    mySquarefill((cx+(wd-gp)/2),cy,gp,hg);
    mySquarefill((cx),(cy+(hg-gp)/2),wd,gp);
    glColor3f(r1,g1,b1);
    mySquarefill(cx,cy,wd,hg);





}
void setWindow(){ // set the window in the house

//    int wd=45;
//    int hg=45;
//    int gp=2;
//    //window type one
//    window(345,620,wd,hg,gp);
//    window(565,620,wd,hg,gp);

    //window type two
    int wd2=90;
    int hg2=90;
    int gp2=3;
    r=0.370;g=0.370;b=0.370;// separator color
    r1=1.0;g1=1.0;b1=0.20; // window color
    window2(345,620,wd2,hg2,gp2); // window top1
    window2(565,620,wd2,hg2,gp2); // window top2

    r=0.370;g=0.370;b=0.370; // separator color
    r1=0.10;g1=0.10;b1=0.10;  // window color
    window2(345,520,wd2,hg2,gp2);
    window2(565,520,wd2,hg2,gp2);

    r=0.370;g=0.370;b=0.370; // separator color
    r1=1.0;g1=0.0;b1=0.20;  // window color
    window2(345,420,wd2,hg2,gp2);

    r=0.370;g=0.370;b=0.370; // separator color
    r1=1.0;g1=1.0;b1=0.20;
    window2(565,420,wd2,hg2,gp2);

}
void brick(){
    int i,j,p,q;
    int x1=30; //  brick width
    int y1=15; // brick height
    int size1=37; // how many brick row
    int size2=10; // how many brick in each row

    p=0;
    q=0;
    int x2=1;
    int y2=1;
    glColor3f(0.400,0.0,0.0);

    for(i=0;i<size1;i++) //brick row
    {
        q=0;
        if(i%2==0)
        {
            size2=10; //cz 10 brick in row
        }
        else{
            size2=10-1; //cz 9 brick in row
        }
        for(j=0;j<size2;j++) // brick column
        {
            if(i%2==0) // for even row
            {
                mySquarefill(327+q,735-p,x1,y1);
                q=q+x1+5;

            }
            else{
                    // for odd row
                mySquarefill(342+q,735-p,x1,y1);
                q=q+x1+5;
            }


        }
        p=p+y1+5;

    }







}
void houseBack(float cx,float cy,float wd,float hg){
    glColor3f(0.400,0.400,0.400);
    mySquarefill(cx,cy,wd,hg);

}

void house()
{




    setDoor();
    setWindow();
    brick(); // house brick
    houseBack(325,0,350,750); //house background
    //drawAxes();


}
void moon(float cx,float cy,float r){

    glColor3f(0,0,0);
    myCirclefill(cx+10,cy-3,r-2,r-2,200);

    glColor3f(.8,.8,.8);
    myCirclefill(cx,cy,r,r,200);


}
void wall(float cx,float cy,float wd,float hg,int seg){


    mySquarefill(cx,cy,wd,hg);

    int j,p=-1;
    int x=30;
    int y=30;
    glColor3f(r1,g1,b1);
    for(j=0;j<seg;j++){

        mytrianglefill(cx+p,cy+hg,x,y);
        p=p+(wd/seg);
    }



}
void setWall(){



    r=0.30;g=0.60;b=0.0;
    r1=0.90;g1=0.90;b1=0.50;
    //wall left
    float cx1=100;
    float cy1=0;
    float wd1=225;
    float hg1=200;
    float seg1=10;



    glColor3f(r,g,b);
    wall(cx1,cy1,wd1,hg1,seg1);

    //wall right
    float cx2=675;
    float cy2=0;
    float wd2=225;
    float hg2=200;
    float seg2=10;

    glColor3f(r,g,b);
    wall(cx2,cy2,wd2,hg2,seg2);

}
void setLamp(){


    r=0.40;g=0.20;b=0.0;
    r1=0.0;g1=0.40;b1=0.20;
    // Lamp left

    float cx1=200;
    float cy1=0;
    float wd1=15;
    float hg1=380;


    glColor3f(r1,g1,b1);
    myCirclefill( (cx1+(wd1)/2),hg1,50,100,100 );
    glColor3f(r,g,b);
    mySquarefill(cx1,cy1,wd1,hg1); // handle


    // right Lamp
    float cx2=795;
    float cy2=0;
    float wd2=15;
    float hg2=380;

    r1=0.0;g1=0.20;b1=0.10;

    glColor3f(r1,g1,b1);
    myCirclefill( (cx2+(wd2)/2),hg2,80,80,100 );
    glColor3f(r,g,b);
    mySquarefill(cx2,cy2,wd2,hg2); // handle



}
void setField(){

    r1=0.50;g1=0.30;b1=0.10;
    float cx1=500;
    float cy1=0;
    float wd1=500;
    float hg1=60;
    glColor3f(r1,g1,b1);
    myCirclefill(cx1,cy1,wd1,hg1,100);

}
void outside(){


    setWall();
    setLamp();


}
void crateMan(float cx,float cy,float bodyWd,float bodyHg){




    float legWd=bodyWd/3.5;
    float legHg=bodyWd;
    float shoeWd=legWd;
    float shoeHg=25;
    float gp=5;
    float headWd=bodyWd/2;
    float eyes=10;
    float lipsWd=20;
    float lipsHg=6;

    float handWd=bodyHg/1.3;
    float handHg=legWd/1.4;
    float angleUp=65;
    float angleLow=115;



  /// upper hand

    glPushMatrix();///
    glTranslatef((cx-gp+handHg),(cy+legHg+shoeHg),0);
    glRotatef(angleUp,0,0,1);
    glTranslatef(-(cx-gp+handHg),-(cy+legHg+shoeHg),0);
    glColor3f(1,1,1);
    mySquarefill(cx-gp+handHg,cy+legHg+shoeHg,handWd,handHg);

    glPopMatrix();///





    ///eyes
    glColor3f(0,0,0);
    mySquarefill((cx-gp)+(bodyWd/2)+(headWd/2.2),cy+bodyHg+legHg+shoeHg+headWd-12,eyes,eyes);

    ///lips
    glColor3f(0,0,0);
    mySquarefill((cx)+(bodyWd/2),cy+bodyHg+legHg+shoeHg+11,lipsWd,lipsHg);


    ///cap
    glColor3f(0,1,0);
    myCirclefillUpper((cx-gp)+(bodyWd/2),cy+bodyHg+legHg+shoeHg+headWd,headWd,headWd,100);
    mySquarefill((cx-gp)+(bodyWd/2),cy+bodyHg+legHg+shoeHg+headWd,headWd+35,8);


    ///Head
    glColor3f(r2,g2,b2);
    myCirclefill((cx-gp)+(bodyWd/2),cy+bodyHg+legHg+shoeHg+headWd,headWd,headWd,100);


    ///body
    glColor3f(r,g,b);
    mySquarefill(cx-gp,cy+legHg+shoeHg,bodyWd,bodyHg);


    ///legs
    glColor3f(r1,g1,b1);
    mySquarefill(cx,cy+shoeHg,legWd,legHg);///left leg






    mySquarefill((cx-gp)+bodyWd-(legWd+gp),cy+shoeHg,legWd,legHg);

    ///shoes
    glColor3f(0,0,0);
    mySquarefill(cx,cy,legWd,shoeHg);///left shoe

    glPushMatrix();
    glTranslatef(cx,cy,0);
    glRotatef(90,0,0,1);
    glTranslatef(-cx,-cy,0);
    mytrianglefill(cx,cy,legWd,shoeHg/6);///left shoe rotate
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cx+legWd,cy+legWd,0);
    glRotatef(270,0,0,1);
    glTranslatef(-(cx+legWd),-(cy+legWd),0);
    mytrianglefill(cx+legWd,cy+legWd,legWd,shoeHg/6);///left leg rotate
    glPopMatrix();


    /// right shoe

    mySquarefill((cx-gp)+bodyWd-(legWd+gp),cy,legWd,shoeHg);


    glPushMatrix();
    glTranslatef((cx-gp)+bodyWd-(legWd+gp),cy,0);
    glRotatef(90,0,0,1);
    glTranslatef(-((cx-gp)+bodyWd-(legWd+gp)),-cy,0);
    mytrianglefill((cx-gp)+bodyWd-(legWd+gp),cy,legWd,shoeHg/6);///right shoe rotate
    glPopMatrix();


    glPushMatrix();
    glTranslatef((cx-gp)+bodyWd-(legWd+gp)+legWd,cy+legWd,0);
    glRotatef(270,0,0,1);
    glTranslatef(-((cx-gp)+bodyWd-(legWd+gp)+legWd),-(cy+legWd),0);
    mytrianglefill((cx-gp)+bodyWd-(legWd+gp)+legWd,cy+legWd,legWd,shoeHg/6);///right shoe rotate
    glPopMatrix();



    /// lower hand

    glPushMatrix();///
    glTranslatef((cx-gp-gp+handHg+bodyWd),(cy+legHg+shoeHg+gp*3),0);
    glRotatef(angleLow,0,0,1);
    glTranslatef(-(cx-gp-gp+handHg+bodyWd),-(cy+legHg+shoeHg+gp*3),0);
    glColor3f(1,1,1);
    mySquarefill(cx-gp-gp+handHg+bodyWd,cy+legHg+shoeHg+gp*3,handWd,handHg);

    glPopMatrix();///



}
void man(){

    r=1.0;g=0.0;b=0.0;
    r1=0.0;g1=0.0;b1=1.0;
    r2=1.0;g2=1.0;b2=1.0;

    crateMan(300,35,80,120);

}
void star(int smallNum,float sm,int bigNum,float bg){

    srand (time(NULL));
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(sm);
    glBegin(GL_POINTS);

    int px,py;
    for(int i = 0;i<smallNum;i++)
    {
        px=rand() % 1000 + 1;
        py=rand() % 1000 + 1;
        glVertex2f(px,py);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(bg);
    glBegin(GL_POINTS);


    for(int i = 0;i<bigNum;i++)
    {
        px=rand() % 1000 + 1;
        py=rand() % 1000 + 1;
        glVertex2f(px,py);
    }
    glEnd();


}
void display(){

	///clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//gluLookAt(0,0,0,	0,0,-1,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	man();
	moon(150,850,40);
    setField();
    house();
    outside();
    star(200,1,200,3);




    //myCirclefill(500,500,5,5,100);

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){


	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization

	cpidx = 0;
    drawaxes=1;
	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	gluOrtho2D(0, HIGHT, 0, WIDTH);
	//gluPerspective(80,	1,	1,	1000.0);

}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(HIGHT, WIDTH);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
