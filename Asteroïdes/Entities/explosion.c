/**
 * @file explosion.c
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
#include "explosion.h"

/**
 * @brief the explosion structure definition. 
 */
struct s_explosion {
    _ENTITY_COMMON_FIELDS_
    /*------------------------------*/
	double	  	m_TTL;
};

/**
 * @brief The explosion "constructor".
 *        Performs memory allocation, and
 *        components initialization.
 * 
 * @param locX x coordinate of explosion location. 
 * @param locY y coordinate of explosion location. 
 * @param color explosion RGBA color.
 * @return t_explosion* pointer to the newly created explosion.
 */
t_explosion*ExplosionNew(double locX, double locY, SDL_Color color){
    /**
     * @todo ExplosionNew()
     */
    return NULL;
}

/**
 * @brief The explosion "destructor".
 *        Performs memory de-allocation, and
 *        freeing all resources.
 * 
 * @param pExplosion pointer to the explosion to destroy. 
 * @return t_explosion* NULL.
 */
t_explosion*ExplosionDel(t_explosion*pExplosion){
    assert(pExplosion);
    /**
     * @todo ExplosionDel()
     */
    return NULL;
}

/**
 * @brief Performs the graphical drawing of the explosion.
 * 
 * @param pExplosion pointer to the explosion to draw.
 * @param pRenderer pointer to the renderer in which to draw.
 * @return t_explosion* depends on condition. 
 */
t_explosion*ExplosionDraw(t_explosion*pExplosion, SDL_Renderer*pRenderer){
    /**
     * @todo ExplosionDraw()
     */
    return NULL;
}

