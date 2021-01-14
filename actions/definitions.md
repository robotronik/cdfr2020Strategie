# Definitions:
## Scores
	Base
	ManchesAir
	Phare
	BonPort
	Gobelets
	Positions -Ideallement, l'origine est au centre du terrain comme ca on peut juste faire un miroir sur toutes les coordonnees
	DebutMancheAir
	FinMancheAir
	AttenteGirouette
	PositionGirouette
	PositionPhare
	PortNord
	PortSud
	Fonctions
	UpdateForSide() -Determine de quel cote du terrain le robot est
	Goto(Position)
	LookAt(Position) -Fait tourner le robot de manier a ce qu'il regarde vers cette position
	DeployArm() -Sort le bon bras (droit si cote gauche, gauche si cote droit)
	RetractArm()
	GetGirouetteValue() -Blocking, True si Nord, False si Sud
	SetScore(value)
	Execution
	SetScore(Base)
## Manches a air
	Goto(DebutMancheAir)
	LookAt(FinMancheAir)
	DeployArm()
	Goto(FinMancheAir)
	SetScore(Base + ManchesAir)
	RetractArm()
## Girouette
	Goto(AttenteGirouette)
	LookAt(PositionGirouette)
	bShouldDockNorth = GetGirouetteValue()
## Phare
	Goto(PositionPhare)
	SetScore(Base + ManchesAir + Phare)
## Rentrer au port
	if(bShouldDockNorth)
	{ Goto(PortNord) }
	else { Goto(PortSud) }
	SetScore(Base + ManchesAir + Phare + BonPort)
