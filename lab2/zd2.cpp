void RenderScene(){
	curSize = 1;
	
	for (int i = 0; i < 30; i++){
		x = rand() % 100 - 50;
		y = rand() % 100 - 50;
		z = rand() % 100 - 50;

		glPointSize(curSize);

		glColor3f(rand()%2,rand()%2,rand()%2);

		glBegin(GL_POINTS);
			glVertex3f(x,y,z);
		glEnd();
		curSize += 0.1;
	}

	
}