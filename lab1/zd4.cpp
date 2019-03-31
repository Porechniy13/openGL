// подключаем заголовочные файлы библиотек
#include "glew.h"
#include "glut.h"
#include <Windows.h>
// Исходное положение и размер прямоугольника
GLfloat x1 = 0.0f;  GLfloat y1 = 0.0f; GLfloat rsize = 50;
// Величина шага в направлениях х и у (число пикселей,
// на которые на каждом шаге перемещается прямоугольник)
GLfloat xstep = 1.0f;  GLfloat ystep = 1.0f;
// Отслеживание изменений ширины и высоты окна
GLfloat windowWidth;  GLfloat windowHeight;
//Вызывается для рисования сцены 
void RenderScene(void) 
{
	// Очищаем окно,  используя текущий цвет очистки 
	glClear(GL_COLOR_BUFFER_BIT);
	// В качестве текущего цвета рисования задает красный //RGB
	glColor3f(1.0f, 0.0f, 0.0f);
	// Рисует прямоугольник, закрашенный текущим цветом
	glRectf(x1,  y1,  x1 + rsize,  y1- rsize);
	// Очищает очередь текущих команд и переключает буферы
	glutSwapBuffers();
}
//Вызывается библиотекой GLUT в холостом состоянии  (окно не меняет 	
//размера и не перемещается) 
void TimerFunction(int value) 
{
	//Основной цикл программы
	int counter = 0;
	while(rsize < 80){
		//Дополнительный счётчик
		if (rsize == 50){
			counter = 0;
		}
		//Очищает окно, используя текущий цвет очистки
		glClear(GL_COLOR_BUFFER_BIT);
		//Задает цвет рисования
		glColor3f(1.0f, 1.0f, 0.5f);
		//Рисует квадрат, на один пиксель больше чем предыдущий
		glRectf(x1-rsize, y1+rsize, x1+rsize, y1-rsize);
		//Условие, при котором квадрат либо увеличивается, 
		//либо уменьшается
		if((rsize != 79) && (counter == 0)){
			rsize += 1;
			counter = 0;
		}
		else
		{
			rsize -= 1;
			counter = 1;
		}
		//Очистка буфера
		glutSwapBuffers();
		//Временная задержка, для визуального восприятия
		//пульсации квадрата
		Sleep(100);
	}
}
//Задает состояние визуализации 
void SetupRC(void) 
{
	// Устанавливает в качестве цвета очистки синий
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
//Вызывается библиотекой GLUT при изменении размеров окна 
void ChangeSize(GLsizei w,  GLsizei h) 
{
	GLfloat aspectRatio; 
	// Предотвращает деление на нуль 
	if(h == 0) h = 1;
	// Устанавливает поле просмотра с размерами окна
	glViewport(0,   0, w,  h);
	// Обновляет систему координат
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//С помощью плоскостей отсечения  (левая,  правая,  нижняя, 
	// верхняя,  ближняя,  дальняя)  устанавливает объем отсечения 	
	aspectRatio = (GLfloat)w / (GLfloat)h; 
	if (w <= h) 
	{
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		glOrtho  (-100.0,   100.0,  -windowHeight,  windowHeight, 1.0,  -1.0);
	}
	else
	{
		windowWidth = 100 * aspectRatio; windowHeight = 100;
		glOrtho  (-windowWidth,  windowWidth,  -100.0,   100.0, 1.0,  -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//Точка входа основной программы 
void main(void) 
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); glutCreateWindow("Bounce") ; 
	glutDisplayFunc(RenderScene) ; 
	glutReshapeFunc(ChangeSize) ; 
	glutTimerFunc(33,   TimerFunction,   1); 
	SetupRC();
	glutMainLoop() ; 
}
