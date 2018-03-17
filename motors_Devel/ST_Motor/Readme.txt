How to use

Functions:
ST_MOT_Init(a,b,c,d) - returns nothing. 
	a - stepper_ID(0-2)
	b - (float) deadzone 
	c - (double) Acceleration (use with caution, no protection) (1000-10000)
	d - (int) Min stepper period (400 works fine);
	
Movment_Prep(a,b) //will return if movment is finished, for now returns nothing. 
	a - stepper_ID{0-2)
	b - (float) absolute position
	
Period_Control(a,b,c) //not safe.
	a - stepper_ID
	b - stepper_period
	c - stepper_turn_flag
	
pos_put(a)
	a - stepper_ID
	
	Warning, edit this function to update encoder values