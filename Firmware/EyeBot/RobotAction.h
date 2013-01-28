
#ifndef robotaction_h
#define robotaction_h

/* Temperament */
void surprise();
void frenetic(int step);
void caress(); 
void greet();
void fearNoise();
void adorablePet();

/* Route */
void goBackward(int step); 
void goForward(int step); 
void BackFootR();
void BackFootL();
void ForwardFootR(); 
void ForwardFootL();
void rush(int step); 
void rotateR();
void rotateL();
void standingHome();

#endif
