void RenderScene(){
	// Начинаем веер треугольников
	glBegin(GL_TRIANGLE_FAN);
	// Вершина конуса является общей вершиной веера. Перемещаясь 
	// вверх по оси z, вместо окружности получаем конус
	glVertex3f(0.0f, 0.0f, 75.0f);
	//По циклу проходим окружность и задаем четные точки вдоль
	 // окружности как вершины веера треугольников
	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f)) 
		{
		// Рассчитываем положения x и у следующей вершины
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		// Чередуем красный и зеленый цвет
		if((iPivot %2) == 0)
			glColor3f(0.0f, 0.0f, 0.0f);
		else
			glColor3f(1.0f, 0.0f, 0.0f);
		// Увеличиваем pivot на 1, чтобы в следующий раз 
		// изменить цвет
		 iPivot++;
		// Задаем следующую вершину веера треугольников
		glVertex2f(x, y);
		}
	// Рисуем веер, имитирующий конус 
	glEnd();
	
}