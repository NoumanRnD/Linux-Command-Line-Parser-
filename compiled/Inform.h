#ifndef INFORM_H
 #define INFORM_H
 
 // largest message (in bytes) that can be kept
 #define MAX_MSG_SIZE    (1024 * 8)
 
 
 class Inform {
 private:
   char *name;                    
   char buf[MAX_MSG_SIZE+1];      
   char tmpbuf[128];              
 #if defined(VMDTKCON)
   int  loglvl;                   
 #endif
   int muted;                     
 
 public:
 #if defined(VMDTKCON)
   Inform(const char *, int lvl); 
 #else
   Inform(const char *);          
 #endif
   ~Inform();                     
   Inform &send();                
   Inform &reset();               
 
   Inform& operator<<(const char *);
   Inform& operator<<(char);
   Inform& operator<<(int);
   Inform& operator<<(unsigned int);
   Inform& operator<<(long);
   Inform& operator<<(unsigned long);
   Inform& operator<<(double);
   Inform& operator<<(Inform& (*f)(Inform &));
 
   void mute() { muted = 1; }
   void unmute() { muted = 0; }
 
   const char *text() const {
     return buf;
   }
 };
 
 extern Inform& sendmsg(Inform&); 
 extern Inform& ends(Inform&);    
 
 // XXX these are global
 extern Inform msgInfo;           
 extern Inform msgWarn;           
 extern Inform msgErr;            
 
 #endif // INFORM_H
