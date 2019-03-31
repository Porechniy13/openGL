void RenderScene(void)
	{
	// Угол поворота системы Земля/Луна
	static float fMoonRot = 0.0f;
	static float fEarthRot = 0.0f;
	static float fSecondPlanetRot = 0.0f;
	static float fSecondMoonRot = 0.0f;

	// Очищаем окно текущим цветом очистки
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Сохраняем матрицу в стек 
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Транслируем всю сцену в поле зрения
	glTranslatef(0.0f, 0.0f, -300.0f);	
	
	// Устанавливаем цвет материала красным
// Солнце
        glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 0);
	glutSolidSphere(15.0f, 30, 17);
        glEnable(GL_LIGHTING);

	// Движение источника света, после прорисовки солнца!
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

	// Поворот системы координат
	glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);

	// Прорисовка Земли
	glColor3ub(0,0,255);
	glTranslatef(105.0f,0.0f,0.0f);
	glutSolidSphere(15.0f, 30, 17);


	// Поворот в системе координат, связанной с Землей
// и изображение Луны

	glColor3ub(200,200,200);
	glRotatef(fMoonRot,0.0f, 1.0f, 0.0f);
	glTranslatef(30.0f, 0.0f, 0.0f);
	fMoonRot+= 15.0f;
	if(fMoonRot > 360.0f)
		fMoonRot = 0.0f;

	glutSolidSphere(6.0f, 30, 17);

	// Восстанавливается состояние матрицы
	glPopMatrix();	// Матрица наблюдения модели


	// Шаг по орбите Земли равен пяти градусам
	fEarthRot += 5.0f;
	if(fEarthRot > 360.0f)
		fEarthRot = 0.0f;


	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, -300.0f);

	glRotatef(fSecondPlanetRot, 0.0f, 1.0f, 0.0f);
	/////////// Прорисовка второй планеты
	///////////
	glColor3ub(128,128,0);
	glTranslatef(30.0f,0.0f,0.0f);
	glutSolidSphere(10.0f, 30, 17);


	// Поворот в системе координат, связанной с Землей
// и изображение Луны

	glColor3ub(200,200,200);
	glRotatef(fSecondMoonRot,0.0f, 1.0f, 0.0f);
	glTranslatef(12.0f, 0.0f, 0.0f);
	fSecondMoonRot+= 3.0f;
	if(fSecondMoonRot > 360.0f)
		fSecondMoonRot = 0.0f;

	glutSolidSphere(1.0f, 30, 17);

	// Восстанавливается состояние матрицы
	glPopMatrix();	// Матрица наблюдения модели


	// Шаг по орбите Земли равен пяти градусам
	fSecondPlanetRot += 3.0f;
	if(fSecondPlanetRot > 360.0f)
		fSecondPlanetRot = 0.0f;

	// Показывается построенное изображение
	glutSwapBuffers();
	}