void RenderScene(){
	width = 1.0f;
	factor = 0.0f;
	glEnable(GL_LINE_STIPPLE);
	 
	for(int i = 0; i < 10; i++) 
		{
		factor = rand()%2+1;
		glLineWidth(width);
		glLineStipple(factor,pattern);
		
		glColor3f(rand()%2, rand()%2, rand()%2);

		glBegin(GL_LINES);

		x = rand() % 200 - 100;
		y = rand() % 200 - 100;
		z = rand() % 200 - 100;		
		glVertex3f(x,y,z);

		x = rand() % 200 - 100;
		y = rand() % 200 - 100;
		z = rand() % 200 - 100;		
		glVertex3f(x,y,z);

		width += 0.5f;

		glEnd();
	}	
}