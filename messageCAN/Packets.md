## Packets nécessaires

Carte camera : 

 - Requete get position girouette -> return bool 
  - Requete get girouette acquise / arretee -> return bool 
  - Requete get phare deploye -> return bool

Carte controle moteurs : 
- Requete get position robot -> return float x, y 
- Requete get angle robot -> return float rotation 
- Requete set cible position robot -> send float x,y -> return ack 
- Requete set cible rotation robot -> send float rotation -> return ack 
- Notify fin de mouvement -> require ack, timeout 100ms 
- Requete set ouverture moteur (genre bras girouette) via bitmask -> return ack 
- Requete get ouverture moteur -> return bitmask(edited)

Requete = envoyé la carte strategie 
Notify = envoyé par la carte cible lors de la fin d'un évenement