Liste des actions effectuées par le robot/ cahier des chargespotentiel

# Actions à effectuer

## Relever les manches à air D.5.
    * moyens méchaniques : 
        * bras à ouvrir(pas besoin de le fermer a priori)
        * capteur fin de course
        * tof (pour assurer la trajectoire le long du bord)
    * description de l'action: 
        * ouvrir bras jusqu'à fin de course
        * déplacement parrallèle le long du terrain
        * le bras pousse le manche à air
    * points : 
        * 5 points = 1 bras levé
        * 15 points = 2 bras levés

## Allumer le phare D.6.
    // activer l'expérience
    * moyens méchaniques : 
        * contact électrique physique qui ferme un circuit sur le phare
        ==> exemple : surface alluminium chargée VCC et bras robot (souple pour éviter la casse/ gérer l'imprécision du déplacement) à GND qui vient toucher et changer l'état de la pin
        * même bras que pour D.5.
    * description de l'action :
        * bras sorti
        * pin chargée
        * déplacement jusqu'au phare ==> contact
        * tof pour se positionner par rapport au bords
    * points :
        * 2 points = phare conforme sur la zone de jeu
        * 3 points = phare activé
        * 10 points = phare déployé et reste allumé jusqu'a la fin du match

## Arriver à bon port D.7. 
    * moyens méchaniques:
        * caméra(si linux+opencv)//capteur de couleur noir/blanc(si stm32)
    * description de l'action:
        * **après 25s de match** se mettre en position pour la lecture de la girouette qui indique la zone de mouillage
        * aller dans la bonne zone de mouillage
    * points:
        * 5 points = être dans la mauvaise zone de mouillage
        * 10 points = être dans la bonne zone de mouillage

## Hisser des pavillions D.8.
    * moyens :
        * bras pivotant levant le drapeau le plus bas au dela de 35cm
    * description de l'action:
        * **entre 95s et 100s de match** hisser le pavillon
    * points:
        * 10 points = pavillon hissé

## Prédire la performance D.9.
    * moyens :
        * une ardoise/feuille
    * points :
        * Points = (0.3 * score) - ecart

# Score visé
    * D5 = 15pts
    * D6 = 15pts (dont 2pts sûrs)
    * D7 = 10pts
    * D8 = 10pts
    score prédit = 50pts
    * D9 = 15pts
    score = 65pts

# Timeline des actions
0. ouvrir bras
1. Activer phare
2. Ouvrir manche à air = dplt le long du mur
3. Aruco girouette
4. Trouver Nord/sud, recalage odo? naviagation "à vue"(caméra)?
5. Se diriger au bon port
6. Hisser pavillon (implémentable sur la stm32Cerveau)

# A noter/Attention
    * symétrie axiale du terrain !!!
    * le plus simple est d'avoir **deux bras**, un de chaque coté car sinon il faut complètement changer le déplacement du robot


