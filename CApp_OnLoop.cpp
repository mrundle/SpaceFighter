#include "CApp.h"
 
void CApp::OnLoop() {

	if((Fighter.movingUp == true) && (Fighter.Y >0) ){
		Fighter.Y-=0.25;
	}
	if((Fighter.movingDown == true) && ((Fighter.Y + Fighter.Height ) < WHEIGHT) ){
		Fighter.Y+=0.25;
	}

	if(isMoving == true){
		Anim_Char.OnAnimate();
	}

	
	// Randomly generate enemy bullets
	// each one has a 1/100 chance of firing
	std::vector<CEntity*>::iterator i;
	//for(i=EntityList.begin();i!=EntityList.end();i++){
		//if( (*i)->Type == ENTITY_TYPE_ENEMYSHIP){
			int rnd = rand() % 1000;
			if( rnd == 50 ){
				EnemyShip* tempEnemyShip = new EnemyShip;
				(*tempEnemyShip).OnLoad();
				(*tempEnemyShip).X = WWIDTH;
				(*tempEnemyShip).Y = rand() % (WHEIGHT-(*tempEnemyShip).Height);
				EntityList.push_back(tempEnemyShip);
				/*EnemyBullet* tempEnemyBullet = new EnemyBullet;
				(*tempEnemyBullet).OnLoad();
				(*tempEnemyBullet).X = (*i)->X;
				(*tempEnemyBullet).X = ((*i)->Y)+ 6;
				EntityList.push_back(tempEnemyBullet);*/
				std::cout << "Fire\n";		
			}
		//}
	//}


	// Move the Entities and delete them if they are off the screen
	for(i=EntityList.begin();i!=EntityList.end();i++){
		// Move the Entities		
		(*i)->OnLoop();

		// if enemy ship, see if any bullets are in the area
		if( (*i)->Type == ENTITY_TYPE_ENEMYSHIP ){ 
			std::vector<CEntity*>::iterator j;
			for(j=EntityList.begin();j!=EntityList.end();j++){
				if( (*j)->Type == ENTITY_TYPE_BULLET){
					// Check to see if boxes DONT collide
					if( // Rectangle 1′s bottom edge is higher than Rectangle 2′s top edge
						( ((*i)->Y+(*i)->Height) < ((*j)->Y) )  ||
						// Rectangle 1′s top edge is lower than Rectangle 2′s bottom edge
						( ((*i)->Y) > (((*j)->Y)+(*j)->Height) )  ||
						// Rectangle 1′s left edge is to the right of Rectangle 2′s right edge.
						( (((*i)->X)+30) > (((*j)->X)+(*j)->Width) )  ||
						// Rectangle 1′s right edge is to the left of Rectangle 2′s left edge
						( ((*i)->X+(*i)->Width) < ((*j)->X) )
					   ){}else{
						// delete the bullet and the ship
						(*i)->erase = true;
						(*j)->erase = true;
						Mix_PlayChannel(-1, sfx1, 0);
						scoreNumber++;
					}
				}
			}
		}

		// delete if off screen or killed
		if( (((*i)->X) > WWIDTH) || ((((*i)->X)+(*i)->Width) < 0) || ((*i)->erase == true) ){
			delete (*i);
			if(i != EntityList.end()){
				EntityList.erase(i--);
			}
			if(i == EntityList.end()){
				EntityList.pop_back();
			}
		}
	}

	//std::cout << EntityList.size() << std::endl;

}
