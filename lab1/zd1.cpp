#include "glew.h" 
#include "glut.h" 
void RenderScene(void)

{
	// Окно очищается текущим цветом очистки 
	glClear(GL_COLOR_BUFFER_BIT);
	// В буфер вводятся команды рисования 
	glFlush();
}

///////////////////////////////////////////////////////////////////  
// Устанавливается состояние визуализации 
void SetupRC(void)
{
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
}

///////////////////////////////////////////////////////////////////  
// Точка входа основной программы 
void main(void)
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

}
 
