/**
 * @file asteroid.c
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
#include <time.h>
#include <defines.h>
#include "entityDefines.h"
#include "entity.h"
#include "asteroid.h"

struct s_asteroid {
    _ENTITY_COMMON_FIELDS_
    /*--------------------------------*/
	double	*m_pOffsets;
};

/**
 * @brief The asteroid "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of asteroid location. 
 * @param locY y coordinate of asteroid location. 
 * @param radius asteroid radius size.
 * @param heading asteroid angular heading in radians.
 * @param velocX asteroid x velocity component.
 * @param velocY asteroid y velocity component.
 * @param rotation asteroid rotation.
 * @param color asteroid RGBA color.
 * @return t_asteroid* pointer to the newly created asteroid.
 */
t_asteroid*AsteroidNew(double locX, double locY, double radius, SDL_Color color){
	/**
	 * @todo AsteroidNew()
	 */

	t_asteroid*pAsteroid = (t_asteroid*)malloc(sizeof(t_asteroid));

	pAsteroid->m_locX = locX;
	pAsteroid->m_locY = locY;
	pAsteroid->m_radius = radius;
	pAsteroid->m_color = color;

	pAsteroid->m_heading = rand()%(360)*M_PI/180;

	pAsteroid->m_velocX =  (rand()%(ENTITY_ASTEROIDS_SPEED*2)-ENTITY_ASTEROIDS_SPEED)*0.3;
	pAsteroid->m_velocY =  (rand()%(ENTITY_ASTEROIDS_SPEED*2)-ENTITY_ASTEROIDS_SPEED)*0.3;

	pAsteroid->m_szVertices = rand()%(ENTITY_ASTEROIDS_VERTICES_NUM_MAX- ENTITY_ASTEROIDS_VERTICES_NUM_MIN)+ ENTITY_ASTEROIDS_VERTICES_NUM_MIN;
	pAsteroid->m_pVertices = (SDL_Point*)malloc(sizeof(SDL_Point)*pAsteroid->m_szVertices+1);
	pAsteroid->m_pOffsets = (double*)malloc(sizeof(double)*pAsteroid->m_szVertices+1);



	size_t k;

	for(k = 0; k<pAsteroid->m_szVertices;k++){
		pAsteroid->m_pOffsets[k] =   (rand()%(ENTITY_ASTEROIDS_JAGGER*2 + 1) + ENTITY_ASTEROIDS_JAGGER)*0.1;
	}

//	for(k = 0;k<pAsteroid->m_szVertices;k++){
//
//		pAsteroid->m_pVertices[k] =(SDL_Point){
//			.x = pAsteroid->m_locX + pAsteroid->m_pOffsets[k]*pAsteroid->m_radius*cos(k*2*M_PI/pAsteroid->m_szVertices),// *cos(pAsteroid->m_heading),
//			.y = pAsteroid->m_locY + pAsteroid->m_pOffsets[k]*pAsteroid->m_radius*sin(k*2*M_PI/pAsteroid->m_szVertices), //*sin(pAsteroid->m_heading),
//		};
//	}
//	pAsteroid->m_pVertices[k] = pAsteroid->m_pVertices[0];
    return pAsteroid;
}

/**
 * @brief The asteroid "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pAsteroid pointer to the asteroid to destroy. 
 * @return t_asteroid* NULL.
 */
t_asteroid*AsteroidDel(t_asteroid*pAsteroid){
    assert(pAsteroid);
	/**
	 * @todo AsteroidDel()
	 */
    free(pAsteroid->m_pOffsets);
    free(pAsteroid->m_pVertices);
    free(pAsteroid);
    return NULL;
}

/**
 * @brief Performs the graphical drawing of the asteroid.
 * 
 * @param pAsteroid pointer to the asteroid to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_asteroid* pointer to the actual asteroid. 
 */
const t_asteroid*AsteroidDraw(const t_asteroid*pAsteroid, SDL_Renderer*pRenderer){
    assert(pAsteroid);
	/**
	 * @todo drawing the asteroid polygon
	 */


    EntityDraw((t_entity*)pAsteroid,pRenderer);

    size_t k;
	for(k = 0;k<pAsteroid->m_szVertices;k++){

		pAsteroid->m_pVertices[k] =(SDL_Point){
			.x = pAsteroid->m_locX + pAsteroid->m_pOffsets[k]*pAsteroid->m_radius*cos(k*2*M_PI/pAsteroid->m_szVertices), //*cos(pAsteroid->m_heading),
			.y = pAsteroid->m_locY + pAsteroid->m_pOffsets[k]*pAsteroid->m_radius*-sin(k*2*M_PI/pAsteroid->m_szVertices), //*-sin(pAsteroid->m_heading), // DID NOT DO ON PURPOSE
		};
	}
	pAsteroid->m_pVertices[k-1] = pAsteroid->m_pVertices[0];


	return NULL;
}

/**
 * @brief Performs the moving of the asteroid.
 *        Takes care of space area limits over-crossing.
 * 
 * @param pAsteroid pointer to the asteroid to move.
 * @param pSpaceArea pointer to the space area properties.
 * @return t_asteroid* pointer to the actual asteroid. 
 */
t_asteroid*AsteroidMove(t_asteroid*pAsteroid, const SDL_Rect*pSpaceArea){
    assert(pAsteroid);
	/**
	 * @todo moving the asteroid
	 */

    EntityMove((t_entity*)pAsteroid, pSpaceArea);
    pAsteroid->m_heading += 0.01;

	return NULL;
}
