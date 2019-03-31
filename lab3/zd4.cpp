void RenderScene()
    {
    GLTMatrix   transformationMatrix;  // Матрица поворота       

    yRot += 0.5f;

    // Очистка окна ткущим цветом очистки
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

    // Строим матрицу поворота
    gltRotationMatrix(gltDegToRad(yRot), 0.0f, 1.0f, 0.0f, transformationMatrix);
    transformationMatrix[12] = 0.75f;
    transformationMatrix[13] = 0.5f;
    transformationMatrix[14] = -3.5f;
        
    DrawTorus(transformationMatrix);	

	gltRotationMatrix(gltDegToRad(yRot), 1.0f, 0.0f, 0.0f, transformationMatrix);
    transformationMatrix[12] = -0.75f;
    transformationMatrix[13] = 0.5f;
    transformationMatrix[14] = -3.5f;
        
    DrawTorus(transformationMatrix);

	gltRotationMatrix(gltDegToRad(yRot), 1.0f, 1.0f, 0.0f, transformationMatrix);
    transformationMatrix[12] = -0.75f;
    transformationMatrix[13] = -0.5f;
    transformationMatrix[14] = -3.5f;
        
    DrawTorus(transformationMatrix);

	gltRotationMatrix(gltDegToRad(yRot), 1.0f, 1.0f, 1.0f, transformationMatrix);
    transformationMatrix[12] = 0.75f;
    transformationMatrix[13] = -0.5f;
    transformationMatrix[14] = -3.5f;
        
    DrawTorus(transformationMatrix);

    // Буфер обмена
    glutSwapBuffers();
    }
