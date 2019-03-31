void RenderScene(){
glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);
	// Центром веера является начало координат 
	glVertex2f(0.0f, 0.0f);
	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
		{
		// Рассчитываем координаты х и у следующей вершины
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		// Чередуем красный и зеленый цвета
		if((iPivot %2) == 0)
			glColor3f(0.0f, 1.0f, 0.0f);
		else
			glColor3f(1.0f, 0.0f, 0.0f); 
		// Увеличиваем pivot на единицу, чтобы в следующий раз
		// поменять цвета 
		iPivot++;
		// Задаем следующую вершину веера треугольников
		glVertex2f(x, y);
		}
	// Рисуем веер
	 glEnd();
}