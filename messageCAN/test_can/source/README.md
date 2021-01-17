**Pseudo-code CAN:**

-A message to send is created, for instance a command to turn on the receptor LED;

-Can is set up;

-Data are registered in a transmitting FIFO;

-The message is emitted and the board checks the acknowledgement of the message;

-The emitting board turned on a LED if the message is acknowledged;

-Otherwise, the board spawns an error message and stops; 
