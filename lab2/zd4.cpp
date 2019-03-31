void RenderScene(){
	glBegin(GL_LINES);
	z = -50.0f;	
	u = -GL_PI;
	for(v = 0.0f; v < (GL_PI*2.0f)*3.0f; v+=0.1f){
		x = 50.0f*sin(u)*cos(v);
		y = 50.0f*sin(u)*cos(v);
		z = 50.0f * cos(u);
					// Задаем первую точку отрезка		
		glVertex3f(x, y, z);
		

		x = 50.0f*sin(u+0.1f)*cos(v+0.1f);
		y = 50.0f*sin(u+0.1f)*cos(v+0.1f);
		z = 50.0f * cos(u+0.1f);
					// Задаем конец отрезка		
		glVertex3f(x, y, z);
			
		
		u+=0.1f;		
		}
	glEnd();	
}