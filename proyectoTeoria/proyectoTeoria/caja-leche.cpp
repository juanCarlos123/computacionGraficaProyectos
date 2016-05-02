
#include "Main.h"
#include "texture.h"

float transZ = -30.0f;
float transY = 0.0f;
float transX = 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float rot1 = 0.0;
float rot2 = 0.0;
float rot3 = 0.0;

boolean encenderLuces = false;

CTexture texturaLeche1;
CTexture texturaLeche2;
CTexture texturaLeche3;

GLfloat Position[] = { 0.0f, 0.0f, 50.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position
//GLfloat colorDifussa[] = { 0.5f, 0.5f, 0.5f, 1.0f };

boolean lecheAnimacion = false;

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	texturaLeche1.LoadTGA("texturas/texturaLeche1.tga");
	texturaLeche1.BuildGLTexture();
	texturaLeche1.ReleaseImage();

	texturaLeche2.LoadTGA("texturas/texturaLeche2.tga");
	texturaLeche2.BuildGLTexture();
	texturaLeche2.ReleaseImage();

	texturaLeche3.LoadTGA("texturas/texturaLeche3.tga");
	texturaLeche3.BuildGLTexture();
	texturaLeche3.ReleaseImage();
	//Configuracion luz

	//glLightfv(GL_LIGHT0, GL_DIFFUSE, colorDifussa);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);

	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable (GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void animacionCajaLeche() {
	if (lecheAnimacion)
	{
			rot2 += 1.0;
			rot3 += 1.0;
			rot1 += 0.1 * (rand() % 10); 
			Sleep(5);
	}
	glutPostRedisplay();
}

void dibujarCajaLeche(GLuint cajaLeche1, GLuint cajaLeche2, GLuint cajaLeche3) {

	glColor3f(0.5f, 0.5f, 0.5f);
	glBindTexture(GL_TEXTURE_2D, cajaLeche2);
	//Cara frontal
	 glBegin(GL_QUADS);
	 glTexCoord2f(0, 0);glVertex3f(-5.0f, -10.0f, 5.0f);
	 glTexCoord2f(1, 0);glVertex3f(5.0f, -10.0f, 5.0f);
	 glTexCoord2f(1, 1);glVertex3f(5.0f, 10.0f, 5.0f);
	 glTexCoord2f(0, 1);glVertex3f(-5.0f, 10.0f, 5.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, cajaLeche1);
	//Cara trasera
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 0); glVertex3f(5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 1); glVertex3f(5.0f, 10.0f, -5.0f);
	glTexCoord2f(0, 1); glVertex3f(-5.0f, 10.0f, -5.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, cajaLeche3);
	//Cara lateral  izq
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(-5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 0);glVertex3f(-5.0f, -10.0f, 5.0f);
	glTexCoord2f(1, 1);glVertex3f(-5.0f, 10.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(-5.0f, 10.0f, -5.0f);
	glEnd();


	glColor3f(0.4f, 0.4f, 0.4f);
	//Lateral der
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 0); glVertex3f(5.0f, -10.0f, 5.0f);
	glTexCoord2f(1, 1); glVertex3f(5.0f, 10.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(5.0f, 10.0f, -5.0f);
	glEnd();



	//Tapas
	//Frontal
	glColor3f(0.3f, 0.4f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f, 10.0f, 5.0f);
	glVertex3f(5.0f, 10.0f, 5.0f);
	glVertex3f(5.0f, 12.5f, 0.0f);
	glVertex3f(-5.0f, 12.5f, 0.0f);
	glEnd();


	//tRASERA
	glColor3f(0.4f, 0.5f, 0.6f);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f, 10.0f, -5.0f);
	glVertex3f(5.0f, 10.0f, -5.0f);
	glVertex3f(5.0f, 12.5f, 0.0f);
	glVertex3f(-5.0f, 12.5f, 0.0f);
	glEnd();

	//Base
	glColor3f(0.1f, 0.5f, 0.6f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 0); glVertex3f(5.0f, -10.0f, -5.0f);
	glTexCoord2f(1, 1); glVertex3f(5.0f, -10.0f, 5.0f);
	glTexCoord2f(0, 1); glVertex3f(-5.0f, -10.0f, 5.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(transX, transY, transZ);
	glRotatef(rot1, 0.0, 1.0, 0.0);
	glRotatef(rot2, 1.0, 0.0, 0.0);
	glRotatef(rot3, 0.0, 0.0, 1.0);

	dibujarCajaLeche(texturaLeche1.GLindex, texturaLeche2.GLindex, texturaLeche3.GLindex);

	animacionCajaLeche();
	glutSwapBuffers ( );	
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'n':
			transY -= 0.2f;
			break;
		case 'N':
			transY +=0.2f;
			break;
		case 'r':
			rot1 -=1.0f;
			break;
		case 'R':
			rot1 +=1.0f;
			break;
			case 't':
			rot2 -=1.0f;
			break;
		case 'T':
			rot2 +=1.0f;
			break;
		case 'y':
			rot3 -=1.0f;
			break;
		case 'Y':
			rot3 +=1.0f;
			break;
		case 'l':
		case 'L':
			if (encenderLuces) {
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
			}
			else {
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
			}
			encenderLuces = !encenderLuces;
			break;
		case 'k':
			lecheAnimacion = !lecheAnimacion;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		AnguloX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		AnguloX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		AnguloY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		AnguloY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto - Caja de leche"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}


