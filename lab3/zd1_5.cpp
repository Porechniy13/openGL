void RenderScene(void)
	{
// Угол поворота вокруг ядра
	static GLfloat fElect1 = 0.0f;

	// Очищаем окно текущим цветом очистки
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Обновляем матрицу наблюдения модели
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Транслируем всю сцену в поле зрения
//Это исходное преобразование наблюдения
	glTranslatef(0.0f, 0.0f, -100.0f);	

	// Красное ядро и малая орбита для вращения
	glPushMatrix();
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-10.0f, 0.0f, 0.0f);
	glColor3ub(255, 0, 0);
	glutSolidSphere(10.0f, 15, 15);
	glPopMatrix();
	

	// Желтые электроны
	glColor3ub(255,255,0);

	// Орбита первого электрона
// Записываем преобразование наблюдения
	glPushMatrix();

	// Поворачиваем на угол поворота
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);

	// Трансляция элемента от начала координат на орбиту
	glTranslatef(90.0f, 0.0f, 0.0f);

	// Рисуем электрон
	glutSolidSphere(6.0f, 15, 15);
    

	// Восстанавливаем преобразование наблюдения
	glPopMatrix();

	//Орбита второго электрона
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-70.0f, 0.0f, 0.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();


	// Орбита третьего электрона
	glPushMatrix();
	glRotatef(360.0f-45.0f,0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 60.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();


// Увеличиваем угол поворота
	fElect1 += 10.0f;
	if(fElect1 > 360.0f)
		fElect1 = 0.0f;

// Показываем построенное изображение
	glutSwapBuffers();
	}
