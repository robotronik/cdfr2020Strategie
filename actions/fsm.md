# Pseudocode State machine :
*(on suppose que le robot part de la gauche)*

## Etape hisser les manches a air
- Aller en bas a gauche
- Se tourner vers la droite, si possible en suivant le mur
- Deployer le bras
- Avancer vers la droite d'une distance suffisante pour pousser toutes les manches a air
- Incrementer le compteur de points de la valeur des manches a air
## Etape Girouette
(au debut de cette etape, le robot se situe environ au milieu en bas du plateau)
- Le robot se tourne vers le haut
- Il avance vers la girouette. Lancement de la subroutine Determiner la position de la girouette
- Il prend la valeur de la girouette lorsqu'elle ne tourne pas, la subroutine s'arrete alors
## Etape Phare
(le robot est au milieu de terrain)
- Il continue alors son chemin jusqu'au mur superieur
- Il suit le mur du haut vers la gauche jusqu'a toucher le phare. Le compteur est mis a jour
## Etape Rentrer au port
(le robot est en haut a gauche du terrain)
- Il rentre au port en suivant le mur de gauche, et s'arrete dans la bonne zone. Le compteur est mis a jour

Si le robot demarre dans la zone droite, alors tout est en miroir horizontal
