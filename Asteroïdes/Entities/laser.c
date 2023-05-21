/**
 * @file laser.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <SDL2/SDL.h>

#include <defines.h>
#include "entityDefines.h"
#include "entity.h"
#include "laser.h"

/**
 * @brief the ship structure definition.
 */
struct s_laser{
    _ENTITY_COMMON_FIELDS_
    /*----------------------------------*/
	int		m_dist;
};

/**
 * @brief The laser "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of laser location. 
 * @param locY y coordinate of laser location. 
 * @param radius laser radius size.
 * @param heading laser angular heading in radians.
 * @param velocX laser x velocity component.
 * @param velocY laser y velocity component.
 * @param color laser RGBA color.
 * @return t_laser* pointer to the newly created laser.
 */
t_laser*LaserNew(
        double locX, double locY, double radius, 
        double heading, double velocX, double velocY, SDL_Color color){
    /**
     * @todo LaserNew()
     */

	t_laser*pLaser = (t_laser*)malloc(sizeof(t_laser));
	assert(pLaser);

	pLaser->m_locX	  = locX;
	pLaser->m_locY 	  = locY;
	pLaser->m_radius  = radius;
	pLaser->m_heading = heading;
	pLaser->m_velocX  = velocX/30;
	pLaser->m_velocY  = velocY/30;
	pLaser->m_color   = color;
	pLaser->m_dist    = 0;
//	pLaser = (t_laser*)realloc(pLaser,sizeof(SDL_Point)*5);
	pLaser->m_pVertices =(SDL_Point*)malloc(sizeof(SDL_Point)*5);
	pLaser->m_szVertices =5;


	pLaser->m_velocX = pLaser->m_velocX*cos(pLaser->m_heading);
	pLaser->m_velocY = -pLaser->m_velocX*tan(pLaser->m_heading);


    return pLaser;
}

/**
 * @brief The laser "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pLaser pointer to the laser to destroy. 
 * @return t_laser* NULL.
 */
t_laser*LaserDel(t_laser*pLaser){
    assert(pLaser);
    /**
     * @todo LaserDel()
     */
    free(pLaser);

    return NULL;
}

/**
 * @brief Performs the graphical drawing of the laser.
 * 
 * @param pLaser pointer to the laser to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_laser* NULL. 
 */
const t_laser*LaserDraw(const t_laser*pLaser, SDL_Renderer*pRenderer){
    assert(pLaser);
    /**
     * @todo LaserDraw()
     */

    EntityDraw((t_entity*)pLaser, pRenderer);

    return NULL;
}

/**
 * @brief Performs the moving of the laser.
 *        Takes care of space area limits over-crossing.
 * 
 * @param pLaser pointer to the laser to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return t_laser*  depends on condition. 
 */
t_laser*LaserMove(t_laser*pLaser, const SDL_Rect*pSpaceArea){
    assert(pLaser);
    /**
     * @todo LaserMove()
     */

    EntityMove((t_entity*)pLaser, pSpaceArea);

    size_t k;
    for(k = 0; k <4; k++){
    	pLaser->m_pVertices[k].x = pLaser->m_locX + pLaser->m_radius*(cos(((90*k+45)*M_PI)/180)*cos(pLaser->m_heading)+sin(((90*k+45)*M_PI)/180)*sin(pLaser->m_heading));
		pLaser->m_pVertices[k].y = pLaser->m_locY + pLaser->m_radius*(-cos(((90*k+45)*M_PI)/180)*sin(pLaser->m_heading)+sin(((90*k+45)*M_PI)/180)*cos(pLaser->m_heading));
    }

	pLaser->m_pVertices[4] = pLaser->m_pVertices[0];

	pLaser->m_dist++;

	if(pLaser->m_dist > ENTITY_LASER_MAX_DIST*pSpaceArea->w){

		return pLaser;
	}


    return NULL;
}
