void RenderScene(){
z = 0.0f;		
	
	for (u = 0.0f; u < 3.0f; u+=1.0f){
		glBegin(GL_LINE_LOOP);
		for(v = 0.0f; v < (GL_PI*2.0f); v+=0.1f){
			x = 50.0f*cos(v);
			y = 50.0f*sin(v);
			
			glVertex3f(x, y, z);			
		
					
			}
		glEnd();
		z += 20.0f;
	}
}	
