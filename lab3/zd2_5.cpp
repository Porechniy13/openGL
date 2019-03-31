void RenderScene(void)
    {
    float fZ,bZ;

    // Очищаем окно текущим цветом очистки
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    fZ = 100.0f;
    bZ = -100.0f;

    // Записываем состояние матрицы и выполняем поворот 
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);

    // Лицевая часть ///////////////////////////////////
    glBegin(GL_QUADS);
        
        // Левая сторона
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-40.0f, 50.0f, fZ);
		glVertex3f(-80.0f, 0.0f, fZ);
        glVertex3f(-70.0f, 0.0f, fZ);        
        glVertex3f(-30.0f, 50.0f,fZ);
		
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-40.0f, 50.0f, fZ);
		glVertex3f(-5.0f, 0.0f, fZ);
        glVertex3f(5.0f, 0.0f, fZ);        
        glVertex3f(-30.0f, 50.0f,fZ);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-80.0f, 0.0f, fZ);
        glVertex3f(-40.0f, -50.0f, fZ);
		glVertex3f(-30.0f, -50.0f,fZ);
        glVertex3f(-70.0f, 0.0f, fZ);        
        

		// Правая сторона

		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(30.0f, 50.0f, fZ);
		glVertex3f(-5.0f, 0.0f, fZ);
		glVertex3f(5.0f, 0.0f, fZ);                
        glVertex3f(40.0f, 50.0f,fZ);
		
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(30.0f, 50.0f, fZ);
		glVertex3f(70.0f, 0.0f, fZ);
		glVertex3f(80.0f, 0.0f, fZ);                
        glVertex3f(40.0f, 50.0f,fZ);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(70.0f, 0.0f, fZ);
        glVertex3f(30.0f, -50.0f, fZ);
		glVertex3f(40.0f, -50.0f,fZ);
		glVertex3f(80.0f, 0.0f, fZ);                
        
		// Нижняя линия

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-40.0f, -40.0f, fZ);
		glVertex3f(-40.0f, -50.0f,fZ);
		glVertex3f(40.0f, -50.0f, fZ);
		glVertex3f(40.0f, -40.0f,fZ);

		
    glEnd();

	///////////////Боковые стороны

	glBegin(GL_QUADS);
        
        // Левая сторона с крышкой
		glNormal3f(-40.0f, 50.0f, 0.0f);
        glVertex3f(-40.0f, 50.0f, fZ);
		glVertex3f(-40.0f, 50.0f, bZ);
		glVertex3f(-80.0f, 0.0f, bZ);
        glVertex3f(-80.0f, 0.0f, fZ);        
        
		glNormal3f(-40.0f, -50.0f, 0.0f);
		glVertex3f(-80.0f, 0.0f, fZ);
		glVertex3f(-80.0f, 0.0f, bZ);
		glVertex3f(-40.0f, -50.0f, bZ);
        glVertex3f(-40.0f, -50.0f, fZ);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-40.0f, 50.0f, fZ);
		glVertex3f(-30.0f, 50.0f, fZ);
		glVertex3f(-30.0f, 50.0f, bZ);
        glVertex3f(-40.0f, 50.0f, bZ);
		
		glNormal3f(-40.0f, 50.0f, 0.0f);   
		glVertex3f(-30.0f, 50.0f, fZ);
		glVertex3f(5.0f, 0.0f, fZ);   
		glVertex3f(5.0f, 0.0f, bZ);
		glVertex3f(-30.0f, 50.0f, bZ);	

		//////Правая сторона

		glNormal3f(40.0f, 50.0f, 0.0f);
        glVertex3f(40.0f, 50.0f, fZ);
		glVertex3f(80.0f, 0.0f, fZ);
		glVertex3f(80.0f, 0.0f, bZ);
		glVertex3f(40.0f, 50.0f, bZ);

		glNormal3f(40.0f, -50.0f, 0.0f);
        glVertex3f(40.0f, -50.0f, fZ);
		glVertex3f(40.0f, -50.0f, bZ);
		glVertex3f(80.0f, 0.0f, bZ);
		glVertex3f(80.0f, 0.0f, fZ);
		
		              
		          
        
    glEnd();   

	///////////////Внутренние поверхности
	glFrontFace(GL_CW);
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_QUADS);
        
        // Левая сторона
		glNormal3f(-40.0f, 50.0f, 0.0f);        
        glVertex3f(-70.0f, 0.0f, fZ);	
		glVertex3f(-30.0f, 50.0f, fZ);
		glVertex3f(-30.0f, 50.0f, bZ);
		glVertex3f(-70.0f, 0.0f, bZ); 

		glNormal3f(-40.0f, -50.0f, 0.0f);
		glVertex3f(-70.0f, 0.0f, fZ);
		glVertex3f(-70.0f, 0.0f, bZ);
		glVertex3f(-30.0f, -50.0f, bZ);
        glVertex3f(-30.0f, -50.0f, fZ);        

		glNormal3f(-40.0f, 50.0f, 0.0f);
        glVertex3f(-40.0f, 50.0f,fZ);
		glVertex3f(-5.0f, 0.0f, fZ);
        glVertex3f(-5.0f, 0.0f, bZ);
		glVertex3f(-40.0f, 50.0f,bZ);

		glNormal3f(0.0f, 1.0f, 0.0f);       
		glVertex3f(-5.0f, 0.0f, fZ);
        glVertex3f(5.0f, 0.0f, fZ);
		glVertex3f(5.0f, 0.0f, bZ);
		glVertex3f(-5.0f, 0.0f, bZ);

		///Правая сторона

		glNormal3f(40.0f, 50.0f, 0.0f);
		glVertex3f(5.0f, 0.0f, fZ);
		glVertex3f(40.0f, 50.0f, fZ);
		glVertex3f(40.0f, 50.0f, bZ);
		glVertex3f(5.0f, 0.0f, bZ);

		glNormal3f(30.0f, 50.0f, 0.0f);
        glVertex3f(30.0f, 50.0f, fZ);
		glVertex3f(70.0f, 0.0f, fZ);
		glVertex3f(70.0f, 0.0f, bZ);                
        glVertex3f(30.0f, 50.0f,bZ);
        
		glNormal3f(40.0f, -50.0f, 0.0f);
        glVertex3f(30.0f, -50.0f, fZ);
		glVertex3f(30.0f, -50.0f, bZ);
		glVertex3f(70.0f, 0.0f, bZ);
		glVertex3f(70.0f, 0.0f, fZ);
		
		glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-40.0f, -40.0f, fZ);
		glVertex3f(-40.0f, -40.0f, bZ);
		glVertex3f(40.0f, -40.0f, bZ);
		glVertex3f(40.0f, -40.0f, fZ);				

    glEnd();   

	glColor3f(1.0f, 0.0f, 0.0f);
	//////Внешние поверхности с обходом по часовой стрелке
	glBegin(GL_QUADS);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-40.0f, -50.0f, fZ);
		glVertex3f(40.0f, -50.0f, fZ);
		glVertex3f(40.0f, -50.0f, bZ);
        glVertex3f(-40.0f, -50.0f, bZ);

		//////Профильный силуэт
		//////Левая сторона
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-40.0f, 50.0f, bZ);
		glVertex3f(-80.0f, 0.0f, bZ);
        glVertex3f(-70.0f, 0.0f, bZ);        
        glVertex3f(-30.0f, 50.0f,bZ);
		
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-40.0f, 50.0f, bZ);
		glVertex3f(-5.0f, 0.0f, bZ);
        glVertex3f(5.0f, 0.0f, bZ);        
        glVertex3f(-30.0f, 50.0f,bZ);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-80.0f, 0.0f, bZ);
        glVertex3f(-40.0f, -50.0f, bZ);
		glVertex3f(-30.0f, -50.0f,bZ);
        glVertex3f(-70.0f, 0.0f, bZ);        
        

		// Правая сторона

		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(30.0f, 50.0f, bZ);
		glVertex3f(-5.0f, 0.0f, bZ);
		glVertex3f(5.0f, 0.0f, bZ);                
        glVertex3f(40.0f, 50.0f,bZ);
		
		glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(30.0f, 50.0f, bZ);
		glVertex3f(70.0f, 0.0f, bZ);
		glVertex3f(80.0f, 0.0f, bZ);                
        glVertex3f(40.0f, 50.0f,bZ);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(70.0f, 0.0f, bZ);
        glVertex3f(30.0f, -50.0f, bZ);
		glVertex3f(40.0f, -50.0f,bZ);
		glVertex3f(80.0f, 0.0f, bZ);                
        
		// Нижняя линия

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-40.0f, -40.0f, bZ);
		glVertex3f(-40.0f, -50.0f,bZ);
		glVertex3f(40.0f, -50.0f, bZ);
		glVertex3f(40.0f, -40.0f,bZ);

		//Правые крышки

		glNormal3f(30.0f, 50.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, fZ);
		glVertex3f(-5.0f, 0.0f, bZ);
        glVertex3f(30.0f, 50.0f, bZ);
		glVertex3f(30.0f, 50.0f, fZ);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(40.0f, 50.0f, fZ);
		glVertex3f(30.0f, 50.0f, fZ);
        glVertex3f(30.0f, 50.0f, bZ);
		glVertex3f(40.0f, 50.0f, bZ);	

	glEnd();
    
	glFrontFace(GL_CCW); 
	// Восстанавливается состояние матрицы
    glPopMatrix();

    // Буфер-обмена
    glutSwapBuffers();
	}