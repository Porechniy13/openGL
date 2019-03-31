void RenderScene(void)
    {
    int i;
 static GLfloat yRot = 0.0f; // Используемый в анимации угол поворота

    yRot += 0.5f;
        
    // Очищаем окно текущим цветом очистки
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    glPushMatrix();
        gltApplyCameraTransform(&frameCamera);
        
        // Рисуем землю
        DrawGround();
        
        // Рисуем случайным образом расположенные сферы
        for(i = 0; i < 10; i++)
            {
            glPushMatrix();
            gltApplyActorTransform(&spheres[i]);
            glutSolidSphere(0.1f, 13, 26);
            glPopMatrix();
            }

		 for(i = 0; i < 10; i++)
            {
            glPushMatrix();
            gltApplyActorTransform(&spheres[i+10]);
			glTranslatef(0.0f, 0.0f, -2.5f);
			glRotatef(yRot, 0.0f, 1.0f, 0.0f);
            glutSolidTeapot(0.3f);
            glPopMatrix();
            }

		 for(i = 0; i < 10; i++)
            {
            glPushMatrix();
            gltApplyActorTransform(&spheres[i+20]);
			glTranslatef(0.0f, 0.0f, -2.5f);
			glRotatef(yRot, 0.0f, 1.0f, 0.0f);
            glutSolidCube(0.3f);
            glPopMatrix();
            }


        glPushMatrix();
            glTranslatef(0.0f, 0.0f, -2.5f);
    
            glPushMatrix();
                glRotatef(-yRot * 2.0f, 0.0f, 1.0f, 0.0f);
                glTranslatef(1.0f, 0.0f, 0.0f);
                glutSolidSphere(0.1f, 13, 26);
            glPopMatrix();
    
            glRotatef(yRot, 0.0f, 1.0f, 0.0f);			
            gltDrawTorus(0.35, 0.15, 40, 20);
        glPopMatrix();
    glPopMatrix();
        
    // Переключение буферов
    glutSwapBuffers();
    }
