,                           ;read character and store it in p1
------------------------------------------------   ;return ascii to Dec
>;move pointer to p2 (second byte)
,
<                         ;read character and store it in p2
------------------------------------------------ ;return ascii to Dec
[                           ; enter loop
-                           ; decrement p2
>                           ; move to p1
+ 
<                           
]                                                    ;go back to p1
++++ ++++[
	>+++ +++<-
]>    ;return Dec to ascii
.                           ;print p1